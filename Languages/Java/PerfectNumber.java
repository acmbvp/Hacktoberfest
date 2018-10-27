class PerfectNumber {
	public static void main(String[] args) {
		perfect p=new perfect();
		int n=Integer.parseInt(args[0]);
		boolean b=false;
		b=p.perfectNo(n);
		if(b==true)
		{
			System.out.println("No is perfect");
		}
		else
		{
			System.out.println("No is not perfect");
		}
	}
	boolean perfectNo(int n)
	{
		int sum=0,i;
		for(i=1;i<n;i++)
		{
			if(n%i==0)
			{
				sum=sum+i;
			}
		}
		if(sum==n)
		{
			return true;
		}
		return false;
	}
}
