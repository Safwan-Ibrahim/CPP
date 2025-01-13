#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void br(int x) {
    for (int i = 31; i >= 0; i--) {
        cout << ((x >> i) & 1) << " "; 
    }
    cout << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    br(5), br(3);
    
    return 0;
} 