#include <bits/stdc++.h>
using namespace std;

int hashint(int key){
  key = ~key + (key << 15); // key = (key << 15) - key - 1;
  key = key ^ (key >> 12);
  key = key + (key << 2);
  key = key ^ (key >> 4);
  key = key * 2057; // key = (key + (key << 3)) + (key << 11);
  key = key ^ (key >> 16);
  return key;
}
vector<int> duplicates(int arr[], int n) {
    vector<int> ret;
    for(int i=0;i<n;i++){
        int hashCode = hashint(arr[i]) % n;
        cout << hashCode << "\n";
        if(hashCode == i) continue;
        if(arr[hashCode] == arr[i] && hashCode != i) ret.push_back(arr[i]);
        else{
            int temp = arr[i];
            arr[i] = arr[hashCode];
            arr[hashCode] = temp;
        }
    }
    return ret;
}

int main() {
    int arr[] = {0, 3, 1, 3, 2};
    int n = 5;
    vector<int> ans = duplicates(arr, n);
    if(ans.size() == 0) cout << "No Duplicates\n";
    else {
        for(int i = 0;i < ans.size();i++){
            cout << i << ", ";
        }
    }
    return 0;
}