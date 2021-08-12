#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mxN = 2e3+10;
int dp1[mxN], dp2[mxN][mxN];
int N, A, B;
int Y[mxN];
ll msk, ans;

int fun2(int idx, int grp) {
	if (grp > B)
		return 0;
	if (idx == N)
		return (A <= grp && grp <= B);

	int &ret = dp2[idx][grp];
	if (~ret) return ret;

	ret = 0;
	ll sum = 0;
	for (int i = idx; i < N; ++i) {
		sum += Y[i];
		if (!(sum & msk))
			ret |= fun2(i+1, grp+1);
	}

	return ret;
}

int fun1(int idx) {
	if (idx == N)
		return 0;
	int &ret = dp1[idx];
	if (~ret) return ret;
	ret = 1e9;
	ll sum = 0;
	for (int i = idx; i < N; ++i) {
		sum += Y[i];
		if (!(sum & msk))
			ret = min(ret, fun1(i+1) + 1);
	}
	return ret;
}

bool check2() {
	memset(dp2, -1, sizeof dp2);
	return fun2(0, 0);
}

bool check1() {
	memset(dp1, -1, sizeof dp1);
	return fun1(0) <= B;
}

void solve1() {
	for (int bit = 50; bit >= 0; --bit) {
		msk |= (1LL << bit);
		if (!check1())
			msk ^= (1LL << bit), ans |= (1LL << bit);
	}
	cout << ans << endl;
}

void solve2() {
	for (int bit = 50; bit >= 0; --bit) {
		msk |= (1LL << bit);
		if (!check2())
			msk ^= (1LL << bit), ans |= (1LL << bit);
	}
	cout << ans << endl;
}

void solve() {
	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i)
		cin >> Y[i];
	if (A == 1) {
		solve1();
	}
	else {
		solve2();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}