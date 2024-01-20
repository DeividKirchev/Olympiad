#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long fact(int x)
{
	if (x == 0 || x == 1) return 1;
	else return x * fact(x - 1);
}
void pushToFront(string& str, size_t index) {
	if (index < str.length()) {
		string rotatedPart = str.substr(index, 1);

		str.erase(index, 1);

		str.insert(str.begin(), rotatedPart[0]);
	}
}
string solve()
{
	int S;
	long long x;
	long long a[26];
	string s, s1, s2;
	cin >> S >> x;
	for (char c = 'a'; c < 'a' + S;c++)
		s += c;
	for (int i = 1;i <= S;i++)
	{
		a[i] = fact(i);
		if (x <= a[i])
		{
			s1 = s.substr(0, s.length() - i);
			s2 = s.substr(s.length() - i, i);
			break;
		}
	}
	const int size = s2.length();
	x--;
	for (int i = 1;i <= size;i++)
	{
		
		pushToFront(s2, x / a[size - i]);
		x %= a[size - i];

		s1 += s2[0];
		s2.erase(0, 1);
	}
	return s1;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
		cout << solve() << endl;
	return 0;
}