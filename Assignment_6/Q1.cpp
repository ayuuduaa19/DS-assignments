#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) { data = d; next = prev = NULL; }
};

void insertNode(Node*& tail, int element, int d) {
    Node* newNode = new Node(d);

    if (tail == NULL) { 
        tail = newNode;
        tail->next = tail->prev = tail;
        return;
    }

    Node* curr = tail;
    while (curr->data != element) {
        curr = curr->next;
        if (curr == tail) break;
    }

    Node* nextNode = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = nextNode;
    nextNode->prev = newNode;

    if (curr == tail) tail = newNode;
}

void deleteNode(Node*& tail, int value) {
    if (tail == NULL) { cout << "List empty" << endl; return; }

    Node* curr = tail->next;
    Node* prev = tail;

    do {
        if (curr->data == value) {
            if (curr->next == curr) { delete curr; tail = NULL; return; }
            prev->next = curr->next;
            curr->next->prev = prev;
            if (curr == tail) tail = prev;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Node not found" << endl;
}

void print(Node* tail) {
    if (tail == NULL) { cout << "List empty" << endl; return; }

    Node* temp = tail->next;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

bool search(Node* tail, int value) {
    if (tail == NULL) return false;

    Node* temp = tail->next;
    do {
        if (temp->data == value) return true;
        temp = temp->next;
    } while (temp != tail->next);

    return false;
}

int main() {
    Node* tail = NULL;
    int choice, element, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Print List\n";
        cout << "4. Search Node\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (tail == NULL) {
                    cout << "List is empty. Enter value to insert: ";
                    cin >> value;
                    insertNode(tail, 0, value);
                } else {
                    cout << "Enter element after which to insert: ";
                    cin >> element;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insertNode(tail, element, value);
                }
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(tail, value);
                break;

            case 3:
                print(tail);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(tail, value)) cout << "Found\n";
                else cout << "Not Found\n";
                break;

            case 5:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
