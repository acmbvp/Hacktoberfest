package Strings;

import java.util.Scanner;

public class ultra_fast_mathmatician {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- > 0) {
			String a = s.next();
			String b = s.next();
			System.out.println(ultra(a, b));
		}
		s.close();
	}

	public static String ultra(String a, String b) {
		int i = 0;
		int j = 0;
		String n = "";
		while (i < a.length()) {
			if (a.charAt(i) == b.charAt(j)) {
				n = n + "0";
			} else {
				n = n + "1";
			}
			i++;
			j++;
		}
		return n;
	}
}
