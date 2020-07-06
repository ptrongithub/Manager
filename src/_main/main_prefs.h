//
// Created by jvines on 6/7/2020.
//

#ifndef MANAGER_MAIN_H
#define MANAGER_MAIN_H

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
#include <wx/valgen.h>

// Boost #includes
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// Database #includes
#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>


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

};

wxDECLARE_APP(MyApp);

#endif //MANAGER_MAIN_H
