#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
ll p_pow = 29;

vector <ll> pref(string s){
    int n = s.size();
    vector <ll> h(n + 5, 0), p(n + 5, 1);
    
    for(int i = 0 ; i < n ; i++){
        h[i+1] = (h[i] * p_pow + (s[i] - 'a' + 1)) % mod;
        p[i+1] = (p[i] * p_pow) % mod;
    }
    return h;
}

ll get_hash(vector <ll> &h, vector <ll> &p, int l, int r){
    ll res = (h[r] - h[l] * p[r-l]) % mod;
    if(res < 0) res += mod;

    return res;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n1 = s1.size();
    int m = t.size();

    vector <ll> h1 = pref(s1);
    vector <ll> h2 = pref(s2);

    vector <ll> p(n1 + 1, 1); 
    
    for(int i = 1 ; i <= n1 ; i++){
        p[i] = (p[i-1] * p_pow) % mod;
    }

    ll h_t = 0;
    for(int i = 0 ; i < m ; i++){
        h_t = (h_t * p_pow + (t[i] - 'a' + 1)) % mod;
    }

    int count = 0; 
    for(int i = 0 ; i + m <= n1 ; i++){
        ll h_s1 = get_hash(h1, p, i, i + m);
        ll h_s2 = get_hash(h2, p, i, i + m);
        if(h_s1 == h_t && h_s2 == h_t) count++;
    }

    cout << count;
    return 0;
}