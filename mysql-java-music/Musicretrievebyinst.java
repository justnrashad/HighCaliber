import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

/*
 
 javac Musicretrievebyinst.java
 
 java -cp /home/codio/workspace/mysql-java-music/mysql-connector-java-8.0.13.jar:.: Musicretrievebyinst

*/
public class Musicretrievebyinst {  
    
    public static void main(String args[]){  
    
        
     Scanner sc = new Scanner(System.in);
        
     String inst;
    
     System.out.print("Instrument: ");
     inst = sc.nextLine();
        
    try{  
  
        Class.forName("com.mysql.cj.jdbc.Driver");  
 
        Connection con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root");  
  
        PreparedStatement stmt=con.prepareStatement("select firstname, lastname, instrument " +
                                   "FROM musicians join instrumentsplayed " +
                                   "ON musicians.Id = instrumentsplayed.Musician " +
                                   "WHERE instrument = ?");
    
        stmt.setString(1,inst);
        
        ResultSet rs=stmt.executeQuery();  
    
        while(rs.next()) {
        
            System.out.print(rs.getString("firstname") + " ");
            System.out.print(rs.getString("lastname") + " ");
            System.out.println(rs.getString("instrument"));
    
        }
    
        con.close();  
    
    }catch(Exception e){ System.out.println(e);}  
  }  
}
