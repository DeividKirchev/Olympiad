#include <iostream>

using namespace std;

int countSequences(int X, int N, int Y) {
	if (N == 0) {
		return 1;
	}

	int count = 0;
	for (int i = 0; i < X && i < Y; i++) {
		count += countSequences(X, N - 1, Y - i);
	}

	return count;
}

int main() {
	
	for (int n = 1; n < 20; n++) {}
		for (int y = 3;y < 30;y++)
		{
			for (int x = 2;x < y;x++)
			{
				int result = countSequences(x, y, n);
				cout << result << " ";
			}
			cout << "|";
		}
		cout << endl;
	}

	return 0;
}