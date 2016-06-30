#include<stdlib.h>
//#include<stdio.h>

void merge(int *arr, int start, int middle, int end)
{
	int *temp, index = 0;
	temp = (int*)malloc(sizeof(int)*(end - start + 1));
	/*for (int i = start; i <= end; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/
	int i = start, j = middle + 1;
	while (i <= middle && j <= end)
	{
		temp[index++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}
	while (i <= middle)
	{
		temp[index++] = arr[i++];
	}
	while (j <= end)
	{
		temp[index++] = arr[j++];
	}
	for (int k = 0, i = start; k < index; i++, k++)
	{
		arr[i] = temp[k];
	}
	free(temp);
}


void merge_sort(int *arr, int start, int end)
{
	if (start == end)
	{
		return;
	}
	int middle;
	middle = (start + end) / 2;
	/*for (int i = start; i <= end; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/
	merge_sort(arr, start, middle);
	merge_sort(arr, middle + 1, end);
	merge(arr, start, middle, end);
	/*for (int i = start; i <= end; i++)
	{
	printf("%d ", arr[i]);
	}
	printf("\n");*/
}