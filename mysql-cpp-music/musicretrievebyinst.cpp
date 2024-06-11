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
#include <cppconn/prepared_statement.h>
using namespace std;

// This program finds a musicians who play a particular instrument. This is
// done by joining the musicians and instrumentsplayed tables
// 

// Compile:
// g++ -I/usr/include musicretrievebyinst.cpp -o musicretrievebyinst -I /usr/local/lib -lmysqlcppconn
// 
// Execute:
// ./musicretrievebyinst
// 

int main(void)
{

try {

    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;
    
 string instrument;
    
 cout << "Enter the instrument : ";
 cin >> instrument;
    
 /* Create a connection */
 driver = get_driver_instance();
    

con = driver->connect("tcp://127.0.0.1:3306", "root", "");
    
/* Connect to the MySQL test database */
 con->setSchema("music");
    

prep_stmt = con->prepareStatement("SELECT firstname, lastname, instrument " \
                                   "FROM musicians join instrumentsplayed " \
                                   "ON musicians.Id = instrumentsplayed.Musician " \
                                   "WHERE instrument = ?");
    
prep_stmt->setString(1, instrument);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
     cout << res->getString("firstname") << " ";
     cout << res->getString("lastname") << " ";
     cout << res->getString("instrument") << endl;
     

 }
 delete res;
 delete prep_stmt;
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