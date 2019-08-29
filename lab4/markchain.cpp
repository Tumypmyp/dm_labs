#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1;
const double EPS = 1e-5;
int n;

vector<vector<double>> sq(vector<vector<double>> &a) {
	auto b = a;
	auto ans = a;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ans[i][j] = 0;
			for (int u = 0; u < n; ++u) 
				ans[i][j] += a[i][u] * b[u][j];
			}
	return ans;
}

bool eq(vector<vector<double>> a, vector<vector<double>> b) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] + EPS < b[i][j] || a[i][j] - EPS > b[i][j])
				return false;
	return true;
}

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("markchain.in", "r", stdin), freopen("markchain.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cout << setprecision(7) << fixed;

	vector<vector<double>> a(n, vector<double> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		} 

	for (int i = 0; true; ++i) {
		auto b = sq(a);
		if (eq(a, b))
			break;
		a = b;
	}

	for (auto &p : a[0])
		cout << p << " ";
	return 0;
}