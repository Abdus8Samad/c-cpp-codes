#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool checkPrime(int n){
    int cnt = 0;
    for(int i=2;i<=pow(n, 0.5);i++){
        if(n % i == 0) cnt++;
    }
    return cnt == 0;
}

int primeNos1(int n){
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(checkPrime(i)){
            cout << i << "\n";
            cnt++;
        }
    }
    return cnt;
}

vector<int> primeNos2(int n){
    vector<int> primes;
    for(int i=2;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<primes.size();j++) if(i % primes[j] == 0) cnt++;
        if(cnt == 0) primes.push_back(i);
    }
    return primes;
}

int countPrimes(int l, int r){
    vector<int> notPrime(r);
    for(int i=2;i<=pow(r, 0.5);i++){
        if(notPrime[i]) continue;
        else if(checkPrime(i)) {
            if(i < pow(r, 0.5)) for(int j=i*i;j<r;j+=i) if(j % i == 0) notPrime[j] = 1;
        }
    }
    int cnt = 0;
    for(int i=l;i<r;i++) cnt += !notPrime[i];
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << primeNos1(n) << " Prime Numbers\n\n";
    vector<int> primes = primeNos2(n);
    for(auto i : primes) cout << i << "\n";\
    cout << primes.size() << " Prime Numbers\n";
    cout << countPrimes(1, 30) << " Prime Numbers\n";
}