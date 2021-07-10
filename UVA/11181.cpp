#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
	https://en.wikipedia.org/wiki/Conditional_probability
	https://en.wikipedia.org/wiki/Bayes%27_theorem
*/

const int N = 30;
double p[N];
int n, r;
double ans;

double pro(int msk) {
	double ret = 1;
	for (int i = 0; i < n; i++) {
		if (1 & (msk >> i)) {
			ret *= p[i];
		}
		else {
			ret *= 1-p[i];
		}
	}
	return ret;
}

void solve() {
	double sum = 0;

	for (int i = 0; i < n; i++)
		cin >> p[i], sum += p[i];

	for (int i = 0; i < n; i++) {
		double a = 0, b = 0;
		for (int msk = 0; msk < (1<<n); msk++) {
			if (__builtin_popcount(msk) == r) {
				double tmp = pro(msk);

				b += tmp;
				if (1 & (msk >> i))
					a += tmp;
			}
		}
		cout << fixed << setprecision(6) << a/b << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc = 0;
	while(cin >> n >> r && (n + r)) {
		cout << "Case " << ++tc << ":\n";
		solve();
	}
}