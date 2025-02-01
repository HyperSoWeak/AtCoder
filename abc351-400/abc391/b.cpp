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
const int MN = 5005;

signed main() {
    hyper;
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i,0,n) cin >> s[i];
    rep(i,0,m) cin >> t[i];
    rep(i,0,n-m+1) {
        rep(j,0,n-m+1) {
            bool ok = true;
            rep(k,0,m) {
                rep(l,0,m) {
                    if(s[i+k][j+l] != t[k][l]) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok) {
                cout << i+1 << ' ' << j+1 << '\n';
                return 0;
            }
        }
    }
}
