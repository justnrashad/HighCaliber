import mysql.connector

# Execute:
# python3 musicretrieveall.py
#

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="music"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT * FROM musicians")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
