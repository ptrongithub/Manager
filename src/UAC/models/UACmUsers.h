//
// Created by jvines on 6/30/2020.
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#ifndef MANAGER_UACMUSERS_H
#define MANAGER_UACMUSERS_H

#include "src/includes.h"
// Database #includes
#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>

class UACmUsers {
public:
	UACmUsers();
	UACmUsers(int userid, const wxString& username, const wxString& password, int contactid);
	virtual ~UACmUsers();

	int GetUserid() const;
	void SetUserid(int userid);

	const wxString& GetUsername() const;
	void SetUsername(const wxString& username);

	const wxString& GetPassword() const;
	void SetPassword(const wxString& password);

	int GetContactid() const;
	void SetContactid(int contactid);

	bool GetUser(int userid);
	bool GetUser(const wxString& username);

	soci::indicator GetIndUserid() const;
	soci::indicator GetIndUsername() const;
	soci::indicator GetIndPassword() const;

protected:

private:
	int      iDuserid;    // userid    int(11)      pk
	wxString sDusername;  // username  varchar(64)  uk idx
	wxString sDpassword;  // password  varchar(256)
	int      iDcontactid; // contactid int(11)      fk
	soci::indicator indUserid;
	soci::indicator indUsername;
	soci::indicator indPassword;

};

#endif //MANAGER_UACMUSERS_H
