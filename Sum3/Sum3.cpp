#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int solve(const int& n, const int& m)
{
	int arr[104];
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int closest = arr[0] + arr[1] + arr[n - 1];
	for (int i = 0;i < n - 2;i++)
	{
		int left = i + 1, right = n - 1;
		while (left < right)
		{
			int sum = arr[i] + arr[left] + arr[right];
			if (sum == m) return sum;

			if (abs(m - sum) < abs(m - closest) && sum < m) closest = sum;
			if (sum > m)right--;
			else left++;
		}

	}
	return closest;
}
int main()
{
	int n, m;
	while (true)
	{
		cin >> n;
		if (n > 3 && n < 101)
		{
			cin >> m;
			cout << solve(n, m) << endl;
		}
		else break;
	}
	return 0;
}