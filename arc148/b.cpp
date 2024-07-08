#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, l = 0, r;
string s, ans;

signed main() {
    hyper;
    cin >> n >> s;
    ans = s;
    while(s[l] == 'd') l++;
    rep(i,0,n) {
        if(s[i] == 'p') {
            while(s[i] == 'p') i++;
            r = i-1;
            string t = s.substr(0, l);
            for(int i=r; i>=l; --i) {
                if(s[i] == 'd') t += 'p';
                else t += 'd';
            }
            t += s.substr(r+1, n-r);
            ans = min(ans, t);
        }
    }
    cout << ans;
}