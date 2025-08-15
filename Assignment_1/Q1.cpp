#include <iostream>
using namespace std;
void create(int arr[], int size)
{
    cout << "Enter array elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void insert(int arr[], int size, int el, int pos)
{
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = el;
}

void del(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[50], size;

    while (1)
    {
        int p;
        cout << "Enter program" << endl;
        cout << "1.CREATE" << endl
             << "2.DISPLAY" << endl
             << "3.INSERT" << endl
             << "4.DELETE" << endl
             << "5.LINEAR SEARCH" << endl
             << "6.EXIT" << endl;
        cin >> p;
        switch (p)
        {
        case 1:
        {
            cout << "Enter size of array (less than 50):";
            cin >> size;
            create(arr, size);
            break;
        }
        case 2:
        {
            display(arr, size);
            break;
        }

        case 3:
        {
            size = size + 1;
            int pos, el;
            cout << "Enter position and element:";
            cin >> pos >> el;
            insert(arr, size, el, pos);
            display(arr, size);
            break;
        }
        case 4:
        {
            int index;
            cout << "Enter index:";
            cin >> index;
            del(arr, size, index);
            size--;
            display(arr, size);
            break;
        }

        case 5:
        {
            int key;
            cout << "Enter key:";
            cin >> key;
            cout << "Element found at index:" << search(arr, size, key) << endl;

            break;
        }
        case 6:
        {
            exit(0);
        }
        default:

            cout << "Invalid choice.";
        }
    }
}