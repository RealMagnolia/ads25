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
    int n, m;
    cin >> n;
    
    vector <int> primes = sieve(10000);
    cout << primes[n-1] << endl;
    return 0;
}