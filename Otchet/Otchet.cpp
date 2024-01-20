#include <iostream>
using namespace std;
int findPrev(const int arr[], const int index)
{
	static int found[100000];
	int i = index - 1;
	while (true)
	{
		if (i == -1)return 0;
		//cout << arr[i] << " " << arr[index] << endl;
		if (arr[i] < arr[index])
		{
			found[index] = i + 1;
			return found[index];
		}
		if (arr[found[i]-1] < arr[index] || found[i] == 0)
		{
			found[index] = found[i];
			return found[index];
		}
		else i--;
	}
}
int main()
{
	int n;
	cin >> n;
	int arr[100000];
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	for (int i = 0;i < n - 1;i++)
		cout << findPrev(arr, i) << " ";
	cout << findPrev(arr, n - 1);
	return 0;
}