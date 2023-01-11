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

Node *segregateEvenOdd(Node *head)
{
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *current = head;

    while (current != NULL)
    {
        int val = current->data;
        if (val % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = current;
                evenEnd = current;
            }
            else
            {
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = current;
                oddEnd = current;
            }
            else
            {
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
        }
        current = current->next;
    }

    if (oddStart == NULL)
        return evenStart;
    else if (evenStart == NULL)
        return oddStart;
    else
    {
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        return evenStart;
    }
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

    head = segregateEvenOdd(head);

    cout << "Modified Linked list: ";
    printList(head);

    return 0;
}
