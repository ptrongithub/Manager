//
// Created by jvines on 6/28/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "UACvLogin.h"

wxBEGIN_EVENT_TABLE(UACvLogin, wxDialog)
//				EVT_EVENT(CLASS::ID_Control, Class::OnEvent)
wxEND_EVENT_TABLE()

UACvLogin::UACvLogin() {
	Init();
	Create(this);

}

UACvLogin::UACvLogin(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                     const wxSize &size, long style)
		: wxDialog(parent, id, title, pos, size, style) {
	Init();
	Create(parent, id, title, pos, size, style);
}

//Login::Login(Login login) {
//	;
//}

UACvLogin::~UACvLogin() {
	;
}

bool UACvLogin::Create(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                       const wxSize &size, long style) {
	CreateControls();
	return true;
}

void UACvLogin::Init() {
	wxDialog::Init();
	sUser = "";
	sPass = "";
}

void UACvLogin::CreateControls() {
	auto* stUser = new wxStaticText(this, wxID_ANY, "User Name", wxDefaultPosition, wxDefaultSize, 0);
	auto* stPass = new wxStaticText(this, wxID_ANY, "Password", wxDefaultPosition, wxDefaultSize, 0);
	tcUser = new wxTextCtrl(this, ID_Tc_User, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	tcUser->SetValidator(wxGenericValidator(&sUser));
	tcPass = new wxTextCtrl(this, ID_Tc_Pass, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
	tcPass->SetValidator(wxGenericValidator(&sPass));
	btnOk = new wxButton(this, wxID_OK, "OK", wxDefaultPosition, wxDefaultSize, 0);
	btnCancel = new wxButton(this, wxID_CANCEL, "Cancel", wxDefaultPosition, wxDefaultSize, 0);

	auto* fgsForm = new wxFlexGridSizer(2, wxSize(0,0));
	fgsForm->SetFlexibleDirection(wxHORIZONTAL);
	fgsForm->AddGrowableCol(1);
	fgsForm->Add(stUser, 1, wxALL, 5);
	fgsForm->Add(tcUser, 2, wxALL|wxEXPAND, 5);
	fgsForm->Add(stPass, 1, wxALL, 5);
	fgsForm->Add(tcPass, 2, wxALL|wxEXPAND, 5);

	auto* sdbsButtons = new wxStdDialogButtonSizer();
	sdbsButtons->AddButton(btnOk);
	sdbsButtons->AddButton(btnCancel);
	sdbsButtons->Realize();

	auto* bsRoot = new wxBoxSizer(wxVERTICAL);
	bsRoot->Add(fgsForm, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 15);
	bsRoot->Add(sdbsButtons, 0, wxRIGHT|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 15);

	this->SetSizer(bsRoot);
	this->Layout();
	this->Fit();
	this->Center(wxBOTH);
}

const wxString& UACvLogin::GetUser() const {
	return sUser;
}

const wxString& UACvLogin::GetPass() const {
	return sPass;
}

void UACvLogin::SetUser(const wxString& sUser) {
	UACvLogin::sUser = sUser;
}

void UACvLogin::SetPass(const wxString& sPass) {
	UACvLogin::sPass = sPass;
}
