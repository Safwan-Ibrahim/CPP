#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;

struct ds{
    int a[N];
    int s = 0, p = 0;

    void push_back(int x) {
        a[p++] = x;
        s++;
    }
    int size() {
        return s;
    }
    int get(int x) {
        return a[x];
    }
    void pop() {
        s--;
        a[--p] = 0; 
    }
};

int main() {


    ds a;
    a.push_back(8);
    a.push_back(12);
    a.push_back(1);

    for (int i = 0; i < a.size(); i++) {
        cout << a.get(i) << " ";
    }


    return 0;
}