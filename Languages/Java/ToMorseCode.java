import java.util.Scanner;

public class Morse {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter text to convert");
		String plainText = input.nextLine().toUpperCase();
		char[] plainTestSplit = plainText.toCharArray();
		String[][] morse = new String[][]{
				{"A","\u2022\u2014"},	{"B","\u2014\u2022\u2022\u2022"},{"C","\u2014\u2022\u2014\u2022"},{"D","\u2014\u2022\u2022"},{"E","\u2022\u2022\u2014\u2022"},
				{"F","\u2022\u2022\u2014\u2022"},{"G","\u2014\u2014\u2022"},{"H","\u2022\u2022\u2022\u2022"},{"I","\u2022\u2022"},{"J","\u2022\u2014\u2014\u2014"},{"K","\u2014\u2022\u2014"},{"L","\u2022\u2014\u2022\u2022"},{"M","\u2014\u2014"},{"N","\u2014\u2022"},
				{"O","\u2014\u2014\u2014"},{"P","\u2022\u2014\u2014\u2022"},{"Q","\u2014\u2014\u2022\u2014"},{"R","\u2022\u2014\u2022"},{"S","\u2022\u2022\u2022"},{"T","\u2014"},{"U","\u2022\u2022\u2014"},{"V","\u2022\u2022\u2022\u2014"},{"W","\u2022\u2014\u2014"},
				{"X","\u2014\u2022\u2022\u2014"},{"Y","\u2014\u2022\u2014\u2014"},{"Z","\u2014\u2014\u2022\u2022"},
		};
		
		
		for (int i = 0; i < plainText.length(); i++) {
			for (int k = 0; k < morse.length; k++) {
				if (plainTestSplit[i] == morse[k][0].charAt(0)) {
					System.out.print(morse[i][1]);
					System.out.print("   ");
				}
			}
		}
		System.out.println("");
	}
}
