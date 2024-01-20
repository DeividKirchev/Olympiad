#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double diagonal = 1.414;
double calculate(double x, double y, double x1, double y1)
{
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
double solve(int x1, int y1)
{
	double x = x1, y = y1, l;
	int d;
	while (true)
	{
		cin >> d >> l;
		if (d == -1 && l == -1) return calculate(x, y, x1, y1);
		switch (d) {
		case 1:
			y += l;
			break;
		case 2:
			y += (l / diagonal);
			x += (l / diagonal);
			break;
		case 3:
			x += l;
			break;
		case 4:
			y -= (l / diagonal);
			x += (l / diagonal);
			break;
		case 5:
			y -= l;
			break;
		case 6:
			y -= (l / diagonal);
			x -= (l / diagonal);
			break;
		case 7:
			x -= l;
			break;
		case 8:
			y += (l / diagonal);
			x -= (l / diagonal);
			break;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	for (int i = 0;i < t;i++) {
		int x1, y1;
		cin >> x1 >> y1;
		cout << solve(x1, y1) << endl;
	}
	return 0;
}