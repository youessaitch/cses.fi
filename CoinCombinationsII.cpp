#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
// bottom up approach (iterative) as top bottom giving tle bcuz of the deep recursion tree

// TOP BOTTOM:
// ll solve(ll i, ll n, ll x, vector<ll> &v, vector<vector<ll>> &dp)
// {
//     if (x < 0 || i >= n)
//         return 0;
//     if (x == 0)
//         return 1;

//     if (dp[i][x] != -1)
//         return dp[i][x];

//     // ll ans = 0;
//     ll take = solve(i, n, x - v[i], v, dp);
//     ll notTake = solve(i + 1, n, x, v, dp);

//     return dp[i][x] = (take + notTake) % mod;
// }

// int main()
// {
//     ll n, x;
//     cin >> n >> x;
//     vector<ll> v(n);
//     for (auto &it : v)
//     {
//         cin >> it;
//     }
//     vector<vector<ll>> dp(n + 1, vector<ll>(x + 5, -1));

//     ll ans = solve(0, n, x, v, dp);
//     cout << ans % mod << endl;

//     return 0;
// }

// BOTTOM UP:
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    vector<int> dp(x + 5, 0);

    dp[0] = 1; // sum = 0 ==> ans = 1

    for (int i = 0; i < n; i++) // loop over coins -> for ordered (no duplicates)
    {
        for (int sum = v[i]; sum <= x; sum++)
        {
            if (sum - v[i] >= 0)
            {
                dp[sum] += dp[sum - v[i]];
                while (dp[sum] > mod)
                    dp[sum] -= mod;
            }
        }
    }

    cout << dp[x] % mod << endl;
    return 0;
}