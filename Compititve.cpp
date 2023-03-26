#include <iostream>

using namespace std;

template <class T>

class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	int count;

public:
	LinkedList()
	{
		head = NULL;
		count = 0;
	}
	void CreatList(T x[], int n)
	{
		Node* p = new Node;
		head = p;
		p->data = x[0];
		p->next = NULL;

		for (int i = 1; i < n; i++)
		{
			p = p->next = new Node;
			p->data = x[i];
			p->next = NULL;
		}
		count = n;
	}

	void InsertFirst(T item)
	{
		Node* p = new Node;
		p->data = item;
		p->next = head;
		head = p;

		count++;
	}

	void InsertAfter(T item, T key)
	{
		Node* p = find(key);

		if (p == NULL)
		{
			cout << key << "key is not found\n";
		}
		else
		{
			Node* q = new Node;
			q->data = item;
			q->next = p->next;

			p->next = q;
			count++;
		}
	}

	void DeleteAfter(T key)
	{
		Node* p = find(key);

		if (p == NULL)
		{
			cout << key << " key is not found\n";
		}
		
		else
		{
			Node* q = p->next;
			p->next = q->next;
			count--;
		}
	}

	void DeleteNode(T item)
	{
		Node* p = new Node;
		Node* prevNode = new Node;

		if (IsEmpty())
		{
			cout << "list is empty: no deletion\n";
			return;
		}
		
		if (head->data == item)
		{
			p = head;
			head = head->next;
			count--;
		}

		else
		{
			p = head;
			while (p != NULL && p->data != item)
			{
				prevNode = p;
				p = p->next;
			}
			
			if (p != NULL)
			{
				prevNode->next = p->next;
				count--;
			}
			else
				cout << item << " Not Found\n";
		}
	}

	void DisplayList()
	{
		Node* p = head;
		cout << "\nLinked List : ";
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->next;
		}
		cout << "NULL\n";
	}

	bool IsEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	Node* find(T key)
	{
		Node* p = head;
		while (p != NULL)
		{
			if (p->data == key)
			{
				return p;
			}
			p = p->next;
		}
		return p;
	}
};

int main()
{
	int x[4] = { 11,22,33,44 };

	LinkedList<int> list;
	list.CreatList(x, 4);
	list.DisplayList();
	list.InsertFirst(55);
	list.DisplayList();
	list.InsertAfter(66, 33);

	list.DeleteAfter(22);
	list.DisplayList();

}