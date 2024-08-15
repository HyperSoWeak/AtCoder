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
const int MN = 105;

int n, k, p, cost[MN], v[MN][6], dp[6][6][6][6][6], pp[6];

signed main() {
    hyper;
    cin >> n >> k >> p;
    rep1(i,1,n) {
        cin >> cost[i];
        rep1(j,1,k) cin >> v[i][j];
    }
    rep1(i,1,k) pp[i] = p;
    rep1(a,0,pp[1]) rep1(b,0,pp[2]) rep1(c,0,pp[3]) rep1(d,0,pp[4]) rep1(e,0,pp[5]) dp[a][b][c][d][e] = INF;
    dp[0][0][0][0][0] = 0;
    rep1(t,1,n) {
        for(int a=pp[1]; a>=0; --a)
            for(int b=pp[2]; b>=0; --b)
                for(int c=pp[3]; c>=0; --c)
                    for(int d=pp[4]; d>=0; --d)
                        for(int e=pp[5]; e>=0; --e) {
                            int aa = min(pp[1],a+v[t][1]);
                            int bb = min(pp[2],b+v[t][2]);
                            int cc = min(pp[3],c+v[t][3]);
                            int dd = min(pp[4],d+v[t][4]);
                            int ee = min(pp[5],e+v[t][5]);
                            dp[aa][bb][cc][dd][ee] = min(dp[aa][bb][cc][dd][ee], dp[a][b][c][d][e] + cost[t]);
                        }
    }
    int ans = dp[pp[1]][pp[2]][pp[3]][pp[4]][pp[5]];
    if(ans != INF) cout << ans;
    else cout << -1;
}
