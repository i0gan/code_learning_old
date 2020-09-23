import java.util.ArrayList;

public class bubule {
	public static int size_ = 10;
	public static int[] sort(int[] arr) {
		for(int i = 0; i < arr.length; ++i) {
			for(int j = 0; j < (arr.length - i); ++j) {
				if(arr[i] < arr[j]) {
					arr[i] += arr[j];
					arr[j] = arr[i] - arr[j];
					arr[i] = arr[i] - arr[j];
				}
			}	
		}	
		return arr;
	}

	public static void print(int[] arr) {
		for(int i = 0; i < arr.length; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		int[] arr1 = new int[size_];
		int[] arr2 = null;
		for(int i = 0; i < size_; ++i)
			arr1[i] = (int)(100 +Math.random() * (100 + 1));

		System.out.println("before order:");
		print(arr1);
			
		arr2 = sort(arr1);
		System.out.println("after order:");
		print(arr2);
	}

};
