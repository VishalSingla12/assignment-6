#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }
    
    void insert(char value) {
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
    
    bool isPalindrome() {
        if (head == nullptr) return true;
        
        Node* left = head;
        Node* right = head;
        while (right->next != nullptr) {
            right = right->next;
        }
        
        while (left != right && left->prev != right) {
            if (left->data != right->data) {
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
    
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insert(ch);
    }
    
    cout << "List: ";
    dll.display();
    
    if (dll.isPalindrome()) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }
    
    return 0;
}