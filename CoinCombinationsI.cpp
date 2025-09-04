#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
// bottom up approach (iterative) as top bottom giving tle bcuz of the deep recursion tree

// TOP BOTTOM:
//  ll solve(ll n, ll x, vector<ll> &v, vector<ll> &dp)
//  {
//      if (x < 0)
//          return 0;
//      if (x == 0)
//          return 1;

//     if (dp[x] != -1)
//         return dp[x];

//     ll ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans = (ans + solve(n, x - v[i], v, dp)) % mod;
//     }

//     return dp[x] = ans;
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
//     vector<ll> dp(x + 5, -1);

//     ll ans = solve(n, x, v, dp);
//     cout << ans << endl;

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

    dp[0] = 1; // sum =0 ==> ans = 1

    for (int sum = 1; sum <= x; sum++)
    {
        for (auto it : v)
        {
            if (sum - it >= 0)
            {
                dp[sum] += dp[sum - it];
                while (dp[sum] > mod)
                    dp[sum] -= mod;
            }
        }
    }

    cout << dp[x] % mod << endl;
    return 0;
}