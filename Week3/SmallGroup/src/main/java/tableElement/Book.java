package tableElement;
import java.util.*;
public class Book {
	private String name;
	private int importance;
	private boolean completion;
	public Book() {
		super();
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = String.format("'%s'", name) ;
		//don't forget the SQL syntax: string with '
	}
	public int getImportance() {
		return importance;
	}
	public void setImportance(int importance) {
		this.importance = importance;
	}
	public boolean isCompletion() {
		return completion;
	}
	public void setCompletion(boolean completion) {
		this.completion = completion;
	}
	public boolean check() {//prevent SQL attack
		Iterator<String> inspector=name.Iterator();
		while(inspector.hasNext()) {
			char sign=inspector.next();
			if(sign==';')
				return true;
		}
		return false;
	}
}
