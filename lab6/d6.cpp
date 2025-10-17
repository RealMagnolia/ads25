#include <iostream>
#include <vector>
using namespace std;

struct dt{
    int d, m, y;
};

bool isless(dt a, dt b){
    if(a.y != b.y) return a.y < b.y;
    if(a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

void quick(int l, int r, vector <dt> &a){
    dt p = a[(l+r)/2];
    int i = l, j = r;

    while(i < j){
        while(isless(a[i], p)) i++;
        while(isless(p, a[j])) j--;

        if(i <= j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if(l < j) quick(l, j, a);
    if(i < r) quick(i, r, a);
}

int main(){
    dt p;
    int n; cin >> n;
    vector <dt> a;

    for(int i = 0 ; i < n ; i++){
        string s; cin >> s;

        int d = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        int y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
        dt p;
        p.d = d, p.m = m , p.y = y;
        a.push_back(p);
    } quick(0, n-1, a);

    for(int i = 0 ; i < a.size() ; i++){
        if(a[i].d < 10 && a[i].m < 10){
            cout << "0" << a[i].d << "-0" << a[i].m << "-" << a[i].y << endl;
        } else if(a[i].d < 10){
            cout << "0" << a[i].d << "-" << a[i].m << "-" << a[i].y << endl;
        } else if(a[i].m < 10){
            cout << a[i].d << "-0" << a[i].m << "-" << a[i].y << endl;
        } else{
             cout << a[i].d << "-" << a[i].m << "-" << a[i].y << endl;
        }
    }
    return 0;
}