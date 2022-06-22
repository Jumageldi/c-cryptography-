#include <iostream>
#include <ctime>
using namespace std;
long long modpow(long long a, long long b, long long c) {
	int o = 1;
	while (b) {
		if (b % 2)
			o = (o * a) % c;
		a = (a * a) % c;
		b /= 2;
	}
	return o;
	cout << " " << o << endl;
}
long long reverseMod(int a, long long b)
{
	long long d = 0, f = a, e = 0, o = 0;
	long long i;
	if (a < 0)
	{
		a = a * -1;
		f = f * -1;
		o++;
	}
	while (d == 0)
	{
		if (f < 0)
		{
			f = f * -1;
		}
		i = modpow(f, 1, b);
		if (i == 1)
		{
			d++;
		}
		else
		{
			f = f + a;
		}
		e++;
		if (e > 100000) {
			cout << "you are dumn  " << e << endl;
		}
	}
	if (o > 0)
	{
		return e;
	}
	else
		return e;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");

	cout << "start program" << endl;
	const char* m = "magjan";
	int n = strlen(m);
	int* M = new int[n];
	int hM = 0, h0 = 100, hN = 187;
	cout << "text m:" << m << endl;
	//cin>>m;
	for (int i = 0; i < n; i++) {
		M[i] = m[i] - 96;
		cout << M[i] << " ";
	}cout << endl;
	hM = hM + h0;
	for (int i = 0; i < n; i++) {
		int temp1 = hM + M[i];
		hM = (temp1 * temp1) % hN;
		//cout << temp1 << " ";
	}
	//hM = 29;
	cout << "hash:" << hM << endl;
	int p, q, N;
	p = 11;
	q = 19;
	N = p * q;
	int c = modpow(hM, 2, N);
	cout << "c=" << c << endl;
	int m1[4], M1[4];
	m1[0] = modpow(c, (p + 1) / 4, p);
	int temp1 = (p + 1) / 4;
	int temp2 = (q + 1) / 4;
	m1[1] = modpow(p - pow(c, temp1), 1, p);
	if (m1[1] < 0) {
		m1[1] = m1[1] + p;
	}
	m1[2] = modpow(c, temp2, q);
	m1[3] = modpow(q - pow(c, temp2), 1, q);
	if (m1[3] < 0) {
		m1[3] = m1[3] + q;
	}
	for (int i = 0; i < 4; i++) {
		cout << m1[i] << " ";
	}
	cout << endl;
	int a, b;
	a = q * reverseMod(q, p);
	b = p * reverseMod(p, q);
	cout << a << " " << b << endl;
	M1[0] = modpow(((a * m1[0]) + (b * m1[2])), 1, N);
	M1[1] = modpow(((a * m1[0]) + (b * m1[3])), 1, N);
	M1[2] = modpow(((a * m1[1]) + (b * m1[2])), 1, N);
	M1[3] = modpow(((a * m1[1]) + (b * m1[3])), 1, N);
	for (int i = 0; i < 4; i++) {
		cout << M1[i] << " ";
	}
}
