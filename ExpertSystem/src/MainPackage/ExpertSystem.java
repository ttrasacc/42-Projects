package MainPackage;
import java.util.*;
import java.io.*
;
public class ExpertSystem {

	public static int networkI = 0;
	public static ArrayList<Node> network = new ArrayList<Node>();
	public static ArrayList<MegaNode> meganet = new ArrayList<MegaNode>();
	
	
	
	@SuppressWarnings("resource")
	public static void main(String[] args) throws IOException {

		int			reg = 0;
		int			facts = 0;
		int			question = 0;
		String		npi = new String();
		BufferedReader br = null;
		String 		toprint = new String();
		
		if(args.length != 1)
		{
			System.out.println("not the good number of arguments");
			return;
		}
		try {
			br = new BufferedReader(new FileReader(args[0]));
		} catch (FileNotFoundException e) {
			System.out.println("file not found : " + args[0]);
			return;
		}
		String line;
		while ((line = br.readLine()) != null) {
			System.out.println(line);
			if (!(line.isEmpty())) // ===> blindage contre chaine vide
			{
				if (line.charAt(0) != '=' && line.charAt(0) != '?' && facts == 0 && question == 0) { // ===> test via Regex du format d'une equation
					if (parsing(line) == true)
					{
						ArrayList<String> composed = new ArrayList<String>(Arrays.asList(line.split("=")));
						npi = NpiConverter.convert(npi, composed.get(0)).trim();
						ArrayList<String> aNpi = new ArrayList<String>(Arrays.asList(npi.split(" ")));
						networkCreator(aNpi);
						create_mega_node(npi, composed.get(1).replaceAll(" ", ""));
						++reg;
						npi = "";
					}
					else
					{
						System.out.println("parsing error at : <" + line + ">");
						return;
					}
				}

				if (facts == 1 && line.charAt(0) == '=')// ===> test si on lit une ligne avec '=' apres avoir lu la premiere '='
				{
					System.out.println("parsing error at : <" + line + ">");
					return;
				}
				if (line.charAt(0) == '=' && reg > 0 && facts == 0) // ===> test et du bon ordre et de la ligne '='
				{
					if (!line.matches("(=)([A-Z]+)?"))// ===> blindage via Regex declaration
					{
						System.out.println("parsing error at : <" + line + ">");
						return;
					}
					setFacts(line);
					++facts;
				}
				if (question == 1)// ===> test si on lit une ligne non nulle apres avoir lu la ligne '?'
				{
					System.out.println("parsing error at : <" + line + ">");
					return;
				}
				if (line.charAt(0) == '?' && reg > 0 && question == 0 && facts == 1) {
					
					toprint = line;
					++question;
				}
			}
		}
		br.close();
		calc_caller();
		printAnswer(toprint);
		/*int i = 0;
		while (i < network.size())
		{
			network.get(i).printNode();
			++i;
		}*/
	}

	public static void setFacts(String facts)
	{
		int i = 1;
		Node n;
		if (facts.length() == 1)
			return;
		while (i < facts.length())
		{
			n = findLetter(Character.toString(facts.charAt(i)));
			if (n == null)
				n = letterCreator(Character.toString(facts.charAt(i)));
			n.status = true;
				++i;
		}
	}
	
	 public static void printAnswer (String ask)
	{
		
		int i = 1;
		Node n;
		while (i < ask.length())
		{
			n = findLetter(Character.toString(ask.charAt(i)));
			if (n != null)
			{
				if (n.status == true){
					System.out.println(ask.charAt(i) + " = " + "\u001B[32m true \u001B[0m");
				}
				else {
					System.out.println(ask.charAt(i) + " = " + "\u001B[31m false \u001B[0m");
				}
			}
			else
			{
				System.out.println(ask.charAt(i) + " = " + "\u001B[31m false \u001B[0m");
			}
				++i;
		}
	}
	
	public static void calc_caller()
	{
		int i = 0;
		int j = 0;
		boolean result;
		boolean rerun = false;
		MegaNode mn;

		while (i < meganet.size())
		{
			mn = meganet.get(i);
			result = Operations.calc(network,mn.source.index);
			while (j < mn.target.size())
			{				
				if (result == true)
				{
					if (result != mn.target.get(j).status)
					{
						rerun = true;
					}
					mn.target.get(j).status = result;
				}
					++j;
			}
			j = 0;
			++i;
		}
		if (rerun == true)
			calc_caller();
	}
	
	public static void create_mega_node(String npi, String arg)
	{
		//System.out.println("create mega node NPI : " + npi);
		//System.out.println("create mega node ARG : " + arg);
		int		i = 2;
		String letter = Character.toString(arg.charAt(1));
		Node src;
		Node tgt;
		if (npi.length() != 1)
			src = network.get(network.size() - 1);
		else
			src = letterCreator(Character.toString(npi.charAt(0)));
		tgt =findLetter(letter);
		if (tgt == null) {
			letterCreator(letter);
			tgt = findLetter(letter);
//			System.out.print("MN : "); tgt.printNode();
		}
		MegaNode mn = new MegaNode(src , tgt);
		meganet.add(mn);
		while (i < arg.length())
		{
			letter = Character.toString(arg.charAt(i));
			if (isLetter(letter)) {
				tgt = findLetter(letter);
				if (tgt == null) {
					letterCreator(letter);
					tgt = findLetter(letter);
				}
				mn.addTarget(tgt);
			}
			++i;
		}
		//System.out.println("MEGANODE source : "); src.printNode();
		//System.out.println("MEGANODE target : "); tgt.printNode();
}
			
	private static void networkCreator(ArrayList<String> npi) {
		int		i = 0;
		Node	n = new Node();
		Node	na = null;
		Node	nb = null;
		String	pa = null;
		String	pb = null;

		if (npi.size() == 1 )
		{
			letterCreator(Character.toString(npi.get(0).charAt(0)));
			return;
		}
		while (i < npi.size() && NpiConverter.isOperator(npi.get(i).charAt(0)) == false) {
			++i;
		}		
		if (npi.get(i).charAt(0) != '!')
		{
			pa = new String(npi.get(i - 2));
			pb = new String(npi.get(i - 1));
			na = (isNum(pa) == false ? letterCreator(pa) : findIndex(pa));
			nb = (isNum(pb) == false ? letterCreator(pb) : findIndex(pb));
			n.setPatte1(na);
			n.setPatte2(nb);
			n.setName(npi.get(i));
			npi.remove(i);
			npi.add(i, String.valueOf(networkI));
			npi.remove(i - 2);
			npi.remove(i - 2);
		}
		else
		{
			pa = new String(npi.get(i - 1));
			na = (isNum(pa) == false ? letterCreator(pa) : findIndex(pa));
			n.setPatte1(na);
			n.setName(npi.get(i));
			npi.remove(i);
			npi.add(i, String.valueOf(networkI));
			npi.remove(i - 1);
		}
		n.setIndex(networkI);
		++networkI;
		network.add(n);
		if (npi.size() > 1) {
			networkCreator(npi);
		}
	}
	
	private static Node letterCreator(String p) {
		
		Node n = null;
		
		if (isNum(p) == false)
		{
			n = findLetter(p);
			if (n == null) {
				n = new Node(networkI, p);
				network.add(n);
				++networkI;
			}
		}
		return n;
	}

	private static Node findLetter(String s) {
		
		int i = 0;
		Node n;

		if (network == null)
			return null;
		while (i < network.size()) {
			n = network.get(i);
			if (n.getName().equals(s))
				return n;
			++i;
		}
		return null;
	}

	private static Node findIndex(String s) {
		
		int i = 0;
		Node n;
		int intS = Integer.parseInt(s);
		
		if (network == null) {
			System.out.println("Error ExpertSystem.findIndex");
			return null;
		}
		while (i < network.size()) {
			n = network.get(i);
			if (n.getIndex() == intS)
				return n;
			++i;
		}
		return null;
	}
	
	public static boolean parsing(String s) {
		
		int i = 0;
		int np = 0;
		
		s = s.replaceAll(" ", "");
		if (s.contains("!!"))
			return false;
		if (!s.matches("(([(]?)+([!]?)([(]?)?)+([A-Z])((([)]?)+[+*|^]([(]?)+([!]?)([(]?)+([A-Z]))?)+([)]?)+(=>)([A-Z])((([+][A-Z])?)+)?"))
			return false;
		while (i < s.length()) {
			if (s.charAt(i) == '(') {
				++np;
			}
			else if (s.charAt(i) == ')') {
				--np;
			}
			if (np < 0) {
				return false;
			}
			++i;
		}
		if (np != 0)
			return false;
		return true;
	}
	
	public static boolean isNum(String s) {
		return s.matches("[0-9]+");
	}
	
	public static boolean isLetter(String s) {
		return s.matches("[A-Z]");
	}
}