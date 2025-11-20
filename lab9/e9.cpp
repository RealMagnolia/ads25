#include <iostream>
#include <vector>
using namespace std;

int pref(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++) {
        int j = pi[i-1];

        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }

        if(s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi[pi.size()-1];
}


int main() {
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; int k;
        cin >> s >> k;

        int p = pref(s);
        int len = s.size();

        cout << len + (k-1)*(len-p) << endl;
    }
    return 0;
}