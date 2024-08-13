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

int n, m;
string a[50], b[50];

bool check(int x, int y) {
    rep(i,0,m) rep(j,0,m) {
        if(a[x+i][y+j] != b[i][j]) return 0;
    }
    return 1;
}

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    rep1(i,0,n-m) rep1(j,0,n-m) {
        if(check(i,j)) return cout << "Yes\n", 0;
    }
    cout << "No\n";
}
