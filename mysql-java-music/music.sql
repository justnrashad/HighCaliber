DROP database IF EXISTS music;
CREATE database music;
USE music;

CREATE TABLE musicians(
    Id INT NOT NULL auto_increment,
    FirstName TEXT NOT NULL,
    LastName TEXT NOT NULL,
    Born INT NOT NULL,
    PRIMARY KEY (Id)
);

CREATE TABLE instrumentsplayed(
    Id INT NOT NULL auto_increment,
    Musician INT NOT NULL,
    Instrument TEXT NOT NULL,
    PRIMARY KEY (Id),
    FOREIGN KEY (musician) REFERENCES musicians(Id)
);

INSERT INTO musicians (FirstName, LastName, Born) VALUES ('Thelonious', 'Monk', 1917);
INSERT INTO musicians (FirstName, LastName, Born) VALUES ('Sonny', 'Rollins', 1930);
INSERT INTO musicians (FirstName, LastName, Born) VALUES ('Steve', 'Lehman', 1978);

INSERT INTO instrumentsplayed (Musician, Instrument) VALUES (1, 'Piano');
INSERT INTO instrumentsplayed (Musician, Instrument) VALUES (2, 'Saxophone');
INSERT INTO instrumentsplayed (Musician, Instrument) VALUES (3, 'Saxophone');













/*
CREATE VIEW 
pianoplayers AS 
SELECT FirstName, LastName FROM musicians 
JOIN instrumentsplayed ON musicians.Id = instrumentsplayed.Musician
WHERE instrumentsplayed.Instrument = 'Piano';

INSERT INTO musicians (Id, FirstName, LastName, Born) VALUES (4, 'Art', 'Tatum', 1909);
INSERT INTO instrumentsplayed (Id, Musician, Instrument) VALUES (5, 4, 'Piano');

update instrumentsplayed set Instrument='drums' where Id=5;

ALTER TABLE musicians MODIFY COLUMN Id INT NOT NULL AUTO_INCREMENT;

INSERT INTO musicians (FirstName, LastName, Born) VALUES ('Bill', 'Evans', 1908);


DELIMITER $$
CREATE PROCEDURE saxes()
BEGIN

  SELECT FirstName, LastName FROM musicians
  JOIN instrumentsplayed ON musicians.Id = instrumentsplayed.Musician
  WHERE instrumentsplayed.Instrument = 'Saxophone';

  
END
$$
DELIMITER ;

 

*/