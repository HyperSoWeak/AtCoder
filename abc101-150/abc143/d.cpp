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
const int MN = 2e3+5;

signed main() {
    hyper;
    int n, l[MN];
    cin >> n;
    rep(i,0,n) cin >> l[i];
    sort(l, l+n);
    int ans = 0;
    rep(i,0,n-2) {
        int a = l[i], k = i+2;
        rep(j,i+1,n-1) {
            int b = l[j];
            while(k+1 < n && l[k+1] < a+b) ++k;
            if(k >= j+1 && l[k] < a+b) ans += k-j;
        }
    }
    cout << ans << '\n';
}
