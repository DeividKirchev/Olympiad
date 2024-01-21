#include <iostream>
using namespace std;
int countSequences(int x, int n, int y) {
	if (n == 1) {
		return min(y, x);
	}
	int count = 0;
	for (int i = 0; i < x && i < y; i++) {
		count += countSequences(x, n - 1, y - i);
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int x, n, y;
		cin >> x >> n >> y;
		cout << countSequences(x, n, y) << endl;
	}

	return 0;
}