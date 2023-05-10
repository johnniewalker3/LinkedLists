#include <iostream>
#include <unordered_map>
using namespace std;

#define N 10

class Node{
    public:
       int value;
       Node *Next;
};


//it will be the first node of the list and it will point to the old head.
void push_front(Node **head,int value);

//it will be the last node of the list.this node will point to NULL
void push_back(Node **head,int value);

//it will be placed after a given node of the list
void push_random(Node *previous, int value);

//prints the linked list
void print(Node *current);

//removes the nodes with duplicates values from linked list
void remove_duplicates(Node *head);

//removes the head node and sets the next node as the new head
void remove_first_node(Node **head);


//removes the last node 
void remove_last_node(Node *head);

//remove a node after a given node.Of course this node is not the first or the last node
void remove_after_node(Node *previous);

//creates a linked list that includes a loop
void create_circular_list(Node *head);

//detects if a linked list is a circular list
bool detect_loop(Node *head);

//insertion sort in linked list in ascending order
void insertion_sort(Node **head); 

//group all odd nodes together followed by the even nodes.Of course we are talking about the odd positions and the even positions.More specifically group all odd positions
//together followed by all even positions
void odd_even_list(Node *head);

//number of nodes in list
int Nodes_number(Node *head);


void reverse_list(Node **head);

bool palindrome(Node *head);

Node *mergeTwoLists(Node *list1, Node *list2){
    if (list1 == NULL && list2 == NULL)
            return list1;
    else if (list1 == NULL)
            return list2;
    else if (list2 == NULL)
        return list1;
        
    Node *head = new Node;
    if (list1->value<=list2->value)
    {
        head = list1;
        list1 = list1->Next;
    }
    else{
        head = list2;
        list2 = list2->Next;
    }
    head->Next = NULL;
    Node *current = head;
    while (list1 != NULL && list2!=NULL){
        Node *newnode = new Node;
            if (list1->value<=list2->value)
            {
                newnode = list1;
                list1 = list1->Next;
            }
            else{
                newnode = list2;
                list2 = list2->Next;
            }
        newnode->Next = NULL;
        current->Next = newnode;
        current = current->Next;
    }
    if (list1 == NULL)
       current->Next = list2;
    else if (list2 == NULL)
       current->Next = list1; 
    return head;
}



int main(){
    int value;
    Node *head = NULL;
    //cout<<"Read a value for the head node:";
    //cin>>value;
    head = new Node;
    head->value = 1;
    head->Next = NULL;
    //push_front(&head, 1);
    push_back(&head, 2);
    push_back(&head, 4);
    push_back(&head, 6);
    /*push_back(&head, 15);*/
    //push_back(&head, 4);
    //push_back(&head, 7);



    Node *head2 = new Node;
    head2->value = 1;
    head2->Next = NULL;
    push_back(&head2, 3);
    push_back(&head2, 5);
    push_back(&head2, 6);

    unordered_map<Node*, int> map;
    map[head] = 1;
    if (map.find(head->Next) == map.end())
       cout<<"me lene gianni"<<endl;
    else
       cout<<"Cant found that Node"<<endl;
    

    //Node *head3 = mergeTwoLists(head, head2);
    //print(head3);

    /*Node *current = head;
    while (current!=NULL){
        cout<<current->value<<" ";
        current = current->Next;
    }*/
    cout<<endl;
    
    return 0;
}

void push_front(Node **head, int value){
    Node *node = new Node;
    node->value = value;
    
    //check if the head node does not exist
    if (!(*head))
    {
        *head = node;
        (*head)->Next = NULL;
        return;
    }
    node->Next = *head;
    *head = node;
}


void push_back(Node **head, int value){
    Node *node = new Node;
    node->value = value;
    //node->Next = NULL;
    if (!(*head))
    {
        *head = node;
        (*head)->Next = NULL;
        return;
    }
    Node *current = *head;
    while (current!=NULL){
        if (current->Next == NULL){
            current->Next = node;
            current->Next->Next = NULL;
            break;
        }
        current = current->Next;
    }
    
}


void push_random(Node *previous, int value){
    Node *node;
    if (previous==NULL)
       throw "NULL pointer";
    node = new Node;
    node->value = value;
    node->Next = previous->Next;
    previous->Next = node;
}

void remove_duplicates(Node *head){
    Node *current = head;
    while (current !=NULL && current->Next != NULL){
        if (current->value != current->Next->value)
        {
            current = current->Next;
            continue;
        }
        else{
            Node *temp = current->Next;
            current->Next = temp->Next;
            delete temp;
        }
        
    }
}

void remove_first_node(Node **head){
     Node *temp = (*head)->Next;
     delete  *head;
     *head = NULL;
     *head = temp;
     
}


void remove_last_node(Node *head){
    Node *current = head;
    Node *previous = current;
    if (current)
    {
        previous = current;
        if (previous->Next == NULL)
            previous = NULL;
        while(current->Next !=NULL)
        {
            previous = current;
            current = current->Next;
        }
        delete  current;
        if (previous!= NULL)
           previous->Next = NULL;
        
    }
}

void remove_after_node(Node *previous){
    Node *current;
    if (!previous || !previous->Next)
    {
        cout<<"NULL pointer";
        return;
    }
    current = previous->Next;
    previous->Next = current->Next;
    delete current;
}

void create_circular_list(Node *head){
    Node *current = head;
    while (current->Next != NULL)
         current = current->Next;
    current->Next = head;
}

bool detect_loop(Node *head){
    Node *first = head;
    Node *second = head;
    if (!first)
       return 0;
    while (first!=NULL && second!=NULL){
        first = first->Next;
        if (second->Next == NULL)
        {
            second = NULL;
            break;
        }
        second = second->Next->Next;
        if (first == second)
           break;
    }
    if (first == NULL || second ==NULL)
       return 0;
    else 
       return 1;
}

void insertion_sort(Node **head){
    if ((*head)->Next == NULL || (*head) == NULL)
       throw "The number of elements needs for insertion sort is greater or equal to 2";
    
    Node *given_node = (*head)->Next;
    int count = 1;
    while(given_node != NULL)
    {
        Node *current = *head;
        Node *pre_current = NULL;
        Node *after_current = current->Next;
        Node *pre_given = *head;
        while (pre_given->Next != given_node)
              pre_given = pre_given->Next;
        Node *after_given = given_node->Next;
        count++;
        for (int i=1;i<count;i++){
            if (current->value > given_node->value){
                Node *temp;
                pre_given->Next = current;
                if (pre_current == NULL)
                {
                    *head = given_node;
                    given_node = current;
                    given_node->Next = after_given;
                    current = *head;
                    if (current == after_current)
                       current->Next = given_node;
                    else
                       current->Next = after_current;
                }
                else{
                    temp = current;
                    pre_current->Next = given_node;
                    current = given_node;
                    given_node = temp;
                    given_node->Next = after_given;
                    if (current == after_current)
                       current->Next = given_node;
                    else
                       current->Next = after_current;
                }
            }
            pre_current = current;
            current = current->Next;
            after_current = current->Next;
        }
        given_node = given_node->Next;
    }
}

int Nodes_number(Node *head){
    Node *current = head;
    int count = 1;
    while (current->Next != NULL)
    {
        current = current->Next;
        count++;
    }
    return count;
}

void odd_even_list(Node *head){
    int array[N];
    int number = Nodes_number(head);
    if (number % 2 == 0 || number <=2)
       throw "The number of nodes needs to be an odd nmumber and greater than 2";
    for (int i=1;i<=number;i++)
        array[i - 1] = i;
    int count = 1;
    bool flag = true;
    Node *pre_current = head;
    Node *current = head->Next;
    Node *after_current = current->Next;
    Node *after = after_current->Next;
    while (flag){
        int found = 0;
        Node *temp = NULL;
        if (array[count] % 2 == 0 && array[count+1] % 2 == 1){
            int temp1;
            pre_current->Next = after_current;
            temp = current;
            current = after_current;
            after_current = temp;
            current->Next = after_current;
            after_current->Next = after;
            temp1 = array[count];
            array[count] = array[count+1];
            array[count+1] = temp1;
        }
        else{
            for (int i=0;i<number;i++){
                if (array[i] % 2 == 0)
                   found = 1;
                if (array[i] % 2 == 1 && found == 1){
                    found = 2;
                    break;
                }
            }
        }
        if (found == 1)
        {
            flag = false;
            continue;
        }
        pre_current = current;
        current = current->Next;
        if (current != NULL && current->Next != NULL)
        {
            after_current = current->Next;
            after = after_current->Next;
            count++;
        }
        else{
            pre_current = head;
            current = head->Next;
            after_current = current->Next;
            after = after_current->Next;
            count = 1;
        }
    }
}


void reverse_list(Node **head){
    const int number = Nodes_number(*head);
    Node **arr = new Node *[number];
    if (!arr)
       throw "Error allocation memory";
    int i=0;
    Node *current = *head;
    while (current->Next != NULL){
        arr[i] = current;
        i++;
        current = current->Next;
    }
    arr[i] = current;
    i=number-1;
    *head = arr[i];
    --i;
    current = *head;
    while (i>0){
        current->Next = arr[i];
        --i;
        current = current->Next;
    }
    current->Next = arr[0];
    current = current->Next;
    current->Next = NULL;
    delete [] arr;
}

bool palindrome(Node *head){
    int number = Nodes_number(head);
    if (number == 1)
       return 1;
    
    int *arr = new int [number];
    Node *current = head;
    for (int i=0;i<number;i++){
        arr[i] = current->value;
        current = current->Next;
    }
    bool flag = true;
    for (int i=0;i<number/2;i++)
    {
        if (arr[i] != arr[number-1-i])
        {
            flag = false;
            break;
        }
    }
    return flag;
    
}



void print(Node *head){
    Node *current = head;
    while (current!=NULL){
        cout<<current->value<<" ";
        current = current->Next;
    }
}