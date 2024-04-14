#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main()
{
	cout << "Enter value of n and m :" << endl;
	int m = 0, n = 0;
	cin >> n >> m;
	vector<vector<int>> table(n, vector<int>(n,0)) ;
	table = { {1,3,2},{3,2,1},{2,1,3} };
	vector<int> reagents(m, 0);

	/*cout << "Enter matrix :" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> table[i][j];
		}
	}*/

	cout << "Enter numbers of reagents :" << endl;
	for (int i = 0; i < m; ++i) {
		cin >> reagents[i];
	}
	int num = 0;
	for (int i = 0; i < m - 1; ++i) {
		num = reagents[i + 1];
		reagents[i + 1] = table[reagents[i] - 1][num - 1];
	}
	cout << "Result : " << reagents[m - 1];
}
