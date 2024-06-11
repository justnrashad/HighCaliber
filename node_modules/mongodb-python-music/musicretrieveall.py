import pymongo

myclient = pymongo.MongoClient("mongodb://localhost/")
mydb = myclient["test"]
mycol = mydb["musicians"]

myquery = {"lastname":"Monk" }

mydoc = mycol.find(myquery)



for x in mydoc:
    print('hello')
#  print(x)