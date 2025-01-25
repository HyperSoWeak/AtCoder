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
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 1e5+5;

int n, w[MN][5], dp[MN][5], mx = -1;

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        int t, x, a;
        cin >> t >> x >> a;
        w[t][x] = a;
        mx = max(mx, t);
    }
    rr(dp, -1);
    dp[0][0] = w[0][0];
    rep1(i,1,mx) {
        rep(j,0,5) {
            int r = -1;
            if(dp[i-1][j] != -1) r = max(r, dp[i-1][j] + w[i][j]);
            if(j-1 >= 0 && dp[i-1][j-1] != -1) r = max(r, dp[i-1][j-1] + w[i][j]);
            if(j+1 <= 4 && dp[i-1][j+1] != -1) r = max(r, dp[i-1][j+1] + w[i][j]);
            dp[i][j] = r;
        }
    }
    int ans = -1;
    rep(i,0,5) ans = max(ans, dp[mx][i]);
    cout << ans << '\n';
}
