import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

/*
 
 Compile:
 javac Musicinsert.java
 
 Execute:
 java -cp /home/codio/workspace/mysql-java-music/mysql-connector-java-8.0.13.jar:.: Musicinsert

*/

public class Musicinsert {  
    
    public static void main(String args[]){  
    
    String fn,ln, inst;
        
    int bornyear, lastid=0;
        
     Scanner sc = new Scanner(System.in);
        
     System.out.print("First name: ");
     fn = sc.nextLine();
        
     System.out.print("Last name: ");
     ln = sc.nextLine();
        
     System.out.print("Instrument: ");
     inst = sc.nextLine();
        
     System.out.print("Enter year of birth: ");
     bornyear = sc.nextInt();
        

        
    try{  
  
        Class.forName("com.mysql.cj.jdbc.Driver");  
 
        //Connection con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root&password=YES");  
  Connection con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root");  
  
        PreparedStatement stmt=con.prepareStatement("insert into musicians (firstname, lastname, born) VALUES(?,?,?)", Statement.RETURN_GENERATED_KEYS);  
        
        stmt.setString(1,fn);
        stmt.setString(2,ln);
        stmt.setInt(3,bornyear);
        
        
        stmt.executeUpdate();  
    
            ResultSet rs=stmt.getGeneratedKeys();
            
            if(rs.next())
                lastid =rs.getInt(1);
                
         stmt=con.prepareStatement("insert into instrumentsplayed (musician, instrument) VALUES(?,?)");  
  
                stmt.setInt(1,lastid);
        stmt.setInt(1,lastid);
        stmt.setString(2,inst);
       
        
        stmt.executeUpdate();  
        
    
        con.close();  
    
    }catch(Exception e){ System.out.println(e);}  
  }  
}

