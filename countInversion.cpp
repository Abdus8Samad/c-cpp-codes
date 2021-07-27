#include <iostream>
#include <vector>

using namespace std;

long long int ans = 0;
void merge(long long* arr, long long si, long long ei){
    long long mid = (si + ei) / 2;
    long long i = si, j = mid + 1;
    vector<long long> temp;
    while(i <= mid && j <= ei){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            ans += mid - i + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(j <= ei){
        temp.push_back(arr[j]);
        j++;
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    for(long long i=0;i<temp.size();i++){
        arr[si + i] = temp[i];
    }
}
void mergeSort(long long* arr, long long si, long long ei){
    if(si >= ei) return;
    long long mid = (si + ei) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, ei);
}
long long int countInversions(long long* arr, long long n)
{
    long long* arr_temp = new long long[n];
    for(long long i=0;i<n;i++) arr_temp[i] = arr[i];
    mergeSort(arr_temp, 0, n-1);
    delete[] arr_temp;
    return ans;
}

int main(){
    long long n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << countInversions(arr, n) << "\n";
}