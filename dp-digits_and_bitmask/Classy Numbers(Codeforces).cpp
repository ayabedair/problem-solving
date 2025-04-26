#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define MOD 1073741824
#define int long long

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
// int dx[]{2, 2, -2, -2, -1, 1, 1, -1}; //row
// int dy[]{-1, 1, 1, -1, 2, 2, -2, -2};

// int dx[]{0, 0, 1, -1, 1, 1, -1, -1};
// int dy[]{-1, 1, 0, 0, 1, -1, 1, -1};

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
int n, m, k ,mx = LONG_MAX;
vector<int> levels, vis;
// map<pair<int, bool>, int> vis, levels;
vector<vector<int>> adj;
int dp[19][3][4];
string s;

int rec(int i, bool tight, int rem) {
    if (i == s.size() || rem < 0) {
        return rem >= 0;
    }

    if (~dp[i][tight][rem]) {
        return dp[i][tight][rem];
    }

    int ans = 0;
    if (tight) {
        for (int j = 0; j <= s[i] - '0'; j++) {
            ans += rec(i + 1, j == s[i] - '0', rem - (j > 0));
        }
    } else {
        for (int j = 0; j <= 9; j++) {
            ans += rec(i + 1, 0, rem - (j > 0));
        }
    }
    return dp[i][tight][rem] = ans;
}

void solve() {
    int ans = 0;
    int l, r; cin >> l >> r;
    s = to_string(r);
    memset(dp, -1, sizeof(dp));
    ans += rec(0, 1, 3);
    memset(dp, -1, sizeof(dp));
    s = to_string(l - 1);
    ans -= rec(0, 1, 3);
    cout << ans << endl;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
