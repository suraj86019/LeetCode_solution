//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  map<vector<int>,int>ans;
  
  void help(vector<int>& nums,int i,vector<int> v){
      if(i>=nums.size()){
         ans[v]++;
          return ;
      }
    help(nums,i+1,v);
    // for(int j=i;j<nums.size();j++){
         v.push_back(nums[i]);
         help(nums,i+1,v);
        
   //  }
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
     help(nums,0,{});
        vector<vector<int>>res;
        for(auto it:ans){
            res.push_back(it.first);
        }
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends