// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool solve(vector<vector<char>>& board, int i, int j, string word, int k)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m)
        return false;
        
        if(k == word.length())
        return true;
        
        if(word[k] == board[i][j])
        {
            char temp = board[i][j];
            board[i][j] = '&';
            
            bool a=solve(board,i+1,j,word,k+1); 
            bool b=solve(board,i-1,j,word,k+1);
            bool c=solve(board,i,j+1,word,k+1);
            bool d=solve(board,i,j-1,word,k+1);
            board[i][j]=temp;
            return a||b||c||d;
        }
        
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(board,i,j,word,0))
                    return true;
                }
            }
        }
        
        return false;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends