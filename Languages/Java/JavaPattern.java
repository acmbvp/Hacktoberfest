class JavaPattern {
		public static void main(String[] args) {
		
		int temp,n=5,x;
		for(int i=1;i<=n;i++)
		{
			temp=i;x=n-1;
			for(int j=1;j<=n;j++)
			{
				if(j<=i)
				{
					System.out.print(temp+" ");
				}
				temp=temp+x;
				x--;
			}
			System.out.println();
		}
	}
}