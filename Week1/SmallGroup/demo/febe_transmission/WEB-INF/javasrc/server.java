import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.http.*;
public class server extends HttpServlet {
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out=response.getWriter();
        String name=request.getParameter("name"); 
        String method=request.getMethod();
        if(name.equals("(default)")) {
            response.sendError(400,"你能不能修改一下default(怒)"); 
        }
        else if(name.equals("(break_server)"))
            response.sendError(503,"超负荷了呢");
        else
            out.println("<html><meta charset=\"UTF-8\"><title>response</title><body><p>Method:"+method+"</p><p>Parameter name="+name+"</p></body></html>");
    }
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException {
        doGet(request, response);
    }
}