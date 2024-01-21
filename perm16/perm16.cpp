#include <iostream>
#include <string>
using namespace std;
#define TOOBIG 1000000007

int toDigit(char c)
{
	return ((int)(c - '0'));
}
bool isDivisible(string s)
{
	int n = toDigit(s[s.size() - 1]) + 10 * toDigit(s[s.size() - 2]) + 100 * toDigit(s[s.size() - 3]) + 1000 * toDigit(s[s.size() - 4]);
	return n % 16 == 0;
}
long long perm(int n)
{
	if (n <= 1) return 1;
	return (n * perm(n - 1)) % TOOBIG;
}
int main()
{
	int n;
	cin >> n;
	if (n == 3)
	{
		cout << 0 << endl;
		return 0;
	}
	long long count = 0;
	for (int i1 = 1;i1 <= n;i1++)
		for (int i2 = 1;i2 <= n;i2++)
		{
			if (i2 == i1)continue;
			for (int i3 = 1;i3 <= n;i3++)
			{
				if (i3 == i1 || i3 == i2)continue;
				for (int i4 = 1;i4 <= n;i4++)
				{
					if (i4 == i1 || i4 == i2 || i4 == i3)continue;
					string s = to_string(i1) + to_string(i2) + to_string(i3) + to_string(i4);
					if (isDivisible(s))
					{
						count += perm(n - 4);
						count %= TOOBIG;
					}
				}
			}
		}
	cout << count << endl;
	return 0;
}