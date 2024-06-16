#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
using namespace std;

signed main() {
    int n, a, t, x = 0;
    cin >> n >> a;
    rep(i,0,n) {
        cin >> t;
        x = max(t, x) + a;
        cout << x << '\n';
    }
}