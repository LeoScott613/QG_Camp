import java.sql.SQLException;
import java.util.Scanner;

public class crud {
    public static void main(String[] args) throws SQLException,ClassNotFoundException{
        Scanner in=new Scanner(System.in);

        Utils_crud crud=new Utils_crud();
        crud.login("root","123456");
        
        Book book=new Book("NULL BOOK", 0, false);
        System.out.println("Input the name of the book, the importance, and the completion(boolean) of it:(divided by blank-space)");
        book.setName(in.nextLine());
        book.setImportance(in.nextInt());
        book.setCompletion(in.nextBoolean());
        //get user input to renew the data of the book you want to add

        int affected=crud.insertion(book);
        System.out.println(affected+" rows affected.");

        in.close();
        crud.release();//a must
    }
}
