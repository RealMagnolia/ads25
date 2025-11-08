#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const ll p_pow = 29;

vector <ll> pref(string &s){
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

string s[155], long_s;
ll m , cnt[155];

int main(){
    while(true){
        int n;
        cin >> n;
        if(!cin || n == 0) break;

        for(int i = 1 ; i <= n ; i++){
            cin >> s[i];
        }
        m = 0;
        for(int i = 1 ; i <= n ; i++){
            cnt[i] = 0;
        }

        cin >> long_s;
        vector <ll> h = pref(long_s);
        ll sz = long_s.size();

        vector <ll> p(sz + 1, 1);
        for(int i = 1 ; i <= sz ; i++){
            p[i] = (p[i-1] * p_pow) % mod;
        }

        for(int i = 1 ; i <= n ; i++){
            ll hash = 0 , count = 0;
        
            for(char c : s[i]){
                hash = (hash * p_pow + (c - 'a' + 1)) % mod;
            }
            for(int j = 0 ; j + s[i].size() <= sz ; j++){
                ll sub = get_hash(h, p, j, j + s[i].size());
                if(sub == hash) count++;
            }

            m = max(m, count);
            cnt[i] = count;
        }
        cout << m << endl;
        for(int i = 1 ; i <= n ; i++){
            if(cnt[i] == m) cout << s[i] << endl;
        }
    }

    return 0;
}