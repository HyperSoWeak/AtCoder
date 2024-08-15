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
const int MOD = 998244353;
const int MN = 3005;

int n, a[MN], b[MN], dp[MN][MN], ps[MN][MN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> a[i];
    rep1(i,1,n) cin >> b[i];
    rep1(j,a[1],b[1]) dp[1][j] = 1;
    rep1(j,0,3000) ps[1][j+1] = (ps[1][j] + dp[1][j]) % MOD;
    rep1(i,2,n) {
        rep1(j,a[i],b[i]) dp[i][j] = ps[i-1][j+1];
        rep1(j,0,3000) ps[i][j+1] = (ps[i][j] + dp[i][j]) % MOD;
    }
    cout << ps[n][3001];
}
