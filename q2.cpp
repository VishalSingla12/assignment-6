#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }
    
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    void displayWithHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int n, value;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insert(value);
    }
    
    cout << "Output: ";
    cll.displayWithHead();
    
    return 0;
}