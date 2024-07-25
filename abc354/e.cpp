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

int n, a[18], b[18];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) cin >> a[i] >> b[i];
    bool dp[1<<n] = {0};
    dp[0] = 0;
    rep(t,1,1<<n) {
        rep(x,0,n-1) rep(y,x+1,n) {
            if(((t&(1<<x)) && (t&(1<<y))) && 
               (a[x]==a[y] || b[x]==b[y]) &&
               !dp[t-(1<<x)-(1<<y)]) dp[t] = 1;
        }
    }
    cout << (dp[(1<<n)-1] ? "Takahashi" : "Aoki");
}