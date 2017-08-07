// STD
#include <stdexcept>

// Boon
#include <Boon/algorithm.hpp>

// Boon
namespace Boon {
	template<class T>
	void swap(DynamicArray<T>& first, DynamicArray<T>& second) noexcept {
		using std::swap;
		swap(first.data_size, second.data_size);
		swap(first.data_capacity, second.data_capacity);
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
	template<typename>
	DynamicArray<T>::IteratorBase<IsConst>::IteratorBase(const IteratorBase<false>& other) :
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
		data_size = list.size();
	}

	template<class T>
	DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) :
		data_size{other.data_size},
		data_capacity{data_size},
		data{new T[data_size]} {

		Boon::copy(other.data, other.data + other.data_size, data);
	}

	template<class T>
	DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) {
		swap(*this, other);
	}

	template<class T>
	DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
		if (data_capacity >= other.data_size) {
			data_size = other.data_size;
			Boon::copy(other.data, other.data + other.data_size, data);
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
		if (data_size != other.data_size) {
			return false;
		}

		// See if they use the same internal array
		if (data == other.data) {
			return true;
		}

		// Check for equality
		return std::equal(data, data + data_size, other.data);
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
		if (data_capacity >= capacity) { return; }

		// Create the new array
		T* newData = new T[capacity];

		// Copy over the old data
		Boon::copy(data, data + data_size, newData);

		// Delete old array
		delete[] data;

		// Update variables
		data = newData;
		data_capacity = capacity;
	}

	template<class T>
	void DynamicArray<T>::setSize(size_t size, const T& value = T{}) {
		// Make sure we have enough capacity
		reserveCapacity(size);

		// Fill any uninitialized indicies with value
		for (size_t i = data_size; i < size; ++i) {
			data[i] = value;
		}
		
		// Update size
		data_size = size;
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(size_t index, const T& value) {
		return insert(index, 1, value);
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(size_t index, T&& value) {
		// Make sure index is valid
		if (index > data_size) {
			throw std::out_of_range("The index \"" + std::to_string(index) + "\" is larger than DynamicArray<T>::getSize()");
		}

		// Reserver the additional capacity
		reserveCapacity(data_size + 1);

		// Shift values
		for (size_t i = data_size; i > index; --i) {
			data[i] = data[i - 1];
		}

		// Insert our new values
		data[index] = std::move(value);
		++data_size;

		// Return an iterator to our new values
		return Iterator{data + index};
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(ConstIterator it, T&& value) {
		return insert(it - begin(), std::move(value));
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(ConstIterator it, const T& value) {
		return insert(it, 1, value);
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(size_t index, size_t count, const T& value) {
		// Make sure index is valid
		if (index > data_size) {
			throw std::out_of_range("The index \"" + std::to_string(index) + "\" is larger than DynamicArray<T>::getSize()");
		}

		// Reserver the additional capacity
		reserveCapacity(data_size + count);

		// Shift values
		for (size_t i = data_size + count - 1; i > index; --i) {
			data[i] = data[i - count];
		}

		// Insert our new values
		for (size_t i = index; i < index + count; ++i) {
			data[i] = value;
		}
		data_size += count;

		// Return an iterator to our new values
		return Iterator{data + index};
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::insert(ConstIterator it, size_t count, const T& value) {
		return insert(it - begin(), count, value);
	}

	template<class T>
	void DynamicArray<T>::pushBack(const T& value) {
		insert(end(), value);
	}

	template<class T>
	void DynamicArray<T>::pushBack(T&& value) {
		reserveCapacity(data_size + 1);
		data[data_size] = std::move(value);
		++data_size;
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::erase(size_t beginIndex, size_t endIndex) {
		if (beginIndex >= data_size) {
			throw std::out_of_range("The start index \"" + std::to_string(beginIndex) + "\" is greater or equal to DynamicArray<T>::getSize()");
		}

		if (endIndex > data_size) {
			throw std::out_of_range("The end index \"" + std::to_string(endIndex) + "\" is greater than DynamicArray<T>::getSize()");
		}

		if (endIndex <= beginIndex) {
			throw std::domain_error("end index (" + std::to_string(endIndex) + ") must be greater than start index (" + std::to_string(beginIndex) + ")");
		}

		for (size_t i = 0; i < endIndex; ++i) {
			data[i].~T();
		}

		Boon::move(begin() + endIndex, end(), begin() + beginIndex);
		data_size -= endIndex - beginIndex;

		return begin() + beginIndex;
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::erase(size_t index) {
		return erase(index, index + 1);
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::erase(ConstIterator it) {
		return erase(it - begin());
	}

	template<class T>
	typename DynamicArray<T>::Iterator DynamicArray<T>::erase(ConstIterator startIt, ConstIterator endIt) {
		return erase(startIt - begin(), endIt - begin());
	}

	template<class T>
	void DynamicArray<T>::pop_back() {
		erase(--end());
	}

	template<class T>
	void DynamicArray<T>::clear() {
		delete[] data;
		data_size = 0;
		data = new T[data_capacity];
	}

	template<class T>
	void DynamicArray<T>::shrinkToFit() {
		T* newData = new T[data_size];
		Boon::copy(data, data + data_size, newData);
		delete[] data;
		data = newData;
		data_capacity = data_size;
	}
	
	template<class T>
	inline size_t DynamicArray<T>::getSize() const {
		return data_size;
	}

	template<class T>
	inline size_t DynamicArray<T>::getCapacity() const {
		return data_capacity;
	}

	template<class T>
	inline bool DynamicArray<T>::isEmpty() const {
		return data_size == 0;
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

		return data[data_size - 1];
	}

	template<class T>
	const T& DynamicArray<T>::getBack() const {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getBack was called on an empty array.");
		}

		return data[data_size - 1];
	}

	template<class T>
	T& DynamicArray<T>::getAt(size_t index) {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called on an empty array.");
		}

		if (index >= data_size) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called with an out of range index.");
		}

		return data[index];
	}

	template<class T>
	const T& DynamicArray<T>::getAt(size_t index) const {
		if (isEmpty()) {
			throw std::out_of_range("Boon::DynamicArray<T>::getAt was called on an empty array.");
		}

		if (index >= data_size) {
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
		return Iterator{data + data_size};
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::begin() const {
		return ConstIterator{data};
	}

	template<class T>
	typename DynamicArray<T>::ConstIterator DynamicArray<T>::end() const {
		return ConstIterator{data + data_size};
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