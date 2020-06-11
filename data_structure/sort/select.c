#include <stdio.h>

// 插入排序

/*
*/

void swap(int *n_1, int *n_2) {
	int temp = *n_1;	
	*n_1 = *n_2;
	*n_2 = temp;
}

void select_sort(int arr[], int len) {

}

void print_arr(int arr[], int len) {
	for(int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int arr[] = {5, 2, 4, 2, 5, 9, 1, 3, 3, 10, 8};
	select_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
