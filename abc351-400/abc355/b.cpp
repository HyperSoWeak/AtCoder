#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int n, m, a[105], b[105];
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    b[m] = INF;
    int x = 0, y = 0;
    while(x < n-1 && y < m+1) {
        if(b[y] < a[x]) y++;
        else if(a[x+1] < b[y]) {
            cout << "Yes";
            return 0;
        }
        else x++;
    }
    cout << "No";
}