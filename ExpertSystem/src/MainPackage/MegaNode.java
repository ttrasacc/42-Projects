package MainPackage;

import java.util.ArrayList;

public class MegaNode {
	Node source;
	ArrayList<Node> target = new ArrayList<Node>();
	
	public MegaNode(Node src, Node tgt) {
		source = src;
		target.add(tgt);
	}

	public void addTarget(Node tgt)
	{
		this.target.add(tgt);
	}
}
