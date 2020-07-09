//
// Created by jvines on 7/8/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#ifndef MANAGER_MPREFS_H
#define MANAGER_MPREFS_H

#include "src/includes.h"
#include "src/views.inc.h"
#include "src/ptree.inc.h"

class mPrefs {
public:
	static bool LoadPrefs();
	static bool WritePrefs();

	static const pt::ptree& GetPreferences();
	static void SetPreferences(const pt::ptree& preferences);

	static const std::string GetPref(const std::string& setting);
	static void SetPref(const std::string& setting, const std::string& data);


private:
	static bool Defaults();
	static pt::ptree Preferences;

};


#endif //MANAGER_MPREFS_H
