#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& grid, int i, int j) {
    cout << "grid[i][j] : " << grid[i][j] << endl;
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    cout << "over here.";
    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);        
}

int main() {
    vector<vector<int>> input = {{0, 1}};
    cout << "input[0][1] = " << input[0][1] << endl;
    cout << dfs(input, 0, 1) << endl;
    return 0;
}