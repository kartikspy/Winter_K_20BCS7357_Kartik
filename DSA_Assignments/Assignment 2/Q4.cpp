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
Node *merge(Node *list1, Node *list2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (list1 != NULL || list2 != NULL)
    {
        if (list1 == NULL && list2 != NULL)
        {
            if (head == NULL)
            {
                head = list2;
                tail = list2;
            }
            else
                tail->next = list2;
            break;
        }
        else if (list1 != NULL && list2 == NULL)
        {
            if (head == NULL)
            {
                head = list1;
                tail = list1;
            }
            else
                tail->next = list1;
            break;
        }
        Node *temp = NULL;
        if (list1->data <= list2->data)
        {
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp = list2;
            list2 = list2->next;
        }
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (!slow->next && (!fast && !fast->next))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *sort(Node *head)
{

    if (head->next == NULL)
        return head;

    Node *mid = middle(head);
    Node *head2 = mid->next;
    mid->next = NULL;
    Node *finalhead = merge(sort(head), sort(head2));
    return finalhead;
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

    cout << "\nLinked list1: ";
    printList(head1);

    cout << "\nLinked list2: ";
    printList(head2);

    head1 = sort(head1);
    head2 = sort(head2);

    cout << "Linked list after merging: ";
    Node *mergedHead = merge(head1, head2);
    printList(mergedHead);

    return 0;
}
