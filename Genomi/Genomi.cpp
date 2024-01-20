#include <iostream>
#include <cstring>
using namespace std;
int compare(char s1[], char s2[], const int& pos)
{
	int br = 0;
	const int length = strlen(s2);
	for (int i = 0;i < length; i++)
		if (s1[i] == s2[(i + pos) % length])br++;
	//for (int i = 0;i < length;i++)
	//	cout << s1[i];
	//cout << " ";
	//for (int i = 0;i < length;i++)
	//	cout << s2[(i + pos) % length];
	//cout << endl;
	return br;
}
void solve(char s1[], char s2[])
{
	int maxi = 0;
	const int length = strlen(s2);
	for (int i = 0;i < length;i++)
		maxi = max(maxi, compare(s1, s2, i));
	cout << maxi << endl;
}
int main()
{
	char s1[200], s2[200];
	while (cin >> s1 >> s2)
	{
		solve(s1, s2);
	}
	return 0;
}