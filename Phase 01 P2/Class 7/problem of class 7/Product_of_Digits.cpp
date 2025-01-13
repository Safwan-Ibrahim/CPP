// credit: rabbi
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;cin >> n;
    if (n == 0) {
        cout << 10 << '\n'; return 0;
    }

    if (n == 1) {
        cout << n << '\n'; return 0;
    }
    vector<int> ans;
    for (int i = 9; i > 1; i--){
        while (n % i == 0) {
            ans.push_back(i);
            cout << i << " " << n << " ";
            n /= i;
            cout << n << endl;
        }
    }

    if (n != 1) {
        cout << -1 << '\n'; return 0;
    }
    
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }

    cout << '\n';
    return 0;
}