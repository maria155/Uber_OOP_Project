#pragma once

template <typename T>
class Vector {
	T* elements;
	size_t size;
	size_t capacity;

	void copyFrom(const Vector<T>& other);
	void free();
	void resize();

public:
	Vector();
	Vector(size_t capacity);
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();

	size_t Size() const;
	bool deleteAt(size_t i);
	void push_back(T el);
	T& operator[](size_t i);
	T& operator[](size_t i) const;
	bool isEmpty() const;

};

template<class T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename T>
Vector<T>::Vector()
{
	capacity = 4;
	size = 0;
	elements = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t capacity)
{
	this->capacity = capacity;
	size = 0;
	elements = new T[capacity];
}

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	elements = new T[capacity];

	for (size_t i = 0; i < size; i++)
		elements[i] = other.elements[i];
}

template<typename T>
void Vector<T>::free()
{
	delete[] elements;
}

template<typename T>
void Vector<T>::resize()
{
	T* temp = new T[capacity *= 2];

	for (size_t i = 0; i < size; i++)
		temp[i] = elements[i];

	free();
	elements = temp;
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	copyFrom(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
size_t Vector<T>::Size() const
{
	return size;
}

template<typename T>
bool Vector<T>::deleteAt(size_t i)
{
	if (i >= size)
		return false;

	swap(elements[i], elements[size - 1]);
	size--;
	return true;
}

template<typename T>
void Vector<T>::push_back( T el)
{
	if (size == capacity)
		resize();

	elements[size++] = el;
}

template<typename T>
T& Vector<T>::operator[](size_t i)
{
	return elements[i];
}

template<typename T>
T& Vector<T>::operator[](size_t i) const
{
	return elements[i];
}

template<typename T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}


//#pragma once
//#define CHECKBOUNDS
//
//template<class T>
//class MyArray {
//public:
//
//	MyArray();
//	MyArray(unsigned int n);
//	MyArray(unsigned int n, const T& val);
//	MyArray(const MyArray<T>&);
//
//
//	~MyArray();
//
//	unsigned int size() const;
//	unsigned int capacity() const;
//
//	T& operator[](unsigned int i);
//	MyArray<T>& operator=(const MyArray<T>&);
//	void resize(unsigned int n);
//	void resize(unsigned int n, const T& val);
//	void push_back(const T& value);
//	void pop_back();
//	void clear();
//	bool empty() const;
//	void remove(unsigned int index);
//
//private:
//	unsigned int m_size;
//	unsigned int m_capacity;
//	T* m_data;
//
//	void copy(const MyArray<T>& a);
//};
//
//template<class T>
//MyArray<T>::MyArray() {
//	m_size = 0;
//	m_capacity = 0;
//	m_data = NULL;
//}
//
//template<class T>
//MyArray<T>::MyArray(unsigned int n) {
//	m_size = n;
//	m_capacity = n;
//	m_data = new T[n];
//}
//
//template<class T>
//MyArray<T>::MyArray(unsigned int n, const T& val) {
//	m_size = n;
//	m_capacity = n;
//	m_data = new T[n];
//	for (unsigned int i = 0; i < n; i++)
//		m_data[i] = val;
//}
//
//template<class T>
//MyArray<T>::~MyArray() {
//	delete[] m_data;
//}
//
//template<class T>
//unsigned int MyArray<T>::size() const {
//	return m_size;
//}
//
//template<class T>
//unsigned int MyArray<T>::capacity() const {
//	return m_capacity;
//}
//
//template<class T>
//T& MyArray<T>::operator[](unsigned int i) {
//#ifdef CHECKBOUNDS
//	if (i >= m_size) {
//		std::cout << "Error: Out of bounds\n";
//		exit(1);
//	}
//#endif
//	return m_data[i];
//}
//
//template<class T>
//void MyArray<T>::copy(const MyArray<T>& a) {
//	for (unsigned int i = 0; i < m_size; i++)
//		m_data[i] = a.m_data[i];
//}
//
//template<class T>
//MyArray<T>::MyArray(const MyArray<T>& a) {
//	m_size = a.m_size;
//	m_capacity = a.m_size;
//	m_data = new T[m_size];
//	copy(a);
//}
//
//template<class T>
//MyArray<T>& MyArray<T>::operator=(const MyArray<T>& a) {
//	if (this != &a) {
//		delete[] m_data;
//		m_size = a.m_size;
//		m_capacity = a.m_size;
//		m_data = new T[m_size];
//		copy(a);
//	}
//	return *this;
//}
//
//template<class T>
//void MyArray<T>::resize(unsigned int n) {
//	if (n == 0) {
//		clear();
//	}
//	else {
//		if (n > m_capacity) {
//			m_capacity = n;
//			T* newData = new T[n];
//			for (unsigned int i = 0; i < m_size; i++)
//				newData[i] = m_data[i];
//			delete[] m_data;
//			m_data = newData;
//		}
//		m_size = n;
//	}
//}
//
//template<class T>
//void MyArray<T>::resize(unsigned int n, const T& val) {
//	if (n == 0) {
//		clear();
//	}
//	else {
//		if (n > m_capacity) {
//			m_capacity = n;
//			T* newData = new T[n];
//			for (unsigned int i = 0; i < m_size; i++)
//				newData[i] = m_data[i];
//			delete[] m_data;
//			m_data = newData;
//		}
//		/*if (n > m_size) {
//
//			for (unsigned int i = m_size; i < n; i++)
//				newData[i] = val;
//		}*/
//		m_size = n;
//	}
//}
//
//template<class T>
//void MyArray<T>::push_back(const T& value) {
//	if (m_size == m_capacity) {
//		m_capacity += m_capacity / 2 + 1;
//		T* newData = new T[m_capacity];
//		for (unsigned int i = 0; i < m_size; i++)
//			newData[i] = m_data[i];
//		delete[] m_data;
//		m_data = newData;
//	}
//	m_data[m_size++] = value;
//}
//
//template<class T>
//void MyArray<T>::pop_back() {
//	if (m_size > 0) {
//		m_size--;
//		if (m_size == 0)
//			clear();
//	}
//}
//
//template<class T>
//void MyArray<T>::clear() {
//	delete[] m_data;
//	m_size = 0;
//	m_capacity = 0;
//	m_data = NULL;
//}
//
//template<class T>
//bool MyArray<T>::empty() const {
//	return m_size == 0;
//}
//
//template<class T>
//inline void MyArray<T>::remove(unsigned int index)
//{
//	for (int i = index; i < m_size - 1; i++)
//	{
//		m_data[i] = m_data[i + 1];
//	}
//	pop_back();
//
//}
//
