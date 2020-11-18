package MainPackage;

public class Node {

	int		index;
	String	name;
	Node 	patte1 = null;//+
	Node 	patte2 = null;//-
	boolean	status = false;

	public Node(int index, String name) {
		
		this.index = index;
		this.name = name;
		this.status = false;
	}

	public Node() {
	}
	
	public Node(int index, String name, Node patte1, Node patte2) {
		
		this.index = index;
		this.name = name;
		this.patte1 = patte1;
		this.patte2 = patte2;
		this.status = false;
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Node getPatte1() {
		return patte1;
	}

	public void setPatte1(Node spatte1) {
		patte1 = spatte1;
	}

	public Node getPatte2() {
		return patte2;
	}

	public void setPatte2(Node spatte2) {
		patte2 = spatte2;
	}

	public boolean getStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
	
	public void printNode() {
		System.out.println("This Node : " + name + "(" + index + ") --- Status = " + status);
		if (patte1 != null)
			System.out.println("	patte1 : " + patte1.name + "(" + patte1.index + ")");
		if (patte2 != null)
			System.out.println("	patte2 : " + patte2.name + "(" + patte2.index + ")");
	}
}