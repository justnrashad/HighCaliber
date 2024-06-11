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

// This program retrieves all of the musicians

// Compile:
// g++ -I/usr/include musicretrieveall.cpp -o musicretrieveall -I /usr/local/lib -lmysqlcppconn
// 
// Execute:
// ./musicretrieveall
// 

int main(void)
{
cout << endl;
cout << "SELECT * from musicians" << endl;
try {

    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 /* Create a connection */
 driver = get_driver_instance();

    

con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL music database */
    
 con->setSchema("music");
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from musicians");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << res->getString("id") << " ";
     cout << res->getString("firstname") << " ";
     cout << res->getString("lastname") << " ";
     cout << res->getString("born") << endl;
 
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