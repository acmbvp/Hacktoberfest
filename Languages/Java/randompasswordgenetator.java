import java.util.Random;

public class RandomPasswordGenerator {

	static public char[] getPassword(int len) {
		
		String capital_letters ="QWERTYUIOPASDFGHJKLZXCVBNM";
		String small_letters="qwertyuiopasdfghklzxcvbnm";
		String special_chars="~!@#$%^&*()_+=-`][{}|;'<>?/.,";
		
		String values=capital_letters+small_letters+special_chars;
		
		char password[]=new char[len];
		Random random=new Random();
		
		for(int i=0;i<len;i++) {
			
			password[i]=values.charAt(random.nextInt(values.length()));
		}
		
		return password;
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int length=8;
		System.out.println(getPassword(length));

	}

}
