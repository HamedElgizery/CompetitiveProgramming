#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5;
int n, a[N];

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

int seg[N*4];

void build(int node, int l, int r) {
	if (l == r)
		return void(seg[node] = a[l]);
	int mid = (l+r)>>1;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);
	seg[node] = gcd(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int lt, int rt) {
	if (l >= lt && r <= rt)
		return seg[node];
	if (l > rt || r < lt)
		return 0;

	int ret = 0;
	int mid = (l+r)>>1;
	ret = gcd(query(node*2, l, mid, lt, rt), query(node*2+1, mid+1, r, lt, rt));
	return ret;
}

int Q(int s, int len) {
	int ret = 0;
	if (s + len >= n) {
		ret = query(1, 0, n-1, s, n-1);
		len -= n - s;
		s = 0;
	}
	ret = gcd(ret, query(1, 0, n-1, s, s+len));
	return ret;
}

bool can(int len) {
	int def = Q(0, len);
	for (int i = 1; i < n; i++) {
		int tmp = Q(i, len);
		if (tmp != def) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	cin >> n ;
	memset(seg, 0, sizeof (int) * ((n+5)*4));
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n-1);
	int l = 0, r = n-1, mid;
	while(l < r) {
		mid = (l+r)>>1;
		if (can(mid))
			r = mid;
		else
			l = mid+1;
	} 

	cout << r;
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