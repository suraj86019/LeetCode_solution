//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<string>ans;
   void help(int i,string s,set<string>& st,string temp){
        if(i>=s.size()){
            temp.pop_back();
                ans.push_back(temp);
                return ;
            }
        
        string tm;
        for(int j=i;j<s.size();j++){
            tm+=s[j];
            if(st.find(tm)!=st.end()){
                string jemp = temp+tm+" ";
              help(j+1,s,st,jemp);
            }
        }
        return ;
    }

    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        set<string>st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
         help(0,s,st,"");
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends