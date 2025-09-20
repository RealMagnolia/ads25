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

    for(int i = 0 ; i < n ; i++){
        if(i%2 == 0){
            dq.push_back(dq.front());
            cout << dq.front() << " ";
            dq.pop_front();
        } else {
            dq.pop_front();
        }
    }
    return 0;
}