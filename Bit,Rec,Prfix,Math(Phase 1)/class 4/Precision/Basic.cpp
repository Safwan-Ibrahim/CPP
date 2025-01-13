#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    int n = 1000;
    cout << round(pow(n,2)) << endl;

    // sqrt
    int ans = sqrt(n); 
    while(ans*ans <= n) ans++;
    while(ans*ans > n) ans--;
    cout << ans << endl;

    // comparision in double 
    double a = 7834.1298301;
    double b = 7834.129830100000000000001;
    double c = 1e17;
    cout << (a==b) << endl;

    // better approach 
    cout << (abs(a-b) < 1e-9) << endl;

    // precision set
    cout << c << endl; // to avoid scientific notaion we should use fixed;
    cout << fixed << setprecision(0) << c << endl;
    cout << setprecision(5) << a << endl;  // that means shuru theke 5 ghor
    cout << fixed << setprecision(5) << a << endl; // . er por theke 5 ghor

    return 0;
} 