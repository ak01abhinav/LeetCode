#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int value)
    {
        val = value;
        next = nullptr;
    }
};

void traverse(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insEnd(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

node *oddEvenList(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    node *odd = head;
    node *even = head->next;
    node *evenHead = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    node *head = nullptr;
    insEnd(head, 1);
    insEnd(head, 2);
    insEnd(head, 3);
    insEnd(head, 4);
    insEnd(head, 5);

    traverse(head);
    traverse(oddEvenList(head));
}