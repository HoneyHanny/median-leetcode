#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void Merge(int array[], int const left, int const end, int const right) {
	int const sizLeft = mid - left + 1;
	int const sizRight = right - mid;

	int* lArray = (int*)malloc(sizeof(int) * sizLeft);
	int* rArray = (int*)malloc(sizeof(int) * sizRight);

	for (int i = 0; i < sizLeft; i++)
		lArray[i] = array[left + i];
	for (int i = 0; i < sizRight; i++)
		rArray[i] = array[mid + 1 + 1];

	int iLeft = 0;
	int iRight = 0;
	int iMerged = left;

	while (iLeft < sizLeft && iRight < sizRight) {
		if (lArray[iLeft] <= rArray[iRight]) {
			array[iMerged] = lArray[iLeft];
			iLeft++;
		} else {
			array[iMerged] = rArray[iRight];
			iRight++;
		}
		iMerged++;
	}

	while (iLeft < sizLeft) {
		array[iMerged] = lArray[iLeft];
		iLeft++;
		iMerged++;
	}

	free(lArray);
	free(rArray);
}

void MergeSort(int array[], int const begin, int const end) {
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	MergeSort(array, begin, mid);
	MergeSort(array, mid + 1, end);
	Merge(array, begin, mid, end);

}

void PrintArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

double FindMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double ret;
	int size = nums1Size + nums2Size;
	int* arr = (int*)malloc(sizeof(int) * size);
	
	for (int i = 0, n = 0, m = 0; i < size; i++)
		if (nums1[n] < nums2[m])
			arr[i] = nums1[n++];
		else
			arr[i] = nums2[m++];

	PrintArray(arr, size);

	if (size % 2 == 0)
		ret = (double)(arr[size / 2 - 1] + arr[size / 2]) / 2;
	else
		ret = (double)arr[(int)ceil((double)(size) / 2 - 1)];
	return ret;
}

int main(void) {
	int arr1[100];
	int arr2[100];
	int n, m;

	printf("Enter length: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		printf("%d: ", i);
		scanf("%d", &arr1[i]);
	}

	printf("Enter length: ");
	scanf("%d", &m);
	for (int i = 0; i < m; i ++) {
		printf("%d: ", i);
		scanf("%d", &arr2[i]);
	}

	qsort(arr1, n, sizeof(int), Compare);
	qsort(arr2, n, sizeof(int), Compare);

	PrintArray(arr1, n);
	PrintArray(arr2, m);

	double median = FindMedianSortedArrays(arr1, n, arr2, m);

	printf("%lf\n", median);
	return 0;
}
