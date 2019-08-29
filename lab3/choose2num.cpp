#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 33, P = 'z' - 'a' + 1;

vector<ll> fact(N, 1);
vector<vector<ll>> C2(N, vector<ll> (N, 1));

int C(int n, int k) {
	return fact[n] / fact[k] / fact[n - k];
}

void rec(vector<int> &a, int n, int k) {
	ll ans = 0;
	for (int i = 1; i <= k; ++i) {
		cout << i << ":\n";
		for (int j = a[i - 1] + 1; j <= a[i] - 1; ++j) {
			ans += C2[n - j][k - i];
			// cout << "C" << n - j << " " << k - i << "\n";
		}
	}
	cout << ans;

}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("choose2num.in", "r", stdin), freopen("choose2num.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < fact.size(); ++i)
		fact[i] = fact[i - 1] * i;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			C2[i][j] = C2[i][j - 1] * (i - j + 1) / j;
			// cout << C2[i][j] << " ";
		}
		// cout << "\n";
	}
	ll n, k;
	cin >> n >> k;
	vector<int> a(k + 1);
	for (int i = 1; i <= k; ++i)
		cin >> a[i];
	rec(a, n, k);
	return 0;
}