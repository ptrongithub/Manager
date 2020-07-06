//
// Created by jvines on 6/3/2020.
//

#include "ConfigDatabaseConn.h"

wxBEGIN_EVENT_TABLE(DatabaseConn, wxPanel)
	EVT_BUTTON(DatabaseConn::ID_BTN_Test, DatabaseConn::OnTestButton)
	EVT_TEXT(DatabaseConn::ID_TC_Host, DatabaseConn::OnTextChange)
	EVT_TEXT(DatabaseConn::ID_TC_Port, DatabaseConn::OnTextChange)
	EVT_TEXT(DatabaseConn::ID_TC_User, DatabaseConn::OnTextChange)
	EVT_TEXT(DatabaseConn::ID_TC_Pass, DatabaseConn::OnTextChange)
	EVT_TEXT(DatabaseConn::ID_TC_Data, DatabaseConn::OnTextChange)
wxEND_EVENT_TABLE()

/*
		ID_Field_Host,
		ID_Field_Port,
		ID_Field_User,
		ID_Field_Pass,
		ID_Field_Data
*/

// TODO: Add Show/Hide Password Control

//IMPLEMENT_DYNAMIC_CLASS(DatabaseConn, wxPanel)

DatabaseConn::DatabaseConn() {
	;
}

DatabaseConn::DatabaseConn(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style,
                           const wxString &name) : wxPanel(parent, id, pos, size, style, name) {
	Create(parent, id, pos, size, style, name);
}

DatabaseConn::~DatabaseConn() {
	;
}

bool DatabaseConn::Create(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style,
                           const wxString &name) {
//	if (!wxPanel::Create(parent, id, pos, size, style, name)) return false;

	// Create Field Labels
	auto* stHost = new wxStaticText(this, wxID_ANY, "Host", wxDefaultPosition, wxDefaultSize, 0);
	auto* stPort = new wxStaticText(this, wxID_ANY, "Port", wxDefaultPosition, wxDefaultSize, 0);
	auto* stUser = new wxStaticText(this, wxID_ANY, "User", wxDefaultPosition, wxDefaultSize, 0);
	auto* stPass = new wxStaticText(this, wxID_ANY, "Password", wxDefaultPosition, wxDefaultSize, 0);
	auto* stData = new wxStaticText(this, wxID_ANY, "Database", wxDefaultPosition, wxDefaultSize, 0);

	// Create Field Controls
	tcHost = new wxTextCtrl(this, ID_TC_Host, host);
	tcHost->SetValidator(wxGenericValidator(&host));
	tcHost->SetMaxLength(255);
	tcPort = new wxTextCtrl(this, ID_TC_Port, port);
	tcPort->SetValidator(wxTextValidator(wxFILTER_DIGITS, &port));
	tcPort->SetMaxLength(5);
	tcUser = new wxTextCtrl(this, ID_TC_User, user);
	tcUser->SetValidator(wxGenericValidator(&user));
	tcUser->SetMaxLength(255);
	tcPass = new wxTextCtrl(this, ID_TC_Pass, pass, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
//	tcPass->SetWindowStyle(wxTE_PASSWORD);
//	tcPass->Refresh();
	tcUser->SetValidator(wxGenericValidator(&pass));
	tcPass->SetMaxLength(255);
	tcData = new wxTextCtrl(this, ID_TC_Data, data);
	tcData->SetValidator(wxGenericValidator(&data));
	tcData->SetMaxLength(255);

	// Create connection test Button and Static Text to show test result
	bTest = new wxButton(this, ID_BTN_Test, "Test Connection");
	bTest->Enable(false);
	stResult = new wxStaticText(this, ID_ST_Result, "");
	stResult->Wrap(-1);
//	stResult->Hide();

	// Create Flex Grid Sizer to hold labels and their fields
	auto* fgSizer = new wxFlexGridSizer(2, wxSize(0, 0));
	fgSizer->SetFlexibleDirection(wxBOTH);
	fgSizer->AddGrowableCol(1);

	// Add labels and fields to Flex Grid Sizer
	fgSizer->Add(stHost, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(tcHost, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);
	fgSizer->Add(stPort, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(tcPort, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(stUser, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(tcUser, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);
	fgSizer->Add(stPass, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(tcPass, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);
	fgSizer->Add(stData, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->Add(tcData, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

	// Add test controls, with spacers, to Flex Grid Sizer
	fgSizer->AddSpacer(-1);
	fgSizer->Add(bTest, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	fgSizer->AddSpacer(-1);
	fgSizer->Add(stResult, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	// Add Flex Grid to Root Sizer
	auto* bSizerRoot = new wxBoxSizer(wxVERTICAL);
	bSizerRoot->Add(fgSizer, 1, wxEXPAND, 5);

	// Finalize Layout
	this->SetSizer(bSizerRoot);
	this->Layout();

	Init();

	return true;
}

void DatabaseConn::Init () {
	host = APP.Preferences.get("database.mysql.host", "").data();
	port = APP.Preferences.get("database.mysql.port", "").data();
	user = APP.Preferences.get("database.mysql.user", "").data();
	pass = APP.Preferences.get("database.mysql.pass", "").data();
	data = APP.Preferences.get("database.mysql.data", "").data();

	tcHost->ChangeValue(host);
	tcPort->ChangeValue(port);
	tcUser->ChangeValue(user);
	tcPass->ChangeValue(pass);
	tcData->ChangeValue(data);

	if (host.length() && port.length() && user.length() && pass.length() && data.length()) {
		bTest->Enable(true);
	}
}

bool DatabaseConn::SetDialog(PrefsData* PrefsDialog) {
	Dialog = PrefsDialog;
	return true;
}


void DatabaseConn::OnTextChange(wxCommandEvent &event) {
	//event.GetId();
	auto* eventObject = reinterpret_cast<wxTextCtrl*>(event.GetEventObject());
	if (eventObject->IsModified()) {
		wxString newData = eventObject->GetValue();
		Dialog->SetModified(true);

		switch (event.GetId()) {
			case ID_TC_Host:
				host = newData;
				Dialog->SetPrefs("database.mysql.host", host);
				break;
			case ID_TC_Port:
				port = newData;
				Dialog->SetPrefs("database.mysql.port", port);
				break;
			case ID_TC_User:
				user = newData;
				Dialog->SetPrefs("database.mysql.user", user);
				break;
			case ID_TC_Pass:
				pass = newData;
				Dialog->SetPrefs("database.mysql.pass", pass);
				break;
			case ID_TC_Data:
				data = newData;
				Dialog->SetPrefs("database.mysql.data", data);
				break;
			default:
				break;
		};

		if (host.length() && port.length() && user.length() && pass.length() && data.length()) {
			bTest->Enable(true);
		}
//		stResult->Hide();
		stResult->SetLabel("");

	}
}

void DatabaseConn::OnTestButton(wxCommandEvent &event) {
	// TODO: Test Connection Button: test database connection parameters.

	try {
		std::string connection = "mysql://";
		connection += "host=" + host + " ";
		connection += "port=" + port + " ";
		connection += "user=" + user + " ";
		connection += "pass=" + pass + " ";
		connection += "dbname=" + data;
		soci::session sql(connection);
		std::string version, date;
		sql << "SELECT VERSION(), SYSDATE() FROM DUAL", soci::into(version), soci::into(date);
//		wxMessageBox("MySQL version " + version +"\nSystem Date " + date, "It Works!", wxOK);
		stResult->SetLabel("MySQL version " + version +"\nSystem Date " + date);
//		stResult->Show(true);
	} 	catch (const std::exception& err) {
		wxMessageBox(err.what(), "Exception Error!", wxOK);
//		exit(1);
	}


	event.Skip();
}
