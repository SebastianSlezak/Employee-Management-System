#pragma once
#ifndef JIPPVECTOR_H
#define JIPPVECTOR_H

using namespace std;

template <typename T>
class JippVector
{
private:

public:
	T* data;
	int size;
	int capacity;

	JippVector() {
		data = nullptr;
		capacity = size = 0;
	}

	explicit JippVector(const size_t& capacity) {
		data = new T[capacity];
		this->capacity = capacity;
		this->size = 0;
	}

	~JippVector() {
		delete[] data;
	}

	void reserve(const int& val) {
		if (capacity < val) {
			int lenOldData = sizeof(data) / sizeof(data[0]);
			capacity = val;
			T* tempData = new T[capacity];
			copy(data, data + min(lenOldData, capacity), tempData);
			delete[] data;
			data = tempData;
		}
	}

	void fill(const int& val) {
		for (int i = 0; i < size; i++) {
			data[i] = val;
		}
	}

	void fill(const int& start, const int& len, const int& val) {
		for (int i = start; i < start + len; i++) {
			data[i] = val;
		}
	}

	void pushBack(const int& val) {
		
	}
};

#endif // JIPPVECTOR_H