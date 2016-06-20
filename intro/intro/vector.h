#ifndef Vector_h_
#define Vector_h_

class Vector
{
	private:
		int* arr;
		int size;
		int cap;

		void resize();
		void copy(Vector const&);
	public:
		Vector();

		~Vector();

		

		Vector(Vector const&);

		Vector operator=(Vector const&);

		void insert(int, int);

		void print() const;

		void reverseFrom(int);
};


#endif