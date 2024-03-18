//Задача 4. Существует такое понятие как горный массив - массив размерности n, который удолетворяет следующим условиям :
//a[0] < a[1] < … < a[i]
//	a[i] > a[i + 1] > … > a[n]
//	Необходимо проанализировать поступающий массив и вернуть true, если массив является горным.
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 6;
void FillArray(int arr[])
{
	cout << " Enter elements of array :" << endl;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cin >> arr[i];
	}
}

bool IfMountain(int arr[])
{
	bool if_mountain = 0;
	if (arr[0] > arr[1]) return if_mountain;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if ((i + 1) == ARRAY_SIZE) break;
		if (!if_mountain && arr[i] < arr[i + 1]) continue;
		else
		{
			if (arr[i] > arr[i + 1]) if_mountain = 1;
			else return 0;
		}
	}
	return if_mountain;
}

void main()
{
	int array[ARRAY_SIZE]{};
	FillArray(array);
	if (IfMountain(array)) cout << " Araay is mountain";
	else cout << " Array is not mountain";
}