#include <iostream>
#include <cmath>
using namespace std;
int startTest();
int main()
{
	short t;
	cin >> t;
	for (int i = 0;i < t;i++)
		cout << startTest() << endl;
	return 0;
}
int findMax(const int arr[], const int& n, const int& k)
{
	int maxi = arr[0];
	for (int i = 1;i < n;i++)
		maxi = max(maxi, arr[i]);
	return maxi;
}
int check(const int arr[], const int& n, const int& size)
{
	int total = 0;
	for (int i = 0;i < n;i++)
		total += (arr[i] / size);
	return total;
}
int startTest()
{
	int n, k, arr[10000];
	cin >> n >> k;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	int maxi = findMax(arr, n, k);
	int left = 1;
	int right = maxi, ans = -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int total = check(arr, n, middle);
		if (total >= k)
		{
			ans = middle;
			left = middle + 1;
		}
		else  right = middle - 1;
	}
	return ans;
}