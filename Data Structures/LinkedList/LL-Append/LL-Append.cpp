#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    // parameterised constructor
    Node(int value)
    {
        this->value = value;
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
    // parameterised constructor
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        // head, tail, length will be removed by default destructor
        //  e.g 4, 6, 8, 10  - we need to remove these nodes

        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void getHead();
    void getTail();
    void getLength();
    void printList();
    void append(int);
};

void LinkedList::getHead()
{
    if (head == nullptr)
    {
        cout << "Head: nullptr " << endl;
    }
    cout << "Head: " << head->value << endl;
}
void LinkedList::getTail()
{
    if (tail == nullptr)
    {
        cout << "Tail: nullptr " << endl;
    }
    cout << "Tail: " << tail->value << endl;
}
void LinkedList::getLength()
{
    cout << "Length: " << length << endl;
}
void LinkedList::printList()
{
    Node *temp = head;
    cout << "LinkedList: " << endl;
    while (temp)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
void LinkedList::append(int value)
{
    Node *newNode = new Node(value);
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
    myLinkedList->getLength();
    myLinkedList->printList();
    cout << "==================" << endl;
    myLinkedList->append(2);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();

    delete myLinkedList;
}