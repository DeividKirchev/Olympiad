#include <iostream>
using namespace std;

long long perm(int n)
{
	if (n <= 1)return 1;
	return n * perm(n - 1);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		int x;
		cin >> x;
		cout << perm(x - 1) << endl;
	}
	return 0;
}