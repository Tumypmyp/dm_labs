#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define poll pair<ll, bool>
#define x first
#define y second



int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("bwt.in", "r", stdin), freopen("bwt.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<char>> a(n, vector<char> (n));
	for (int i = 0; i < n; ++i)
		a[0][i] = s[i];
	for (int i = 1; i < n; ++i) {
		copy(a[i - 1].begin() + 1, a[i - 1].end(), a[i].begin());
		a[i].back() = a[i - 1][0];
	}
	
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i)
		cout << a[i].back();

	return 0;
}
