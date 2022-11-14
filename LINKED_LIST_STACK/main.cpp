#include <iostream>

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

void Print(Node* top)
{
	while (top != NULL)
	{
		std::cout << top->data << " ";
		top = top->link;
	}
	std::cout << "\n";
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
}