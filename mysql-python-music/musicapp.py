import mysql.connector

# Execute:
# python3 musicapp.py
#
def showall():
  
  mycursor = mydb.cursor()

  mycursor.execute("SELECT * FROM musicians")

  myresult = mycursor.fetchall()

  for x in myresult:
    print(x)
    
  return;

def findbyid():
    
    id = input("Id: ")

    mycursor = mydb.cursor()

    sql = "SELECT * FROM musicians WHERE id = %s"
    arg = (id, )

    mycursor.execute(sql, arg)

    myresult = mycursor.fetchall()

    for x in myresult:
       print(x)
    
    return;

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="music"
)

option = 0;

while option != 5: 
    
    print("")
    print("1. Add a musician")
    print("2. Find a musician by id")
    print("3. Find a musician by instrument")
    print("4. Show all musicians")
    print("5. Exit")
    
    option = int(input("Choice: "))
    print (option)
    if option == 4:
        showall()
    elif option == 2:
        findbyid()


