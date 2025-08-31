#include <iostream>
using namespace std;
int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int i = 0;
    while (str[i] != '\0')
    {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            int j = i;
            while (str[j] != '\0')
            {
                str[j] = str[j + 1];
                j++;
            }
        }
        else
            i++;
    }

    cout << "after vowel deletion: " << str << endl;
    return 0;
}
