#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

#define loop(n)          for(ll i = 0; i < (n); i++)
#define lp(x, s, e)      for(ll x = (s); x < (e); x++)
#define loopj(n)         for(ll j = 0; j < (n); j++)

int main() {
    int n; cin >> n;
    vector<int>v(n);
    loop(n) cin >> v[i];

    stack<int>st;
    loop(n){
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();

        st.empty()? cout << 0 << " " : cout << st.top() + 1 << " ";

        st.push(i);
    }

    return 0;
}
