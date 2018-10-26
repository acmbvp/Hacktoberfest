
public class BubbleSort {

	public static void main(String[] args) {
		int[] numbers = {5,6,4,9,11,3,2,7,1,8,10,12};
		for(int x = 0; x < numbers.length - 1; x++) {
			for(int y = 0; y < numbers.length - x - 1; y++) {
				if(numbers[y] > numbers[y + 1]) {
					int temp = numbers[y];
					numbers[y] = numbers[y + 1];
					numbers[y + 1] = temp;
				}
			}
		}
		
		//print array - should be smallest to largest
		for(int i : numbers) {
			System.out.println(i);
		}
	}

}
