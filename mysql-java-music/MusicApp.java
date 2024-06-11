import java.sql.*;  
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

/*
 
 javac MusicApp.java
 
 java -cp /home/codio/workspace/mysql-java-music/mysql-connector-java-8.0.13.jar:.: MusicApp

*/

     
public class MusicApp {  
    
    static Connection con;
    static Scanner sc;
    public static void main(String args[]){  
    
            sc = new Scanner(System.in);
            int option=6;
   
            try{  
  
                con=DriverManager.getConnection("jdbc:mysql://localhost/music?user=root");  
 
                Class.forName("com.mysql.cj.jdbc.Driver");  
 
                while (option != 5) {
      
    
                 System.out.println();
                 System.out.println("1. Add a musician");
                 System.out.println("2. Find a musician by id");
                 System.out.println("3. Find a musician by instrument");
                 System.out.println("4. Show all musicians");
                 System.out.println("5. Exit");
     
                 System.out.print("\nChoice : ");
        
                  option = sc.nextInt(); 
     
                 switch(option) {
        
                     case 2: findbyid();
                     break;
             
                     case 4: findall();
                     break;             
                 }
                        
                 }
                
            con.close();
        
            }catch(Exception e){ System.out.println(e);}
      }
    
public static void findall() {
    try{ 
        Statement stmt=con.createStatement();  
        ResultSet rs=stmt.executeQuery("select * from musicians");  
    
        while(rs.next()) {
        
            System.out.print(rs.getString("id") + " ");
            System.out.print(rs.getString("firstname") + " ");
            System.out.print(rs.getString("lastname") + " ");
            System.out.println(rs.getString("born"));
    
        }
    
          
    }catch(Exception e){ System.out.println(e);}
    
  }  
    
public static void findbyid() {
      
     System.out.print("Enter id: ");
     int id = sc.nextInt();
      
      try {
          
        PreparedStatement stmt=con.prepareStatement("select * from musicians where id = ?");   
        stmt.setInt(1,id);
        
        ResultSet rs=stmt.executeQuery();  
    
        while(rs.next()) {
        
            System.out.print(rs.getString("id") + " ");
            System.out.print(rs.getString("firstname") + " ");
            System.out.print(rs.getString("lastname") + " ");
            System.out.println(rs.getString("born"));
    
        }
    
          
    } catch(Exception e){ System.out.println(e);}
    
  }  
}
