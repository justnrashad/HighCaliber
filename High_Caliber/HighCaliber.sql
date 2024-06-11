-- HighCaliber DATABASE
--
drop database if exists HighCaliber;

create database HighCaliber;

use HighCaliber;


drop table if exists Driver;
drop table if exists CarDescription;
drop table if exists Record;
drop table if exists CarPerformance;


CREATE TABLE Driver(
  DriverID integer NOT NULL AUTO_INCREMENT,
  lName varchar(35),
  fName varchar(35),
  Age integer NOT NULL,
  States varchar(15) NOT NULL,
  PRIMARY KEY(DriverID)
);


CREATE TABLE CarDescription (
  VIN INT NOT NULL,
  MakeModel VARCHAR(50),
  CarYear INT NOT NULL,
  CarColor VARCHAR(35),
  TrimColor VARCHAR(35),
  DriverID INT not null, -- Adds DriverID field as foregin key
  PRIMARY KEY (VIN),
  foreign key (DriverID) REFERENCES Driver(DriverID),
  UNIQUE (VIN)
);


CREATE TABLE Record (
  SeedNum INT AUTO_INCREMENT,
  Wins INT,
  Losses INT,
  BestTime VARCHAR(100),
  TopSpeed INT,
  DriverID INT not null, -- Add DriverID field as foreign key
  PRIMARY KEY (SeedNum),
  FOREIGN KEY (DriverID) REFERENCES Driver(DriverID)
);

CREATE TABLE CarPerformance (
    VIN INT,
    Horsepower INT,
    Torque INT,
    Drivetrain VARCHAR(3),
    BoostType VARCHAR(50),
    FOREIGN KEY (VIN) REFERENCES CarDescription(VIN)
);

-- Insert data into the Driver table
insert into Driver (lName, fName, Age, States) values ('Perez', 'Chris', 21, 'Florida');
insert into Driver (lName, fName, Age, States) values ('Lowery', 'Justin', 21, 'Florida');
insert into Driver (lName, fName, Age, States) values ('Sisson', 'Andrew', 21, 'Georgia');
insert into Driver (lName, fName, Age, States) values ('Walker', 'Paul', 40, 'California');
insert into Driver (lName, fName, Age, States) values ('Andre', 'Eduardo', 20, 'Florida');
insert into CarDescription ( MakeModel, CarYear, CarColor, TrimColor, DriverID) values ('Ford Mustang GT', 2020, 'Orange', 'Black',1);
insert into CarDescription ( VIN, MakeModel, CarYear, CarColor, TrimColor, DriverID) values (1, 'Volkwagen Golf', 2020, 'White', 'Black',2);
insert into CarDescription ( VIN, MakeModel, CarYear, CarColor, TrimColor, DriverID) values (2, 'Ford Mustang GT', 2019, 'Blue', 'Black',3);
insert into CarDescription ( VIN, MakeModel, CarYear, CarColor, TrimColor, DriverID) values (3, 'Nissan Skyline GTR', 2000, 'Gray', 'Black',4);
insert into CarDescription ( VIN, MakeModel, CarYear, CarColor, TrimColor, DriverID) values (4, 'Toyota Supra GR', 2021, 'Black', 'Black',5);
insert into Record (SeedNum, Wins, Losses, BestTime, TopSpeed, DriverID) values (1, 5, 0, '8.958', 150, 1);
insert into Record (SeedNum, Wins, Losses, BestTime, TopSpeed, DriverID) values (2, 3, 1, '9.58', 130, 2);
insert into Record (SeedNum, Wins, Losses, BestTime, TopSpeed, DriverID) values (3, 3, 2, '8.958', 150, 3);
insert into Record (SeedNum, Wins, Losses, BestTime, TopSpeed, DriverID) values (4, 20, 0, '7.250', 190, 4);
insert into Record (SeedNum, Wins, Losses, BestTime, TopSpeed, DriverID) values (5, 6, 0, '8.300', 170, 5);
insert into CarPerformance (VIN, Horsepower, Torque, Drivetrain, BoostType) values (0, 460, 420, 'RWD', 'N/A');
insert into CarPerformance (VIN, Horsepower, Torque, Drivetrain, BoostType) values (1, 315, 310, 'FWD', 'Turbo');
insert into CarPerformance (VIN, Horsepower, Torque, Drivetrain, BoostType) values (2, 460, 420, 'RWD', 'N/A');
insert into CarPerformance (VIN, Horsepower, Torque, Drivetrain, BoostType) values (3, 1000, 999, 'AWD', 'Turbo');
insert into CarPerformance (VIN, Horsepower, Torque, Drivetrain, BoostType) values (4, 700, 650, 'RWD', 'Turbo');




/*
insert into Driver values (2, 'Justin', 'Lowery', 20, 'Florida');
a. select MakeModel from CarDescription;
b. update Record set Wins=5 where DriverID=1;
c. delete from CarPerformance where Horsepower=1000;
d. select DriverID, Wins, Losses from Record join Driver using (DriverID);


ALTER TABLE CarPerformance
ADD COLUMN VIN INT NOT NULL,
ADD CONSTRAINT fk_CarDescription_VIN
FOREIGN KEY (VIN)
REFERENCES CarDescription(VIN);