#include<iostream> 
#include<stack> 
#include<string> 

using namespace std; 

int main()
{
	string s; stack<char> b; cin >> s;
	for (auto c = s.begin(); c != s.end(); c++)
	{
		if (!b.empty() && (*c == ')' && b.top() == '(' ||
			*c == ']' && b.top() == '[' ||
			*c == '}' && b.top() == '{'))
			b.pop();
		else if (*c == ')' || *c == ']' || *c == '}')
		{
			cout << "NO"; return 0;
		}
		else
			b.push(*c);
	}
	b.empty() ? cout << "YES" : cout << "NO"; return 0;
}