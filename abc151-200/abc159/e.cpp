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
const int MN = 2e5+5;

int h, w, k;
int a[12][1005], ps[12][1005];
string s;
int ans = INF;

inline int getSum(int x1, int x2, int y1, int y2) {
    return ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
}

bool check(int t, int lst, int c) {
    int l = 0;
    rep1(i,1,h) {
        if(i == h || t & (1<<(i-1))) {
            if(getSum(l+1, i, lst+1, c) > k) return 0;
            l = i;
        }
    }
    return 1;
}

void solve(int t) {
    int cnt = __builtin_popcount(t);
    int i = 0;
    rep1(j,1,w) {
        if(!check(t, i, j)) {
            cnt++;
            i = j-1;
        }
        if(cnt >= ans) return;
    }
    if(check(t, i, w)) ans = min(ans, cnt);
}

signed main() {
    hyper;
    cin >> h >> w >> k;
    rep1(i,1,h) {
        cin >> s;
        rep1(j,1,w) a[i][j] = s[j-1] - '0';
    }
    rep1(i,1,h) rep1(j,1,w) ps[i][j] = ps[i][j-1]+ps[i-1][j]-ps[i-1][j-1]+a[i][j];
    rep(t,0,1<<(h-1)) solve(t);
    cout << ans << '\n';
}