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
};

int main()
{

    LinkedList *myLinkedList = new LinkedList(11);
    cout << "======Before Insert======" << endl;
    myLinkedList->append(3);
    myLinkedList->append(23);
    myLinkedList->append(7);
    myLinkedList->printList();

    cout << "======After Insert in middle======" << endl;
    myLinkedList->insert(2, 4);
    myLinkedList->printList();

    cout << "======After Insert at index 0======" << endl;
    myLinkedList->insert(0, 4);
    myLinkedList->printList();

    cout << "======After Insert at index equal length ======" << endl;
    myLinkedList->insert(6, 4);
    myLinkedList->printList();

    cout << "======After Insert at index -1 ======" << endl;
    myLinkedList->insert(-1, 4);
    myLinkedList->printList();

    cout << "======After Insert at index 7 ======" << endl;
    myLinkedList->insert(8, 4);
    myLinkedList->printList();
    delete myLinkedList;
}
