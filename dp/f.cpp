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

string s, t;
int dp[3005][3005], pv[3005][3005];

void print(int i, int j) {
    if(i==0 || j==0) return;
    if(pv[i][j]==0) {
        print(i-1, j-1);
        cout << s[i-1];
    }
    else if(pv[i][j]==1) print(i-1, j);
    else print(i, j-1);
}

signed main() {
    hyper;
    cin >> s >> t;
    int ls = s.length(), lt = t.length();
    rep1(i,1,ls) rep1(j,1,lt) {
        if(s[i-1] == t[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            pv[i][j] = 0;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) {
            dp[i][j] = dp[i-1][j];
            pv[i][j] = 1;
        }
        else {
            dp[i][j] = dp[i][j-1];
            pv[i][j] = 2;
        }
    }
    print(ls, lt);
}