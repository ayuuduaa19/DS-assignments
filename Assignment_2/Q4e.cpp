#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a string:";
    char str[100];
    cin.getline(str, 100);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
    cout << "After Lowercase:" << str << endl;
    return 0;
}