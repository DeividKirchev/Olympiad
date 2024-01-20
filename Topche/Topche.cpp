#include <iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	short guesses[3] = { 0,0,0 };
	short pos[3] = { 0,1,2 };
	for (int i = 0;i < n;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		swap(pos[a], pos[b]);
		guesses[pos[c]]++;
	}
	cout << max(guesses[0], max(guesses[1], guesses[2])) << endl;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
		solve();
	return 0;
}