#include <iostream>
#include <deque>
using namespace std;

int freq[26] = {};

void clear(){
    for(int i = 0 ; i < 26 ; i++){
        freq[i] = 0;
    }
}

void find(char c, deque <char>&dq){
    int id = (c - 'a');
    freq[id]++;
    while(!dq.empty() && freq[dq.front() - 'a'] > 1) dq.pop_front();

    if(dq.empty()){
        if(freq[id] > 1) cout << "-1 ";
        else{
            dq.push_back(c);
            cout << c << " ";
        }
    } else{
        cout << dq.front() << " ";
        if(freq[id] == 1) dq.push_back(c);
    }
}
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        deque <char> dq;
        while(n--){
            char c; cin >> c;
            find(c, dq);
        }
        cout << endl;
        clear();
    }
    return 0;
}