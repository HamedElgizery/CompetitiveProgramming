#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, I;
double p;
const double eps = 1e-10;
bool equal(double f, double s) {
	return abs(f-s) < eps;
}

void solve() {
	cin >> n >> p >> I;
	if (equal(p, 0))
		return void(cout << fixed << setprecision(4) << 0.0);

	double failing = 1-p, prop = p, tmp, tmpfailing = 1;
	for (int i = 1; i < I; i++)
		prop *= failing;
	tmp = (prop/p)*failing;

	for (int j = 0; j+1 < n; j++)
			tmpfailing *= failing;

	for (int i = 0; i < 100000; i++) {
		tmp *= p * tmpfailing;
		prop += tmp;
		tmp = (tmp/p) * failing;
	}
	cout << fixed << setprecision(4) << prop;
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
	while(t--) {
		solve();
		cout << '\n';
	}
}