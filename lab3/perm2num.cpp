#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 20, P = 'z' - 'a' + 1;

vector<ll> fact(N, 1);

ll ans = 0;

void rec(vector<int> &a, vector<bool> used, int j) {
	if (j == used.size()) {
		cout << ans;
		return;
	}
	// cout << j << ": ";
	for (int i = 0; i < used.size(); ++i) {
		if (used[i])
			continue;
		// cout << a[j] << endl;
		if (i == a[j]) {
			used[i] = true;
			// ans += fact[used.size() - n];
			rec(a, used, j + 1);
			return;
		}
		// cout << used.size() - j - 1 << "!\n";
		ans += fact[used.size() - j - 1];
	}
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("perm2num.in", "r", stdin), freopen("perm2num.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < fact.size(); ++i)
		fact[i] = fact[i - 1] * i;
	
	ll n;
	cin >> n;
	vector<int> a(n);
	for (auto &p : a)
		cin >> p, --p;
	vector<bool> used(n);
	rec(a, used, 0);
	return 0;
}