package util;

import java.io.IOException;
import java.io.PrintWriter;
//import java.sql.SQLException;
import java.util.Map;
import java.util.HashMap;
import java.lang.reflect.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import tableElement.*;
import com.fasterxml.jackson.databind.ObjectMapper;

@WebServlet("/BookShelf")
public class BookShelf extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public BookShelf() {
        super();
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("charset=UTF-8");
		String func=request.getParameter("func");
		
		try {
			//QUESTION: WHY IT SHOULD BE A SUBCLASS ?!  A: It doesn't
			//Q2: WHY CLASS SHOULD BE A GENERIC TYPE?!  A: Read the book
			Class<funct> reflect=funct.class;//class information has been stored in the reflect
			Method ofBookshelf=reflect.getMethod(func, HttpServletRequest.class, HttpServletResponse.class);
			ofBookshelf.invoke(null,request,response);
			
			CrudUtil.close();
		}
		catch (Exception e) {e.printStackTrace();}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
class funct extends BookShelf{
	/*
	 * To execute all functions of the website
	 * @Author LeoScott
	 * */
	private static final long serialVersionUID = 1L;
	public static void doLogin(HttpServletRequest request, HttpServletResponse response) throws Exception {//func:doLogin
		Librarian newer=new Librarian(request.getParameter("account"),request.getParameter("password"));
		boolean ver=CrudUtil.Verification(newer.getUserName(),newer.getPassword());
		PrintWriter out=response.getWriter();
		if(ver) {
			Map<String,Object> message=new HashMap<>();//pack things up: message, token
			message.put("message", "login_success");
			message.put("token", "11451419260817");
			message.put("account",newer.getUserName());
			ObjectMapper sender=new ObjectMapper();
			sender.writeValue(out, message);
		}
		else {
			Map<String,Object> message=new HashMap<>();//pack things up: message
			message.put("message", "login_failed");
			//message.put("token", "11451419260817");
			ObjectMapper sender=new ObjectMapper();
			sender.writeValue(out, message);
		}
	}
	public static void seek(HttpServletRequest request, HttpServletResponse response) {//func:seek
		String bookName=request.getParameter("bookname");
		try {
			Integer amount=CrudUtil.Seek(bookName);//seek the book and get the amount, database related
			Map<String,Object> mapp=new HashMap<>();//ready to packup
			mapp.put("amount", amount.toString());//key-value
			ObjectMapper sender=new ObjectMapper();
			sender.writeValue(response.getWriter(), mapp);//output json
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void fseek(HttpServletRequest request, HttpServletResponse response) {//func:fseek
		String bookName=request.getParameter("bookname");
		try {
			Integer amount=CrudUtil.fSeek(bookName);
			Map<String,Object> mapp=new HashMap<>();
			mapp.put("amount", amount.toString());
			ObjectMapper sender=new ObjectMapper();
			sender.writeValue(response.getWriter(), mapp);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void signup(HttpServletRequest request, HttpServletResponse response) {//func:signup
		Librarian newUser=new Librarian();
		newUser.setUserName(request.getParameter("account")); 
		newUser.setPassword(request.getParameter("password"));
		try {
			boolean status=CrudUtil.Insert(newUser);
			Map<String,Object> mapp=new HashMap<>();
			mapp.put("message", (status?"success":"failed") );
			ObjectMapper sender=new ObjectMapper();
			sender.writeValue(response.getWriter(), mapp);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}

