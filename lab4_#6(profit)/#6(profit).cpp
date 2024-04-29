#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

void showVector(vector<short>& a)
{
	for (vector<short>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it <<" ";
	cout << endl;
}

void showVectors(vector <short> sellers, vector<short> buyers)
{
	cout << "sellers : ";
	showVector(sellers);
	cout << "buyers : ";
	showVector(buyers);
	cout << endl;
}

void fillByUser(vector<short>& sellers, vector<short>& buyers)
{
	cout << " enter N values of sell prices" << endl;
	for (int i = 0; i < sellers.size(); ++i) {
		cin >> sellers[i];
	}
	cout << " enter M values of buying prices" << endl;
	for (int i = 0; i < buyers.size(); ++i) {
		cin >> buyers[i];
	}
}
void fillByRand(vector<short>& sellers , vector<short>& buyers)
{
	for (int i = 0; i < sellers.size(); ++i) {
		sellers[i] = rand() % 109;
	}
	for (int i = 0; i < buyers.size(); ++i) {
		buyers[i] = rand() % 109;
	}
	;
}
int getProfit(vector<short>& sellers, vector<short>& buyers)
{
	sort(sellers.begin(), sellers.end());
	sort(buyers.rbegin(), buyers.rend());
	showVectors(sellers, buyers);
	int minVecSize = 0;
	if (sellers.size() >= buyers.size()) minVecSize = buyers.size();
	else minVecSize = sellers.size();
	int profit = 0;
	for (int i = 0; i < minVecSize; ++i) {
		if (sellers[i] > buyers[i]) break;
		profit += buyers[i] - sellers[i];
	}
	return profit;
}

enum Chose {
	ByUser = 1,
	ByRand
};

int main()
{
	srand(time(NULL));
	cout << "Enter values of N sellers and M byers" << endl;
	int m, n;
	cin >> n >> m;
	vector<short> sellers(n);
	vector<short> buyers(m);
	cout << "Enter 1 to fill values by user;" << endl
		<< "Enter 2 to fill values by random." << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case ByUser:
		fillByUser(sellers, buyers);
		break;
	case ByRand:
		fillByRand(sellers, buyers);
		break;
	}
	cout << "Initial vector" << endl;
	showVectors(sellers, buyers);
	cout << "Max profit that you can get : " << getProfit(sellers , buyers);
}