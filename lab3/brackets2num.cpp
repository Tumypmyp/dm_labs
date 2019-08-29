#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;

vector<ll> fact(N, 1);
vector<vector<ll>> dp(N, vector<ll> (N));

int C(int n, int k) {
	return fact[n] / fact[k] / fact[n - k];
}

void f(string &a, ll n) {
	/*/
	for (auto &p : a)
		cout << p << " ";
	cout << "\n" << m << " " << j << " " << n << " " << k << "\n\n";
	//*/
	//*
	ll d = 0, ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		// cout << i << " " << ans << "\n";
		if (a[i] == ')') {
			ans += dp[2 * n - i - 1][d + 1];
			d--;	
		} else {
			d++;
		}
	}

	cout << ans;
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("brackets2num.in", "r", stdin), freopen("brackets2num.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < fact.size(); ++i)
		fact[i] = fact[i - 1] * i;
	dp[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = (j > 0 ? dp[i - 1][j - 1] : 0) + (j + 1 < N ? dp[i - 1][j + 1] : 0);
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}
	// ll n, k;
	// cin >> n >> k, ++k;
	string a;
	cin >> a;
	// for (auto &p : a)
	// 	cin >> p;

	f(a, a.size() / 2);
	return 0;
}