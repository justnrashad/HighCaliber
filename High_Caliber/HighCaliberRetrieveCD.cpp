#include <stdlib.h>
#include <iostream>
/*
 Include directly the different
 headers from cppconn/ and mysql_driver.h + mysql_util.h
 (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

// This program retrieves all data from the CarDescription table

// Compile:
// g++ -o HighCaliberRetrieveCD HighCaliberRetrieveCD.cpp -lmysqlcppconn

// 
// Execute:
// ./HighCaliberRetrieveCD
// 

int main(void)
{
cout << endl;
cout << "SELECT * from CarDescription" << endl;
try {

    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 /* Create a connection */
 driver = get_driver_instance();

    

con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL music database */
    
 con->setSchema("HighCaliber");
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from CarDescription");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << res->getInt("VIN") << " ";
     cout << res->getString("MakeModel") << " ";
     cout << res->getInt("CarYear") << " ";
     cout << res->getString("CarColor") << " ";
     cout << res->getString("TrimColor") << endl;
 
 }
 delete res;
 delete stmt;
 delete con;
} catch (sql::SQLException &e) {
 cout << "# ERR: SQLException in " << __FILE__;
 cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
 cout << "# ERR: " << e.what();
 cout << " (MySQL error code: " << e.getErrorCode();
 cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}
cout << endl;
return EXIT_SUCCESS;
}