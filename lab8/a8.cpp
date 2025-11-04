#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
vector <string> a;
unordered_set <string> b; 

string Hash(string &s){
    ll h = 0, pow = 1;

    for(int i = 0 ; i < s.size() ; i++){
        h = (h + ((s[i] - 47) * pow) % mod) % mod;
        pow = (pow * 11) % mod;
    }
    return to_string(h);
}

int main(){
    int n; cin >> n;
    string s;

    for(int i = 1 ; i <= 2*n ; i++){
        cin >> s;
        a.push_back(s);
        b.insert(s);
    }
    int count = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(count == n) break;
        string hash = Hash(a[i]);

        if(b.find(hash) != b.end()){
            cout << "Hash of string \"" << a[i] << "\"" << " is " << hash << endl;
            count++;
        }
    }
    return 0;
}