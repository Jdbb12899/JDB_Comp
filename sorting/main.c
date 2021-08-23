#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void bubble_sort(int a[], int size);
void selection_sort(int a[], int size);
void insertion_sort(int a[], int size);
void insertion_sort_sentinel(int a[], int size);
void insertion_sort_sentinel_shift(int a[], int size);
void shell_sort(int a[], int size);
void quick_sort(int a[], int size);

int main(int argc, char* argv[]) {
	int i;
	int num[] = { 3,5,1,77,0 };
	for (i = 0; i < 5; ++i) {
		printf("%d\n", num[i]);
	}
	//bubble_sort(num, 5);
	//for (i = 0; i < 5; ++i) {
	//	printf("%d\n", num[i]);
	//}
	shell_sort(num, 5);
	for (i = 0; i < 5; ++i) {
		printf("%d\n", num[i]);
	}
	return 0;
}


void bubble_sort(int a[], int size) {
	//start in the beginning of the list
	//compare first pair of elements
	//if out of order- swap
	//move through the list
	//repeat operation
	int n, i;
	for (n = 0; n < size - 1; ++n) {
		for (i = 0; i < size - 1; ++i) {
			if (a[i] > a[i + 1]) {
				swap(&a[i], &a[i + 1]);
			}
		}
	}
}
void selection_sort(int a[], int size) {
	int i;
	int index_smallest;
	for (i = 0; i > size - 1; ++i) {
		index_smallest = find_index(a, size, i);
		swap(&a[i], &a[index_smallest]);
	}
}
int find_index(int a[], int size, int start_index) {
	int i;
	int index_min = start_index;
	for (i = start_index; i < size; ++i) {
		if (a[i] < a[index_min]) {
			index_min = 1;
		}
	}
	return index_min;
}
void insertion_sort(int a[], int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		j = i;
		while (j - 1 >= 0 && a[j] < a[j - 1]) {
			swap(&a[j - 1], &a[j]);
			j--;
		}
	}
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion_sort_sentinel(int a[], int size) {
	int i, j;
	swap(&a[0], &a[find_index(a, size, 0)]);
	for (i = 0; i < size; ++i) {
		j = i;
		while (a[j] < a[j - 1]) {
			swap(&a[j - 1], &a[j]);
			j--;
		}
	}
}

void insertion_sort_sentinel_shift(int a[], int size) {
	int i, j;
	int temp;
	swap(&a[0], &a[find_index(a, size, 0)]);
	for (i = 0; i < size; ++i) {
		j = i;
		temp = a[j];
		while (a[j] < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
			a[j] = temp;
		}
	}
}

void shell_sort(int a[], int size) {
	int i, j, gap;
	gap = size / 3 + 1;
	do {
		gap--;
		for (i = gap; i < size; ++i) {
			j = i;
			while (j - gap >= 0 && a[j] < a[j - gap]) {
				swap(&a[j - gap], &a[j]);
			}
		}
	}
		while (gap != 1);
}

void quick_sort(int a[], int size) {
	//chose pivot
	//put everything smaller than pivot on the left
	//everything larger on right of pivot
	int* left;
	int* right;
	int* pivot;
	pivot = &a[0];
	left = a;
	right = a + size - 1;
	if (size < 2)
		return;
	while (left < right) {
		//move right pointer
		while (right > left && *right > *pivot)
			right--;
		//move left pointer
		while (left < right && *left < *pivot)
			left++;
		if (left != right)
			swap(left, right);
	}
	swap(pivot, left);
	quick_sort(a, left - a);
	quick_sort(&a[left - a + 1], &a[size - 1] - right);
}