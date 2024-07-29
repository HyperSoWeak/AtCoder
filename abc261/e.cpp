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
#define MAXN 200005

int n, c;
bool dp[2][30][MAXN]; // dp[init][bit][op]

signed main() {
    hyper;
    cin >> n >> c;
    rep(i,0,2) rep(j,0,30) dp[i][j][0] = i;
    rep1(k,1,n) {
        int t, a;
        cin >> t >> a;
        rep(i,0,2) rep(j,0,30) {
            if(t == 1) dp[i][j][k] = dp[i][j][k-1] & ((a>>j)&1);
            else if(t == 2) dp[i][j][k] = dp[i][j][k-1] | ((a>>j)&1);
            else dp[i][j][k] = dp[i][j][k-1] ^ ((a>>j)&1);
        }
    }
    rep1(i,1,n) {
        int t = 0;
        rep(j,0,30) t |= (dp[(c>>j)&1][j][i]<<j);
        c = t;
        cout << c << '\n';
    }
}