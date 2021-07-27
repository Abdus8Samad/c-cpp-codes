#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long

using namespace std;

ll termsInBW(ll a, ll l, ll cd){
    double ans = (1.0 * (l - a) / cd) + 1;
    return ceil(ans) == floor(ans) ?(ll) (ans - 2) : (ll) (ans - 1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k, x, mxReached = 1;
    ll groups = 1;
    cin >> n >> k >> x;
    vector<ll> levels;
    vector<ll> terms;
    while(n--){
        ll temp;
        cin >> temp;
        levels.push_back(temp);
    }
    sort(levels.begin(), levels.end());
    for(ll i=1;i<levels.size();i++){
        if(levels[i] - levels[i - 1] > x){
            ll term = termsInBW(levels[i - 1], levels[i], x);
            if(term > k) groups++;
            else terms.push_back(term);
        }
    }
    sort(terms.begin(), terms.end());
    for(ll i=0;i<terms.size();i++){
        k -= terms[i];
        if(k < 0) groups++;
    }
    cout << groups << "\n";
}