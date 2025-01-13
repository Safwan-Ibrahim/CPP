// Created on: 2024-10-13 17:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

map<int,int>mp;
map<string,int>t;

void track(int x) {
    while(x > 0) {
        mp[x % 10]++;
        x /= 10;
    }
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 100; i++) {
        track(i);
        int mx = -1, ans = -1;
        for (auto [x,y] : mp) {
            if (y >= mx) {
                mx = y;
                ans = x;
            }
        }
        t[to_string(i)] = ans;
    }

    string s; 
    char ch;

    while(cin >> ch) {
        if (ch != '0') {
            s += ch;
        }
    }
    bool ok = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '9') {
            ok = false;
        }
    }

    if (ok) {
        cout << s[0] << endl; return 0;
    }

    if (s.size() < 3) {
        cout << t[s] << endl; return 0;
    }

    vector<int>v; v.push_back(t[s.substr(s.size()-2,2)]);
    for (int i = s.size()-3; i >= 0; i--) {
        int a = s[i] - '0';
        v.push_back(max(1,a-1));
    }

    cout << *(min_element(v.begin(),v.end()));
    
    return 0;
} 