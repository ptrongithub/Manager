//
// Created by jvines on 7/8/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "mPrefs.h"

pt::ptree mPrefs::Preferences;


const pt::ptree& mPrefs::GetPreferences() {
	return mPrefs::Preferences;
}

void mPrefs::SetPreferences(const pt::ptree& preferences) {
	mPrefs::Preferences = preferences;
}

const std::string mPrefs::GetPref(const std::string& setting) {
	std::string data = mPrefs::Preferences.get(setting, "").data();
	return data;
}

void mPrefs::SetPref(const std::string& setting, const std::string& data) {
	mPrefs::Preferences.put(setting, data);
}

bool mPrefs::LoadPrefs() {
	try {
		std::ifstream prefsFile;
		prefsFile.open("preferences.json");
		if (prefsFile) {
			pt::read_json(prefsFile, mPrefs::Preferences);
			prefsFile.close();
		} else {
			// throw std::runtime_error("preferences file missing");
			wxMessageBox("Preferences file not found.\nLoading defaults.",
			             "Preferences File Error!", wxOK | wxICON_ERROR);
			mPrefs::Defaults();
			return false;
		}
	} catch (const std::exception& err) {
//		wxMessageBox(err.what(), "Exception Error!", wxOK | wxICON_ERROR);
		wxMessageBox("There was a problem reading the Preferences file.\nLoading defaults.",
		             "Preferences File Error!", wxOK | wxICON_ERROR);
		mPrefs::Defaults();
		return false;
	}
	return true;
}

bool mPrefs::WritePrefs() {
	pt::write_json("preferences.json", mPrefs::Preferences);
	return true;
}

bool mPrefs::Defaults() {
	mPrefs::Preferences.put("database.mysql.host", "localhost");
	mPrefs::Preferences.put("database.mysql.port", "3306");
	mPrefs::Preferences.put("database.mysql.user", "");
	mPrefs::Preferences.put("database.mysql.pass", "");
	mPrefs::Preferences.put("database.mysql.data", "");

	return true;
}
