package MainPackage;

import java.util.ArrayList;

public class Operations {
	
	public static int and(int a, int b) {
		return (a == 1 && b == 1 ? 1 : 0);
	}
	
	public static int or(int a, int b) {
		return (a == 1 || b == 1 ? 1 : 0);	
	}
	
	public static int xor(int a, int b) {
		return (a != b ? 1 : 0);
	}
	
	public static int not(int a) {
		return (a == 0 ? 1 : 0);
	}
	
	public static boolean calc(ArrayList<Node> var, int i)
	{
		Node v = var.get(i);
//System.out.print("CALCULATING > " + v.name + "(" + v.index + ")");
		if (ExpertSystem.isNum(v.getName()))
		{
			i = Integer.parseInt(v.getName());
		}
		if (ExpertSystem.isLetter(v.getName()))
		{
//System.out.println("direct return");
			return (v.status);
		}
		else
		{
//System.out.println("recall return");
			switch (v.name)
			{
				case "+": return (calc(var, v.patte1.index) && calc(var, v.patte2.index));
				case "|": return (calc(var, v.patte1.index) || calc(var, v.patte2.index));
				case "^": return (!(calc(var, v.patte1.index) && calc(var, v.patte2.index)) && (calc(var, v.patte1.index) || calc(var, v.patte2.index)));
				case "!": return (!calc(var, v.patte1.index));
			}
		}
		System.out.println("error return");
		return false;	
	}
}
