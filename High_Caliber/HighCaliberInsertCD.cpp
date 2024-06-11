#include <stdlib.h>
#include <iostream>
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
    cout << endl;
    cout << "Insert a new car into CarDescription table" << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");
        con->setSchema("HighCaliber");

        string makeModel, carColor, trimColor;
        int carYear, driverID;

        cout << "Enter the make and model of the car: ";
        getline(cin, makeModel);

        cout << "Enter the year of the car: ";
        cin >> carYear;

        cout << "Enter the color of the car: ";
        cin.ignore();
        getline(cin, carColor);

        cout << "Enter the trim color of the car: ";
        getline(cin, trimColor);

        cout << "Enter the ID of the driver assigned to this car: ";
        cin >> driverID;

        // Insert the car information into CarDescription table
        stmt = con->createStatement();
        string insertQuery = "INSERT INTO CarDescription (MakeModel, CarYear, CarColor, TrimColor) "
                             "VALUES ('" + makeModel + "', " + to_string(carYear) + ", '" + carColor + "', '" + trimColor + "')";
        stmt->execute(insertQuery);

        // Get the ID of the newly inserted car
        res = stmt->executeQuery("SELECT LAST_INSERT_ID() AS ID");
        res->next();
        int carID = res->getInt("ID");

        // Update the driver's assigned car ID in Driver table
        string updateQuery = "UPDATE Driver SET CarID = " + to_string(carID) + " WHERE DriverID = " + to_string(driverID);
        stmt->execute(updateQuery);

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