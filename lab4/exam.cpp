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
		freopen("exam.in", "r", stdin), freopen("exam.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, p, m, sum = 0;
	cin >> k >> n;
	for (int i= 0; i < k; ++i) {
		cin >> p >> m;
		sum += p * m;
	}
	
	double ans = (double)sum / 100 / n;
	cout << setprecision(13) << fixed;
	cout << ans;

	
	return 0;
}