#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 20, P = 'z' - 'a' + 1;

vector<ll> fact(N, 1);

void rec(vector<int> &a, ll k, vector<bool> used, int n) {
	if (n == 0 && k == 0) {
		for (auto &p : a)
			cout << p + 1 << " ";
		return;
	}

	for (int i = 0; i < used.size(); ++i) {
		if (used[i])
			continue;
		if (k < fact[n - 1]) {
			a.push_back(i);
			used[i] = true;
			rec(a, k, used, n - 1);
			return;
		}
		k -= fact[n - 1];
	}
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("num2perm.in", "r", stdin), freopen("num2perm.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < fact.size(); ++i)
		fact[i] = fact[i - 1] * i;
	
	ll n, k;
	cin >> n >> k;
	vector<int> a;
	vector<bool> used(n);
	rec(a, k, used, n);
	return 0;
}