// Created on: 2024-10-12 19:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string year,month,date;
    string s; 
    cin >> s;
    year = s.substr(0,4); month = s.substr(5,2); date = s.substr(8,2);
    int y = stoi(year), m = stoi(month), d = stoi(date);
    if (y <= 2019) {
        if (m <= 4) {
            if (d <= 30) {
                cout << "Heisei\n";
            }
            else {
                cout << "TBD\n";
            }
        }
        else {
            cout << "TBD\n";
        }
    }
    else {
        cout << "TBD\n";
    }
    
    return 0;
} 