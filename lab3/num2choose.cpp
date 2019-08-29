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

void rec(vector<int> &a, int n, int k, int m) {
	/*/
	for (auto &p : a)
		cout << p << " ";
	cout << "\n" << m << " " << j << " " << n << " " << k << "\n\n";
	//*/
	int last = 1;
	while (k > 0) {
		// cout << n << " " << k << " " << m << endl;
		if (m < C2[n - 1][k - 1]) {
			a.push_back(last);
			k--;
		} else {
			m -= C2[n - 1][k - 1];
		}
		n--;
		last++;
	}
	
	for (auto &p : a)
		cout << p << " ";


}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("num2choose.in", "r", stdin), freopen("num2choose.out", "w", stdout);
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
	ll n, k, m;
	cin >> n >> k >> m;
	vector<int> a;

	rec(a, n, k, m);
	return 0;
}