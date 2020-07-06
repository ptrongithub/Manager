//
// Created by jvines on 6/29/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#include "dbU.h"

std::string dbU::Connection() {
	std::string connection = "mysql://";
	(connection +=  "host="  ) += APP.Preferences.get("database.mysql.host", "").data();
	(connection += " port="  ) += APP.Preferences.get("database.mysql.port", "").data();
	(connection += " user="  ) += APP.Preferences.get("database.mysql.user", "").data();
	(connection += " pass="  ) += APP.Preferences.get("database.mysql.pass", "").data();
	(connection += " dbname=") += APP.Preferences.get("database.mysql.data", "").data();
	return connection;
}
