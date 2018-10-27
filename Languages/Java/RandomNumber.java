import java.util.Random;
class RandomNumber {
	public static void main(String[] args) {
		Random r=new Random();
		boolean[] b=new boolean[10];
		int count=0;
		int random;
		for(int i=1;count<=10;i++){
			random=(r.nextInt(10));
			if(b[random]==false){
			System.out.print(random+1+" ");
				b[random]=true;
				count++;
		 	}
		}
	}
}