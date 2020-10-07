package algorithms;

public class QuickSort {
	
	public static void quickSort(int[] arr,int low ,int high) {
		if(low < high) {
			int pivot = partition(arr,low,high);
			quickSort(arr, low, pivot-1);
			quickSort(arr, pivot+1, high);
		}
	}

	private static int partition(int[] arr, int low, int high) {
		int start=low;
		int pivot = arr[low];
		while(start<high) {
			while(arr[start]<=pivot) {
				start++;
			}
			while(arr[high]>pivot) {
				high--;
			}
			if(start<high) {
				int temp = arr[start];
				arr[start] = arr[high];
				arr[high] = temp;
				return high;
			}
		}
		
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		return high;
	}

}
