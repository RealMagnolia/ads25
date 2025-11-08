#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7, pp = 29;

vector <ll> pref(string &s){
    int n = s.size();
    vector <ll> h(n + 5, 0), p(n + 5, 1);
    
    for(int i = 0 ; i < n ; i++){
        h[i+1] = (h[i] * pp + (s[i] - 'a' + 1)) % mod;
        p[i+1] = (p[i] * pp) % mod;
    }
    return h;
}

ll get_hash(vector <ll> &h, vector <ll> &p, int l, int r){
    ll res = (h[r] - h[l] * p[r-l]) % mod;
    if(res < 0) res += mod;

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s, t, c;
    int n;

    cin >> s;
    for(int i = 0 ; i < s.size() ; i++) c += '0';
    
    vector <ll> h = pref(s);
    vector <ll> p(s.size()+1, 1);
    for(int i = 1 ; i <= s.size() ; i++){
        p[i] = (p[i-1] * pp) % mod;
    }

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> t;
        ll ht = 0;
        for(char d : t){
            ht = (ht * pp + (d - 'a' + 1)) % mod;
            for(int j = 0 ; j + t.size() <= s.size() ; j++){
                ll sub = get_hash(h, p, j, j + t.size());
                if(sub == ht){
                    for(int k = j ; k < j + t.size() ; k++) c[k] = '1';
                }
            }
        }
    }

    for(int i = 0 ; i < c.size() ; i++){
        if(c[i] == '0'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}