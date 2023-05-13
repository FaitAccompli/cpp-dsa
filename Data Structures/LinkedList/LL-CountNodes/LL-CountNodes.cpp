#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int countNodes(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    // 4, 2, 3, 10, 2
    Node *head = new Node(4);
    Node *nodeB = new Node(2);
    Node *nodeC = new Node(3);
    Node *nodeD = new Node(10);
    Node *nodeE = new Node(2);

    head->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nodeE;

    cout << "Nodes on this Linked List: " << countNodes(head) << endl;
}