#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e6+10;
int BIT[mxN], N, P;
vector<ll> A, APR;

void add(int idx, int delta) {
	for (; idx <= N; idx += idx & -idx)
		BIT[idx] += delta;
}

int query(int idx) {
	int ret = 0;
	for (; idx > 0; idx -= idx & -idx)
		ret += BIT[idx];
	return ret;
}

void solve() {
	scanf("%d", &N);
	A.resize(N);
	for (auto& a : A) scanf("%lld", &a);
	scanf("%d", &P);

	ll sum = 0;
	for (auto& a : A) {
		a -= P;
		sum += a;
		APR.push_back(sum);
	}

	sort(APR.begin(), APR.end());
	for (int i = 0; i < N; i++) {
		add(N - i, 1);
	}

	sum = 0;
	ll ans = 0;
	for (auto a : A) {
		ans += query(APR.end() - lower_bound(APR.begin(), APR.end(), sum));
		sum += a;
		add(APR.end() - lower_bound(APR.begin(), APR.end(), sum), -1);
	}
	printf("%lld", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
}