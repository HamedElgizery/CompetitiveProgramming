#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+100;
int n, x;

struct voucher {
	int l, r, c;
	voucher(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
	bool operator <(const voucher& right) const {
		if (l < right.l)
			return 1;
		if (l == right.l) {
			return r < right.r;
		}
		return 0;
	} 
	int duration() {
		return r - l + 1;
	}
} VOU[N];

vector<pair<voucher, int>> VBD[N];

void solve() {
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		VOU[i] = voucher(l, r, c);
		VBD[VOU[i].duration()].push_back({VOU[i], 0});
	}

	for (int i = 1; i < N; i++)
		sort(VBD[i].begin(), VBD[i].end());

	for (int i = 1; i < N; i++) {
		int prev = 2e9;
		for (vector<pair<voucher, int>>::reverse_iterator it = VBD[i].rbegin(); it != VBD[i].rend(); it++) {
			prev = it->second = min(it->first.c, prev);
		}
	}

	ll ans = 2e10;
	for (int i = 0; i < n; i++) {
		if (VOU[i].duration() >= x)
			continue;

		ll tmp = VOU[i].c;
		int d = x - VOU[i].duration();

		auto it = lower_bound(VBD[d].begin(), VBD[d].end(), make_pair(voucher(VOU[i].r+1, VOU[i].r+1, (int)-1e9), (int)-1e9));
		if(it == VBD[d].end())
			continue;

		tmp += it->second;
		ans = min(ans, tmp);
	}

	if (ans == (long long)2e10)
		ans = -1;
	cout << ans << endl;
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