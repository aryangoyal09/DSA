#include <iostream>
using namespace std;

// Node class
class Node{
    public:
    // Creating class objects
    string name;
    int age;
    Node*next; // A node pointer for next node
    Node*prev; // A node pointer for previous node
    // calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; // initialising next as NULL
        prev=NULL; // initialising prev as NULL
    }
};

//Function to insert data at start
void append(Node* &head,string name,int age){
    // Creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    // Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    // Inserting node in non empty list
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

// Function to insert data at start
void insert_at_head(Node*&head,string name,int age){
    // Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    // Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

// Function for displaying data from start
void display_from_start(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}

// Function for  displaying data form end
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

// Function for deleting index(0,n-1)
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

// Function for Deleting last element
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    // Initialising an empty linked list
    Node*head=NULL;
	int no_of_family_mem;
    // Taking no of family mem as input
	cout<<"Enter Number Of Family Members:";cin>>no_of_family_mem;
    // Inserting family members details
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        // Appending data name and age
		append(head,name,age);
	}
    cout<<endl;// For space
    // Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    display_from_start(head);
}

/*BONUS QUESTION

Q.Try to find a way to link the family members' doubly-linked list based on their relationship.

Ans.This can be done by sorting the doubly linked list according to age in decending order.
By doing so we will get a doubly linked list in which older people will be close to the head and younger people will be close to the tail.

*/
