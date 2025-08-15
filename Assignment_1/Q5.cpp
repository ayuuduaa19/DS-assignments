#include <iostream>
using namespace std;
void sum(int arr[][50], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "The sum of row " << i + 1 << ": " << sum << endl;
    }
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        cout << "The sum of col " << j + 1 << ": " << sum << endl;
    }
}
int main()
{
    int arr[50][50] = {{1, 2}, {3, 4}, {5, 6}};
    sum(arr, 3, 2);
}