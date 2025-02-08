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
const int MN = 1005;

signed main() {
    hyper;
    int n, m;
    bool b[MN];
    cin >> n >> m;
    rr(b,0);
    rep(i,0,m) {
        int a;
        cin >> a;
        b[a] = 1;
    }
    int cnt = 0;
    rep1(i,1,n) if(!b[i]) ++cnt;
    cout << cnt << '\n';
    rep1(i,1,n) if(!b[i]) cout << i << ' ';
    cout << '\n';
}
