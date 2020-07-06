//
// Created by jvines on 6/29/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//


#ifndef MANAGER_INCLUDES_H
#define MANAGER_INCLUDES_H

// STL #includes
#include <string>
#include <iostream>
#include <fstream>

// wxWidgets #includes
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/app.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>

// Boost #includes
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

//// Database #includes
//#include <soci/soci.h>
//#include <soci/mysql/soci-mysql.h>

// src #includes
#include "src/main.h"
#include "src/Database/helpers/dbU.h"
//#include "src/UAC/controllers/cUAC.h"

// Global #define MACROS
//#define APP wxGetApp()

#endif //MANAGER_INCLUDES_H
