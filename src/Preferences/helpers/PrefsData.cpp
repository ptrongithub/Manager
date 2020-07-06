//
// Created by jvines on 6/23/2020.
//

#include "PrefsData.h"

PrefsData::PrefsData() {
//	Prefs = nullptr;
	Prefs = APP.Preferences;
	modified = false;
}

PrefsData::PrefsData(const pt::ptree& prefs, bool modified = false) : Prefs(prefs), modified(modified) {
	;
}

PrefsData::~PrefsData() {
	;
}

bool PrefsData::GetModified() const {
	return modified;
}

void PrefsData::SetModified(bool Modified) {
	modified = Modified;
//	DialogButtonsApply->Enable(modified);
//	DialogButtonsCancel->Enable(modified);
}

wxString PrefsData::GetPrefs(const std::string& Path) const {
	return Prefs.get(Path, "").data();
}

void PrefsData::SetPrefs(const std::string& Path, wxString& Data) {
	Prefs.put(Path, Data.ToStdString());
}

bool PrefsData::SavePrefs() {
	pt::write_json("preferences.json", Prefs);
	ApplyPrefs();
	modified = false;
	return true;
}

bool PrefsData::ReadPrefs() {
	ApplyPrefs();
	return true;
}

bool PrefsData::ApplyPrefs() {
	APP.Preferences = Prefs;
	return true;
}

