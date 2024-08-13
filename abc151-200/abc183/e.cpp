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
const int MN = 2005;

int h, w, dp[MN][MN], hsum[MN], wsum[MN], dsum[MN*2];
string s[MN];

signed main() {
    hyper;
    cin >> h >> w;
    rep(i,0,h) cin >> s[i];
    rep1(i,1,h) rep1(j,1,w) {
        if(i == 1 && j == 1) {
            dp[i][j] = 1;
            hsum[i] = 1;
            wsum[j] = 1;
            dsum[MN+i-j] = 1;
        }
        else if(s[i-1][j-1] == '#') {
            dp[i][j] = 0;
            hsum[i] = 0;
            wsum[j] = 0;
            dsum[MN+i-j] = 0;
        }
        else {
            dp[i][j] = (hsum[i]+wsum[j]+dsum[MN+i-j]) % MOD;
            hsum[i] = (hsum[i] + dp[i][j]) % MOD;
            wsum[j] = (wsum[j] + dp[i][j]) % MOD;
            dsum[MN+i-j] = (dsum[MN+i-j] + dp[i][j]) % MOD;
        }
    }
    cout << dp[h][w];
}
