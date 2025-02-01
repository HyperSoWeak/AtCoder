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
const int MN = 1e6+5;

int n, q;
int pos[MN], cnt[MN], ans = 0;

signed main() {
    hyper;
    cin >> n >> q;
    rep1(i,1,n) {
        pos[i] = i;
        cnt[i] = 1;
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int p, h;
            cin >> p >> h;
            cnt[pos[p]]--;
            if(cnt[pos[p]] == 1) ans--;
            pos[p] = h;
            cnt[pos[p]]++;
            if(cnt[pos[p]] == 2) ans++;
        } else {
            cout << ans << '\n';
        }
    }
}
