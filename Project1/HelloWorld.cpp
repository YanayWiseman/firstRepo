#include <iostream>
#include <string>

using namespace std;

typedef struct personNode
{
	int age = 0;
	string name = "";
	personNode* next = nullptr;
} personNode;

void createLinkedList(int length, personNode** head);
personNode* createNode(string name, int age);
void addNode(personNode** head, personNode* toAdd);
void printList(personNode* head);
void freeList(personNode* head);
int listLength(personNode* head);
personNode* copyList(personNode* head);

int main()
{
	int length = 0;
	cout << "Enter amount of people: ";
	cin >> length;
	personNode* head = nullptr;

	createLinkedList(length, &head);

	printList(head);

	personNode* copy = copyList(head);
	printList(copy);

	freeList(copy);
	freeList(head);

	return 0;
}

/*
	function to create and initialize the linked list
	input: the length of the list
	output: no return values
*/

void createLinkedList(int length, personNode** head)
{
	int i = 0, age = 0;
	string name = "";
	personNode* newNode = nullptr;

	for (i = 0; i < length; i++)
	{
		cout << "Enter name for person number " << i + 1 << ":";
		cin.ignore();
		getline(cin, name);

		cout << "Enter age: ";
		cin >> age;

		newNode = createNode(name, age);

		addNode(head, newNode);
	}
}

/*
	function to create a person node
	input: the data
	output: the new node
*/

personNode* createNode(string name, int age)
{
	personNode* newNode = new personNode;
	newNode->name = name;
	newNode->age = age;
	newNode->next = nullptr;

	return newNode;
}

/*
	function to add a node to a linked list
	input: the head of the list and the node to add
	output: no return values
*/

void addNode(personNode** head, personNode* toAdd)
{
	if (!(*head))
	{
		*head = toAdd;
	}
	else
	{
		personNode* temp = *head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = toAdd;
	}
}

/*
	function to print a linked list
	input: the linked list
	output: no return values
*/

void printList(personNode* head)
{
	personNode* temp = head;
	int i = 1;

	while (temp)
	{
		cout << "----Person " << i << "----" << endl;
		cout << "age: " << temp->age << ", name: " << temp->name << endl;
		temp = temp->next;
		i++;
	}
}

/*
	function to free a linked list
	input: the linked list
	output: no return values
*/

void freeList(personNode* head)
{
	personNode* temp = nullptr;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
}

/*
	function to get the length of the linked list
	input: the linked list
	output: the amount of nodes
*/
int listLength(personNode* head)
{
	int length = 0;
	if (head)
	{
		length = 1 + listLength(head->next);
	}
	return length;
}

/*
	fucntion to copy a linked list
	input: a linked list to copy
	output: the new copied linked list
*/

personNode* copyList(personNode* head)
{
	personNode* copy = nullptr;
	personNode* temp = head;

	while (temp)
	{
		addNode(&copy, createNode(temp->name, temp->age));
		temp = temp->next;
	}
	return copy;
}