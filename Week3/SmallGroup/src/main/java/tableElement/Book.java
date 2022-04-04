package tableElement;

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
}
