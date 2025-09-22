#include <iostream>
#include <list>
using namespace std;

list <int> l;
int n, mval, cur;
int main(){
    cin >> n;
    while(n--){
        int temp; cin >> temp;
        l.push_back(temp);
    }

    auto it = l.begin();
    mval = *it;
    cur = 0;
    for(; it != l.end() ; it++){
        cur += *it;
        if(*it < 0){
            if(cur - (*it) == 0){
                if(mval < cur) mval = cur;
            }
            else if(mval < cur-(*it)) mval = cur -(*it);
        }
        if(cur <= 0) cur = 0;
    }

    if(mval < cur && cur != 0) cout << cur;
    else cout << mval;
}