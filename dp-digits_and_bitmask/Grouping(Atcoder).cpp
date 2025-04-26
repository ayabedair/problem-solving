#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define mod 1000000007
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
// int n, k, mx = LONG_MAX;
vector<int> levels, vis;
vector<vector<int>> grid;
vector<int> val;
int n, d;
int dp[1 << 17];

int rec(int mask) {
    if (!mask) return 0;

    if (~dp[mask]) return dp[mask];

    int ans = 0;
    for (int i = mask; i; i = (i - 1) & mask) {
        ans = max(ans, rec(mask ^ i) + val[i]);
    }

    return dp[mask] = ans;
}


void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    grid.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    val.resize(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if((mask & (1<<i)) && (mask & (1<<j)))
                {
                    val[mask] += grid[i][j];
                }
            }
        }
    }

    cout << rec((1 << n) - 1);
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
