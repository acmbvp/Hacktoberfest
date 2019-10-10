
//Given a integer as a input and replace all the '0' with '5' in the integer




import java.util.Scanner;
public class replace_them_all {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		long n=s.nextLong();;
		long temp=n;
		long rem=0;
		int pos=1;
		if(temp==0)
		{
			System.out.print(5);
		}
		else
		{	
			while(temp>0)
			{
				rem=temp%10;
				if(rem==0)
				{
					n=n+5*(long)Math.pow(10, pos-1);
				}
				temp=temp/10;
				pos++;
			}
			System.out.print(n);
		}
	}
}
