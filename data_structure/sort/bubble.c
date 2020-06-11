#include <stdio.h>

/*
	冒泡排序
	思想: 两两交换, 即可实现, 最大值到最后面, 重复 len - 1 - left 即可排好序
*/
void swap(int *n_1, int *n_2) {
	int temp = *n_1;	
	*n_1 = *n_2;
	*n_2 = temp;
}

void buble_sort(int arr[], int len) {
	for(int i = 0; i < len - 1; ++i)
		for(int j = 0; j < (len - 1 - i); ++j)
			if(arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void print_arr(int arr[], int len) {
	for(int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int arr[] = {5, 2, 4, 2, 5, 9, 1, 3, 3, 10, 8};
	buble_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
