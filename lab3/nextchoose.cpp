#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;



void get_next(vector<int> a, int n, int k) {
	vector<int> ans(k);
	for (int i = 0; i < k; ++i)
		if (a[k - i - 1] < n - i) {
			ans = a;
			ans[k - i - 1]++;
			for (int j = k - i; j < k; ++j)
				ans[j] = ans[j - 1] + 1;
		
			for (auto &p : ans)
				cout << p << " ";
			cout << "\n";
			return;
		}
	cout << -1;
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextchoose.in", "r", stdin), freopen("nextchoose.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (auto &p : a)
		cin >> p;
	sort(a.begin(), a.end());


	get_next(a, n, k);
	return 0;
}