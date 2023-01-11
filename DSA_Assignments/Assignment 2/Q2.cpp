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
void deleteAlternateNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *temp = head->next;
    head->next = temp->next;

    delete temp;

    deleteAlternateNode(head->next);
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

    cout << "\nOriginal Linked list: ";
    printList(head);

    deleteAlternateNode(head);

    cout << "Modified Linked list: ";
    printList(head);

    return 0;
}
