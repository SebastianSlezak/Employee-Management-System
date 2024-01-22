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
	int _size;
	int _capacity;

public:
	JippVector() {
		try {
			data = nullptr;
			_capacity = _size = 0;
		} catch (const exception& e) {
			throw VectorException();
		}
	}

	explicit JippVector(const int& _capacity) {
		try {
			data = new T[_capacity];
			this->_capacity = _capacity;
			this->_size = 0;
		} catch (const bad_alloc& e) {
			throw VectorException();
		}
	}

	//copy constructor
	JippVector(const JippVector& other) {
		_size = other._size;
		_capacity = other._capacity;
		data = new T[_capacity];

		for (int i = 0; i < _size; i++) {
			data[i] = other.data[i];
		}
	}

	~JippVector() {
		delete[] data;
	}
	
	JippVector& operator=(const JippVector& rhs) = delete;

	const T& operator[](const int& index) const {
		if (index < 0 || index >= _size) {
			throw OutOfRangeException();
		}
		return data[index];
	}

	void reserve(const int& val) {	 
		try {
			if (val > _capacity) {
				T* temp = new T[val];

				for (int i = 0; i < _size; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				_capacity = val;
			}
		} catch (const bad_alloc&) {
			throw VectorException();
		}
	}

	void fill(const int& val) {
		for (int i = 0; i < _size; i++) {
			data[i] = val;
		}
	}

	void fill(const int& start, const int& len, const int& val) {
		if (start < 0 || start + len > _size) {
			throw OutOfRangeException();
		}

		for (int i = start; i < start + len; i++) {
			data[i] = val;
		}
	}

	void pushBack(const T& val) {
		try {
			if (_size == _capacity) {
				reserve(max(1, _capacity * 2));
			}
			data[_size++] = val;
		} catch (const VectorException&) {
			throw; // Re-throwing exception from reserve
		}
		
	}

	void pushFront(const T& val) {
		if (isEmpty()) {
			throw EmptyVectorException();
		}

		try {
			if (_size == _capacity) {
				reserve(max(1, _capacity * 2));
			}

			for (size_t i = _size; i > 0; i--)
			{
				data[i] = data[i - 1];
			}

			data[0] = val;
			_size++;
		} catch (const VectorException&) {
			throw;  // Re-throwing exception from reserve
		}
		
	}

	void insert(const int& index, const T& val) {
		if (index < 0 || index > _size) {
			throw OutOfRangeException();
		} else if (_size == 0) {
			reserve(1);
		} else if (_size == _capacity) {
			reserve(_capacity * 2);
		}

		for (int i = _size; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = val;
		_size++;
	}

	void erase(const int& index) {
		if (index < 0 || index >= _size) {
			throw OutOfRangeException();
		}

		for (int i = index; i < _size - 1; i++) {
			data[i] = data[i + 1];
		}

		_size--;
	}

	void erase(int index, int len) {
		if (index < 0 || index + len > _size) {
			throw OutOfRangeException();
		}
		for (int i = index; i < _size - len; i++) {
			data[i] = data[i + len];
		}
		_size -= len;
	}

	void shrinkToFit() {
		if (isEmpty()) {
			throw EmptyVectorException();
		}

		try {
			if (_capacity > _size) {
				T* temp = new T[_size];
				for (int i = 0; i < _size; i++) {
					temp[i] = data[i];
				}
				delete[] data;
				data = temp;
				_capacity = _size;
			}
		} catch (const bad_alloc&) {
			throw VectorException();
		}
	}

	int size() const {
		return _size;
	}

	int capacity() const {
		return _capacity;
	}

	bool isEmpty() const {
		return _size == 0;
	}
}; 
#endif //JIPP_VECTOR_H