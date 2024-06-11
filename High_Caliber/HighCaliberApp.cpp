#include <stdlib.h>
#include <iostream>
//Compile: g++ -o HighCaliberApp HighCaliberApp.cpp -lmysqlcppconn
//Run: ./HighCaliberApp

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

 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 sql::PreparedStatement  *prep_stmt;


void findall();
void findbyid();
void insertDriver();
void findallcar();
void insertCar();
void findbyD();
void ShowR();
void UpdateR();
void RemoveC();
void minAge();


int main(void)
{

try {

   
 /* Create a connection */
 driver = get_driver_instance();

  
con = driver->connect("tcp://127.0.0.1:3306", "root", "");

/* Connect to the MySQL HighCaliber database */
    
 con->setSchema("HighCaliber"); //Equivelent to use command
 //stmt = con->createStatement();
    
 int option = 10;
 
 while (option != 0) {
     
     cout << endl;
    cout << "Select an option:" << endl;
    cout << "1. Add a Driver" << endl;
    cout << "2. Add Car Description" << endl;
    cout << "3. Find a Driver by id" << endl;
    cout << "4. Find a Driver by CarDescription" << endl;
    cout << "5. Retrieve data from Driver table" << endl;
    cout << "6. Retrieve data from CarDescription table" << endl;
    cout << "7. Retrieve data from Record" << endl;
    cout << "8. Update Race Record" << endl;
    cout << "9. Find how many drivers are above the minimum age" << endl;
    cout << "10. Remove Car by Description" << endl;
    cout << "0. Exit" << endl;
     
     cout << "Choice : ";
     cin >> option;
     
     switch(option) {

         case 1:insertDriver();
                break;
        
         case 2: insertCar();
                break;

         case 3: findbyid();
                 break;
            
         case 4: findbyD();
                 break;
             
         case 5: findall();
                 break;

         case 6: findallcar();
                 break;
             
         case 7: ShowR();
                 break;

         case 8: UpdateR();
                break;

         case 9: minAge();
                break;

         case 10: RemoveC();
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
 res = stmt->executeQuery("SELECT * from Driver");
    
  cout << endl;

 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << res->getString("DriverID") << " ";
     cout << res->getString("fName") << " ";
     cout << res->getString("lName") << " ";
     cout << res->getString("Age") << " ";
     cout << res->getString("States") << endl;
 
 }

 }


 void ShowR()
 {
   stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from Record");
    
 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << endl;
     cout << res->getString("Wins") << " ";
     cout << res->getString("Losses") << " ";
     cout << res->getString("BestTime") << " ";
     cout << res->getString("TopSpeed") << " ";
     cout << res->getString("DriverID") << endl;
     
 }
 }

void findbyid() {
     
 
 int DriverID;
    
 cout << "Enter the Driver ID : ";
 cin >> DriverID;
    
 
prep_stmt = con->prepareStatement("SELECT * FROM Driver WHERE DriverID = ?");
prep_stmt->setInt(1, DriverID);
res = prep_stmt->executeQuery();

  cout << endl;

 while (res->next()) {

 /* Access column data by alias or column name */
     
     cout << res->getString("DriverID") << " ";
     cout << res->getString("lName") << " ";
     cout << res->getString("fName") << " ";
     cout << res->getString("Age") << " ";
     cout << res->getString("States") << endl;
 
 }
     
 }

void insertDriver()
{
    string fName, lName,States;
    int DriverID, Age, VIN;
    bool b;
        
    cout << "Firstname : ";
    cin >> fName;
    
    cout << "Lastname : ";
    cin >> lName;
    
    cout << "Age : ";
    cin >> Age;
    
    cout << "State : ";
    cin >> States;

    prep_stmt = con->prepareStatement("INSERT INTO Driver (fName, lName, Age, States) " \
                                   "VALUES(?,?,?,?) ");
                                                                    
                                   
    prep_stmt->setString(1, fName);
    prep_stmt->setString(2, lName);
    prep_stmt->setInt(3, Age);
    prep_stmt->setString(4, States);


    prep_stmt->execute();

    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT LAST_INSERT_ID() as id");
    res->next();
    DriverID = res->getInt("id");
    cout << "last id " << DriverID << endl;
                                    
    prep_stmt = con->prepareStatement("INSERT INTO CarDescription (DriverID, VIN) " \
                                    "VALUES(?,?)");
    prep_stmt->setInt(1, DriverID);
    prep_stmt->setInt(2, VIN); 

    prep_stmt->execute();

}

void insertCar()
{
  string MakeModel, CarColor,TrimColor;
  int CarYear, Age, VIN, DriverID;
  bool b;

  cout << "Make & Model : ";
  cin.ignore();
  getline(cin,MakeModel);
  
  cout << "Car Year : ";
  cin >> CarYear;
  
  cout << "Car Color : ";
  cin >> CarColor;
  
  cout << "Trim Color : ";
  cin >> TrimColor;

  cout << "Driver ID : ";
  cin >> DriverID;

  cout << "VIN : ";
  cin >> VIN; 
 

  prep_stmt = con->prepareStatement("INSERT INTO CarDescription (VIN, MakeModel, CarYear, CarColor, TrimColor, DriverID) " \
                                   "VALUES(?,?,?,?,?,?) ");
                                                                    

  prep_stmt->setInt(1, VIN);
  prep_stmt->setString(2, MakeModel);
  prep_stmt->setInt(3, CarYear);
  prep_stmt->setString(4, CarColor);
  prep_stmt->setString(5, TrimColor);
  prep_stmt->setInt(6, DriverID);


  prep_stmt->execute();


  stmt = con->createStatement();

}

void UpdateR()
{
  int DriverID, Wins, Losses;

        /* Get user input */
        cout << "Enter Driver ID: ";
        cin >> DriverID;

        cout << "Enter New Wins: ";
        cin >> Wins;

        cout << "Enter New Losses: ";
        cin >> Losses;

  /* Prepare statement */
        prep_stmt = con->prepareStatement("UPDATE Record SET Wins = ?, Losses = ? WHERE DriverID = ?");
        prep_stmt->setInt(1, Wins);
        prep_stmt->setInt(2, Losses);
        prep_stmt->setInt(3, DriverID);

        /* Execute query */
        int updateCount = prep_stmt->executeUpdate();

        if (updateCount > 0) {
            cout << "Driver record updated successfully." << endl;
        } else {
            cout << "Failed to update driver record." << endl;
        }

}

void RemoveC()
{
  int CarYear;
        string CarColor;

        /* Get user input */
        cout << "Enter the Car Year : ";
        cin >> CarYear;

        cout << "Enter Car Color : ";
        cin >> CarColor;

  prep_stmt = con->prepareStatement("DELETE FROM CarDescription WHERE CarYear = ? AND CarColor = ?");
        prep_stmt->setInt(1, CarYear);
        prep_stmt->setString(2, CarColor);

        /* Execute query */
        int rows_deleted = prep_stmt->executeUpdate();

        if (rows_deleted > 0) {
            cout << rows_deleted << " car(s) removed from the database." << endl;
        } else {
            cout << "No cars found with the given year and color." << endl;
        }

}

void findbyD()
{
  int CarYear;
  string CarColor;

  /* Get user input */
        cout << "Enter the Car Year : ";
        cin >> CarYear;

        cout << "Enter Car Color : ";
        cin >> CarColor;

        /* Prepare statement */
        prep_stmt = con->prepareStatement("SELECT CarDescription.VIN, CarDescription.MakeModel, CarDescription.CarYear, CarDescription.CarColor, CarDescription.TrimColor, Driver.fName, Driver.lName FROM CarDescription JOIN Driver ON CarDescription.DriverID = Driver.DriverID WHERE CarDescription.CarYear = ? AND CarDescription.CarColor = ?");
        prep_stmt->setInt(1, CarYear);
        prep_stmt->setString(2, CarColor);

        /* Execute query */
        res = prep_stmt->executeQuery();

        if (res->next()) {
            /* Access column data by alias or column name */
            cout << res->getString("VIN") << " ";
            cout << res->getString("MakeModel") << " ";
            cout << res->getString("CarYear") << " ";
            cout << res->getString("CarColor") << " ";
            cout << res->getString("TrimColor") << " ";
            cout << res->getString("fName") << " ";
            cout << res->getString("lName") << endl;
        } else {
            cout << "No results found." << endl;
        }

}


void findallcar()
{
  stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * from CarDescription");
    
    cout << endl; 

 while (res->next()) {
 
 /* Access column data by alias or column name */
     
     cout << res->getString("VIN") << " ";
     cout << res->getString("MakeModel") << " ";
     cout << res->getString("CarYear") << " ";
     cout << res->getString("CarColor") << " ";
     cout << res->getString("TrimColor") << " ";
     cout << res->getString("DriverID") << endl;        // 
 }

 
  
}

void minAge()
{
    int oldAge;

    cout << endl;
    cout << "Enter minimum age: ";
    cin >> oldAge;
    cout << endl;

    prep_stmt = con->prepareStatement("SELECT count(Age) from Driver where Age >= ?");
    prep_stmt->setInt(1, oldAge);

 res = prep_stmt->executeQuery();

 while (res->next()) {
 /* Access column data by alias or column name */
     cout << res->getInt("count(Age)") << " ";       // 
 }

 cout << "driver(s) are the minimum age or older." << endl;
}