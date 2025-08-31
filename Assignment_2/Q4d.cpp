#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (str[j] > str[j + 1])
                swap(str[j], str[j + 1]);
        }
    }

    cout << "Sorted string:" << str << endl;
    return 0;
}