var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  database: "music"
});

con.connect(function(err) {
  if (err) throw err;
  con.query("SELECT * FROM musicians", function (err, result, fields) {
    if (err) throw err;
    console.log(result);
  });
});