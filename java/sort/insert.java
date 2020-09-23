public class insert {
	public static int size_ = 10;
	public static int[] sort(int[] arr) {
		for(int i = 1; i < arr.length; ++i) {
			int t = arr[i];	// unorder arr
			int j;
			// move arr to back
			for(j = i - 1; j >= 0 && t < arr[j]; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = t;
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

		for(int i = 0; i < arr1.length; ++i)
			arr1[i] = (int)(Math.random() * (100 + 1));

		System.out.println("before sort");
		print(arr1);

		arr2 = sort(arr1);
		System.out.println("after sort");
		print(arr2);
	}
};
