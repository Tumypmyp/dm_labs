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
		freopen("huffman.in", "r", stdin), freopen("huffman.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k, ans = 0;
	cin >> n;
	multiset<ll> q;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		q.insert(k);
	} 
	while (q.size() > 1) {
		ll p1 = *q.begin();
		q.erase(q.begin());
		ll p2 = *q.begin();
		q.erase(q.begin());
		ans += p1 + p2;
		q.insert(p1 + p2);
	}
	cout << ans;
	 
 
	return 0;
}