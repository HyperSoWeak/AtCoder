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

signed main() {
    hyper;
    cin >> s;
    int l = s.length();
    for(int i=l-1; i>=0; --i) {
        bool f = false;
        rep(j,0,4) {
            if(i-b[j]+1>=0 && s.substr(i-b[j]+1,b[j])==a[j]) {
                f = true;
                i = i-b[j]+1;
            }
        }
        if(!f) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}