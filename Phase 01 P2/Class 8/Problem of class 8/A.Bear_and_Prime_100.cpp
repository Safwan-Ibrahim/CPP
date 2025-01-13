#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[102];

int32_t main()
{   
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) {
            a[j]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 100; i++) {
        if (a[i] == 2) {
            cout << i << endl;
        }
    }
    
    return 0;
} 