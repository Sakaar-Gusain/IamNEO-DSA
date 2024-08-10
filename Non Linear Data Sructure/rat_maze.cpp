/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination
at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a
cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in
the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot 
move to any other cell. In case of no path, return an empty list. 
The driver will output "-1" automatically.

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void findPaths(vector<vector<int>> &mat, int n, int x, int y, vector<string> &paths, string path, vector<vector<int>> &visited) {
        // Base condition: If destination is reached
        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Move Down
        if (x + 1 < n && mat[x + 1][y] == 1 && visited[x + 1][y] == 0) {
            findPaths(mat, n, x + 1, y, paths, path + 'D', visited);
        }

        // Move Right
        if (y + 1 < n && mat[x][y + 1] == 1 && visited[x][y + 1] == 0) {
            findPaths(mat, n, x, y + 1, paths, path + 'R', visited);
        }

        // Move Up
        if (x - 1 >= 0 && mat[x - 1][y] == 1 && visited[x - 1][y] == 0) {
            findPaths(mat, n, x - 1, y, paths, path + 'U', visited);
        }

        // Move Left
        if (y - 1 >= 0 && mat[x][y - 1] == 1 && visited[x][y - 1] == 0) {
            findPaths(mat, n, x, y - 1, paths, path + 'L', visited);
        }

        // Backtrack: Unmark the current cell
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> paths;

        // If starting or ending point is blocked
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return paths;
        }

        // Visited matrix to keep track of visited cells
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Start the pathfinding
        findPaths(mat, n, 0, 0, paths, "", visited);

        // Sort the paths lexicographically
        sort(paths.begin(), paths.end());

        return paths;
    }
};

// Hardcoded input and output
int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = sol.findPath(mat);

    if (result.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string &path : result) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
