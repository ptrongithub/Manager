//
// Created by jvines on 6/7/2020.
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#ifndef MANAGER_MAIN_H
#define MANAGER_MAIN_H

#include "includes.h"
#include "views.inc.h"
#include "ptree.inc.h"

#include "src/UAC/controllers/UACcDefault.h"
//#include "Tools/views/ManualQuery.h"

class MyApp : public wxApp {
public:
	virtual bool OnInit();

};

wxDECLARE_APP(MyApp);

#endif //MANAGER_MAIN_H
