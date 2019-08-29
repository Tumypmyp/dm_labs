#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
#define x first
#define y second
#define point pair<int, int>
 
const int P = 'z' - 'a' + 1;

 
int main() {
	#ifdef ON_PC
		freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	#else
		freopen("shooter.in", "r", stdin), freopen("shooter.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k, --k;
	vector<double> p(n);
	double sum = 0;
	for (auto &x : p) {
		cin >> x;
		x = pow(1 - x, m);
		sum += x;
	}
	cout << setprecision(13) << fixed;
	cout << p[k] / sum;
	return 0;
}