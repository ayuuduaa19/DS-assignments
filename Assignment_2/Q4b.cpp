#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter a string:";
    cin.getline(str, 100);
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    int i = 0, j = len - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }

    cout << "Reversed string:" << str << endl;
    return 0;
}