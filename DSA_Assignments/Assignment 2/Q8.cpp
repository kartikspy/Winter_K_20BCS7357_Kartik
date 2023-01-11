#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void deletekthNodeFromEnd(Node *head, int k)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < k; i++)
        fast = fast->next;

    if (fast == NULL)
    {
        head = head->next;
        return;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return;
}
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}
int main()
{
    cout << "\nEnter number of values in linked list: ";
    int n;
    cin >> n;
    cout << "\nEnter the values: ";
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        Node *temp = new Node(k);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "\nEnter value of k: ";
    int k;
    cin >> k;

    cout << "\nOriginal Linked list: ";
    printList(head);

    deletekthNodeFromEnd(head, k);

    cout << "Modified Linked list: ";
    printList(head);

    return 0;
}
