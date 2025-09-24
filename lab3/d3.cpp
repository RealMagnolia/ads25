#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
 
vector<int> numbers; 
 
 
int left_binarysearch(int data, int size) { 
    int left = 0, right = size - 1, answer = size; 
 
    while (left <= right) 
    { 
        int mid = left + (right-left)/2; 
        if (numbers[mid] >= data) 
        { 
            right = mid - 1; 
            answer = mid; 
        } 
        else 
        { 
            left = mid + 1; 
        } 
    } 
    return answer; 
     
} 
 
 
int right_binarysearch(int data, int size) { 
    int left = 0, right = size - 1, answer = -1; 
 
    while (left <= right) 
    { 
        int mid = left + (right-left)/2; 
        if (numbers[mid] <= data) 
        { 
            left = mid + 1; 
            answer = mid; 
        } 
        else 
        { 
            right = mid - 1; 
        } 
    } 
    return answer; 
} 
 
 
 
int findrange(int L, int R, int n) { 
    if (L > R) return 0; 
    int leftIndex = left_binarysearch(L, n); 
    int rightIndex = right_binarysearch(R, n); 
 
    return rightIndex - leftIndex + 1; 
} 
 
 
int main() { 
 
    int n, m; 
    cin >> n >> m; 
 
    for (int i = 0; i < n; i++) 
    { 
        int k; 
        cin >> k; 
        numbers.push_back(k); 
    } 
 
    sort(numbers.begin(), numbers.end()); 
 
    for (int i = 0; i < m; i++) 
    { 
        int l1, r1, l2, r2; 
        cin >> l1 >> r1 >> l2 >> r2; 
 
        int cnt1 = findrange(l1, r1, n); 
        int cnt2 = findrange(l2, r2, n); 
 
        int L, R; 
 
        if (l1 > l2) 
        { 
            L = l1; 
        } 
        else 
        { 
            L = l2; 
        } 
 
        if (r1 > r2) 
        { 
            R = r2; 
        } 
        else 
        { 
            R = r1; 
        } 
 
        int cnt_instersection = findrange(L, R, n); 
 
        cout << cnt1 + cnt2 - cnt_instersection << endl;  
         
    } 

    return 0; 
}