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

void f(vector<char> &a, ll n, ll k) {
	/*/
	for (auto &p : a)
		cout << p << " ";
	cout << "\n" << m << " " << j << " " << n << " " << k << "\n\n";
	//*/
	//*
	vector<char> b;
	ll d = 0;
	for (int i = 0; i < 2 * n; ++i) {
		ll x = dp[2 * n - i - 1][d + 1] * pow(2, (2 * n - i - 1 - (d + 1)) / 2);
		if (k <= x) {
			a.push_back('(');
			b.push_back('(');
			d++;
			continue;
		} 
		k -= x;
		x = (!b.empty() && b.back() == '(' ?
				dp[2 * n - i - 1][d - 1] * pow(2, (2 * n - i - 1 - (d - 1)) / 2) : 0);
		
		if (k <= x) {
			a.push_back(')');
			b.pop_back();
			d--;	
			continue;
		}
		k -= x;
		x = dp[2 * n - i - 1][d + 1] * pow(2, (2 * n - i - 1 - (d + 1)) / 2);
		if (k <= x) {
			a.push_back('[');
			b.push_back('[');
			d++;
		} else {
			k -= x;
			a.push_back(']');
			b.pop_back();
			--d;
		}
	}
	for (auto &p : a)
		cout << p;
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("num2brackets2.in", "r", stdin), freopen("num2brackets2.out", "w", stdout);
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
	ll n, k;
	cin >> n >> k, ++k;
	vector<char> a;

	f(a, n, k);
	return 0;
}