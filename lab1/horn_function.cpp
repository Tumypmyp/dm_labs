#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define point pair<int, bool>
#define x first
#define y second

const int N = 103;

int n, k;

vector<int> ans;
vector<vector<int>> a;

bool change(vector<int> &v) {
	/*/
	cout << "\n";
	for (auto &p : v)
		cout << p << " ";
	cout << "\n";
	for (auto &p : ans)
		cout << p << " ";
	cout << endl;
	//*/
	if (v == vector<int> (n, -1))
		return false;

	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == -1)
			continue;

		if (v[i] == ans[i]) {
			v.assign(n, -1);
			return true;
		} else if (ans[i] >= 0) {
			v[i] = -1;
			continue;
		}
		num++;
	}
	if (num == 0) {
		cout << "YES";
		exit(0);
	}
	if (num == 1) {
		for (int i = 0; i < n; ++i)
			if (v[i] != -1) {
				ans[i] = v[i];
				v[i] = -1;
			}
		return true;
	}
	return false;
}

int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	a.resize(k, vector<int> (n));
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j]; 

	ans.resize(n, -1);
	while (true) {
		int upd = 0;
		for (int i = 0; i < k; ++i)
			upd += change(a[i]);
		/*/
		cout << "\n";
		for (auto &p : a) {
			for (auto &p2 : p)
				cout << p2 << " ";
			cout << "\n";
		}
		cout << "\n";
		//*/
		if (upd == 0) {
			break;
		}
	}
	cout << "NO";
	return 0;
}
