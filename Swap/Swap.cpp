#include <iostream>
#include <cmath>
using namespace std;
int nod(int A, int B) {
	while (B != 0) {
		A %= B;
		swap(A, B);
	}
	return A;
}
void extended_euclid(long long a, long long b, long long& x1, long long& y1)
{
	long long q, r, x2, y2, t;
	x1 = 1; y1 = 0; x2 = 0; y2 = 1;
	while (b != 0)
	{
		q = a / b; r = a % b; a = b;b = r;
		t = x2; x2 = x1 - q * x2; x1 = t;
		t = y2; y2 = y1 - q * y2; y1 = t;
	}
}

void solve()
{
	long long a, b, d, x, c, x0, y0, p;
	cin >> a >> b >> c >> p;
	d = nod(a, b);
	//cout << d << endl;
	if (c % d == 0)
	{
		extended_euclid(a, b, x0, y0);
		x0 *= c / d;
		y0 *= c / d;
		double k = (double)(p - x0) * d / b;
		k = round(k);
		x = x0 + b / d * k;
		cout << x << " " << (c - a * x) / b << endl;
	}
	else cout << "0 0" << endl;
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
		solve();
	return 0;
}