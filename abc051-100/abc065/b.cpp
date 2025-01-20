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
const int MN = 1e5+5;

int n, a[MN], vis[MN];

signed main() {
    hyper;
    cin >> n;
    rep1(i,1,n) cin >> a[i];
    int x = 1, cnt = 0;
    while(!vis[x]) {
        vis[x] = 1;
        x = a[x];
        ++cnt;
        if(x == 2) {
            cout << cnt << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
