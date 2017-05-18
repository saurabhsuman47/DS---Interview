//Find Height of N-ary Tree represented by Parent array//

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case number of nodes, parent array)
1
10
-1 0 0 0 1 1 8 8 4 8 
*/

#include<bits/stdc++.h>
using namespace std;

//calculate depth for each node, update it to dp array//
int calculateDepthNode(int idx, int parent[], int* dpDepth, int n){
    if(parent[idx] == -1){
        dpDepth[idx] = 0;
        return dpDepth[idx];
    }
    dpDepth[idx] = 1 + calculateDepthNode(parent[idx], parent, dpDepth, n);
    return dpDepth[idx];
}

//calculate depth for each node and update max - O(n) using dp array//
int calculateHeight(int parent[], int n){
    int dpDepth[n];
    int gmax = INT_MIN;
    for(int i = 0; i < n; i++){
        gmax = max(gmax, calculateDepthNode(i, parent, dpDepth, n));
    }
    return gmax;
}

//driver program to test//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int parent[n];
        for(int i = 0; i < n; i++){
            cin>>parent[i];
        }
        cout<<calculateHeight(parent, n)<<endl;
    }
}
