class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector <int> adj[numCourses]; 
	   // int k = prerequisites.size();
	    for(int i=0;i<prerequisites.size();i++) 
	    {
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    vector<int>indegree(numCourses,0);
	    
	    for(int i=0;i<numCourses;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<numCourses;i++)
	    {
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	    
	    // int count = 0;
	    while(!q.empty())
	    {
	        // count++;
            ans.push_back(q.front());
	        int node = q.front();
	        q.pop();
	        
	        for(int i=0;i<adj[node].size();i++)
	        {
	            indegree[adj[node][i]]--;
	            if(indegree[adj[node][i]] == 0)
	            q.push(adj[node][i]);
	        }
	    }
	    
	    if(ans.size()  == numCourses)
	    return ans;
	    
        vector<int>a;
	    return a;
    }
};