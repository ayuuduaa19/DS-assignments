#include <iostream>
using namespace std;
void transpose(int arr[][50], int res[][50], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[50][50] = {{1, 2, 3}, {3, 4, 5}};
    int res[50][50] = {0};
    transpose(arr, res, 2, 3);
}