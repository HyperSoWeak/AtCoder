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

int n, cnt[10], ans = 0;
string s;

bool check(int x) {
    int cc[10] = {0};
    while(x > 0) {
        cc[x%10]++;
        x /= 10;
    }
    if(cnt[0] < cc[0]) return false;
    rep(i,1,10) if(cnt[i] != cc[i]) return false;
    return true;
}

signed main() {
    hyper;
    cin >> n >> s;
    for(auto e: s) cnt[e-'0']++;
    rep(i,0,3162280) {
        if(check(i*i)) ans++;
    }
    cout << ans;
}