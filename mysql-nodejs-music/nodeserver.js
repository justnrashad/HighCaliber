var http = require('http');
var url = require('url');
var mysql = require('mysql');
var ra = require('./musicretrieveall-web');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  var q = url.parse(req.url, true).query;
  var txt = q.year + " " + q.month;
  //res.end(txt);
  if(q.command == "retrieveall") {
     //res.end("hello");
      a = ra.retrieveall();
      res.end(a);
  }
}).listen(8080);