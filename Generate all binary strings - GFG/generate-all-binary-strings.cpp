//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void help(string s,int i,int n){
        if(i==n){
            cout<<s<<" ";
            return ;
        }
        s.push_back('0');
        help(s,i+1,n);
        s.pop_back();
        if(i>0 && s[i-1]!='1'){
            s.push_back('1');
            help(s,i+1,n);
        }else if(i==0){
            s.push_back('1');
            help(s,i+1,n);
        }
    }
   

    void generateBinaryStrings(int& num){
       help("",0,num);
       return ;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends