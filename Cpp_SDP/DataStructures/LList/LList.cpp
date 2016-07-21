#pragma once
#include<iostream>
using namespace std;

template <typename T>
class LList
{

private:
	struct Node {
		Node* next;
		T data;
	};
	Node* head;
	Node* curr;
	Node* tmp;

public:
	LList();
	~LList();

	bool InsertNode(Node *newNode, T val);
	bool RemoveNode(T val);
	void PrintList();
};

template <typename T>
LList<T>::LList()
{
	head->data = 0;
	head->next = nullptr;
}

template <typename T>
LList<T>::~LList()
{
	Node* temp;
	temp = head;
	while (temp != nullptr)
	{
		temp = temp->pNext;
		delete head;
	}
}

template <typename T>
bool LList<T>::InsertNode(Node* newNode, T val)
{
	Node* node = new Node;
	node->pNext = nullptr;
	node->data = val;
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		curr = head;
		while (curr->pNext != nullptr)
		{
			curr = curr->pNext;
		}
		curr->pNext = node;
	}
}

template <typename T>
bool LList<T>::RemoveNode(T val)
{
	if (head->value == val)
	{
		tmp = head;
		head = head->pNext;
		delete tmp;
		return;
	}
	else
	{
		curr = head;
		while (curr->data != val)
		{
			if (curr->pNext == nullptr)
				return;

			tmp = curr;
			curr = curr->pNext;
		}
		tmp->pNext = curr->pNext;
		delete curr;
	}

}

template <typename T>
void LList<T>::PrintList()
{
	Node* temp;
	temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << std::endl;
		temp = temp->pNext;
	}
}