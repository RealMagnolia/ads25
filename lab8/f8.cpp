#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string> 
#include <set>  
#include <unordered_set>
using namespace std;

#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int, int>
#define vll vector<ll>
#define all(x) x.begin(), x.end() 
#define sz(x) (int)x.size()
#define F first
#define S second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define rep0(i, n) rep(i, 0, n)


const int inf = (1ll << 30) - 1;
const int N = (int)1e5 + 10;
// const int MOD = 1e9 + 7;  
// const ll BASE = 31; 

const ll BASE1 = 31; 
const ll MOD1 = 1e9 + 7; 

const ll BASE2 = 53; 
const ll MOD2 = 1e9 + 9;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first); 
        auto h2 = std::hash<T2>{}(p.second); 
        h1 ^= h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2);
        return h1; 
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    unordered_set<pair<ll, ll>, pair_hash> hashes;
    hashes.reserve(n * (n + 1) / 2);
    rep0(i, n) { 
        ll cur_h1 = 0;
        ll cur_p1 = 1;  

        ll cur_h2 = 0;
        ll cur_p2 = 1;  

        rep(j, i, n) {
            int char_v = s[j] - 'a' + 1;
            cur_h1 = (cur_h1 + char_v * cur_p1) % MOD1;
            cur_p1 = (cur_p1 * BASE1) % MOD1;
            cur_h2 = (cur_h2 + char_v * cur_p2) % MOD2;
            cur_p2 = (cur_p2 * BASE2) % MOD2;
            hashes.insert({cur_h1, cur_h2});
        }
    }
    cout << sz(hashes) << "\n";
}

int main() {
    fast;
    solve();

    return 0;
} 