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
const int MN = 1005;

int rec[1005][1005];

int nCr(int n, int r) {
    if(rec[n][r]) return rec[n][r];
    if(r == 0 || r == n) return rec[n][r] = 1;
    if(r == 1) return rec[n][r] = n;
    return rec[n][r] = (nCr(n-1,r) + nCr(n-1,r-1)) % MOD;
}

signed main() {
    hyper;
    int k, c[30], dp[30][MN];
    cin >> k;
    rep1(i,1,26) cin >> c[i];
    rep1(i,0,c[1]) dp[1][i] = 1;
    rep1(i,2,26) {
        rep1(j,0,k) {
            int sum = 0;
            rep1(k,0,min(j,c[i])) {
                sum += dp[i-1][j-k] * nCr(j,k);
                sum %= MOD;
            }
            dp[i][j] = sum;
        }
    }
    int ans = 0;
    rep1(i,1,k) ans = (ans + dp[26][i]) % MOD;
    cout << ans << '\n';
}
