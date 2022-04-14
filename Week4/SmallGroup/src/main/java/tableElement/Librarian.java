package tableElement;

public class Librarian {
	private String userName;
	private String password;
	public Librarian() {}
	public Librarian(String user,String pass) {
		this.userName=user;
		this.password=pass;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public boolean equal(Librarian a) {
		if(a.getPassword()==this.password && a.getUserName()==this.userName)
			return true;
		else return false;
	}
}
