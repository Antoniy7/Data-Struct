#pragma once
#include<memory>

//path in a labirynth

template<typename T>
class Stack
{
	struct Node
	{
		Node(Node*p , T v):value(v), prev(p)
		{

		}
		T value;
		//Node* next;
		Node*prev;
	};

public:
	Stack()
	{
		top=NULL;
	}
	~Stack()
	{
		while(top) // dokato top sushtestvuva
		{
			Node*temp=top;
			top=top->prev;
			delete temp;
		}
	}
public:
	void push(const T& value)
	{
		Node*temp= new Node(NULL,value);
		temp->prev = top;
		top=temp;
	}
	void pop()
	{
		Node*temp=top;
		top= top->prev;
		delete temp;
	}
	T* head()
	{
		if (top)
			return &(top->value);
		return NULL;
	}
private:
	Node*top;

};