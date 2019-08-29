#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define point pair<int, bool>
#define x first
#define y second

const int N = 103;


bool getb(int a, int i) {
	return (a >> i) & 1;
}

int invb(int a, int i) {
	return a ^ (1 << i);
}

bool oneb(int a) {
	return (a & (a - 1)) == 0;
}

bool T0(int sz, vector<bool> &v) {
	return v[0] == 0;
}

bool T1(int sz, vector<bool> &v) {
	return v[(1 << sz) - 1] == 1;
}

bool S(int sz, vector<bool> &v) {
	if (sz == 0)
		return false;
	for (int mask = 0; mask < (1 << sz); ++mask) {
		if (v[mask] == v[mask ^ ((1 << sz) - 1)])
			return false;
	}
	return true;
}

bool M(int sz, vector<bool> &v) {
	for (int mask = 0; mask < (1 << sz); ++mask)
		for (int i = 0; i < sz; ++i) {

			int mask2 = invb(mask, i);
			if (mask2 < mask && v[mask2] > v[mask]) {
				return false;
			}
		}
	return true;
}

bool L(int sz, vector<bool> &v) {
	vector<vector<bool>> dp(v.size(), vector<bool>(v.size()));
	dp[0] = v;
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 0; j < (int)dp.size() - 1; ++j)
			dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
		/*/
		for (int i = 0; i < v.size(); ++i) {
			cout << i << " i : ";
			for (int j = 0; j < v.size(); ++j)
				cout << dp[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
		//*/
		if (!oneb(i) && dp[i][0] == 1) {
			return false;
		}
	}
	return true;
}


int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> s(n);
	vector<vector<bool>> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		a[i].resize(1 << s[i]);
		for (int j = 0; j < a[i].size(); ++j) {
			char p;
			cin >> p;
			a[i][j] = p - '0';
		}
	}
	/*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i].size(); ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	//*/
	bool all_T0 = true;
	bool all_T1 = true;
	bool all_S = true;
	bool all_M = true;
	bool all_L = true;
	for (int i = 0; i < n; ++i) {
		all_T0 &= T0(s[i], a[i]);
		all_T1 &= T1(s[i], a[i]);
		all_S &= S(s[i], a[i]);
		all_M &= M(s[i], a[i]);
		all_L &= L(s[i], a[i]);
	}
	// cout << all_L << " " << all_M << " " << all_S << " " << all_T0 << " " << all_T1 << "	\n";
	if (all_L || all_M || all_S || all_T0 || all_T1) 
		cout << "NO";
	else
		cout << "YES";
	
	return 0;
}
