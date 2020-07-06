//
// Created by jvines on 6/27/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "ManualQuery.h"

wxBEGIN_EVENT_TABLE(ManualQuery, wxFrame)
				EVT_BUTTON(ManualQuery::ID_Btn_Execute, ManualQuery::OnExecute)
				EVT_BUTTON(ManualQuery::ID_Btn_Close, ManualQuery::OnClose)
				EVT_CHECKBOX(ManualQuery::ID_Cb_WordWrap, ManualQuery::OnWordWrap)
wxEND_EVENT_TABLE()

ManualQuery::ManualQuery() {
	Create(this);
}

ManualQuery::ManualQuery(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size,
                         long style)
                         : wxFrame(parent, id, title, pos, size, style) {
	Create(parent, id, title, pos, size, style);
}

ManualQuery::~ManualQuery() {
	;
}

void ManualQuery::Init() {
	wxFrame::Init();
}

bool ManualQuery::Create(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
		const wxSize& size, long style) {

	std::string defaultQuery = "SELECT * FROM contact_name LIMIT 10;";

	this->SetMinSize(wxSize(512,384));

	auto* stQuery  = new wxStaticText(this, wxID_ANY, "Enter Query",  wxDefaultPosition, wxDefaultSize, 0);
	auto* stResult = new wxStaticText(this, wxID_ANY, "Query Result", wxDefaultPosition, wxDefaultSize, 0);

	tcQuery  = new wxTextCtrl(this, ID_Tc_Query,  defaultQuery, wxDefaultPosition, wxDefaultSize,
			wxTE_MULTILINE | wxTE_PROCESS_ENTER | wxTE_PROCESS_TAB | wxTE_DONTWRAP);
	tcQuery->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	tcQuery->SetMinSize(wxSize(-1,64));
	tcResult = new wxTextCtrl(this, ID_Tc_Result, wxEmptyString, wxDefaultPosition, wxDefaultSize,
			wxTE_MULTILINE | wxTE_READONLY | wxTE_DONTWRAP);
	tcResult->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	tcResult->SetMinSize(wxSize(-1,128));

	btnExecute = new wxButton(  this, ID_Btn_Execute, "Execute",   wxDefaultPosition, wxDefaultSize, 0);
	btnClose   = new wxButton(  this, ID_Btn_Close,   "Close",     wxDefaultPosition, wxDefaultSize, 0);
	cbWordWrap = new wxCheckBox(this, ID_Cb_WordWrap, "Word Wrap", wxDefaultPosition, wxDefaultSize, 0);
	cbWordWrap->Disable();

	auto* bsButtons = new wxBoxSizer(wxVERTICAL);
	auto* bsQuery =   new wxBoxSizer(wxHORIZONTAL);
	auto* bsRoot =    new wxBoxSizer(wxVERTICAL);

	bsButtons->Add(btnExecute, 0, wxALL, 5);
	bsButtons->Add(btnClose,   0, wxALL, 5);
	bsButtons->Add(cbWordWrap, 0, wxALL, 5);


	bsQuery->Add(stQuery, 0, wxALL, 5);
	bsQuery->Add(tcQuery, 1, wxALL|wxEXPAND, 5);
	bsQuery->Add(bsButtons, 0, wxALL, 5);

	bsRoot->Add(bsQuery, 4, wxALL|wxEXPAND, 5);
	bsRoot->Add(stResult, 0, wxALL, 5);
	bsRoot->Add(tcResult, 8, wxALL|wxEXPAND, 5);

	this->SetSizer(bsRoot);
	this->Layout();
	this->Center(wxBOTH);

	return true;
}

void ManualQuery::OnExecute(wxCommandEvent &event) {

	try {
		soci::session sql(dbU::Connection());
		std::string version, date;
		soci::row result;
		sql << "SELECT VERSION(), SYSDATE() FROM DUAL", soci::into(version), soci::into(date);
		std::ostream osResult(tcResult);
		osResult << "MySQL version " << version << std::endl << "System Date " << date << std::endl;

		soci::statement query = (sql.prepare << tcQuery->GetValue(), soci::into(result));
		query.execute();
		for (std::size_t i = 0; i != result.size(); ++i) {
			const soci::column_properties &cProperties = result.get_properties(i);
			osResult << cProperties.get_name();
			if (i+1 != result.size()) osResult << " | ";
		}
		osResult << " \266" << std::endl;
		while (query.fetch()) {

			for (std::size_t i = 0; i != result.size(); ++i) {
				const soci::column_properties& cProperties = result.get_properties(i);
				switch (cProperties.get_data_type()) {
					case soci::dt_string:
						osResult << result.get<std::string>(i);
						break;
					case soci::dt_double:
						osResult << result.get<double>(i);
						break;
					case soci::dt_integer:
						osResult << result.get<int>(i);
						break;
					case soci::dt_long_long:
						osResult << result.get<long long>(i);
						break;
					case soci::dt_unsigned_long_long:
						osResult << result.get<unsigned long long>(i);
						break;
					case soci::dt_date:
						auto dt = result.get<std::tm>(i);
						std::string format = "Y/b/d H:M:S";
						char time[100];
						std::strftime(time, sizeof(time), "Y/b/d H:M:S", &dt);
						osResult << time;
						break;
//					default:
//						break;
				} // end switch
				if (i+1 != result.size()) osResult << " | ";

			} // end for
			osResult << " \266" << std::endl;
		} // end while
		osResult.flush();

	} catch (const std::exception &err) {
		wxMessageBox(err.what(), "Exception Error!", wxOK);
//		exit(1);
	} // end try/catch
}

void ManualQuery::OnClose(wxCommandEvent &event) {
	Close(true);
}

void ManualQuery::OnWordWrap(wxCommandEvent &event) {
	 tcQuery->ToggleWindowStyle(wxTE_DONTWRAP);
	tcResult->ToggleWindowStyle(wxTE_DONTWRAP);
	 tcQuery->Update();
	tcResult->Update();

	event.Skip();
}
