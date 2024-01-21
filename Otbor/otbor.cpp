#include <iostream>
using namespace std;
long long perm(int n)
{
	if (n <= 1)return 1;
	return n * perm(n - 1);
}
long long combinations(int n, int k)
{
	return perm(n) / (perm(k) * perm(n - k));
}
int main()
{
	int t;
	cin >> t;
	int all, allM, allF, going, goingM, goingF;
	for (int i = 0;i < t;i++)
	{
		cin >> all >> allM >> allF >> going >> goingM >> goingF;
		if (all != allM + allF || going != goingM + goingF) {
			cout << 0 << endl;
			continue;
		}
		cout << combinations(allM, goingM) * combinations(allF, goingF) << endl;
	}

	return 0;
}