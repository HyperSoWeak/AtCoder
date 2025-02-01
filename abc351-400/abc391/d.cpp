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
const int MOD = 998244353;
const int MN = 2e5+5;

int n, w, q;
vector<pii> col[MN]; // (y, id)
int d[MN]; // disappear time

bool check(int c) {
    rep1(i,1,w) if(col[i].size() < c) return 0;
    return 1;
}

signed main() {
    hyper;
    cin >> n >> w;
    rr(d,0x3f);
    rep1(i,1,n) {
        int x, y;
        cin >> x >> y;
        col[x].emplace_back(y, i);
    }
    int c = 1;
    while(check(c)) {
        int mx = 0;
        rep1(i,1,w) mx = max(mx, col[i][c-1].fi);
        rep1(i,1,w) d[col[i][c-1].se] = mx;
        ++c;
    }
    cin >> q;
    while(q--) {
        int t, a;
        cin >> t >> a;
        cout << (t < d[a] ? "Yes" : "No") << '\n';
    }
}
