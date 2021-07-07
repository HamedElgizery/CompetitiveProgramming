#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
	the I'th player can win at his first turn "I'th turn"
	or at his second turn "the I+N turn"
	or at his third turn "the I+2N turn"
	.....
	so, we will loop an arbitary large number of times and 
	add the probailtiy of him winning at the I+(JN) turn
*/

const double eps = 1e-10;

int n, I;
double p;

bool equal(double f, double s) {
	return abs(f-s) < eps;
}

void solve() {
	cin >> n >> p >> I;
	if (equal(p, 0))
		return void(cout << fixed << setprecision(4) << 0.0 << endl);

	double failing = 1-p, prop = p, tmp, allFailing = 1;

	for (int i = 0; i < n; i++) {
		if (i+1 < I) prop *= failing;
		allFailing *= failing;
	}

	tmp = prop;

	for (int i = 0; i < 100000; i++) {
		tmp *= allFailing;
		prop += tmp;
	}
	cout << fixed << setprecision(4) << prop << endl;
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