//Write a function that returns its inverse, where inverse is defined as follows

//Inverse of 32145 is 12543. In 32145, “5” is at 1st place, therefore in 12543, “1” is at 5th place; in 32145, “4” is at 2nd place, therefore in 12543, “2” is at 4th place.



import java.util.Scanner;
public class inverse_of_a_number {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a=s.nextInt();
		int pos=1;
		int sum=0;
		int rem=0;
		while(a>0)
		{
			rem=a%10;
			sum=sum+pos*(int)Math.pow(10, rem-1);
			a=a/10;
			pos++;
		}
		System.out.println(sum);
	}
}
