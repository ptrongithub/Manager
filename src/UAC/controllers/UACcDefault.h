//
// Created by jvines on 6/30/2020.
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#ifndef MANAGER_UACCDEFAULT_H
#define MANAGER_UACCDEFAULT_H

#include "src/includes.h"
#include "src/db.inc.h"
#include "../views/UACvLogin.h"
#include "../models/UACmUsers.h"

class UACcDefault {
public:
	UACcDefault();
//	UACcDefault(int iMaxLogin, UACmUsers* mUsers = nullptr, UACvLogin* viewLogin = nullptr);
	virtual ~UACcDefault();

	int GetUserid() const;
	void SetUserid(int userid);
	wxString GetUsername() const;
	void SetUsername(const wxString& username);
	void SetUsername(const std::string& username);
	wxString GetPassword() const;
	void SetPassword(const wxString& password);
	void SetPassword(const std::string& password);
	int GetContactid() const;
	void SetContactid(int contactid);

	bool GetLoggedIn();

protected:

private:
	UACmUsers* mUsers;
	UACvLogin* viewLogin;
	int iMaxLogin;

};

#endif //MANAGER_UACCDEFAULT_H
