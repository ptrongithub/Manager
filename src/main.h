//
// Created by jvines on 6/7/2020.
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#ifndef MANAGER_MAIN_H
#define MANAGER_MAIN_H

// Source #includes
#include "includes.h"
//#include "Database/helpers/dbU.h"
#include "src/UAC/controllers/UACcDefault.h"
#include "Tools/views/ManualQuery.h"
//#include "UAC/models/mUACUsers.h"

#define APP wxGetApp()
//#define APP ((MyApp*)wxTheApp)

namespace pt = boost::property_tree;
//using namespace json;

class MyApp : public wxApp {
public:
	virtual bool OnInit();
	pt::ptree Preferences;
	bool LoadOptions();
	bool SaveOptions();
	bool ReadOptions();
	std::string Connection;

};

wxDECLARE_APP(MyApp);

#endif //MANAGER_MAIN_H
