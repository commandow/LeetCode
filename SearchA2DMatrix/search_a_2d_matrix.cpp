#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        int row = matrix.size();
        if (row == 0)
        {
            return false;
        }

        int col = matrix[0].size();

        int start = 0;
        int end = row - 1;
        int med = start + (end - start) / 2;

        // 二分法找行
        while (med != start)
        {
            if (matrix[med][0] == target)
            {
                return true;
            }

            if (matrix[med][0] > target)
            {
                end = med;
            }
            else
            {
                start = med;
            }

            med = start + (end - start) / 2;
        }

        int exact_row = end;
        if (matrix[end][0] > target)
        {
            exact_row = start;
        }

        start = 0;
        end = col - 1;
        med = start + (end - start) / 2;

        // 二分法找列
        while (start != med)
        {
            if (matrix[exact_row][med] == target)
            {
                return true;
            }

            if (matrix[exact_row][med] > target)
            {
                end = med;
            }
            else
            {
                start = med;
            }

            med = start + (end - start) / 2;
        }

        if (matrix[exact_row][start] == target
            || matrix[exact_row][end] == target)
        {
            return true;
        }

        return false;
    }
};

int main(int argc, char **argv)
{
    Solution test;

    vector<vector<int> > matrix;

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    matrix.push_back(A);

    vector<int> B;
    B.push_back(6);
    B.push_back(9);
    B.push_back(10);
    matrix.push_back(B);

    bool ret = test.searchMatrix(matrix, 5);
    cout << ret << endl;

    int f;
    cin >> f;
}