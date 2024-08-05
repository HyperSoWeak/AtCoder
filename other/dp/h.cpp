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
#define MOD 1000000007
#define MAXN 1005

int h, w, dp[MAXN][MAXN];
string a[MAXN];

signed main() {
    hyper;
    cin >> h >> w;
    rep(i,0,h) cin >> a[i];
    rep(i,0,h) dp[i][0] = 0;
    rep(i,0,w) dp[0][i] = 0;
    dp[1][1] = 1;
    rep1(i,1,h) rep1(j,1,w) {
        if(i==1 && j==1) continue;
        if(a[i-1][j-1] == '#') dp[i][j] = 0;
        else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
    cout << dp[h][w];
}