#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, cs[26], ct[26];
string s, t;

signed main() {
    hyper;
    cin >> n >> s >> t;
    rep(i,0,n) cs[s[i]-'a']++, ct[t[i]-'a']++;
    rep(i,0,26) if(cs[i] != ct[i]) {
        cout << -1;
        return 0;
    }
    int ans = n-1;
    for(int i=n-1; i>=0; --i) if(s[ans]==t[i]) ans--;
    cout << ans+1;
}