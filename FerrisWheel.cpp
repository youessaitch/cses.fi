#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    multiset<ll> ms;
    for (auto &it : v)
    {
        cin >> it;
        ms.insert(it);
    }
    sort(v.begin(), v.end());
    ll ans = 0;

    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;

    while (!ms.empty())
    {

        if (*ms.begin() <= x)
        {
            auto num = *ms.begin();
            ms.erase(ms.begin());
            ll dif = abs(num - x);
            // cout << "dif " << dif << " ";
            auto it = ms.lower_bound(dif);
            auto found = false;
            ans++;

            if ((it != ms.end()) && (*it <= dif))
            {
                ms.erase(it);
                found = true;
            }

            else if (it != ms.begin())
            {
                --it;
                if (*it <= dif)
                {
                    ms.erase(it);
                    found = true;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
