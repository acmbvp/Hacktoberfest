package strings_and_2DArrays;

import java.util.Scanner;

public class Highest_OccurringCharacter {

	public static char highestOccuringCharacter(String inputString)
	{
		
		int arr[] = new int [256];
		int i = 0;
		
		while(i < inputString.length())
		{
			int s1 = inputString.charAt(i);
			arr[s1]++;
			i++;
		}
		char ans = inputString.charAt(0);
		int count = arr[(int)ans];
		
		for(int j = 1; j < inputString.length(); j++)
		{
			if(count < arr[(int)inputString.charAt(j)])
			{
				count = arr[(int)inputString.charAt(j)];
				ans = inputString.charAt(j);
			}
		}
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String input = s.nextLine();
		System.out.println(Highest_OccurringCharacter.highestOccuringCharacter(input));
		s.close();
	}

}
