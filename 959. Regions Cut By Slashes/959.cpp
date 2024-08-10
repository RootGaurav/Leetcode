class Solution {
public:
    void islandcolor(int i,int j,vector<vector<int>> &island,int n)
    {
        if(i<0 or i>=n or j<0 or j>=n or island[i][j]==0)
            return;
        island[i][j]=0;
        islandcolor(i+1,j,island,n);
        islandcolor(i,j+1,island,n);
        islandcolor(i-1,j,island,n);
        islandcolor(i,j-1,island,n);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> island(3*n,vector<int> (3*n,1));
        for(int i=0;i<n;i++)
        {
            int row=i*3;
            int top=0,j=0;
            while(top<grid[i].length())
            {
                if(grid[i][top]=='/')
                {
                    int x=row;
                    int y=j+2;int count=3;
                    while(count--)
                    {
                        island[x][y]=0;
                        x++;
                        y--;
                    }
                }
                else if(grid[i][top]=='\\')
                {
                    int x=row;
                    int y=j;int count=3;
                    while(count--)
                    {
                        island[x][y]=0;
                        x++;
                        y++;
                    }
                }
                top++;
                j+=3;
            }
        }
        int ans=0;
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(island[i][j]!=0)
                {
                    ans++;
                    islandcolor(i,j,island,3*n);
                }
            }
        }
        return ans;
    }
};