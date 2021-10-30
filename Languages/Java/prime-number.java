public class Prime {
    public static void main(String[] args) {
        int num = 29;
        boolean flag = true;
      	if(n==1)
			flag= false;

		if(n==2 || n==3)
			flag = true;

		if(n%2==0 || n%3==0)
			flag= false;

		for(int i=5; i*i<=n; i=i+6)
		{
			if(n % i == 0 || n % (i + 2) == 0)
				flag= false; 
		}

        if (!flag)
            System.out.println(num + " is a prime number.");
        else
            System.out.println(num + " is not a prime number.");
    }
}
