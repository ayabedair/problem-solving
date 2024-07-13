#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long

int main() {
    ll n; cin >> n;
    vector<string>v(n);
    for(int i = 0 ; i < n ; ++i) cin >> v[i];

    string c, m; cin >> c >> m;

    int nc = find(v.begin(), v.end(), c) - v.begin();
    int nm = find(v.begin(), v.end(), m) - v.begin();
    double dist = abs(nc - nm);
    cout << ::ceil(dist / 2);

}
