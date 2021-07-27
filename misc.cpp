#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr = {1,2,3};
    for(int i=0;i<arr.size();i++){
        cout << i << "\n";
        arr.push_back(arr[i] + 1);
    }
}