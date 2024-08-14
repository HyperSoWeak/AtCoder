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
const int MN = 5005;

int n, k, a[MN];

bool check(int x) {
    bitset<MN> can;
    can[0] = 1;
    rep1(i,1,n) if(i != x) {
        can |= can<<a[i];
    }
    rep(i,max(0, k-a[x]),k) if(can[i]) return 0;
    return 1;
}

signed main() {
    hyper;
    cin >> n >> k;
    rep1(i,1,n) cin >> a[i];
    sort(a+1, a+n+1);
    int l = 0, r = n;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}
