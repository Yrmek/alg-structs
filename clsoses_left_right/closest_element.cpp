#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nearestSmallerElements(const vector<int>& arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) { // left 
            s.pop();
        }
        //while (!s.empty() && arr[s.top()] >= arr[i]) { // right
        //    s.pop();
        //}

        if (!s.empty()) {
            result[i] = s.top();
        }

        s.push(i);
    }

    for (int i = 0; i < arr.size(); ++i) {
        cout << "For element " << arr[i] << ": ";
        if (result[i] != -1) {
            cout << "Nearest smaller element on the left is " << arr[result[i]] << " at index " << result[i] << endl;
        } else {
            cout << "No smaller element on the left" << endl;
        }
    }
}

int main() {
    vector<int> a = {6, 5, 9, 8, 7, 1, 2, 3, 5};
    nearestSmallerElements(a);
    return 0;
}