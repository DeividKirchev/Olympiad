#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int findAll(vector<int>v, const int& over, const int& start)
{
	int count = 0;
	for (int i = start;i < v.size();i++)
		if (v[i] > over)count++;
	return count;
}
int main()
{
	set<int> unique;
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		unique.insert(x);
	}
	for (const int x : unique)
		v.push_back(x);

	sort(v.begin(), v.end());
	/*for (int i = 0;i < v.size();i++)cout << v[i] << " ";
	cout << endl;*/

	int count = 0;
	for (int i = 0;i < v.size() - 1;i++)
		for (int j = i+1;j < v.size();j++) {
			int f = findAll(v, v[i] + v[j], j + 1);
			//cout << v[i] << " " << v[j] << endl;
			count += f;

		}
	cout << count << endl;
	return 0;
}