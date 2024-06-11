import mysql.connector

# Execute:
# python3 musicretrieveid.py
#

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="music"
)

id = input("Id: ")

mycursor = mydb.cursor()

sql = "SELECT * FROM musicians WHERE id = %s"
arg = (id, )

mycursor.execute(sql, arg)

myresult = mycursor.fetchall()

for x in myresult:
  print(x)