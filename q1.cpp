#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }
    
    void insertFirst(int value) {
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
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    
    void insertLast(int value) {
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
    
    void insertAfter(int target, int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Target node not found\n";
    }
    
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        
        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        
        prev = head;
        temp = head->next;
        while (temp != head) {
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Node not found\n";
    }
    
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found\n";
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }
    
    void insertFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    
    void insertLast(int value) {
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
    
    void insertAfter(int target, int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Target node not found\n";
    }
    
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (head->data == value) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node not found\n";
            return;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }
    
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found\n";
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, listType, value, target;
    
    while (true) {
        cout << "\n1. Insert First\n2. Insert Last\n3. Insert After\n";
        cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 7) break;
        
        cout << "Select list type (1-CLL, 2-DLL): ";
        cin >> listType;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                if (listType == 1) cll.insertFirst(value);
                else dll.insertFirst(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                if (listType == 1) cll.insertLast(value);
                else dll.insertLast(value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                if (listType == 1) cll.insertAfter(target, value);
                else dll.insertAfter(target, value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                if (listType == 1) cll.deleteNode(value);
                else dll.deleteNode(value);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (listType == 1) cll.search(value);
                else dll.search(value);
                break;
            case 6:
                if (listType == 1) cll.display();
                else dll.display();
                break;
        }
    }
    return 0;
}