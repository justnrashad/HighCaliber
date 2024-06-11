import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

/*
 
 javac Musicretrieveid.java
 
 java -cp /home/codio/workspace/mysql-java-music/mysql-connector-java-8.0.13.jar:.: Musicretrieveid

*/

public class Musicretrieveid {  
    
    public static void main(String args[]){  
    
    int id;
        
     Scanner sc = new Scanner(System.in);
        
     System.out.print("Enter id: ");
     id = sc.nextInt();
        
    try{  
  
        Class.forName("com.mysql.cj.jdbc.Driver");  
 
        Connection con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root");  
  
        PreparedStatement stmt=con.prepareStatement("select * from musicians where id = ?");  
  
        stmt.setInt(1,id);
        
        ResultSet rs=stmt.executeQuery();  
    
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

