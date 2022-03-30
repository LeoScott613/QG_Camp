import java.sql.*;
import java.util.*;
class Book {//the class that store a book's necessary data
    private String name;
    private int importance;
    private boolean completion;
    //don't use static type because no need to share information between different instances
    public Book(String n,int importan,boolean comp) {
        name=n;
        importance=importan;
        completion=comp;
    }

    //get scope
    public String getName() {
        return name;
    }
    public int getImportance() {
        return importance;
    }
    public boolean getCompletion() {
        return completion;
    }

    //set scope
    public void setName(String n) {
        name=n;
    }
    public void setImportance(int im) {
        importance=im;
    }
    public void setCompletion(boolean comp) {
        completion=comp;
    }
}

public class Utils_crud {//the encapsuled crud utilities
    private String user;
    private String password;
    private Connection conn;
    private Statement stat;
    private ResultSet rs;
    private ResultSetMetaData meta;

    //SQL query
    private String INSERT_QUERY;
    public Utils_crud() throws ClassNotFoundException{
        Class.forName("com.mysql.cj.jdbc.Driver");
        conn=null;
        stat=null;
    }
    public void login(String u,String p) throws SQLException{
        try {
            user=u;
            password=p;
            conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", user, password);
            stat=conn.createStatement();    
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    /*
    BOOKSHELF'S STRUCTURE
    |ID(INT) | NAME(TEXT) | IMPORTANCE(INT) | COMPLETION(BOOLEAN)|
    |        |            |                 |                    |
    */

    public int insertion(Book book) throws SQLException {//insert data into the table:bookshelf
        rs=stat.executeQuery("SELECT ID FROM BOOKSHELF");
        
        int count=0;
        while(rs.next()){
            count++;
        }

        INSERT_QUERY=String.format("INSERT INTO BOOKSHELF VALUES (%d,\'%s\',%d,%b)",++count,book.getName(),
        book.getImportance(),book.getCompletion());//prepare the INSERT_QUERY
        int affected=stat.executeUpdate(INSERT_QUERY);//it's how many rows affected
        return affected;
    }
    
    public int create(String sql) throws SQLException{//create table,temporarily given up
        //column_num is the amount of columns
        LinkedList<String> column=new LinkedList<>();
        Iterator<String> icol;
        int column_num;

        Scanner in=new Scanner(System.in);
        System.out.println("Please enter the name of new table:");
        String tableName=in.nextLine();
        System.out.println("Please enter the amount of columns:");
        column_num=in.nextInt();
        in.nextLine();//get empty line
        System.out.println("(The only support type:TEXT)");
        for(int i=1;i<=column_num;i++) {
            System.out.println("column "+i+" name:");
            column.add(in.nextLine());
        }
        /*
        for(icol=column.iterator();icol.hasNext();System.out.println(icol.next()))//traverse for test
            ;
        */
        in.close();
        
        return 0;
    }

    public void release() throws SQLException {
        if(conn!=null) conn.close();
        if(stat!=null) stat.close();
    }
}