#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 30;
bool vis[N];
double p[N];
int n, r;
double ans;
void fun(double curr,int ct, bool target, int idx, double sum) {
	if (idx == r) {
		if (target) 
			ans += curr;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			fun(curr * (p[i]/sum), ct, target|(i == ct), idx+1, sum - p[i]);
			vis[i] = false;
		}
	}
}

void solve() {
	double sum = 0;
	for (int i = 0; i < n; i++)
		cin >> p[i], sum += p[i];
	for (int i = 0; i < n; i++) {
		ans = 0;
		fun(1, i, 0, 0, sum);
		cout << fixed << setprecision(6) << ans << endl;
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