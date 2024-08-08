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
const int MN = 1e5+5;

signed main() {
    hyper;
    bool p[MN];
    int ps[MN];
    rep(i,2,MN) p[i] = 1;
    rep(i,2,MN) {
        if(p[i]) {
            for(int j=i+i; j<MN; j+=i) p[j] = 0;
        }
    }
    rep(i,1,MN) ps[i] = ps[i-1] + (p[i] && p[(i+1)/2]);
    int q, l, r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << ps[r] - ps[l-1] << '\n';
    }
}