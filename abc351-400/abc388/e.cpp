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
const int MN = 5e5+5;

int n, a[MN];

bool check(int k) {
    rep1(i,1,k) if(a[i] * 2 > a[n-k+i]) return 0;
    return 1;
}

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> a[i];
    int l = 0, r = n/2;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout << l << '\n';
}
