import java.sql.SQLException;

public class crud {
    public static void main(String[] args) throws SQLException,ClassNotFoundException{
        Utils_crud crud=new Utils_crud();
        crud.login("root","123456");
        crud.create("create");
    }
}
