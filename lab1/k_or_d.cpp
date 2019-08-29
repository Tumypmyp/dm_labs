#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define poll pair<ll, bool>
#define x first
#define y second

const ll N = 34;


bool getb(ll a, ll i) {
	return (a >> i) & 1;
}

ll invb(ll a, ll i) {
	return a ^ (1LL << i);
}

bool oneb(ll a) {
	return (a & (a - 1)) == 0;
}

void out_ll(ll a, ll n) {
	for (ll i = n - 1; i >= 0; --i)
		cout << getb(a, i);
	cout << " ";
}




int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, s;
	cin >> n;
	vector<ll> a(n);
	for (auto &p : a)
		cin >> p;
	cin >> s;
	if (s == 0) {
		cout << 1 << "&~" << 1;
		return 0;
	}

	vector<ll> fun(1 << n);
	/*/
	for (ll i = 0; i < n; ++i) {
		out_ll(a[i], N);
		cout << "\n";
	}
	cout << "=\n";
	out_ll(s, N);
	cout << "\n\n";
	//*/
	for (ll i = 0; i < N; ++i) {
		ll mask = 0;
		for (ll j = 0; j < n; ++j)
			mask = getb(a[j], i) ? invb(mask, j) : mask;
		// out_ll(mask, N);
		// cout << " - mask, " << getb(s, i) << " - ans\n";
		fun[mask] = getb(s, i); 
	}
	
	for (ll i = 0; i < N; ++i) {
		ll mask = 0;
		for (ll j = 0; j < n; ++j)
			mask = getb(a[j], i) ? invb(mask, j) : mask;
		if (fun[mask] != getb(s, i)) {
			cout << "Impossible";
			return 0;
		}
	}
	bool frst = true;

	/*/
	for (ll mask = 0; mask < (1 << n); ++mask) {
		out_ll(mask, n);
		cout << fun[mask] << "\n";
	}
	cout << "\n";
	//*/
	for (ll mask = 0; mask < (1 << n); ++mask) {
		if (fun[mask]) {
			if (frst)
				frst = false;
			else
				cout << "|";
			cout << "(";
			cout << (getb(mask, 0) ? "" : "~") << 1;
			for (ll i = 1; i < n; ++i)
				cout << "&" << (getb(mask, i) ? "" : "~") << i + 1;
			cout << ")";
		}
	}

	return 0;
}
