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
// g++ -I/usr/include HighCaliberInsert.cpp -o HighCaliberInsert -I /usr/local/lib -lmysqlcppconn
//
// Execute:
// ./HighCaliberInsert
// 

int main(void)
{
 
try {
 
    
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;
    
 string lname, fname, State, MakeModel, CarColor, TrimColor;
 int Age, CarYear, driverid;
 bool b;
    
 cout << "Lastname : ";
 cin >> lname;


 cout << "Firstname : ";
 cin >> fname;
 
 
 cout << "State : ";
 cin >> State;
 
 cout << "Age : ";
 cin >> Age;
 
 /* Create a connection */
 driver = get_driver_instance();
 
con = driver->connect("tcp://127.0.0.1:3306", "root", "");


/* Connect to the MySQL music database */
 con->setSchema("HighCaliber");
 
prep_stmt = con->prepareStatement("INSERT INTO Driver (lname, fname, State, Age) " \
                                   "VALUES(?,?,?,?) ");
                                                                    
                                   
prep_stmt->setString(1, lname);
prep_stmt->setString(2, fname);
prep_stmt->setString(3, State);
prep_stmt->setInt(4, Age);

prep_stmt->execute();

stmt = con->createStatement();

res = stmt->executeQuery("SELECT LAST_INSERT_ID() as id");
res->next();
driverid = res->getInt("id");
cout << "last id " << driverid << endl;

cout << "Make and Model : ";
cin >> MakeModel;

cout << "Car Year : ";
cin >> CarYear;

cout << "Car Color : ";
cin >> CarColor;

cout << "Trim Color : ";
cin >> TrimColor;

prep_stmt = con->prepareStatement("INSERT INTO CarDescription (MakeModel, CarYear, CarColor, TrimColor) " \
                                   "VALUES(?,?,?,?)");
prep_stmt->setString(1, MakeModel);
prep_stmt->setInt(2, CarYear); 
prep_stmt->setString(3, CarColor); 
prep_stmt->setString(4, TrimColor); 


prep_stmt->execute();
    
 

 delete res;
 delete prep_stmt;
 delete con;
    
} catch (sql::SQLException &e) {
 cout << "# ERR: SQLException in " << __FILE__;
 cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
 cout << "# ERR: " << e.what();
 cout << " (MySQL error code: " << e.getErrorCode();
 cout << ", SQLState: " << e.getSQLState();
}

cout << endl;
return EXIT_SUCCESS;
}