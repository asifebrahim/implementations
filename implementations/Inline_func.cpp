function <void(int,int,int)> dfs=[&](int r,int c,int count){
    if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==-1){
        return;
    }

    if(grid[r][c]==2){
        if(count==empty) paths++;
        return;
    }
    grid[r][c]=-1;
    dfs(r+1,c,count+1);
    dfs(r-1,c,count+1);
    dfs(r,c+1,count+1);
    dfs(r,c-1,count+1);
    grid[r][c]=0;

};


//R is row,c is column and count is the number of empty cells visited so far
//If we reach the destination and count is equal to the number of empty cells then we increment the number of paths
// Leetcode problem unique paths III


//Below is the complete code for the problem unique paths III
//https://leetcode.com/problems/unique-paths-iii/
/*

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int empty=1,startRow,startCol,paths=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startRow=i;
                    startCol=j;
                }else if(grid[i][j]==0) empty++;
            }
        }

        function <void(int,int,int)> dfs=[&](int r,int c,int count){
            if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==-1){
                return;
            }

            if(grid[r][c]==2){
                if(count==empty) paths++;
                return;
            }
            grid[r][c]=-1;
            dfs(r+1,c,count+1);
            dfs(r-1,c,count+1);
            dfs(r,c+1,count+1);
            dfs(r,c-1,count+1);
            grid[r][c]=0;

        };
        dfs(startRow,startCol,0);
        return paths;
    }
};

*/