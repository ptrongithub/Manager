//
// Created by jvines on 6/30/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "UACmUsers.h"
UACmUsers::UACmUsers() {
	iDuserid = 0;
	sDusername = "default";
	sDpassword = "";
	iDcontactid = 0;
}

UACmUsers::UACmUsers(int userid, const wxString& username, const wxString& password, int contactid)
		: iDuserid(userid), sDusername(username), sDpassword(password), iDcontactid(contactid) {
	;
}

UACmUsers::~UACmUsers() {

}

int UACmUsers::GetUserid() const {
	return iDuserid;
}

void UACmUsers::SetUserid(int userid) {
	UACmUsers::iDuserid = userid;
}

const wxString& UACmUsers::GetUsername() const {
	return sDusername;
}

void UACmUsers::SetUsername(const wxString& username) {
	UACmUsers::sDusername = username;
}

const wxString& UACmUsers::GetPassword() const {
	return sDpassword;
}

void UACmUsers::SetPassword(const wxString& password) {
	UACmUsers::sDpassword = password;
}

int UACmUsers::GetContactid() const {
	return iDcontactid;
}

void UACmUsers::SetContactid(int contactid) {
	UACmUsers::iDcontactid = contactid;
}

bool UACmUsers::GetUser(int userid) {
	try {
		soci::session sql(dbU::Connection());
		sql << "SELECT userid, username, password FROM uac_users WHERE userid = " << userid,
				soci::into(iDuserid, indUserid),
				soci::into(sDusername, indUsername),
				soci::into(sDpassword, indPassword);
	} catch (const std::exception& err) {
		wxMessageBox(err.what(), "Exception Error!", wxOK | wxICON_ERROR);
		return false;
	};
	return true;
}

bool UACmUsers::GetUser(const wxString& username) {
	try {
		soci::session sql(dbU::Connection());
		sql << "SELECT userid, username, password FROM uac_users WHERE username = \"" << username << "\"",
				soci::into(iDuserid,   indUserid),
				soci::into(sDusername, indUsername),
				soci::into(sDpassword, indPassword);
	} catch (const std::exception& err) {
		wxMessageBox(err.what(), "Exception Error!", wxOK | wxICON_ERROR);
		return false;
	};
	return true;
}

soci::indicator UACmUsers::GetIndUserid() const {
	return indUserid;
}

soci::indicator UACmUsers::GetIndUsername() const {
	return indUsername;
}

soci::indicator UACmUsers::GetIndPassword() const {
	return indPassword;
}
