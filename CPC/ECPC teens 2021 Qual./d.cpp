#include <bits/stdc++.h>
using namespace std;
long long calc(long long y, long long nm) {
	return (y / nm);
}
int main() {
	freopen("lose.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		long long ans = (b - a + 1LL)
				- ((calc(b, 5LL) + calc(b, 13LL) - calc(b, 65LL))
						- (calc(a - 1, 5LL) + calc(a - 1, 13LL)
								- calc(a - 1, 65LL)));
		cout << ans << endl;
	}
}