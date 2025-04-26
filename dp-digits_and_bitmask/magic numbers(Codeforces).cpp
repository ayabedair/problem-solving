#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define MOD 1000000007
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

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int sub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
int n, k, mx = LONG_MAX;
vector<int> levels, vis;
vector<vector<int>> adj;
vector<int> nums;
int d, m;
int dp[2001][3][2001];
string s;

int rec(int i, bool tight, int rem) {
    if (i == s.size()) return rem == 0;

    if (~dp[i][tight][rem]) return dp[i][tight][rem];

    int ret = 0;
    int mx = tight ? s[i] - '0' : 9;
    if (i & 1) {
        if (d > mx) return 0;
        ret = rec(i + 1, tight && (d == mx), (rem * 10 + d) % m);
    } else {
        for (int j = 0; j <= mx; j++) {
            if (j == d) continue;
            ret = add(ret, rec(i + 1, tight && (j == mx), (rem * 10 + j) % m), MOD);
        }
    }
    return dp[i][tight][rem] = ret;
}

void solve() {
    cin >> m >> d;
    string l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    s = r;
    int ans = rec(0, 1, 0);

    memset(dp, -1, sizeof(dp));
    s = l;
    ans = sub(ans, rec(0, 1, 0), MOD);

    bool f = 1;
    for (int i = 0; i < l.size(); i++) {
        if (i & 1) {
            if (l[i] - '0' != d) {
                f = 0;
                break;
            }
        } else {
            if (l[i] - '0' == d) {
                f = 0;
                break;
            }
        }
    }

    if (f) {
        int sum = 0;
        for (int i = 0; i < l.size(); i++) {
            sum = (sum * 10 + (l[i] - '0')) % m;
        }
        if (sum != 0) f = 0;
    }

    cout << ans + f << endl;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
