#include <iostream>
#include <string>
using namespace std;
int findCode(string s)
{
	int code = 0;

	for (int i = 0;i < s.size();i++)
		code += (int)(tolower(s[i]) - 'a' + 1);
	return code;
}
int main()
{
	string s, miniWord;
	int n, mini = -1;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	miniWord = s;
	mini = findCode(s);

	for (int i = 0;i < n - 1;i++)
	{
		getline(cin, s);
		int code = findCode(s);
		if (code < mini)
		{
			mini = code;
			miniWord = s;
		}
	}
	cout << miniWord << " " << mini << endl;
	return 0;
}