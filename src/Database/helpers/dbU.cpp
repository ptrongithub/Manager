//
// Created by jvines on 6/29/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "dbU.h"

std::string dbU::Connection() {
	std::string connection = "mysql://";
	(connection +=  "host="  ) += mPrefs::GetPref("database.mysql.host");
	(connection += " port="  ) += mPrefs::GetPref("database.mysql.port");
	(connection += " user="  ) += mPrefs::GetPref("database.mysql.user");
	(connection += " pass="  ) += mPrefs::GetPref("database.mysql.pass");
	(connection += " dbname=") += mPrefs::GetPref("database.mysql.data");
	return connection;
}
