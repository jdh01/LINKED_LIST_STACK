#include <iostream>
#include <stack>

struct Node
{
	int data;
	Node* link;
};

Node* CreateNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->link = NULL;
	return temp;
}

Node* InsertAtHead(Node** top, int data)
{
	Node* temp = CreateNode(data);
	temp->link = *top;
	*top = temp;
	return *top;
}

Node* Pop(Node** top)
{
	Node* temp;
	if (*top == NULL) return *top;
	temp = *top;
	*top = temp->link;
	delete temp;
	return *top;
}

void Push(Node** head, int data)
{
	Node* temphead = *head;
	Node* temp = new Node();
	temp->data = data;
	temp->link = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return;
	}
	while (temphead->link != NULL)
	{
		temphead = temphead->link;
	}
	temphead->link = temp;
}

void Print(Node* top)
{
	while (top != NULL)
	{
		std::cout << top->data << " ";
		top = top->link;
	}
	std::cout << "\n";
}

void LinkListReverse(Node** head)
{
	Node* temp = *head;
	if (*head == NULL) return;
	std::stack<Node*> S;
	
	while (temp != NULL)
	{
		S.push(temp);
		temp = temp->link;
	}
	temp = S.top();
	*head = temp;
	S.pop();
	while (!S.empty()) {
		temp->link = S.top();
		S.pop();
		temp = temp->link;
	}
	temp->link = NULL;
}

int main()
{
	struct Node* top = NULL;
	InsertAtHead(&top, 1);
	InsertAtHead(&top, 2);
	InsertAtHead(&top, 3);
	Print(top);
	Pop(&top);
	Print(top);

	struct Node* head = NULL;
	Push(&head, 1);
	Push(&head, 2);
	Push(&head, 3);
	Print(head);
	LinkListReverse(&head);
	Print(head);
}