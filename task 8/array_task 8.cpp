//«адача 8. —уществует массив состо€щий из чисел в диапазоне[1, n].Ќеобходимо проанализировать массив и вернуть другой массив, состо€щий из чисел в диапазоне[1, n], пропущенных в изначальном массиве.
//Input :
//[5, 2, 4, 8, 6, 1]
//Output :
//[3, 7]
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

void FillArray(int arr[] , int n)
{
	cout << " Enter elements of array :" << endl;
	int element = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cin >> element;
		if (element > n || element <= 0)
		{
			cout << " You entered value > n" << endl;
			--i;
			continue;
		}
		arr[i] = element;
	}
}

void UniqueNumbers(int arr[],int* unique_arr, int n)
{
	bool* if_unique = new bool[n];
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if_unique[arr[i]] = 0;
	}
	int j = 0;
	for (int i = 1; i < n; ++i)
	{
		if (if_unique[i])
		{
			unique_arr[j] = i;
			j++;
		}
	}
	delete[] if_unique;
}

void main()
{
	int n = 0;
	cout << "Enter range n of numbers :" << endl;
	cin >> n;
	++n;
	int array[ARRAY_SIZE]{};
	int* unique_arr = new int[n] {};
	FillArray(array, n);
	UniqueNumbers(array,unique_arr,n);
	for (int i = 0; i < n; ++i)
	{
		if (unique_arr[i] == 0) break;
		cout << " |" << unique_arr[i] << "|";
	}
	delete[] unique_arr;
}