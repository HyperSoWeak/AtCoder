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

string s, a[4] = {"dream","dreamer","erase","eraser"};
int b[4] = {5,7,5,6};
bool dp[100005];

signed main() {
    hyper;
    cin >> s;
    int l = s.length();
    dp[0] = 1;
    rep1(i,1,l) {
        rep(j,0,4) {
            if(i-b[j]>=0 && dp[i-b[j]] &&
            s.substr(i-b[j],b[j])==a[j]) dp[i] = 1;
        }
    }
    cout << (dp[l] ? "YES" : "NO");
}