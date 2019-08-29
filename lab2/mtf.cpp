#include <bits/stdc++.h>
  
typedef long long ll;
  
using namespace std;
  
#define point pair<int, int>
#define x first
#define y second
  
 
const int P = 'z' - 'a' + 1;
 
int a[P];
  
int main() {
    #ifdef ON_PC
        freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
    #else
        freopen("mtf.in", "r", stdin), freopen("mtf.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < P; ++i)
        a[i] = i;
    for (int i = 0; i < s.size(); ++i) {
        cout << a[s[i] - 'a'] + 1 << " ";
        for (int j = 0; j < P; ++j)
            if (a[j] < a[s[i] - 'a'])
                ++a[j];
        a[s[i] - 'a'] = 0;
    }
 
  
    return 0;
}