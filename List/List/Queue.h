#pragma once
#include<memory>

//array implementation
template<class T>
class Queue
{
	T*arr;
	T*start; // beginning 
	T*end;  // end
	size_t capacity, size;

	void free()
	{
		delete[]arr;
		arr=start=end=NULL;
		start=end=0;
	}

public:
	Queue(size_t _cap=0 )
	{
		arr=start=end=NULL;
		arr=new T[_size];
		start=end=arr;
		capacity=_cap;
		size=0;
	}
	~Queue()
	{
		free();
	}
	Queue(const Queue& right):Queue()
	{
		this->operator=(right); 
	}

	Queue&operator=(const Queue& right)
	{
		if (this==&left) return *this;
		else
		{
			free();
			arr =  new T [right.capacity];
			size=right.size;
			capacity=right.capacity;
			start= arr+ (right.start - right.arr);
			end= arr + (right.end - right.arr);
		}
		for (int i=0;i<capacity;++i)
			arr[i]=right.arr[i];

	}
	void Dequeue()
	{
		if(!isEmpty())
		{
		if (arr+capacity== start)
		   start=arr
		else
			start++;
		
		size--;
		}
	}
	void Enqueue(const T&val) // push
	{
		//if (size==capacity)
		//{
	//		extend();
		//}

		if(end==arr+cap)
			{
				end=arr;
				*end=val;
		}

		else
			*(++end)=val;

		size++;
	}
	T*head()
	{
		if (!isEmpty())
			return start
		return NULL;
	}
	bool isEmpty()
		return !size;

};
