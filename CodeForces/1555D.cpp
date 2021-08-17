#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
abc
acb
bac
bca
cab
cba
*/
const int mxN = 2e5+10;
int cum[3][3][mxN];
int N, M;
string S;

void solve() {
	cin >> N >> M >> S;
	S = '#' + S;
	for (int i = 1; i <= N; i++) {
		cum[i%3][S[i] - 'a'][i]++;
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				cum[k][j][i] += cum[k][j][i-1];
			}
		}
	}

	while(M--) {
		int l, r;
		cin >> l >> r;
		int ans = INT_MAX;

		string pattern = "abc";
		do {
			int tmp = r - l + 1;
			for (int i = 0; i < 3; i++) {
				tmp -= cum[i][pattern[i]-'a'][r] - cum[i][pattern[i]-'a'][l-1];
			}
			ans = min(ans, tmp);
		}while(next_permutation(pattern.begin(), pattern.end()));


		cout << ans << endl;
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