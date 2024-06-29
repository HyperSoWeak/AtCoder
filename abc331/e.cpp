#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 100005

int n, m, l, x, y, ans = 0;
pii a[MAXN], b[MAXN];
unordered_set<int> st[MAXN];

signed main() {
    hyper;
    cin >> n >> m >> l;
    rep1(i,1,n) cin >> a[i].fi, a[i].se = i;
    rep1(i,1,m) cin >> b[i].fi, b[i].se = i;
    rep(i,0,l) {
        cin >> x >> y;
        st[x].insert(y);
    }
    sort(a+1, a+n+1, greater<pii>());
    sort(b+1, b+m+1, greater<pii>());
    rep1(i,1,n) {
        if(a[i].fi+b[1].fi < ans) continue;
        rep1(j,1,m) {
            if(!st[a[i].se].count(b[j].se)) {
                ans = max(ans, a[i].fi+b[j].fi);
                break;
            }
        }
    }
    cout << ans;
}