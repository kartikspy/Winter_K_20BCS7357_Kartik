#include <iostream>
#include <unordered_map>
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
void Common(Node *head1, Node *head2, Node *head3)
{
    unordered_map<int, int> m;

    Node *current = head1;
    while (current != NULL)
    {
        m[current->data] = 1;
        current = current->next;
    }

    current = head2;
    while (current != NULL)
    {
        if (m.count(current->data))
            m[current->data] = 2;
        current = current->next;
    }

    current = head3;
    while (current != NULL)
    {
        if (m.count(current->data) && m[current->data] == 2)
            m[current->data] = 3;
        current = current->next;
    }

    for (auto i : m)
    {
        if (i.second == 3)
            cout << i.first << " ";
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
    cout << "\nEnter number of values in linked list 1: ";
    int n1;
    cin >> n1;
    cout << "\nEnter the values: ";
    Node *head1 = NULL;
    Node *tail1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        int k;
        cin >> k;
        Node *temp = new Node(k);
        if (head1 == NULL)
        {
            head1 = temp;
            tail1 = temp;
        }
        else
        {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    cout << "\nEnter number of values in linked list 2: ";
    int n2;
    cin >> n2;
    cout << "\nEnter the values: ";
    Node *head2 = NULL;
    Node *tail2 = NULL;
    for (int i = 0; i < n2; i++)
    {
        int k;
        cin >> k;
        Node *temp = new Node(k);
        if (head2 == NULL)
        {
            head2 = temp;
            tail2 = temp;
        }
        else
        {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    cout << "\nEnter number of values in linked list 3: ";
    int n3;
    cin >> n3;
    cout << "\nEnter the values: ";
    Node *head3 = NULL;
    Node *tail3 = NULL;
    for (int i = 0; i < n3; i++)
    {
        int k;
        cin >> k;
        Node *temp = new Node(k);
        if (head3 == NULL)
        {
            head3 = temp;
            tail3 = temp;
        }
        else
        {
            tail3->next = temp;
            tail3 = temp;
        }
    }

    cout << "\nLinked list1: ";
    printList(head1);

    cout << "\nLinked list2: ";
    printList(head2);

    cout << "\nLinked list3: ";
    printList(head3);

    cout << "Common elements in the 3 linked lists are: ";
    Common(head1, head2, head3);

    return 0;
}
