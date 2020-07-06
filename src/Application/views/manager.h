//
// Created by jvines on 6/3/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#ifndef MANAGER_MANAGER_H
#define MANAGER_MANAGER_H

// includes main application object and global library includes
#include "src/includes.h"

#include "src/Preferences/views/Preferences.h"

class ApplicationWindow : public wxMDIParentFrame {
public:
	ApplicationWindow();
//	ApplicationWindow(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
	// Events Handlers
	void OnAbout(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnHello(wxCommandEvent &event);
	void OnPreferences(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();
};

#endif //MANAGER_MANAGER_H
