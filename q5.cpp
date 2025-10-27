#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = nullptr; }
    
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void makeCircular() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
    }
    
    bool isCircular() {
        if (head == nullptr) return false;
        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }
        return (temp == head);
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << temp->data;
        temp = temp->next;
        while (temp != nullptr && temp != head) {
            cout << "->" << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    int n, value;
    char choice;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        ll.insert(value);
    }
    
    cout << "Make it circular? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        ll.makeCircular();
    }
    
    cout << "LinkedList: ";
    ll.display();
    
    if (ll.isCircular()) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }
    
    return 0;
}