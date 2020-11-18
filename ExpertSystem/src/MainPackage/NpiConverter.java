package MainPackage;
import java.util.ArrayList;

public class NpiConverter {

	
	static String convert(String npi, String calcul) {

		ArrayList<String>	pile = new ArrayList<String>();
		int					i = 0;
		int					j = 0;
		int					k = 0;
		int					l = 0;
		calcul = calcul.replaceAll(" ", "");
		while (i < calcul.length())
		{
			if (i < calcul.length() && calcul.charAt(i) == ')')
			{
				
				pile.add(")");
				j = pile.size() - 1;
				while (!pile.get(j).equals("("))
					--j;
				k = j;
				while (j < pile.size())
				{
					if (pile.get(j).equals("!"))
					{
						npi = npi.concat(pile.get(j) + " ");
						pile.remove(j);
						j = k;
					}
					++j;
				}
				j = k;
				while (j < pile.size())
				{
					if (pile.get(j).equals("+"))
					{
						npi = npi.concat(pile.get(j) + " ");
						pile.remove(j);
						j = k;
					}
					++j;
				}
				j = k;
				while (j < pile.size())
				{
					if (pile.get(j).equals("|"))
					{
						npi = npi.concat(pile.get(j) + " ");
						pile.remove(j);
						j = k;
					}
					++j;
				}
				j = k;
				while (j < pile.size())
				{
					if (pile.get(j).equals("^"))
					{
						npi = npi.concat(pile.get(j) + " ");
						pile.remove(j);
						j = k;
					}
					++j;
				}
				j = k;
				l = i;
				while (calcul.charAt(l) != '(')
					--l;
				if (l > 0 && calcul.charAt(l - 1) == '!')
				{
					npi = npi.concat(pile.get(j - 1) + " ");
					pile.remove(j - 1);
					--j;
				}
				pile.remove(k);
				pile.remove(pile.size()-1);
			}
			if (i < calcul.length() && calcul.charAt(i) == '(')
			{
				pile.add("(");
			}
			if (i < calcul.length() && Character.isAlphabetic(calcul.charAt(i)))
			{
				npi = npi.concat(calcul.charAt(i) + " ");
				if (i < calcul.length() - 1 && calcul.charAt(i + 1) != ')')
					++i;
			}
			if (i < calcul.length() && isOperator(calcul.charAt(i)))
			{
				if (calcul.charAt(i) == '!')
				{

					if (calcul.charAt(i + 1) != '(') {//=============================
						npi = npi.concat(calcul.charAt(i + 1) + " ");//==============
						npi = npi.concat(calcul.charAt(i) + " ");//==================
						++i;//=======================================================
					}
					else {
						pile.add(calcul.substring(i, i + 1));
					}
				}
				else
					pile.add(calcul.substring(i, i + 1));
			}
				++i;
		}
		j = 0;
		while (j < pile.size())
		{
			if (pile.get(j).equals("!"))
			{
				npi = npi.concat(pile.get(j) + " ");
				pile.remove(j);
				j = 0;
			}
			else
				++j;
		}
		j = 0;
		while (j < pile.size())
		{
			if (pile.get(j).equals("+"))
			{
				npi = npi.concat(pile.get(j) + " ");
				pile.remove(j);
				j = 0;
			}
			else
				++j;
		}
		j = 0;
		while (j < pile.size())
		{
			if (pile.get(j).equals("|"))
			{
				npi = npi.concat(pile.get(j) + " ");
				pile.remove(j);
				j = 0;
			}
			else
				++j;
		}
		j = 0;
		while (j < pile.size())
		{
			if (pile.get(j).equals("^"))
			{
				npi = npi.concat(pile.get(j) + " ");
				pile.remove(j);
				j = 0;
			}
			else
				++j;
		}
		pile.clear();
		return npi;
	}

	static boolean isOperator(char c)
	{
		if (c == '!' || c == '+' || c == '|' || c == '^')
			return (true);
		else
			return (false);
	}
}
