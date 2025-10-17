#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct st{
    string n, sn;
    double gpa;
};

bool sort(st n1, st n2){
    if(n1.gpa != n2.gpa) return n1.gpa < n2.gpa;
    if(n1.sn != n2.sn) return n1.sn < n2.sn;
    return n1.n < n2.n;
}

void quick(int l, int r, vector <st> &g){
    st  p = g[(l+r)/2];
    int i = l, j = r;

    while(i < j){
        while(sort(g[i], p)) i++;
        while(sort(p, g[j])) j--;

        if(i <= j){
            swap(g[i], g[j]);
            i++; j--;
        }
    }

    if(l < j) quick(l, j, g);
    if(i < r) quick(i, r, g);
}

int main(){
    vector <st> a;
    long long n; cin >> n;

    for(int i = 0 ; i < n ; i++){
        string sn, n;
        int m; cin >> sn >> n >> m;

        long long creds = 0;
        double gpas = 0;
        for(int j = 1 ; j <= m ; j++){
            string s; int x;
            cin >> s >> x;
            if(s == "A+") gpas += (4.0 * x);
            if(s == "A") gpas += (3.75 * x);
            if(s == "B+") gpas += (3.5 * x);
            if(s == "B") gpas += (3.0 * x);
            if(s == "C+") gpas += (2.5 * x);
            if(s == "C") gpas += (2.0 * x);
            if(s == "D+") gpas += (1.5 * x);
            if(s == "D") gpas += (1.0 * x);
            if(s == "F") gpas += (0 * x);
            creds += x;
        } double gpa = gpas/(double)creds;

        st fio;
        fio.n = n; fio.sn = sn; fio.gpa = gpa;
        a.push_back(fio);
    }
    quick(0, a.size()-1, a);
    cout << fixed << setprecision(3);
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i].sn << " " << a[i].n << " " << a[i].gpa << endl;
    }
    return 0;
}