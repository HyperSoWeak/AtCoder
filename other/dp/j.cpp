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
#define MAXN 305

int n, cnt[4];
double dp[MAXN][MAXN][MAXN];

double sol(int x, int y, int z) {
    if(x<0 || y<0 || z<0) return 0;
    if(dp[x][y][z] >= 0) return dp[x][y][z];
    return dp[x][y][z] = (n+x*sol(x-1,y,z)+y*sol(x+1,y-1,z)+z*sol(x,y+1,z-1))/(x+y+z);
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    rep1(i,0,n) rep1(j,0,n) rep1(k,0,n) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cout << fixed << setprecision(10) << sol(cnt[1],cnt[2],cnt[3]);
}