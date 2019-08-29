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


vector<vector<int>> gr;
vector<int> table, ind_v, depth;

int dfs(int v) {
	if (depth[v] >= 0)
		return depth[v];
	depth[v] = 0;
	for (auto &to : gr[v])
		depth[v] = max(depth[v], dfs(to) + 1);
	return depth[v];
}


int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	gr.resize(n);
	table.resize(n);
	ind_v.resize(n, -1);
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		int sz;
		cin >> sz;
		gr[i].resize(sz);
		for (auto &p : gr[i])
			cin >> p, --p;
		// reverse(gr[i].begin(), gr[i].end());
		if (sz == 0)
			ind_v[i] = ind++; 
		else {
			for (int j = 0; j < (1 << sz); ++j) {
				int k;
				cin >> k;
				if (k)
					table[i] = invb(table[i], j);
			}
		}
	}
	depth.resize(n, -1);
	cout << dfs(n - 1) << "\n";

	/*/
	for (int i = 0; i < n; ++i)
		cout << depth[i] << " ";
	cout << "\n";
	cout << ind << " - ind\n";
	for (int i = 0; i < n; ++i) {
		out_int(table[i], 1 << (int)gr[i].size());
		cout << "\n";
	}
	cout << "\n";
	//*/
	for (int mask = 0; mask < (1 << ind); ++mask) {
		vector<bool> dp(n);
		// out_int(mask, ind);
		// cout << "vals\n";
		for (int i = 0; i < n; ++i) {
			if (gr[i].empty()) {
				dp[i] = getb(mask, ind - 1 - ind_v[i]);
				continue;
			}
			int mask2 = 0;
			for (int j = 0; j < gr[i].size(); ++j) {
				// cout << gr[i][j] << " ind ";
				// cout << dp[gr[i][j]] << " val\n";
				mask2 <<= 1;
				mask2 += dp[gr[i][j]];
			}
			// out_int(mask2, gr[i].size());
			// cout << "- mask2\n";
			dp[i] = getb(table[i], mask2);
		}
		/*/
		for (int i = 0; i < dp.size(); ++i)
			cout << dp[i] << " ";
		cout << " - dp\n";
		//*/
		cout << dp[n - 1];
	}
	return 0;
}
