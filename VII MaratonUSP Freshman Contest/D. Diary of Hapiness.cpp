#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long

int main() {
    int n; cin >> n;
    vector<int>v(n);
    ll sum = 0;
    for(int i = 0 ; i < n ; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    if(sum < 0)
        cout << ":(";
    else if(sum > 0)
        cout << ":)";
    else
        cout << ":|";


}
