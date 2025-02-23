#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y; cin >> x >> y;

    double l = y * log(x), r = x * log(y);
    if (l > r) {
        cout << ">";
    }
    else if (r > l) {
        cout << "<";
    }
    else {
        cout << "=";
    }
    cout << endl;

    // if (x == y) {
    //     cout << "=\n";
    // }
    // else if (x == 1) {
    //     cout << "<\n";
    // }
    // else if (y == 1) {
    //     cout << ">\n";
    // }
    // else if (x == 2 && y == 3) {
    //     cout << "<\n";
    // }
    // else if (x == 3 && y == 2) {
    //     cout << ">\n";
    // }
    // else if (x == 2 && y == 4 || x == 4 && y == 2) {
    //     cout << "=\n";
    // }
    // else {
    //     cout << (x > y ? "<\n" : ">\n");
    // }
    
    return 0;
} 