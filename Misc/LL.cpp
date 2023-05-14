#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // default constructor
    Node()
    {
        data = 0;
        next = nullptr;
    }
    // parameterised constructor
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    // default constructor
    LinkedList()
    {
        Node *newNode = new Node();
        head = newNode;
        tail = newNode;
        length = 1;
    }
    // parameterised constructor
    LinkedList(int data)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        Node *temp = head;
        while (temp)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void getHead();
    void getTail();
    void printList();
    void append(int);
};

void LinkedList::getHead()
{
    if (head == nullptr)
    {
        cout << "head: nullptr" << endl;
    }
    cout << "head: " << head->data << endl;
}
void LinkedList::getTail()
{
    if (tail == nullptr)
    {
        cout << "tail: nullptr" << endl;
    }
    cout << "tail: " << tail->data << endl;
}
void LinkedList::printList()
{
    Node *temp = head;
    cout << "LinkedList: " << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void LinkedList::append(int data)
{
    Node *newNode = new Node(data);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

int main()
{
    LinkedList *myLinkedList = new LinkedList(1);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->printList();
    cout << "-----------------------" << endl;
    myLinkedList->append(2);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->printList();
    cout << "-----------------------" << endl;
    myLinkedList->append(3);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->printList();
}