#pragma once
#include <string>
#include "zMisc.h"
#include "DBConnection.h"
#include "UserAccountDAO.h"
#include "StatisticDAO.h"

#define DBInstance 	DBServices::getInstance()

class DBServices: public SingletonBase<DBServices>{
public:
	void init(std::string hostname, std::string username, std::string password){
		connection = new DBConnection(hostname, username, password);
		userAccountDAO = new UserAccountDAO(connection);
	}

	~DBServices(){
		delete userAccountDAO;
		delete connection;
	}

	DBConnection newConnection() {
		return connection->clone();
	}

	UserAccountDAO* userAccountDAO;
private:
	DBConnection* connection;
};