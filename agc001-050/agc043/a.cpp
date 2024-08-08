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

bool check(char pv, char nw) {
    return pv == '.' && nw == '#';
}

signed main() {
    hyper;
    int h, w, dp[105][105];
    string s[105];
    cin >> h >> w;
    s[0] = string(w+1, '.');
    rep1(i,1,h) {
        cin >> s[i];
        s[i] = "." + s[i];
    }
    dp[1][1] = (s[1][1] == '#');
    rep1(i,0,h) dp[i][0] = INF;
    rep1(i,0,w) dp[0][i] = INF;
    rep1(i,1,h) rep1(j,1,w) {
        if(i==1 && j==1) continue;
        dp[i][j] = min(dp[i-1][j]+check(s[i-1][j],s[i][j]),
                       dp[i][j-1]+check(s[i][j-1],s[i][j]));
    }
    cout << dp[h][w];
}
