
#include <iostream>
#include <stack>

using namespace std;

const int SIZE = 10;

void findNearestSmallerElements(int arr[]) 
{
    stack<int> s; 
    int result[SIZE]; // stores the index of nearest smaller element on the right
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] <<" ";
    }
    cout << endl;

    int index = 0;

    for (int i = SIZE - 1; i >= 0; --i)
    {
        index = i;
        s.push(i);
        while(s.top() )

    }
    cout << "ans: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int arr[] = { 6, 5, 9, 8, 7, 1, 2, 3, 5 };
    findNearestSmallerElements(arr);
    return 0;
}
