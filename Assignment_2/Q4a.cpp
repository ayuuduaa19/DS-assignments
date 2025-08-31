#include <iostream>
using namespace std;
int main()
{
    char s1[100], s2[50];
    cout << "Enter first string: ";
    cin.getline(s1, 100);
    cout << "Enter second string: ";
    cin.getline(s2, 50);

    int len = 0, j = 0;
    while (s1[len] != '\0')
        len++;
    while (s2[j] != '\0')
    {
        s1[len] = s2[j];
        len++;
        j++;
    }
    s1[len] = '\0';

    cout << "Concatenated string: " << s1 << endl;
    return 0;
}
