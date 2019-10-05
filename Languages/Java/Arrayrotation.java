import java.util.Scanner;

public class Main {
	
	public static int[] takeInput() {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		int arr[] = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = s.nextInt();
		}
		return arr;
	}
	
	public static void main(String[] args) {
		int[] arr = takeInput();
		System.out.print(CheckRotation.arrayRotateCheck(arr));
	}
}
public class CheckRotation {	

	public static int arrayRotateCheck(int[] arr){
		/* Your class should be named CheckRotation
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
		 * Taking input and printing output is handled automatically.
		 */
int n=arr.length;
   
      
      int min=arr[0];
      int min_index=-1;
     
      for(int i=0;i<n;i++){
           
        if(min>arr[i]){
          min=arr[i];
          min_index=i;
      }
      }
      return min_index;
	}
}
