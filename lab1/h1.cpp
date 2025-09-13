#include <iostream>
#include <vector>
using namespace std;

vector <int> sieve(int n){
    vector <int> v(n+1, 0);

    for(int i = 2 ; i*i <= n ; i++){
        if(v[i] == 0){
            for(int j = i*i; j <= n ; j+=i) v[j] = 1;
        }
    }

    vector <int> result;
    for(int i = 2 ; i <= n ; i++){
        if(!v[i]){
            result.push_back(i);
        }
    }
    return result;
}


int main(){
    int n;
    cin >> n;
    
    bool isprime = false;
    vector <int> primes = sieve(n);
    for(int i = 0 ; i < primes.size() ; i++){
        if(n == primes[i]) {
            isprime = true;
            break;
        }
    }
    
    if(isprime) cout << "YES";
    else cout << "NO";
    return 0;
}