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

const wxString& UACcDefault::GetUsername() const {
	return mUsers->GetUsername();
}

void UACcDefault::SetUsername(const wxString& username) {
	mUsers->SetUsername(username);
}

const wxString& UACcDefault::GetPassword() const {
	return mUsers->GetPassword();
}

void UACcDefault::SetPassword(const wxString& password) {
	mUsers->SetPassword(password);
}

int UACcDefault::GetContactid() const {
	return mUsers->GetContactid();
}

void UACcDefault::SetContactid(int contactid) {
	mUsers->SetContactid(contactid);
}

bool UACcDefault::GetLoggedIn() {
//	auto* viewLogin = new vLogin(nullptr);

	wxString user, pass;
	wxString message = "";
	bool success = false;

	for (int i = iMaxLogin; i > 0 || success; --i) {

		viewLogin->ShowModal();
		user = viewLogin->GetUser();
		mUsers->GetUser(user);

		if (mUsers->GetIndUsername() != soci::i_ok) {
			message << "User not found. You have " << (i) << " attempts left.";
		} else if (mUsers->GetIndUsername() == soci::i_ok) {
			if (viewLogin->GetPass() != mUsers->GetPassword()) {
				message << "Invalid password. You have " << (i) << " attempts left.";
			} else if (viewLogin->GetPass() == mUsers->GetPassword()) {
				success = true;
			}
		}
	}
	return success;
}
