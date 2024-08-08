#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int n, dp[22][1<<21];
bool a[21][21];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) rep(j,0,n) cin >> a[i][j];
    dp[0][0] = 1;
    rep(i,0,n) rep(t,0,1<<n) {
        if(dp[i][t] == 0) continue;
        rep(j,0,n) if(!(t&(1<<j)) && a[i][j]) {
            dp[i+1][t|(1<<j)] = (dp[i+1][t|(1<<j)] + dp[i][t]) % MOD;
        }
    }
    cout << dp[n][(1<<n)-1];
}
