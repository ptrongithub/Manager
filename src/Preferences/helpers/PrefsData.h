//
// Created by jvines on 6/23/2020.
//

#ifndef MANAGER_PREFSDATA_H
#define MANAGER_PREFSDATA_H

#include "src/includes.h"


class PrefsData {

public:

	PrefsData();
	PrefsData(const pt::ptree& prefs, bool modified);
	virtual ~PrefsData();

	wxString GetPrefs(const std::string& Path) const;
	void SetPrefs(const std::string& Path, wxString& Data);

	bool GetModified() const;
	void SetModified(bool Modified);

protected:

	bool SavePrefs();
	bool ReadPrefs();
	bool ApplyPrefs();

private:

	pt::ptree Prefs;
	bool modified;

};

#endif //MANAGER_PREFSDATA_H
