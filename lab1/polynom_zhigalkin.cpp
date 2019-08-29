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

void out_int(int a, int n) {
	for (int i = n - 1; i >= 0; --i)
		cout << getb(a, i);
	cout << " ";
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

	}
	for (int i = 0; i < dp.size(); ++i) {
		out_int(i, sz);
		cout << dp[i][0] << "\n";
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
	vector<bool> a(1 << n);

	for (int j = 0; j < a.size(); ++j) {
		char p;
		string s;
		cin >> s >> p;
		a[j] = p - '0';
	}
	L(n, a);	
	/*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i].size(); ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	//*/

	return 0;
}
