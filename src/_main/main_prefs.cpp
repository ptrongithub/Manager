#include <iostream>

#include "main.h"
#include "forms/main/manager.h"
#include "forms/config/Preferences.h"

bool MyApp::OnInit() {
	if (!ReadOptions()) {
		LoadOptions();
	}
//	auto* frame = new ApplicationWindow();
//	frame->Show();
	auto* frame = new PreferencesWindow(NULL);

	frame->ShowModal();
	frame->Destroy();
	return true;
}

bool MyApp::LoadOptions() {

	Preferences.put("database.mysql.host", "localhost");
	Preferences.put("database.mysql.port", "3306");
	Preferences.put("database.mysql.user", "");
	Preferences.put("database.mysql.pass", "");
	Preferences.put("database.mysql.data", "");

	return true;
}

bool MyApp::SaveOptions() {
	pt::write_json("preferences.json", Preferences);
	return true;
}

bool MyApp::ReadOptions() {
	try {
		std::ifstream prefsFile;
		prefsFile.open("preferences.json");
		if (prefsFile) {
			pt::read_json(prefsFile, Preferences);
			prefsFile.close();
		} else {
			// throw std::runtime_error("preferences file missing");
			wxMessageBox("Preferences file not found.\nLoading defaults.",
					"Preferences File Error!", wxOK | wxICON_ERROR);
			return false;
		}
	} catch (const std::exception& err) {
//		wxMessageBox(err.what(), "Exception Error!", wxOK | wxICON_ERROR);
		wxMessageBox("There was a problem reading the Preferences file.\nLoading defaults.",
				"Preferences File Error!", wxOK | wxICON_ERROR);
		return false;
	}
	return true;
}

//wxDECLARE_APP(MyApp);

wxIMPLEMENT_APP(MyApp);

