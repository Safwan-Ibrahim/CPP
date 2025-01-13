#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct modified_stack 
{
    vector<int>v;

    void push(int x) {
        v.push_back(x);
    }
    void pop() {
        v.pop_back();
    }
    int size() {
        return v.size();
    }
    int top() {
        return v.back();
    }
    void print() {
        for (auto x : v) {
            cout << x << " ";
        }
    }
};

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    modified_stack mst;

    mst.push(12);
    mst.push(11); mst.push(21);
    cout << mst.top() << endl;

    mst.print();
    
    return 0;
} 