package util;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.Map;
import java.util.HashMap;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import tableElement.*;
import com.fasterxml.jackson.databind.*;
import com.fasterxml.jackson.databind.ObjectMapper;

@WebServlet("/BookShelf")
public class BookShelf extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public BookShelf() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("charset=UTF-8");
		PrintWriter out=response.getWriter();
		String bookName=null;
		String func=null;
		func=request.getParameter("func");
		switch(func) {
		case "login_capcha":
			try {
				doLogin(request,response);
			}
			catch (Exception e) {
				e.printStackTrace();
			}
			break;
		case "seek":
			bookName=request.getParameter("bookname");
			try {
				out.print(CrudUtil.Seek(bookName));
			}
			catch (Exception e) {
				e.printStackTrace();
			}
		}
		/*
		int howmany=0;
		try {
			Class.forName("util.CrudUtil");//remember this even in the same pack
			//Execute the static codeblock to init the CrudUtil. For details check util.CrudUtil
			howmany=CrudUtil.Seek(bookName);
		}
		catch (SQLException sqle) {
			sqle.printStackTrace();
		}
		catch (ClassNotFoundException cnfe) {
			cnfe.printStackTrace();
		}
		if(howmany==-1)
			out.println("error");
		else {
			Integer howMany=howmany;
			String result=howMany.toString()+" "+bookName;
			out.println(result);
		}
		*/
		//*************************************
		
		/*
		//test code:for CrudUtil.Insert(Book book)
		Book book=new Book();
		book.setName("Empty");
		book.setImportance(0);
		book.setCompletion(true);
		try {
			CrudUtil.Insert(book);
			out.println("--inserted--");
		}
		catch (SQLException e) {
			System.out.println("bad luck...");
			e.printStackTrace();
		}
		
		try {
			CrudUtil.close();
		}
		catch (Exception e) {
			System.out.println("bad luck...but close");
			e.printStackTrace();
		}
		//****************************************
		
		 */
		try {
			CrudUtil.close();
		}
		catch (Exception e) {
			;
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
	protected void doLogin(HttpServletRequest request, HttpServletResponse response) throws Exception {
		Librarian newer=new Librarian(request.getParameter("account"),request.getParameter("password"));
		boolean ver=CrudUtil.Verification(newer.getUserName(),newer.getPassword());
		PrintWriter out=response.getWriter();
		if(ver) {
			Map<String,Object> message=new HashMap<>();//pack things up: message, token
			message.put("message", "login_success");
			message.put("token", "11451419260817");
			message.put("account",newer.getUserName());
			ObjectMapper packer=new ObjectMapper();
			packer.writeValue(out, message);
		}
		else {
			Map<String,Object> message=new HashMap<>();//pack things up: message
			message.put("message", "login_failed");
			//message.put("token", "11451419260817");
			ObjectMapper packer=new ObjectMapper();
			packer.writeValue(out, message);
		}
		//String name=request.getParameter("name");
		//Map<String,Object> mapp=new HashMap<>();
		//mapp.put("data",name);
		//PrintWriter out=response.getWriter();
		//ObjectMapper mapper=new ObjectMapper();
		//mapper.writeValue(out,mapp);
		//out.println(name);
	}

}
