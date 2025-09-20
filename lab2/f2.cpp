#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n; cin >> n;
    deque <int> dq;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        dq.push_back(a);
    }
    int k, p; cin >> k >> p;

    for(int i = 0 ; i < n ; i++){
        if(i != p) {
            cout << dq.front() << " "; dq.pop_front();
        }
        else {
            cout << k << " " << dq.front() << " ";
            dq.pop_front();
        }
    }
    return 0;
}