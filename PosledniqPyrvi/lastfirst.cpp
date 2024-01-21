#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define f first
#define s second
struct test {
	int order;
	int change;
	vector <pair<int, string>> result;
};
string solve(string word, const int& v)
{
	int n = word.size();
	for (int i = 0;i < v;i++) {
		word = word.substr(n - 1, 1) + word;
		word.erase(n, 1);
		//cout << "WORD " << word << endl;
	}
	return word;
}
bool sortChange(test a, test b)
{
	return a.change < b.change;
}
bool sortOrder(test a, test b)
{
	return a.order < b.order;
}
int main()
{
	vector <string> w;
	string s;
	int n, m1, t, x;
	test r[1000];
	cin >> n;
	cin.ignore();
	for (int i = 0;i < n;i++)
	{
		getline(cin, s);
		w.push_back(s);
	}
	cin >> t;
	int size = w[0].size();
	for (int j = 0;j < t;j++)
	{
		cin >> r[j].change >> m1;
		r[j].order = j;
		r[j].change %= size;
		for (int i = 0;i < m1;i++)
		{
			cin >> x;
			r[j].result.push_back(make_pair(x,""));
		}
	}
	sort(r, r + t, sortChange);
	int curr = 0;
	for (int i = 0;i < t;i++)
	{
		int change = r[i].change - curr;
		for (int j = 0;j < n;j++)
			w[j] = solve(w[j], change);
		sort(w.begin(), w.end());
		for (int j = 0;j < r[i].result.size();j++)
			r[i].result[j].second = w[r[i].result[j].first - 1];
		curr = r[i].change;
	}
	sort(r, r + t, sortOrder);
	for (int i = 0;i < t;i++)
	{
		for (int j = 0;j < r[i].result.size();j++)
			cout << r[i].result[j].second << endl;
		cout << endl;
	}
	return 0;
}