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
const int MN = 5e5+5;

string s;
int a[MN], b[MN];

signed main() {
    hyper;
    cin >> s;
    int n = s.size();
    rep(i,0,n) if(s[i] == '<') a[i+1] = a[i] + 1;
    for(int i=n-1; i>=0; --i) if(s[i] == '>') b[i] = b[i+1] + 1;
    int ans = 0;
    rep(i,0,n+1) ans += max(a[i], b[i]);
    cout << ans << '\n';
}
