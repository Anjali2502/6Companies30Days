// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        
        map<int,vector<int>>row,col,box;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j])
                {
                    int ele = mat[i][j];
                    
                    auto itr1 = find(row[i].begin(),row[i].end(),ele);
                    if(itr1 != row[i].end())
                    return 0;
                    
                    auto itr2 = find(col[j].begin(),col[j].end(),ele);
                    if(itr2 != col[j].end())
                    return 0;
                    
                    int box_no = ((i/3)*3 + (j/3));
                    
                    auto itr3 = find(box[box_no].begin(),box[box_no].end(),ele);
                    if(itr3 != box[box_no].end())
                    return 0;
                    
                    row[i].push_back(ele);
                    col[j].push_back(ele);
                    box[box_no].push_back(ele);
                }
            }
        }
        
        return 1;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends