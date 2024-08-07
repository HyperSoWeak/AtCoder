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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for(char c: s) if(c == 'X') cnt++;
    if(cnt == n) cout << max(0,k-1);
    else if(cnt == 0) cout << max(0,n-1-k);
    else if(cnt >= k) {
        vector<int> v;
        int l = 0, r = n-1;
        while(s[l] == 'X') ++l;
        while(s[r] == 'X') --r;
        int cc = 0, ans = 0;
        rep1(i,l,r) {
            if(s[i] == 'X') ++cc;
            else {
                if(cc) {
                    v.push_back(cc);
                    cc = 0;
                }
                if(i<r && s[i+1] == 'Y') ++ans;
            }
        }
        sort(v.begin(), v.end());
        int s = 0;
        for(int e: v) {
            if(s+e <= k) ans+=e+1, s+=e;
            else break;
        }
        cout << ans + k-s;
    }
    else {
        k -= cnt;
        vector<int> v;
        int l = 0, r = n-1;
        while(s[l] == 'Y') ++l;
        while(s[r] == 'Y') --r;
        int cc = 0, ans = n-1;
        rep1(i,l,r) {
            if(s[i] == 'Y') ++cc;
            else if(cc) {
                v.push_back(cc);
                cc = 0;
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        int s = 0;
        if(l+n-1-r >= k) return cout << ans - k, 0;
        s += l+n-1-r, ans -= s;
        for(int e: v) {
            if(s+e < k) ans-=e+1, s+=e;
            else break;
        }
        cout << ans - (k-s+1);
    }
}
