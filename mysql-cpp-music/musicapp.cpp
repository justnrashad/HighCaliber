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

// This program retrieves all of the musicians

// Compile:
// g++ -I/usr/include musicapp.cpp -o musicapp -I /usr/local/lib -lmysqlcppconn
// 
// Execute:
// ./musicapp
// 
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;

void findall();
void findbyid();

int main(void)
{

try {

   
 /* Create a connection */
 driver = get_driver_instance();

  
con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL music database */
    
 con->setSchema("music");
 //stmt = con->createStatement();
    
 int option = 6;
 
 while (option != 5) {
     
     cout << endl;
     cout << "1. Add a musician" << endl;
     cout << "2. Find a musician by id" << endl;
     cout << "3. Find a musician by instrument" << endl;
     cout << "4. Show all musicians" << endl;
     cout << "5. Exit" << endl << endl;
     
     cout << "Choice : ";
     cin >> option;
     
     switch(option) {
        
         case 2: findbyid();
                 break;
             
         case 4: findall();
                 break;
             
             
     }
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

 void findall() {
     
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from musicians");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << res->getString("id") << " ";
     cout << res->getString("firstname") << " ";
     cout << res->getString("lastname") << " ";
     cout << res->getString("born") << endl;
 
 }
     
 }

void findbyid() {
     
 
 int id;
    
 cout << "Enter the musician ID : ";
 cin >> id;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM musicians WHERE ID = ?");
prep_stmt->setInt(1, id);
res = prep_stmt->executeQuery();


 while (res->next()) {

 /* Access column data by alias or column name */
     
     cout << res->getString("id") << " ";
     cout << res->getString("firstname") << " ";
     cout << res->getString("lastname") << " ";
     cout << res->getString("born") << endl;
 
 }
     
 }