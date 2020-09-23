public class shell {
	public static int size_ = 10;
	public static int[] sort(int[] arr) {
		int j = 0, t;
		for(int r =  arr.length / 2; r >= 1; r /= 2) {
			for (int i = r; i < arr.length; ++i) {
				t = arr[i];
				j = i - r;
				while(j >= 0 && t < arr[j]) {
					arr[j + r] = arr[j];
					j -= r;
				}
				arr[j + r] = t;
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

		for(int i = 0; i < arr1.length; ++i)
			arr1[i] = (int)(Math.random() * (100 + 1));

		System.out.println("before sort");
		print(arr1);

		arr2 = sort(arr1);
		System.out.println("after sort");
		print(arr2);
	}
};
