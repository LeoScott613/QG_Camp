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

import tableElement.Book;
import com.fasterxml.jackson.databind.*;
//import com.fasterxml.jackson.databind.ObjectMapper;

@WebServlet("/BookShelf")
public class BookShelf extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public BookShelf() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//test code for doLogin()
		//doLogin(request,response);
		//***********************
		
		
		response.setContentType("charset=UTF-8");
		PrintWriter out=response.getWriter();
		
		//test code:for CrudUtil.Seek(T anchor)
		String bookName=null;
		bookName=request.getParameter("bookname");
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
		Integer howMany=howmany;
		String result=howMany.toString()+" "+bookName;
		out.println(result);
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
	protected void doLogin(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("utf-8");
		
		String name=request.getParameter("name");
		Map<String,Object> mapp=new HashMap<>();
		mapp.put("data",name);
		PrintWriter out=response.getWriter();
		//ObjectMapper mapper=new ObjectMapper();
		//mapper.writeValue(out,mapp);
		out.println(name);
	}

}
