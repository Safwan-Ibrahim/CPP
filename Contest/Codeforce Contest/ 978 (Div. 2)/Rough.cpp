#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a[5];
    a[3] = 132;
    int *d = a;
    cout << d[2] << endl;
    int b = 125;
    int *c = &b;
    cout << c[0] << endl;
    
    return 0;
} 