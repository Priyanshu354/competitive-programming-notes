#include <bits/stdc++.h>
using namespace std;

// formula :- sum += i * (arr[i] - arr[i - 1]) * (n - i);

int main()
{
    vector<int> arr = {1,3,8,12,15};
    int n = 5;
    
    int sum = 0;
    for(int i=0;i<n;i++){
        /*
        eg :- 
        for index 0 to n-1 :- (3 - 1) + (8 - 1) + (12 - 1) + (15 - 1);
        for index 1 to n-1, 2 to n-1, so on..
        
        this formual give us sorted array differnce sum to all the element;
        in O(n);
        */
        
        sum += i * (arr[i] - arr[i - 1]) * (n - i);
    }

    // second way 
    int total_diff = 0;
    int sum_before = 0;  // Cumulative sum of elements before the current index

    for (int i = 0; i < n; i++) {
        // For each arr[i], the difference contribution when arr[i] is added:
        total_diff += arr[i] * i - sum_before;

        // Update cumulative sum
        sum_before += arr[i];
    }
    
    cout << sum << endl;

    return 0;
}


