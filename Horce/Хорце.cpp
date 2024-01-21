#include <iostream>
#include <string>
using namespace std;
int check(const string& s, const int& start) {
	//cout << start << endl;
	int length = s.size();
	int count = 0;
	int open = 0;
	for (int i = start;i < start + length;i++)
	{
		if (s[i % length] == ')')
		{
			if (open == 0)return 0;
			open--;
		}
		else open++;
		if (open == 0) count++;
	}
	return open == 0 ? count : 0;
}
int findStart(const string& s)
{
	int length = s.size();
	int open = 0;
	int mini = 1000001, miniPos;
	for (int i = 0;i < length;i++)
	{
		if (s[i] == ')') open--;
		else open++;
		if (open < mini)
		{
			mini = open;
			miniPos = i;
		}
	}
	return miniPos + 1;
}
int solve()
{
	string s;
	getline(cin, s);
	return check(s, findStart(s));
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 0;i < t;i++)
		cout << solve() << endl;
	return 0;
}