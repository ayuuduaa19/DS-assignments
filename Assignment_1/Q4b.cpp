#include <iostream>
using namespace std;
void multi(int arr[][50], int brr[][50], int res[][50], int row1, int col1, int row2, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                res[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }
}

int main()
{
    int arr[50][50] = {{1, 2, 3}, {3, 4, 5}};
    int brr[50][50] = {{1}, {2}, {3}};
    int res[50][50] = {0};
    multi(arr, brr, res, 2, 3, 3, 1);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}