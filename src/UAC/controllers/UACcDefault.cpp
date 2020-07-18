//
// Created by jvines on 6/30/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "UACcDefault.h"

UACcDefault::UACcDefault() {
	viewLogin = new UACvLogin(nullptr);
	mUsers = new UACmUsers;
//	viewLogin.Create(nullptr);

	iMaxLogin = stoi(mPrefs::GetPref("uac.maxlogin"));
	viewLogin->SetUser(mPrefs::GetPref("uac.default_user"));
	viewLogin->SetPass(mPrefs::GetPref("uac.default_pass"));
}

//UACcDefault::UACcDefault(int iMaxLogin, UACmUsers* mUsers, UACvLogin* viewLogin)
//		: iMaxLogin(iMaxLogin), mUsers(mUsers), viewLogin(viewLogin) {
//	;
//}

UACcDefault::~UACcDefault() {
	delete mUsers;
}

int UACcDefault::GetUserid() const {
	return mUsers->GetUserid();
}

void UACcDefault::SetUserid(int userid) {
	mUsers->SetUserid(userid);
}

wxString UACcDefault::GetUsername() const {
	return mUsers->GetUsername();
}

void UACcDefault::SetUsername(const wxString& username) {
	mUsers->SetUsername(username);
}

void UACcDefault::SetUsername(const std::string& username) {
	mUsers->SetUsername(username);
}

wxString UACcDefault::GetPassword() const {
	return mUsers->GetPassword();
}

void UACcDefault::SetPassword(const wxString& password) {
	mUsers->SetPassword(password);
}

void UACcDefault::SetPassword(const std::string& password) {
	mUsers->SetPassword(password);
}

int UACcDefault::GetContactid() const {
	return mUsers->GetContactid();
}

void UACcDefault::SetContactid(int contactid) {
	mUsers->SetContactid(contactid);
}

bool UACcDefault::GetLoggedIn() {
// TODO: Encrypt communication with server.

	wxString user, pass;
	wxString message = "";
	bool success = false;

	for (int i = iMaxLogin; i > 0 || success; --i) {

		viewLogin->SetMessage(message);
		if (viewLogin->ShowModal() == wxID_CANCEL) break;

		user = viewLogin->GetUser();
		mUsers->GetUser(user);

		if (mUsers->GetIndUsername() != soci::i_ok) {
			message << "User not found. You have " << (i - 1) << " attempts left.";
		} else if (mUsers->GetIndUsername() == soci::i_ok) {
			if (viewLogin->GetPass() != mUsers->GetPassword()) {
				message << "Invalid password. You have " << (i - 1) << " attempts left.";
			} else if (viewLogin->GetPass() == mUsers->GetPassword()) {
				success = true;
				break;
			}
		}
	}
	return success;
}


