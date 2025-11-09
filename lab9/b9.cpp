#include <iostream>
#include <vector>
using namespace std;

vector <int> pref(string &s){
    int n = s.size();
    vector <int> p(n);
    p[0] = 0;

    for(int i = 1 ; i < n ; i++){
        int j = p[i-1];

        while(j > 0 && s[i] != s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j]) j++;

        p[i] = j;
    }

    return p;
}

int KMP(string t, string p){
    string s = p + "#" + t;
    int n = s.size(), m = p.size();

    vector <int> pi = pref(s);

    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(pi[i] == m){
            int pos = i - 2 * m;
            count++;
        }
    }

    return count;
}

int main(){
    string s1, s2;
    int k;
    cin >> s1 >> k >> s2;

    int count = KMP(s2, s1);
    if(count >= k){
        cout << "YES";
    } else cout << "NO";
    return 0;
}