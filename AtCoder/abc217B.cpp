#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<string> contest = {"ABC", "ARC", "AGC","AHC"} ;
map<string, bool> exist;
void solve() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	exist[s1] = 1;
	exist[s2] = 1;
	exist[s3] = 1;
	for (auto c : contest) {
		if (!exist[c]) {
			cout << c;
			return;
		}
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