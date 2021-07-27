#include <iostream>
#include <algorithm>

using namespace std;

int gcdOrHcf(int a, int b){
    if(b == 0) return a;
    return gcdOrHcf(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int gcd = gcdOrHcf(max(a, b), min(a, b));
    cout << "Gcd or Hcf of " << a << " and " << b << " is " << gcd << "\n";
    cout << "Lcm of " << a << " and " << b << " is " << (a * b) / gcd << "\n";
}