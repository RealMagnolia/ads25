#include <iostream>
#include <vector>
using namespace std;


vector<int> pref(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++) {
        int j = pi[i-1];

        while(j > 0 && s[j] != s[i]) {
            j = pi[j-1];
        }

        if(s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {
    string s; cin >> s;
    vector <int> p = pref(s);

    cout << s.size() - p[p.size() - 1];
    return 0;
}