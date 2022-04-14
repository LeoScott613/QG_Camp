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
	//private static ResultSetMetaData rsma;
	static {
		user="root";
		password="123456";
		table="BOOKSHELF";
		conn=null;
		s=null;
		ps=null;
		rs=null;
		//rsma=null;
		//before initialization, just put them null
		try {
			//Class.forName("com.mysql.cj.jdbc"); ?????? You seem to be soft...
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql:///mydb", user, password);
			s=conn.createStatement();
			//ps=conn.;
			rs=s.executeQuery(String.format("SELECT * FROM %s;", table));
			//rsma=rs.getMetaData();
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
	//Check if there is any SQL attack
	public static boolean Inspector(String query) {
		for(int i=0;i<query.length();i++) {
			if(query.charAt(i)==';')//layer 1
				return true;				
		}
		return false;
	}
	//Search certain value
	public static int Seek(String toFind) throws SQLException {
		CrudUtil.recycle();
		
		if(toFind==null)
			return -1;
		if(Inspector(toFind))//check if there is sql attack
			return -114;
		
		String executeQ=String.format("SELECT * FROM BOOKSHELF WHERE NAME='%s';", toFind);
		rs=s.executeQuery(executeQ);
		int counter=0;
		while(rs.next())
			counter++;
		/*这种从数据集中遍历查找的方式没有很高效
		while(rs.next()) {
			for(int i=1;i<=rsma.getColumnCount();i++) {
				String compare=rs.getString(i).toString();
				if(compare.equals(toFind)) 
					counter++;
			}
		}
		*/
		return counter;
	}
	//Search certain value vaguely
	public static int fSeek(String toFind) throws SQLException {
		CrudUtil.recycle();
		if(toFind==null)
			return -1;
		if(Inspector(toFind))
			return -114;
		
		String executeQ=String.format("SELECT * FROM BOOKSHELF WHERE NAME LIKE '%%%s%%';", toFind);
		rs=s.executeQuery(executeQ);
		
		int counter=0;
		while(rs.next())//traverse and count
			counter++;
		return counter;
	}
	//verify the account and password
	public static boolean Verification(String acc,String pas) throws SQLException{
		CrudUtil.recycle();
		if(Inspector(acc)||Inspector(pas))
			return false;
		
		String executeQ=String.format("SELECT * FROM LIBRARIAN WHERE ACCOUNT='%s' AND PASSWORD='%s';", acc,pas);
		ResultSet librarian=s.executeQuery(executeQ);
		if(librarian.next())
			return true;
		else
			return false;
	}
	//insert a book
	public static boolean Insert(Book book) throws SQLException {
		CrudUtil.recycle();
		
		if(Inspector(book.getName()))
			return false;
		String query=String.format("INSERT INTO BOOKSHELF VALUES (%d,%s,%d,%b);",0,book.getName(),book.getImportance(),book.isCompletion());
		s.executeUpdate(query);
		return true;
	}
	//insert a librarian
	public static boolean Insert(Librarian lib) throws SQLException {
		CrudUtil.recycle();
		
		if(Inspector(lib.getUserName())||Inspector(lib.getPassword()))
			return false;
		String query=String.format("SELECT * FROM LIBRARIAN WHERE ACCOUNT='%s'",lib.getUserName());
		rs=s.executeQuery(query);
		if(rs.next())
			return false;
		rs=s.executeQuery("SELECT ID FROM LIBRARIAN;");
		int id=1;
		while(rs.next()) {
			id++;
		}
		query=String.format("INSERT INTO LIBRARIAN(ID,ACCOUNT,PASSWORD) VALUES (%d,'%s','%s');",id,lib.getUserName(),lib.getPassword());
		s.executeUpdate(query);
		return true;
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
