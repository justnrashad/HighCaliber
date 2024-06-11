import com.mongodb.Block;
 import com.mongodb.client.MongoClients;
 import com.mongodb.client.MongoClient;
 import com.mongodb.client.MongoCollection;
 import com.mongodb.client.MongoDatabase;
 import com.mongodb.client.model.Aggregates;
 import com.mongodb.client.model.Accumulators;
 import com.mongodb.client.model.Projections;
 import com.mongodb.client.model.Filters;
     
 import org.bson.Document;
/*
 
  
 java -cp /home/codio/workspace/musicdatabase-java/mongodb-driver-sync-3.9.0.jar:.: Musicmongodball
java -cp /home/codio/workspace/musicdatabase-java/mongodb-driver-legacy-3.9.0.jar:.: Musicmongodball

javac -verbose -cp /home/codio/workspace/mongodb-java-music/mongodb-driver-async-3.9.0.jar:.: Musicmongodball.java

*/

public class Musicmongodball {
    

public static void main(String args[]) {

   MongoClient mongoClient = MongoClients.create();
MongoDatabase database = mongoClient.getDatabase("test");
MongoCollection<Document> collection = database.getCollection("restaurants");

    

}
    
}

