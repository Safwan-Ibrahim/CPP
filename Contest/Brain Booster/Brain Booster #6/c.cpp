// Created on: 2024-10-03 20:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
int a[N];

bool roy(int odd, int even,bool roy_even, bool h_even) {
    while(1) {
        if (roy_even) {
            roy_even = !roy_even;
            if (even > 0) {
                even--;
            }
            else {
                return false;
            }
        }
        else {
            roy_even = !roy_even;
            if (odd > 0) {
                odd--;
            }
            else {
                return false;
            }
        }
        if (h_even) {
            h_even = !h_even;
            if (even > 0) {
                even--;
            }
            else {
                return true;
            }
        }
        else {
            h_even = !h_even;
            if (odd > 0) {
                odd--;
            }
            else {
                return true;
            }
        }
    }
} 

void solve()
{
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int num_even = 0, num_odd = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
            num_odd++;
        }
        else {
            num_even++;
        }
    }

    int roy_win = 0;

    if (roy(num_odd,num_even,true,true) && roy(num_odd,num_even,true,false)) {
        cout << "Roy\n";
    }
    else if (roy(num_odd,num_even,false,true) && roy(num_odd,num_even,false,false)) {
        cout << "Roy\n";
    }
    else {
        cout << "Hridoy\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 