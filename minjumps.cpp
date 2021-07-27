#include <iostream>
#include <vector>

using namespace std;

int sol(vector<int> arr){
    int pi = 0, cnt = 0, tmp = arr[0], mx = 0,temp = arr[0], mi = 0, i = 1, n = arr.size();
    if(n == 1 || n == 0) return 0;
    if(n == 2) return 1;
    while(pi < n - 1 && i < n){
        if(temp == 0) return -1;
        if(temp + pi >= n - 1){
            return cnt + 1;
        }
        if(tmp != 0){
            if(arr[i] >= mx || (arr[i] + i >= mi + mx)){
                mx = arr[i];
                mi = i;
            }
            tmp--;
        }
        if(tmp == 0){
            tmp = arr[mi] - (i - mi);
            temp = arr[mi];
            pi = mi;
            mx = 0;
            cnt++;
        }
        i++;
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, i, j;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << sol(arr) << "\n";
    }
}