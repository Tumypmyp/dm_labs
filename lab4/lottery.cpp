#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1;

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("lottery.in", "r", stdin), freopen("lottery.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<double> a(m + 1), b(m + 1);
	double left = 1, ans = n;
	
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		ans -= (1 - 1 / a[i]) * b[i - 1] * left;
		left *= 1 / a[i];
	}
	ans -= b[m] * left;

	cout << setprecision(13) << fixed;
	cout << ans;
	return 0;
}