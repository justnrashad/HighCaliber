var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("test");
  var query = {};
  dbo.collection("musicians").find(query).toArray(function(err, result) {
    if (err) throw err;
    console.log(result);
    db.close();
  });
});