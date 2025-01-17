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
const int MOD = 1e9+7;
const int MN = 2e5+5;

string k;
int d, n;
int dp[10005][105][2];

int sol(int pos, int sum, int lim) {
    if(pos == n) return sum == 0;
    int& ret = dp[pos][sum][lim];
    if(~ret) return ret;
    ret = 0;
    int up = lim ? k[pos] - '0' : 9;
    rep1(i,0,up) ret += sol(pos+1, (sum+i)%d, lim&&(i==up));
    return ret %= MOD;
}

signed main() {
    hyper;
    rr(dp, -1);
    cin >> k >> d;
    n = k.size();
    cout << (sol(0, 0, 1) - 1 + MOD) % MOD << '\n';
}
