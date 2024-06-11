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

// This program adds a record to the musician table and 
// a record to the instrumentsplayed table with the musicians id
// as a foreign key. Both tables use the auto increment feature to generate
// the primary key. 

// Compile:
// g++ -I/usr/include musicinsert.cpp -o musicinsert -I /usr/local/lib -lmysqlcppconn
//
// Execute:
// ./musicinsert
// 

int main(void)
{
 
try {
 
    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;
    
 string firstname, lastname,instrument;
 int bornyear, musicianid;
 bool b;
    
 cout << "Firstname : ";
 cin >> firstname;
 
 cout << "Lastname : ";
 cin >> lastname;
 
 cout << "Instrument : ";
 cin >> instrument;
 
 cout << "Year of birth : ";
 cin >> bornyear;
 
 /* Create a connection */
 driver = get_driver_instance();
 
con = driver->connect("tcp://127.0.0.1:3306", "root", "");


/* Connect to the MySQL music database */
 con->setSchema("music");
 
prep_stmt = con->prepareStatement("INSERT INTO musicians (firstname, lastname, born) " \
                                   "VALUES(?,?,?) ");
                                                                    
                                   
prep_stmt->setString(1, firstname);
prep_stmt->setString(2, lastname);
prep_stmt->setInt(3, bornyear);

prep_stmt->execute();

stmt = con->createStatement();

res = stmt->executeQuery("SELECT LAST_INSERT_ID() as id");
res->next();
musicianid = res->getInt("id");
cout << "last id " << musicianid << endl;
                                   
prep_stmt = con->prepareStatement("INSERT INTO instrumentsplayed (musician, instrument) " \
                                   "VALUES(?,?)");
prep_stmt->setInt(1, musicianid);
prep_stmt->setString(2, instrument); 

prep_stmt->execute();
    
 

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