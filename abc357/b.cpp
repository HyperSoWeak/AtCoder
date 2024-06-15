#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
using namespace std;

signed main() {
    string s;
    int cnt[2] = {0}; 
    cin >> s;
    rep(i,0,s.length()) {
        if(isupper(s[i])) cnt[1]++;
        else cnt[0]++;
    }
    if(cnt[1] > cnt[0]) {
        rep(i,0,s.length()) s[i] = toupper(s[i]);
    }
    else {
        rep(i,0,s.length()) s[i] = tolower(s[i]);
    }
    cout << s << '\n';
}