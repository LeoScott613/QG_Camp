package util;
import java.sql.*;
import tableElement.Book;
import tableElement.Librarian;
public class CrudUtil {
	private static String user;
	private static String password;
	private static String table;
	private static Connection conn;
	private static Statement s;
	private static PreparedStatement ps;
	private static ResultSet rs;
	private static ResultSetMetaData rsma;
	static {
		user="root";
		password="123456";
		table="BOOKSHELF";
		conn=null;
		s=null;
		ps=null;
		rs=null;
		rsma=null;
		//before initialization, just put them null
		try {
			//Class.forName("com.mysql.cj.jdbc"); ?????? You seem to be soft...
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql:///mydb", user, password);
			s=conn.createStatement();
			//ps=conn.;
			rs=s.executeQuery(String.format("SELECT * FROM %s;", table));
			rsma=rs.getMetaData();
		}
		catch (Exception cnfe) {
			cnfe.printStackTrace();
		}
	}
	//timeout management prevent connection from used after closed
	public static void recycle() throws SQLException{
		if(conn.isClosed()) {
			conn=DriverManager.getConnection("jdbc:mysql:///mydb", user, password);
			s=conn.createStatement();
		}
	}
	//Search certain value
	public static <T> int Seek(T anchor) throws SQLException {
		CrudUtil.recycle();
		
		if(anchor==null)
			return -1;
		String toFind=anchor.toString();
		int counter=0;
		rs=s.executeQuery("SELECT * FROM BOOKSHELF;");
		while(rs.next()) {
			for(int i=1;i<=rsma.getColumnCount();i++) {
				String compare=rs.getString(i).toString();
				if(compare.equals(toFind)) 
					counter++;
			}
		}
		return counter;
	}
	public static boolean Verification(String acc,String pas) throws SQLException{
		CrudUtil.recycle();
		
		ResultSet librarian=s.executeQuery("SELECT * FROM LIBRARIAN;");
		while(librarian.next()) {
			if(acc.equals(librarian.getString(2))&&pas.equals(librarian.getString(3)))
				return true;
		}
		return false;
	}
	public static void Insert(Book book) throws SQLException {//to improve adaptablity,this function remain no parameters
		CrudUtil.recycle();
		
		String query=String.format("INSERT INTO %s VALUES (%d,%s,%d,%b);", table,0,book.getName(),book.getImportance(),book.isCompletion());
		s.executeUpdate(query);
	}
	public static void close() throws SQLException {//release all the resources, must be done in the end of the program
		if(conn!=null)
			conn.close();
		if(s!=null)
			s.close();
		if(ps!=null)
			ps.close();
		if(rs!=null)
			rs.close();
	}
}
