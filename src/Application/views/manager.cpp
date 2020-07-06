//
// Created by jvines on 6/3/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "manager.h"

enum {
	ID_Hello = wxID_HIGHEST,
	ID_Preferences
};

wxBEGIN_EVENT_TABLE(ApplicationWindow, wxMDIParentFrame)
	EVT_MENU(ID_Hello, ApplicationWindow::OnHello)
	EVT_MENU(ID_Preferences, ApplicationWindow::OnPreferences)
	EVT_MENU(wxID_ABOUT, ApplicationWindow::OnAbout)
	EVT_MENU(wxID_EXIT, ApplicationWindow::OnExit)
wxEND_EVENT_TABLE()

ApplicationWindow::ApplicationWindow()
		: wxMDIParentFrame(NULL, wxID_ANY,
				           "Business Manager",
				           wxPoint(50, 50), //wxDefaultPosition,
				           wxSize(450, 340)) {
	// Create and Populate File menu
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
			"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	// Create and Populate Admin Menu
	wxMenu *menuAdmin = new wxMenu;
	menuAdmin->Append(ID_Preferences, "&Preferences...",
			"Change settings about the program");

	// Create and Populate Help menu
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	// Create and Populate menu bar
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuAdmin, "&Administration");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}

void ApplicationWindow::OnAbout(wxCommandEvent &event) {
	wxMessageBox("This is a wxWidgets' Hello world sample",
			"About Hello World", wxOK | wxICON_INFORMATION);
}

void ApplicationWindow::OnExit(wxCommandEvent &event) {
	Close(true);
}

void ApplicationWindow::OnHello(wxCommandEvent &event) {
	wxLogMessage("Hello world from wxWidgets!");
	std::cout << "Hello, World!" << std::endl;
}

void ApplicationWindow::OnPreferences(wxCommandEvent &event) {
	// TODO: Create and Utilize Preferences Dialog
//	wxLogMessage("Edit Preferences!");
	PreferencesWindow *PreferencesForm = new PreferencesWindow(this);
	PreferencesForm->ShowModal();

}
