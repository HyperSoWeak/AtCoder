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
    int n, c, k, t[100005];
    cin >> n >> c >> k;
    rep(i,0,n) cin >> t[i];
    sort(t, t+n);
    int ans = 0, i = 0;
    while(i < n) {
        int j = i+1;
        while(j-i+1<=c && j<n && t[j]<=t[i]+k) j++;
        ans++, i=j;
    }
    cout << ans;
}