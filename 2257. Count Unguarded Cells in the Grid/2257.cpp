class Solution {
public:
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
	int ans = m * n - walls.size();
	vector<vector<char>> grid(m, vector<char>(n, 0)); 
	for (int i = 0; i < walls.size(); ++i)
		grid[walls[i][0]][walls[i][1]] = -1;
	for (int i = 0; i < guards.size(); ++i) {
		int y = guards[i][0], x = guards[i][1];
		if (grid[y][x] == 0) --ans;
		grid[y][x] = 3;
		int d = x + 1;
		while (d < n && !(grid[y][d] & 1)) {
			if (grid[y][d] == 0) --ans;
			grid[y][d] |= 1;
			++d;
		}
		d = x - 1;
		while (d > -1 && !(grid[y][d] & 1)) {
			if (grid[y][d] == 0) --ans;
			grid[y][d] |= 1;
			--d;
		}
		d = y + 1;
		while (d < m && grid[d][x] != -1 && grid[d][x] < 2) {
			if (grid[d][x] == 0) --ans;
			grid[d][x] |= 2;
			++d;
		}
		d = y - 1;
		while (d > -1 && grid[d][x] != -1 && grid[d][x] < 2) {
			if (grid[d][x] == 0) --ans;
			grid[d][x] |= 2;
			--d;
		}
		if (ans == 0) return 0;
	}
	return ans;
}

};