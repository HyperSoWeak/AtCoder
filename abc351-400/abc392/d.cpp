#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
// #define max max<int>
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

struct Dice {
    int k;
    multiset<int> s;
    set<int> t;
};

int n;
Dice a[MN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) {
        cin >> a[i].k;
        rep(j,0,a[i].k) {
            int x;
            cin >> x;
            a[i].s.insert(x);
            a[i].t.insert(x);
        }
    }
    double ans = 0;
    rep1(i,1,n-1) rep1(j,i+1,n) {
        Dice &x = a[i], &y = a[j];
        double p = 0;
        for(auto &z: x.t) {
            double py = ((double)y.s.count(z)/(double)y.k);
            double px = ((double)x.s.count(z)/(double)x.k);
            p += px * py;
        }
        ans = max<double>(ans, p);
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
