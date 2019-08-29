#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define point pair<int, int>
#define x first
#define y second
 
const int N = 53, P = 'z' - 'a' + 1;


void get_prev(vector<int> a, int n) {
	vector<int> ans(n);
	for (int i = n - 1; i > 0; --i)
		if (a[i - 1] > a[i]) {
			ans = a;
			int maxi = i;
			for (int j = i; j < n; ++j)
				if (a[maxi] < a[j] && a[j] < a[i - 1])
					maxi = j;
			swap(ans[i - 1], ans[maxi]);
			sort(ans.begin() + i, ans.end());
			reverse(ans.begin() + i, ans.end());
			break;
		}
	for (auto &p : ans)
		cout << p << " ";
	cout << "\n";
}

void get_next(vector<int> a, int n) {
	vector<int> ans(n);
	for (int i = n - 1; i > 0; --i)
		if (a[i - 1] < a[i]) {
			ans = a;
			int mini = i;
			for (int j = i; j < n; ++j)
				if (a[mini] > a[j] && a[j] > a[i - 1])
					mini = j;
			swap(ans[i - 1], ans[mini]);
			sort(ans.begin() + i, ans.end());
			break;
		}
	for (auto &p : ans)
		cout << p << " ";
	cout << "\n";
}

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("nextmultiperm.in", "r", stdin), freopen("nextmultiperm.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	vector<int> a(n);
	for (auto &p : a)
		cin >> p;

	get_next(a, n);
	return 0;
}