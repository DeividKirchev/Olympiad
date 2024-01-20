#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double DIAGONAL = sqrt(1.0 / 2);
double calculate1(int x, int y, int x1, int y1, int d1, int d2)
{
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) + abs(d1 - d2) + min(abs(d1), abs(d2)) * DIAGONAL;
}
double solve1(int x1, int y1)
{
	int x = x1, y = y1, d1 = 0, d2 = 0;
	int d, l;
	while (true)
	{
		cin >> d >> l;
		if (d == -1 && l == -1) return calculate1(x, y, x1, y1, d1, d2);
		switch (d) {
		case 1:
			y += l;
			break;
		case 2:
			d1 += l;
			break;
		case 3:
			x += l;
			break;
		case 4:
			d2 -= l;
			break;
		case 5:
			y -= l;
			break;
		case 6:
			d1 -= l;
			break;
		case 7:
			x -= l;
			break;
		case 8:
			d2 += l;
			break;
		}
	}
}
int test()
{
	int t;
	cin >> t;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	for (int i = 0;i < t;i++) {
		int x1, y1;
		cin >> x1 >> y1;
		cout << solve1(x1, y1) << endl;
	}
	return 0;
}