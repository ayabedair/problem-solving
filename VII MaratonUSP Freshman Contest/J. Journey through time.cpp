#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
    int n; cin >> n;

    vector<ll>v;
    vector<ll>mx;
    vector<ll>mn;
    vector<ll>sum;
    ll maxx = LONG_MIN;
    ll minn = LONG_MAX;
    ll s = 0;
    while(n--){
        ll op, x; cin >> op >> x;
        if(op == 1){
            v.push_back(x);
            maxx = max(maxx, x);
            minn = min(minn, x);
            s += x;
        }else if(op == 2)
            cout << mx[x - 1] << ln;
        else if(op == 3)
            cout << mn[x - 1] << ln;
        else{
            cout << sum[x - 1] << ln;
        }

        mx.push_back(maxx);
        mn.push_back(minn);
        sum.push_back(s);
    }

    return 0;
}


