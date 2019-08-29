#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int P = 'z' - 'a' + 1;

bool getb(int a, int ind) {
	return (a >> ind) & 1;
}

int pushb(int a, int ind) {
	return a | (1 << ind);
}

void out_mask(int a, int n, string s) {
	for (int i = 0; i < n; ++i)
		cout << getb(a, n - 1 - i);
	cout << s;
}


 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("telemetry.in", "r", stdin), freopen("telemetry.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;


	vector<int> vals(k * 2);
	for (int i = 0; i < k; ++i) 
		vals[i] = vals[vals.size() - 1 - i] = i;
	
	vector<vector<int>> ans((int)pow(k, n), vector<int> (n));
	for (int i = 0; i < n; ++i) {
		int L = 0, t = 0;
		while (L < ans.size()) {
			for (int j = 0; j < pow(k, i); ++j)
				ans[L + j][i] = vals[t];
			t++;
			t %= vals.size();
			L += pow(k, i);
		}
	}
	for (auto &v : ans) {
		for (auto &p : v)
			cout << p;
		cout << "\n";
	}
	return 0;
}