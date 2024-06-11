import mysql.connector

# Execute:
# python3 musicretrievebyinst.py
#

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="music"
)

inst = input("Instrument: ")

mycursor = mydb.cursor()

sql = "SELECT firstname, lastname, instrument " \
      "FROM musicians join instrumentsplayed " \
      "ON musicians.Id = instrumentsplayed.Musician " \
      "WHERE instrument = %s"
    
arg = (inst, )

mycursor.execute(sql, arg)

myresult = mycursor.fetchall()

for x in myresult:
  print(x)