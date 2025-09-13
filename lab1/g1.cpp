#include <iostream>
#include <vector>
using namespace std;

bool isprime(int n){
    if(n < 2) return false;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    vector <int> a, primes;
    for(int i = 2 ; i <= 100000 ; i++){
        if(isprime(i)) primes.push_back(i);
    }

    for(int i = 0 ; i < primes.size() ; i++){
        if(isprime(i+1)) a.push_back(primes[i]);
    }

    int n; cin >> n;
    cout << a[n-1];
}