import java.sql.*;  
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/*
 
 javac Musicretrieveall.java
 
 java -cp /home/codio/workspace/mysql-java-music/mysql-connector-java-8.0.13.jar:.: Musicretrieveall

*/

public class Musicretrieveall {  
    
    public static void main(String args[]){  
    
    try{  
  
        Class.forName("com.mysql.cj.jdbc.Driver");  
 
        Connection con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root");  
  
        Statement stmt=con.createStatement();  
        ResultSet rs=stmt.executeQuery("select * from musicians");  
    
        while(rs.next()) {
        
            System.out.print(rs.getString("id") + " ");
            System.out.print(rs.getString("firstname") + " ");
            System.out.print(rs.getString("lastname") + " ");
            System.out.println(rs.getString("born"));
    
        }
    
        con.close();  
    
    }catch(Exception e){ System.out.println(e);}  
  }  
}

