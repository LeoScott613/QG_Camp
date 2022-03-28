import java.sql.*;
import java.util.*;
public class Utils_curd {
    private String user;
    private String password;
    private Connection conn;
    private Statement stat;
    private ResultSet rs;
    private ResultSetMetaData meta;
    public Utils_curd() throws ClassNotFoundException{
        Class.forName("com.mysql.cj.jdbc.Driver");
    }
    public void login(String u,String p) throws SQLException{
        try {
            user=u;
            password=p;
            conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", user, password);
            stat=conn.createStatement();    
        }
        catch (Exception e) {
            e.printStackTrace("error");
        }
        finally {
            conn.close();
            stat.close();
        }
    }
    public static int update(String sql) {
    }
}