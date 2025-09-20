#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    deque <string> dq;
    for(int i = 0 ; i < n ; i++){
        string s; cin >> s;
        dq.push_back(s);
    }

    for(int i = 0 ; i < n ; i++){
        while(k > 0){
            dq.push_back(dq.front());
            dq.pop_front();
            k--;
        }

        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}