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

string s;
int n, x;

signed main() {
    hyper;
    cin >> s >> n;
    for(char c: s) {
        x <<= 1;
        x += (c=='?' ? 0 : c-'0');
    }
    if(x > n) {
        cout << "-1";
        return 0;
    }
    int l = s.length();
    int t = 1ll << (l-1);
    for(char c: s) {
        if(c == '?' && (x|t) <= n) x |= t;
        t >>= 1;
    }
    cout << x;
}