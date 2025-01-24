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

int n;

bool check(int a, int b) {
    int x = 1;
    rep(i,0,b) {
        if(x > n/a) return 0;
        x *= a;
    }
    return 1;
}

int bsearch(int p) {
    int l = 1, r = n;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(check(m, p)) l = m;
        else r = m-1;
    }
    return l;
}

vi pfact(int x) {
    vi res;
    for(int i=2; i*i<=x; ++i) {
        while(x%i == 0) {
            res.push_back(i);
            x /= i;
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

signed main() {
    hyper;
    int ans = 1;
    cin >> n;
    rep1(p,2,60) {
        vi f = pfact(p);
        bool same = 0;
        rep(i,1,f.size()) {
            if(f[i] == f[i-1]) {
                same = 1;
                break;
            }
        }
        if(same) continue;
        int r = bsearch(p) - 1;
        if(f.size() % 2) ans += r;
        else ans -= r;
    }
    cout << ans << '\n';
}
