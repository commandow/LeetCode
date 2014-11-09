#include <vector>
#include <iostream>

using namespace std;

/********************************************************
采用动态规划的思想：
1）最优解公式
C(i, j) = Min[ C(i-1, j), C(i, j - 1) ] + Grid[i][j], i > 0, j > 0
2）初始值的边界情况：
当 i == 0, j == 0时，C(i, j) = Grid[i][j]
当 i == 0, j > 0时，C(i, j) = C(i, j - 1) + Grid[i][j]
当 i > 0, j == 0时，C(i, j) = C(i -1, j) + Grid[i][j]
*********************************************************/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {

        int m = grid.size();
        int n = grid[0].size();

        // 最优解矩阵
        vector<vector<int> > c;

        vector<int> e;
        int d = 0;
        
        for (int i = 0; i < m; i ++)
        {
            e.clear();

            for (int j = 0; j < n; j ++)
            {
                
                if (i == 0)
                {
                    d += grid[i][j];
                    e.push_back(d);

                    continue;
                }

                if (j == 0)
                {
                    d = c[i - 1][j] + grid[i][j];
                    e.push_back(d);
                    continue;
                }

                d = d > c[i - 1][j] ? c[i - 1][j] + grid[i][j] : d + grid[i][j];
                e.push_back(d);
            }

            // 一行一行的计算最优解
            c.push_back(e);
        }

        return c[m - 1][n - 1];
    }
};

vector<int> make_row(int a, int b, int c)
{
    vector<int> ret;
    ret.push_back(a);
    ret.push_back(b);
    ret.push_back(c);

    return ret;
}

int main(int argc, char **argv)
{
    Solution test;

    vector<vector<int> > grid;

    vector<int> a;

    a = make_row(5, 1, 3);
    grid.push_back(a);

    a = make_row(3, 2, 4);
    grid.push_back(a);

    a = make_row(4, 7, 9);
    grid.push_back(a);

    int ret = test.minPathSum(grid);

    cout << ret << endl;

    int f;
    cin >> f;
}