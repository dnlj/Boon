// Boon
#include <Boon/algorithm.hpp>

// Boon
namespace Boon {
	template<class T>
	void swap(DynamicArray<T>& first, DynamicArray<T>& second) noexcept {
		using std::swap;
		swap(first.size, second.size);
		swap(first.capacity, second.capacity);
		swap(first.data, second.data);
	}
}

// Boon::DynamicArray::IteratorBase
namespace Boon {
	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>::IteratorBase() {
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>::IteratorBase(const IteratorBase& other) :
		ptr{other.ptr} {
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>::IteratorBase(pointer ptr) :
		ptr{ptr} {
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>& DynamicArray<T>::IteratorBase<IsConst>::operator=(IteratorBase other) {
		swap(*this, other);
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::reference DynamicArray<T>::IteratorBase<IsConst>::operator*() {
		return *ptr;
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::const_reference DynamicArray<T>::IteratorBase<IsConst>::operator*() const {
		return *ptr;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>& DynamicArray<T>::IteratorBase<IsConst>::operator++() {
		++ptr;
		return *this;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst> DynamicArray<T>::IteratorBase<IsConst>::operator++(int) {
		auto temp{*this};
		++(*this);
		return temp;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>& DynamicArray<T>::IteratorBase<IsConst>::operator--() {
		--ptr;
		return *this;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst> DynamicArray<T>::IteratorBase<IsConst>::operator--(int) {
		auto temp{*this};
		--(*this);
		return temp;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>& DynamicArray<T>::IteratorBase<IsConst>::operator+=(difference_type other) {
		ptr += other;
		return *this;
	}

	template<class T>
	template<bool IsConst>
	DynamicArray<T>::IteratorBase<IsConst>& DynamicArray<T>::IteratorBase<IsConst>::operator-=(difference_type other) {
		ptr -= other;
		return *this;
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator==(const IteratorBase& other) const {
		return ptr == other.ptr;
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator!=(const IteratorBase& other) const {
		return !(*this == other);
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::pointer DynamicArray<T>::IteratorBase<IsConst>::operator->() {
		return ptr;
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::const_pointer DynamicArray<T>::IteratorBase<IsConst>::operator->() const {
		return ptr;
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::reference DynamicArray<T>::IteratorBase<IsConst>::operator[](difference_type offset) {
		return ptr[offset];
	}

	template<class T>
	template<bool IsConst>
	typename DynamicArray<T>::IteratorBase<IsConst>::const_reference DynamicArray<T>::IteratorBase<IsConst>::operator[](difference_type offset) const {
		return ptr[offset];
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator<(const IteratorBase& other) const {
		return ptr < other.ptr;
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator>(const IteratorBase& other) const {
		return ptr > other.ptr;
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator>=(const IteratorBase& other) const {
		return !(*this < other);
	}

	template<class T>
	template<bool IsConst>
	bool DynamicArray<T>::IteratorBase<IsConst>::operator<=(const IteratorBase& other) const {
		return !(*this > other);
	}
}

// Boon::DynamicArray
namespace Boon {
	template<class T>
	DynamicArray<T>::DynamicArray() {
	}

	template<class T>
	DynamicArray<T>::DynamicArray(size_t size, const T& value) {
		setSize(size, value);
	}

	template<class T>
	DynamicArray<T>::DynamicArray(std::initializer_list<T> list) {
		reserveCapacity(list.size());
		Boon::copy(list.begin(), list.end(), data);
		size = list.size();
	}

	template<class T>
	DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) :
		size{other.size},
		capacity{other.size},
		data{new T[size]} {

		Boon::copy(other.data, other.data + other.size, data);
	}

	template<class T>
	DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) {
		swap(*this, other);
	}

	template<class T>
	DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
		if (capacity >= other.size) {
			size = other.size;
			Boon::copy(other.data, other.data + other.size, data);
		} else {
			auto temp = other;
			swap(*this, temp);
		}

		return *this;
	}

	template<class T>
	DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) {
		swap(*this, other);
		return *this;
	}

	template<class T>
	DynamicArray<T>::~DynamicArray() {
		if (data != nullptr) {
			delete[] data;
		}
	}

	template<class T>
	bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const {
		// Make sure they are the same size
		if (size != other.size) {
			return false;
		}

		// See if they use the same internal array
		if (data == other.data) {
			return true;
		}

		// Check for equality
		return std::equal(data, data + size, other.data);
	}

	template<class T>
	bool DynamicArray<T>::operator!=(const DynamicArray<T>& other) const {
		return !(*this == other);
	}

	template<class T>
	inline T& DynamicArray<T>::operator[](size_t index) {
		return data[index];
	}

	template<class T>
	inline const T& DynamicArray<T>::operator[](size_t index) const {
		return data[index];
	}

	template<class T>
	void DynamicArray<T>::reserveCapacity(size_t capacity) {
		// Check to see if the array need to be resized
		if (this->capacity >= capacity) { return; }

		// Create the new array
		T* newData = new T[capacity];

		// Copy over the old data
		Boon::copy(data, data + size, newData);

		// Delete old array
		delete[] data;

		// Update variables
		data = newData;
		this->capacity = capacity;
	}

	template<class T>
	void DynamicArray<T>::setSize(size_t size, const T& value = T{}) {
		// Make sure we have enough capacity
		reserveCapacity(size);

		// Fill any uninitialized indicies with value
		for (size_t i = this->size; i < size; ++i) {
			data[i] = value;
		}
		
		// Update size
		this->size = size;
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(size_t index, const T& value) {
		return insert(index, 1, value);
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(Iterator it, const T& value) {
		return insert(it, 1, value);
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(size_t index, size_t count, const T& value) {
		// Make sure index is valid
		if (index > size) {
			throw std::out_of_range("The index \"" + std::to_string(index) + "\" is larger than DynamicArray<T>::getSize()");
		}

		// Reserver the additional capacity
		reserveCapacity(size + count);

		// Shift values
		for (size_t i = size + count - 1; i > index; --i) {
			data[i] = data[i - count];
		}

		// Insert our new values
		for (size_t i = index; i < index + count; ++i) {
			data[i] = value;
		}
		size += count;

		// Return an iterator to our new values
		return Iterator{data + index};
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(Iterator it, size_t count, const T& value) {
		return insert(it - begin(), count, value);
	}

	template<class T>
	void DynamicArray<T>::pushBack(const T& value) {
		insert(end(), value);
	}

	template<class T>
	void DynamicArray<T>::clear() {
		delete[] data;
		size = 0;
		data = new T[capacity];
	}

	template<class T>
	void DynamicArray<T>::shrinkToFit() {
		T* newData = new T[size];
		Boon::copy(data, data + size, newData);
		delete[] data;
		data = newData;
		capacity = size;
	}
	
	template<class T>
	inline size_t DynamicArray<T>::getSize() const {
		return size;
	}

	template<class T>
	inline size_t DynamicArray<T>::getCapacity() const {
		return capacity;
	}

	template<class T>
	inline bool DynamicArray<T>::isEmpty() const {
		return size == 0;
	}

	template<class T>
	T& DynamicArray<T>::getFront() {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getFront was called on an empty array.");
		}

		return data[0];
	}

	template<class T>
	const T& DynamicArray<T>::getFront() const {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getFront was called on an empty array.");
		}
	
		return data[0];
	}

	template<class T>
	T& DynamicArray<T>::getBack() {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getBack was called on an empty array.");
		}

		return data[size - 1];
	}

	template<class T>
	const T& DynamicArray<T>::getBack() const {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getBack was called on an empty array.");
		}

		return data[size - 1];
	}

	template<class T>
	T& DynamicArray<T>::getAt(size_t index) {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called on an empty array.");
		}

		if (index >= size) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called with an out of range index.");
		}

		return data[index];
	}

	template<class T>
	const T& DynamicArray<T>::getAt(size_t index) const {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called on an empty array.");
		}

		if (index >= size) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called with an out of range index.");
		}

		return data[index];
	}

	template<class T>
	inline T* DynamicArray<T>::getData() {
		return data;
	}

	template<class T>
	inline const T* DynamicArray<T>::getData() const {
		return data;
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::begin() {
		return Iterator{data};
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::end() {
		return Iterator{data + size};
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::begin() const {
		return ConstIterator{data};
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::end() const {
		return ConstIterator{data + size};
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::cbegin() const {
		return begin();
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::cend() const {
		return end();
	}

	template<class T>
	typename DynamicArray<T>::ReverseIterator DynamicArray<T>::rbegin() {
		return ReverseIterator{end()};
	}

	template<class T>
	typename DynamicArray<T>::ReverseIterator DynamicArray<T>::rend() {
		return ReverseIterator{begin()};
	}

	template<class T>
	typename DynamicArray<T>::ConstReverseIterator DynamicArray<T>::rbegin() const {
		return ConstReverseIterator{end()};
	}

	template<class T>
	typename DynamicArray<T>::ConstReverseIterator DynamicArray<T>::rend() const {
		return ConstReverseIterator{begin()};
	}

	template<class T>
	typename DynamicArray<T>::ConstReverseIterator DynamicArray<T>::crbegin() const {
		return rbegin();
	}

	template<class T>
	typename DynamicArray<T>::ConstReverseIterator DynamicArray<T>::crend() const {
		return rend();
	}
}