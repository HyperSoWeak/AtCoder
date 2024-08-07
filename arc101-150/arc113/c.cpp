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

signed main() {
    hyper;
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int cnt[26] = {0}, ans = 0;
    rep(i,0,n-2) {
        cnt[s[i]-'a']++;
        if(s[i+1]==s[i+2]) {
            ans += i+1 - cnt[s[i+1]-'a'];
            rr(cnt,0);
            cnt[s[i+1]-'a'] = i+2;
            i++;
        }
    }
    cout << ans;
}
