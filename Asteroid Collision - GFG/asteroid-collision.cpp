//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &nums) {
        stack<int>st;
        vector<int>ans;
        for(int i=N-1;i>=0;i--){
            int kt=0;
            if(nums[i]>0){
            while(!st.empty() && st.top()<0){
                if(abs(st.top())<nums[i]){
                    st.pop();
                }else if(abs(st.top())>nums[i]){
                    kt=-1;
                    break;
                }else if(nums[i]==abs(st.top())){
                    kt=-1;
                    st.pop();
                    break;
                }
             }
            }
            if(kt!=-1){
                st.push(nums[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
      //  reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends