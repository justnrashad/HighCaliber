import mysql.connector

# Execute:
# python3 musicinsert.py
# 

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="music"
)

lastid = 0;

fn = input("First Name: ")
ln = input("Last Name: ")
bornyear = input("Birth Year: ")
inst = input("Instrument: ")

mycursor = mydb.cursor()

sql = "INSERT INTO musicians (firstname, lastname, born) " \
                                   "VALUES(%s,%s,%s)"
  
arg = (fn, ln, bornyear, )

mycursor.execute(sql, arg)

if mycursor.lastrowid:
            lastid = mycursor.lastrowid

sql = "INSERT INTO instrumentsplayed (musician, instrument) " \
                              "VALUES(%s,%s)"
arg = (lastid, inst, ) 

mycursor.execute(sql, arg)

mydb.commit()