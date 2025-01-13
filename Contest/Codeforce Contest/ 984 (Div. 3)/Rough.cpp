#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool check(string& s, int ind, char c,set<int>&ms) {
    int l = max(0,ind - 5);
    int r = min((int)s.size(), ind + 5);
    string sub = "1100";
    int p = 0;
    for (int i = l; i < r - 3; i++) {
        string ss = "";
        for (int j = i; j <= i + 3; j++) {
            ss += s[j];
        }
        if (ss == sub) {
            ms.insert(i+3);
        }
    }
    cout << ms.size() << endl;
    return (int)ms.size() > 0;

}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    string sub = "1100";
    bool no = s.size() < 4;
    set<int>ms;

    for (int i = 0; i < s.size(); i++) {
        int l = i, r = s.size();
        int len = min(3,r-3);
        if (s.substr(l,len) == sub) {
            ms.insert(l+3);
        }
    }

    // for (auto [x,y] : mp) {
    //     cout << x << " " << y << endl;
    // }

    int q; cin >> q;
    while(q--) {
        int i,v; cin >> i >> v;
        i--;
        char c = (v == 1 ? '1' : '0');
        if (no) {
            cout << "NO\n"; continue;
        }
        if (c == s[i]) {
            if (ms.size() > 0) {
                cout <<"YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            s[i] = c;
            if (ms.lower_bound(i) != ms.end()) {
                if (*(ms.lower_bound(i)) - 3 <= i) {
                    ms.erase(*(ms.lower_bound(i)));
                }
            } 
            if (check(s,i,c,ms)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    
    
    return 0;
} 