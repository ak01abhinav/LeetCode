#include <iostream>
#include <algorithm> // for max()
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int value) : val(value), next(nullptr) {}
};

void insertAtEnd(node *&head, int val)
{
    node *newNode = new node(val);
    if (!head)
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

void traverse(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int twinSum(node *head)
{
    // Find middle
    node *slow = head, *fast = head;
    node *prevMid;
    while (fast && fast->next)
    {
        prevMid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    node *prev = nullptr, *curr = slow, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    node *secondHead = prev;    // reversed second half
    prevMid->next = secondHead; // wiring (optional if restoring later)

    // Find twin sums
    node *first = head, *second = secondHead;
    int twinSum = 0;
    while (second)
    {
        twinSum = max(twinSum, first->val + second->val);
        first = first->next;
        second = second->next;
    }
    return twinSum;
}

int main()
{
    node *head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << twinSum(head) << endl;
}
