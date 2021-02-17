#include<iostream>
using namespace std;
void merge(int arr[], int s, int m, int r)
{
	int i, j, k;
	int n1 = m - s + 1;// First subarray is arr[l..m]
	int n2 = r - m;// Second subarray is arr[m+1..r]
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[s + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = j = 0;
	k = s;

	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int s, int r)
{
	if (s < r)
	{
		int m = s + (r - s) / 2;

		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, r);

		merge(arr, s, m, r);
	}
}



void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}
int main()
{

		int arr[] = { 60,10,20,5,60,70 };
		int n = sizeof(arr) / sizeof(arr[0]);//24/4=6

		mergeSort(arr, 0, n-1);
		print(arr,n);
	return 0;

	}
