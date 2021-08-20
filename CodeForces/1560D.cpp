#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string PO2[70];
string n;
int N;

int calc(int k) {
	int st = 0, ret = 0;
	for (int i = 0; i < PO2[k].size(); i++) {
		bool found = 0;
		for (int j = st; j < N; j++) {
			if (n[j] == PO2[k][i]) {
				st = j+1;
				found = 1;
				break;
			}
			ret++;
		}
		if (!found) {
			ret += PO2[k].size() - i;
			st = N;
			break;
		}
	}
	ret += N - st;
	return ret;
}


void solve() {
	cin >> n;
	N = n.size();
	int ans = INT_MAX;

	for (int i = 0; i < 63; i++) {
		ans = min(ans, calc(i));
	}

	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < 63; i++)
		PO2[i] = to_string(1LL<<i);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}