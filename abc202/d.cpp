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

int a, b, k;
int dp[35][35]; // dp[acnt][bcnt]

signed main() {
    hyper;
    cin >> a >> b >> k;
    rep1(i,0,a) dp[i][0] = 1;
    rep1(i,0,b) dp[0][i] = 1;
    rep1(i,1,a) rep1(j,1,b) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    while(a > 0 && b > 0) {
        if(k <= dp[a-1][b]) {
            cout << 'a';
            a--;
        }
        else {
            cout << 'b';
            k -= dp[a-1][b];
            b--;
        }
    }
    while(a--) cout << 'a';
    while(b--) cout << 'b';
}