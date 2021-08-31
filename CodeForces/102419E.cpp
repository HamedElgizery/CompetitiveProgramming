#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double pi = 2.0 * acos(0.0);
/*
H = sqrt(r1^2 + r2^2)
ceta = sin-1(r1/H)
alpha = 180 - (90 + ceta)
V = 180 - 2*alpha
z = 90 - V
D = r1 * sin(V) / sin(alpha)
AREA = 0.5 * r1 * (r1+r2)
AREA2 = sqrt(r1^2 - (D/2)^2) * D * .5
ans = AREA - ((Ceta/360) * pi*r1^2 + ((z/360) * pi * r2^2 + AREA2))

*/

double SIN(double n) {
	double ret = sin(n);
	return ret;
}

double ASIN(double n) {
	double ret = asin(n);
	return ret;
}

void solve() {
	double r1, r2;
	cin >> r1 >> r2;

	double hyp = sqrt(r1*r1 + (r1+r2)*(r1+r2));
	double ceta = ASIN(r1/hyp);

	double alpha = pi - (pi/2 + ceta);
	double v = pi - (2 * alpha);
	double z = pi/2 - v;
	double D = (r1 * SIN(v)) / SIN(alpha);
	double AREA = 0.5 * r1 * (r1 + r2);
	double AREA2 = sqrt(r1*r1 - (D/2)*(D/2)) * D * 0.5;

	cout << fixed << setprecision(10) << AREA - (ceta*.5*r2*r2) - (z*.5*r1*r1) - AREA2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}