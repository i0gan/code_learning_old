public class select {
	public static int size_ = 10;
	public static int[] sort(int[] arr) {
		for(int i = 0; i < arr.length; ++i) {
			int min_p = i;
			for(int j = i; j < arr.length; ++j) {
				if(arr[min_p] > arr[j]) {
					min_p = j;
				}
			}

			//如果是最小是自己, 不用交换
			if(i == min_p) 
				continue;

			arr[i] += arr[min_p];
			arr[min_p] = arr[i] - arr[min_p];
			arr[i] = arr[i] - arr[min_p];
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
