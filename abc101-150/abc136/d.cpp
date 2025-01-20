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

string s;
vi v;
int ans[MN];

signed main() {
    hyper;
    cin >> s;
    int n = s.size();
    rep(i,0,n-1) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            v.push_back(i);
        }
    }
    for(auto x: v) {
        int l = x, r = x+1;
        while(l >= 0 && s[l] == 'R') --l;
        while(r < n && s[r] == 'L') ++r;
        int len = r - l - 1;
        ans[x] = len / 2;
        ans[x+1] = len / 2;
        if(len & 1) {
            if((x-l) & 1) ++ans[x];
            else ++ans[x+1];
        }
    }
    rep(i,0,n) cout << ans[i] << ' ';
    cout << '\n';
}
