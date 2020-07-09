//
// Created by jvines on 6/7/2020
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#include "main.h"

bool MyApp::OnInit() {
	mPrefs::LoadPrefs();
//	auto* mainFrame = new ApplicationWindow();
//	mainFrame->Show();

	auto* User = new UACcDefault();
	User->GetLoggedIn();

	delete User;

//	auto* mainFrame = new ManualQuery(nullptr);
//	mainFrame->Show();
//	this->Exit();

//	wxMessageBox("Successful compile!", "Manager", wxOK);
//	mainFrame->Destroy();

	return true;
}

wxIMPLEMENT_APP(MyApp);

