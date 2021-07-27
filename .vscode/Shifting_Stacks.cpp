#include <iostream>
#define ll long long int

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,a=1;
        ll temp = -1, diff;
        cin >> n;
        while(n--){
            ll tmp;
            cin >> tmp;
            if(temp == -1){
                diff = tmp - temp;
                temp = tmp;
                continue;
            }
            if((tmp + diff - 1) > (temp - (diff - 1))){
                int dif = diff;
                diff = tmp + diff - 1 - (temp - (diff - 1));
                temp = tmp + dif - 1;
            } else if(tmp - temp <= 0) a = 0;
        }
        if(a == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}