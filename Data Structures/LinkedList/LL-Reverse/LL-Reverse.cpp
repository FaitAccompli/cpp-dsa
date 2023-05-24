#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

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
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        if (head == nullptr)
        {
            cout << "Head: nullptr" << endl;
        }
        else
        {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail()
    {
        if (tail == nullptr)
        {
            cout << "Tail: nullptr" << endl;
        }
        else
        {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int value)
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

    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }

        length--;
        delete temp;

        // 1 => 2 => 3 => nullptr
        // 1 => nullptr
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            // 1,2,3,4 => nullptr
        }
        length++;
    }
    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }
    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
        }
        // 1 => 2 => 4 => 6
        // 1 => 2 => 4 => 6 => nullptr
        // 0 => 1 => 2 => 3 => nullptr
    }
    bool set(int index, int value)
    {
        Node *temp = this->get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool insert(int index, int value)
    {
        // 11 -> 3 -> 23 -> 7
        // insert at index 2, the value 4
        // 11 -> 3 -> 4 -> 23 -> 7
        if (index < 0 || index > length)
        {
            return false;
        }
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1);

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }
    void deleteNode(int index)
    {

        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return deleteFirst();
        if (index == length - 1)
            return deleteLast();
        // 11 -> 3 -> 23 -> 7 -> nullptr
        // 0  -> 1 -> 2  -> 3 -> nullptr
        // remove node at index 2
        Node *prev = get(index - 1);
        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
        return;
    }
    void reverse()
    {
        // before reverse
        // h                t
        // 11 -> 3 -> 23 -> 7 -> nullptr
        // after reverse
        //             t               h
        // nullptr <- 11 <- 3 <- 23 <- 7
        Node *temp = head;
        Node *before = nullptr;
        Node *after = temp->next;
        head = tail;
        tail = temp;
        while (temp)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
            // before     temp  after
            // nullptr -> 11 -> 3 -> 23 -> 7 -> nullptr
            //            before temp
            // nullptr <- 11 -> 3 -> 23 -> 7 -> nullptr
            //              before   temp
            // nullptr <- 11 <- 3 -> 23 -> 7 -> nullptr
            //                     before temp
            // nullptr <- 11 <- 3 <- 23 -> 7 -> nullptr
            //                          before  temp
            // nullptr <- 11 <- 3 <- 23 <- 7 -> nullptr
        }
    }
};

int main()
{

    LinkedList *myLinkedList = new LinkedList(11);
    myLinkedList->append(3);
    myLinkedList->append(23);
    myLinkedList->append(7);
    cout << "======Before Reverse======" << endl;
    // 11 -> 3 -> 23 -> 7 -> nullptr
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->printList();

    cout << "======After Reverse======" << endl;
    // 7 -> 23 -> 3 -> 11 -> nullptr
    myLinkedList->reverse();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->printList();

    delete myLinkedList;
}
