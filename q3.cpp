#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }
    
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
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
    
    int getSize() {
        if (head == nullptr) return 0;
        int count = 1;
        Node* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int n, value;
    
    cout << "Enter number of nodes for DLL: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        dll.insert(value);
    }
    cout << "Size of DLL: " << dll.getSize() << endl;
    
    cout << "\nEnter number of nodes for CLL: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insert(value);
    }
    cout << "Size of CLL: " << cll.getSize() << endl;
    
    return 0;
}