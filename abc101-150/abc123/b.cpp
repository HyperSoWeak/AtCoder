#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int x, ans = 0, mn = INF;
    rep(i,0,5) {
        cin >> x;
        ans += (x/10)*10;
        x %= 10;
        if(x != 0) {
            ans += 10;
            if(x < mn) mn = x;
        }
    }
    if(mn == INF) cout << ans;
    else cout << ans - 10 + mn;
}