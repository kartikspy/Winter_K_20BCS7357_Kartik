#include <bits/stdc++.h>
using namespace std;

int runways(int arr[], int dep[], int n)
{
    int runway = 1, result = 1;
    for (int i = 0; i < n; i++) {
        runway = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                if (arr[i] >= arr[j] && dep[j] >= arr[i])
                    runway++;
        }
        result = max(runway, result);
    }
    return result;
}
 
// Driver Code
int main()
{
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << runways(arr, dep, n);
    return 0;
}
 
