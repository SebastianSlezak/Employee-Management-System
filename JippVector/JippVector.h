#pragma once
#ifndef JIPP_VECTOR_H
#define JIPP_VECTOR_H

#include <algorithm>
#include <stdexcept>

using namespace std;

class VectorException : public exception {
public:
	const char* what() const noexcept override {
		return "Vector exception occurred";
	}
};

class OutOfRangeException : public VectorException {
public:
	const char* what() const noexcept override {
		return "Index out of range";
	}
};

class EmptyVectorException : public VectorException {
public:
	const char* what() const noexcept override {
		return "Operation on empty vector";
	}
};

template <typename T>
class JippVector
{
private:
	T* data;
	int size;
	int capacity;

public:
	JippVector() {
		try {
			data = nullptr;
			capacity = size = 0;
		} catch (const exception& e) {
			throw VectorException();
		}
	}

	explicit JippVector(const int& capacity) {
		try {
			data = new T[capacity];
			this->capacity = capacity;
			this->size = 0;
		} catch (const bad_alloc& e) {
			throw VectorException();
		}
	}

	//copy constructor
	JippVector(const JippVector& other) {
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];

		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	~JippVector() {
		delete[] data;
	}
	
	JippVector& operator=(const JippVector& rhs) = delete;

	const T& operator[](const int& index) const {
		if (index < 0 || index >= size) {
			throw OutOfRangeException();
		}
		return data[index];
	}

	void reserve(const int& val) {	 
		try {
			if (val > capacity) {
				T* temp = new T[val];

				for (int i = 0; i < size; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				capacity = val;
			}
		} catch (const bad_alloc&) {
			throw VectorException();
		}
	}

	void fill(const int& val) {
		for (int i = 0; i < size; i++) {
			data[i] = val;
		}
	}

	void fill(const int& start, const int& len, const int& val) {
		if (start < 0 || start + len > size) {
			throw OutOfRangeException();
		}

		for (int i = start; i < start + len; i++) {
			data[i] = val;
		}
	}

	void pushBack(const T& val) {
		try {
			if (size == capacity) {
				reserve(max(1, capacity * 2));
			}
			data[size++] = val;
		} catch (const VectorException&) {
			throw; // Re-throwing exception from reserve
		}
		
	}

	void pushFront(const T& val) {
		if (isEmpty()) {
			throw EmptyVectorException();
		}

		try {
			if (size == capacity) {
				reserve(max(1, capacity * 2));
			}

			for (size_t i = size; i > 0; i--)
			{
				data[i] = data[i - 1];
			}

			data[0] = val;
			size++;
		} catch (const VectorException&) {
			throw;  // Re-throwing exception from reserve
		}
		
	}

	void insert(const int& index, const T& val) {
		if (index < 0 || index > size) {
			throw OutOfRangeException();
		} else if (size == capacity) {
			reserve(capacity * 2);
		}

		for (int i = size; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = val;
		size++;
	}

	void erase(const int& index) {
		if (index < 0 || index >= size) {
			throw OutOfRangeException();
		}

		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}

		size--;
	}

	void erase(int index, int len) {
		if (index < 0 || index + len > size) {
			throw OutOfRangeException();
		}
		for (int i = index; i < size - len; i++) {
			data[i] = data[i + len];
		}
		size -= len;
	}

	void shrinkToFit() {
		if (isEmpty()) {
			throw EmptyVectorException();
		}

		try {
			if (capacity > size) {
				T* temp = new T[size];
				for (int i = 0; i < size; i++) {
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
				capacity = size;
			}
		} catch (const bad_alloc&) {
			throw VectorException();
		}
		
	}

	//TODO zmieniæ na size() ewentualnie sie dopytac prowadzacego
	int getSize() const {
		return size;
	}

	//TODO zmieniæ na capacity() ewentualnie sie dopytac prowadzacego
	int getCapacity() {
		return capacity;
	}

	bool isEmpty() const {
		return size == 0;
	}
}; 
#endif //JIPP_VECTOR_H