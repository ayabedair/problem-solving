#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main() {
    ll q; cin >> q;

    while(q--){
        string s, t, ss = "", tt = ""; cin >> s >> t;
        ll s_len = s.length(); //4
        ll t_len = t.length(); //2
        ll l = lcm(s_len, t_len); //4
        while(ss.length() < l)
            ss += s;
        while(tt.length() < l)
            tt += t;

        if(tt == ss)
            cout << tt << ln;
        else
            cout << -1 << ln;
    }


    return 0;
}
