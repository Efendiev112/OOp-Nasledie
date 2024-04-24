#include <iostream>
#include <string>
using namespace std;




template <typename T>
class MyList {
private:
	int capacity = 10;
	int size = 0;
	T* array;


public:
	MyList() {
		this->array = new T[capacity];
	}

	T& front() {
		return array[0];
	}

	T& back() {
		return array[size-1];
	}
	
	bool empty() {
		if (size > 0) return false;
		return true;
	}


	int getsize() {
		return size;
	}

	void push_back(T elem) {
		increaseList();
		this->array[this->size++] = elem;
	}

	void push_front(T elem) {
		increaseList();
		insert(0, elem);
	}

	void insert(int index, T elem) {
		increaseList();
		if (index >= size || index < 0) {
			return;
		}
		for (int i = size; i >= index; i--)
		{
			array[i]= array[i - 1];
		}
		array[index] = elem;
		size++;

		

	}

	void show() {
		for (int i = 0; i < size; i++) cout << array[i] << " ";
		cout << endl;
	}

	void clear() {
		this->capacity = 10;
		this->size = 0;
		delete[] array;
		array = new T [capacity];
	}

	void pop(int index) {
		if (index >= size || index < 0) {
			return;
		}
		for (int i = index; i < size; i++)
		{
			array[i] = array[i + 1];
		}
		size--;
	}

	void popback() {
		size--;
	}
	
	void popfront() {
		pop(0);
	}


	~MyList() {
		delete[] array;
	}


	void set(int index, T elem) {
		if (index >= size || index < 0) {
			return;
		}
		array[index] = elem;
	}

	void insertrange(int index, T* arr2, int size2) {
		if (index >= size || index < 0) {
			return;
		}
		increaseList(size2);

		for (int i = size; i >= index; i--) {
			array[i + size2] = array[i];
		}
		for (int i = 0; i <size2 ; i++)
		{
			array[i + index] = arr2[i];
		}

	}
private:
	void increaseList(int count=1) {
		if ((this->size + 1) >= (this->capacity * 0.75)) {
			this->capacity *= 1.5;
			if (capacity < (size + count)) this->capacity += count;
			T* buf = new T[this->capacity];
			for (int i = 0; i < size; i++)
			{
				buf[i] = array[i];
			}
			delete[] array;
			array = buf;
		}
	}


	

};




int main()
{
	
	MyList<int> list;
	int* array2 = new int[10]{1, 2, 3, 4, 5};
	list.push_back(12);
	list.push_back(34);
	list.push_back(20);
	list.show();
	list.insert(10, 5);
	list.show();
	/*list.pop(0);*/
	/*list.popback();*/
	/*list.popfront();*/
	//list.set(0, 22);
	list.insertrange(0, array2, 10);
	list.show();


	
	

}

