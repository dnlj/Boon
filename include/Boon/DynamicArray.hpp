#pragma once


namespace Boon {
	/**
	 * @brief A resizable array similar to std::vector.
	 */
	template<class T>
	class DynamicArray {
		private:
			/**
			 * @brief Used to iterator over the elements in a DynamicArray.
			 */
			template<bool IsConst>
			class IteratorBase {
				public:
					using difference_type = ptrdiff_t;
					using value_type = std::conditional_t<IsConst, const T, T>;
					using pointer = value_type*;
					using const_pointer = const value_type*;
					using reference = value_type&;
					using const_reference = const value_type&;
					using iterator_category = std::random_access_iterator_tag;

					/**
					 * @brief Constructs an IteratorBase.
					 */
					IteratorBase();

					/**
					 * @brief Creates a copy from @p other.
					 * @param[in] other The IteratorBase to copy.
					 */
					IteratorBase(const IteratorBase& other);

					/**
					 * @brief Constructs an IteratorBase from @p ptr.
					 * @param[in] ptr The pointer to represent.
					 */
					IteratorBase(pointer ptr);

					/**
					 * @brief Assigns the value of @p other to this.
					 * @param[in] other The value to assign to this.
					 * @return An reference to this.
					 */
					IteratorBase& operator=(IteratorBase other);

					/**
					 * @brief Gets a reference to the value represented by this iterator. 
					 * @return A reference to the value represented by this iterator.
					 */
					reference operator*();

					/** @copydoc Boon::DynamicArray::IteratorBase::operator* */
					const_reference operator*() const;

					/**
					 * @brief Increments the IteratorBase.
					 * @return The IteratorBase.
					 */
					IteratorBase& operator++();

					/** @copydoc Boon::DynamicArray::IteratorBase::operator++ */
					IteratorBase operator++(int);

					/**
					 * @brief Decrements the IteratorBase.
					 * @return The IteratorBase.
					 */
					IteratorBase& operator--();

					/** @copydoc Boon::DynamicArray::IteratorBase::operator-- */
					IteratorBase operator--(int);

					/**
					 * @brief Increments the IteratorBase by @p other.
					 * @param[in] other The amount to increment by.
					 * @return The IteratorBase.
					 */
					IteratorBase& operator+=(difference_type other);

					/**
					 * @brief Decrements the IteratorBase by @p other.
					 * @param[in] other The amount to decrement by.
					 * @return The IteratorBase.
					 */
					IteratorBase& operator-=(difference_type other);

					/**
					 * @brief Checks for equality between two iterators.
					 * @param[in] other The iterator to check for equality with.
					 * @return True if equal otherwise false.
					 */
					bool operator==(const IteratorBase& other) const;

					/**
					 * @brief Checks for inequality between two iterators.
					 * @param[in] other The iterator to check for inequality with.
					 * @return True if inequal otherwise false.
					 */
					bool operator!=(const IteratorBase& other) const;

					/**
					 * @brief Used to accesses a member of the value represented by this iterator.
					 * @return A pointer to the value represented by this iterator.
					 */
					pointer operator->();

					/** @copydoc Boon::DynamicArray::IteratorBase::operator-> */
					const_pointer operator->() const;

					/**
					 * @brief Gets a reference to the value @p offset away from the value represented by this iterator.
					 * @param[in] offset The offset to use.
					 * @return A reference to the value @p offset away from the value represented by this iterator.
					 */
					reference operator[](difference_type offset);

					/** @copydoc Boon::DynamicArray::IteratorBase::operator[] */
					const_reference operator[](difference_type offset) const;

					/**
					 * @brief Checks if this iterator is less than @p other.
					 * @return True if this iterator is less than @p other; otherwise false.
					 */
					bool operator<(const IteratorBase& other) const;

					/**
					 * @brief Checks if this iterator is greater than @p other.
					 * @return True if this iterator is greater than @p other; otherwise false.
					 */
					bool operator>(const IteratorBase& other) const;

					/**
					 * @brief Checks if this iterator is greater than or equal to @p other.
					 * @return True if this iterator is greater than or equal to @p other; otherwise false.
					 */
					bool operator>=(const IteratorBase& other) const;

					/**
					 * @brief Checks if this iterator is less than or equal to @p other.
					 * @return True if this iterator is less than or equal to @p other; otherwise false.
					 */
					bool operator<=(const IteratorBase& other) const;

					/**
					 * @brief Swaps two iterators.
					 * @param[in] first The iterator to swap with @p second.
					 * @param[in] first The iterator to swap with @p first.
					 */
					friend void swap(IteratorBase& first, IteratorBase& second) noexcept {
						using std::swap;
						swap(first.ptr, second.ptr);
					}

					/**
					 * @brief Creates an iterator @p offset away from @p it.
					 * @param[in] it The iterator to add @p offset to.
					 * @param[in] offset How far from @p it to create the new iterator.
					 * @return An iterator @p offset away from @p it.
					 */
					friend IteratorBase operator+(IteratorBase it, difference_type offset) {
						return it += offset;
					}

					/**
					 * @brief Creates an iterator @p offset away from @p it.
					 * @param[in] it The iterator to add @p offset to.
					 * @param[in] offset How far from @p it to create the new iterator.
					 * @return An iterator @p offset away from @p it.
					 */
					friend IteratorBase operator+(difference_type offset, IteratorBase it) {
						return it + offset;
					}

					/**
					 * @brief Creates an iterator @p -offset away from @p it.
					 * @param[in] it The iterator to subtract @p offset from.
					 * @param[in] offset How far from @p it to create the new iterator.
					 * @return An iterator @p -offset away from @p it.
					 */
					friend IteratorBase operator-(IteratorBase it, difference_type offset) {
						return it -= offset;
					}

					/**
					 * @brief Gets the distance between @p first and @p second.
					 * @param[in] first The first iterator.
					 * @param[in] second The second iterator.
					 * @return The distance between @p first and @p second.
					 */
					friend difference_type operator-(IteratorBase first, IteratorBase second) {
						return first.ptr - second.ptr;
					}

				private:
					/** The internal pointer manipulated by this iterator. */
					pointer ptr = nullptr;
			};

		public:
			using Iterator = IteratorBase<false>;
			using ConstIterator = IteratorBase<true>;
			using ReverseIterator = std::reverse_iterator<Iterator>;
			using ConstReverseIterator = std::reverse_iterator<ConstIterator>;

			/**
			 * @brief Constructs a Boon::DynamicArray.
			 */
			DynamicArray();

			/**
			 * @brief Constructs a Boon::DynamicArray of size @p size, 
			 * where each of the @p size elements is initialized to @p value.
			 * @param[in] size The size of the Boon::DynamicArray.
			 * @param[in] value The value used to initialize each of the @p size elements.
			 */
			DynamicArray(size_t size, const T& value = T{});

			/**
			 * @brief Constructs a Boon::DynamicArray from the elements in @p list.
			 * @param[in] list The list of items to initialize the Boon::DynamicArray with.
			 */
			DynamicArray(std::initializer_list<T> list);

			/**
			 * @brief Constructs a Boon::DynamicArray from the elements in @p other.
			 * @param[in] other The array of items to initialize the Boon::DynamicArray with.
			 */
			DynamicArray(const DynamicArray<T>& other);

			/**
			 * @brief Transfers ownership from one Boon::DynamicArray to the other.
			 * @param[in] other The array to transfer ownership from.
			 */
			DynamicArray(DynamicArray<T>&& other);

			/**
			 * @brief Deconstructs a Boon::DynamicArray.
			 */
			~DynamicArray();

			/**
			 * @brief Copies the elements from @p other.
			 * @param[in] other The array to copy the elements from.
			 * @return The array that the elements from @p other were copied to.
			 */
			DynamicArray<T>& operator=(const DynamicArray<T>& other);

			/**
			 * @brief Moves the elements from @p other.
			 * @param[in] other The array to move the elements from.
			 * @return The array that the elements from @p other were moved to.
			 */
			DynamicArray<T>& operator=(DynamicArray<T>&& other);

			/**
			 * @brief Checks for equality between two Boon::DynamicArrays.
			 * @return True if the arrays are equal otherwise false.
			 */
			bool operator==(const DynamicArray<T>& other) const;

			/**
			 * @brief Checks for inequality between two Boon::DynamicArrays.
			 * @return False if the arrays are equal otherwise true.
			 */
			bool operator!=(const DynamicArray<T>& other) const;

			/**
			 * @brief Gets a reference to the value at @p index.
			 * @param[in] index The index to get the reference to.
			 * @return A reference to the value at @p index.
			 */
			T& operator[](size_t index);

			/** @copydoc Boon::DynamicArray::operator[] */
			const T& operator[](size_t index) const;

			/**
			 * @brief Makes sure that enough memory is reserved to store atleast @p capacity items.
			 * @param[in] capacity The capacity to reserve.
			 * @return void
			 */
			void reserveCapacity(size_t capacity);

			/**
			 * @brief Sets the size of the Boon::DynamicArray.
			 * If @p size is greate than the current size new values are filled with @p value.
			 * @param[in] size The size to change the Boon::DynamicArray to.
			 * @param[in] value The default value for new indices.
			 * @return void
			 */
			void setSize(size_t size, const T& value = T{});

			/**
			 * @brief Inserts the value @p value into the index @p index.
			 * @param[in] index The index to insert @p value into.
			 * @param[in] value The value to insert at @p index.
			 * @throws std::out_of_range When @p index is larger than the size of the array.
			 * @return A iterator to the inserted value.
			 */
			Iterator insert(size_t index, const T& value);
			
			/**
			 * @brief Inserts the value @p value before @p it.
			 * @param[in] it The iterator to insert @p value before.
			 * @param[in] value The value to insert.
			 * @throws std::out_of_range When @p it is out of range.
			 * @return A iterator to the inserted value.
			 */
			Iterator insert(Iterator it, const T& value);

			/**
			 * @brief Inserts @p count copies of @p value at the index @p index.
			 * @param[in] index The index to insert at.
			 * @param[in] count The number of values to insert.
			 * @param[in] value The value to insert.
			 * @throws std::out_of_range When @p index is larger than the size of the array.
			 * @return A iterator to the first inserted value.
			 */
			Iterator insert(size_t index, size_t count, const T& value);

			/**
			 * @brief Inserts @p count copies of @p value before @p it.
			 * @param[in] it The iterator to insert before.
			 * @param[in] count The number of values to insert.
			 * @param[in] value The value to insert.
			 * @throws std::out_of_range When @p it is out of range.
			 * @return A iterator to the first inserted value.
			 */
			Iterator insert(Iterator it, size_t count, const T& value);

			/**
			 * @breif Inserts p@ value at the end of the array.
			 * @param[in] value The value to insert at the end of the array.
			 * @return An iterator to the inserted value.
			 */
			Iterator pushBack(const T& value);

			/* TODO: 
			Iterator pushBack(T&& value);
			void popBack(); // TODO: make this use erase?
			void erase(size_t index); // Just make this use start with end = start for simplicity and consitency
			void erase(size_t start, size_t end);
			*/
			
			/**
			 * @brief Clears the Boon::DynamicArray.
			 * @return void
			 */
			void clear();
			
			/**
			 * @brief Shrinks capacity to size.
			 * @return void
			 */
			void shrinkToFit();
			
			/**
			 * @brief Gets the size of the Boon::DynamicArray.
			 * @return The size of the Boon::DynamicArray.
			 */
			size_t getSize() const;

			/**
			 * @brief Gets the capacity of the Boon::DynamicArray.
			 * @return The capacity of the Boon::DynamicArray.
			 */
			size_t getCapacity() const;
			
			/**
			 * @brief Checks if the Boon::DynamicArray is empty.
			 * @return True if the array is empty otherwise false.
			 */
			bool isEmpty() const;
			
			/**
			 * @brief Gets the first element in the Boon::DynamicArray.
			 * @return The first element in the Boon::DynamicArray
			 * @throws std::out_of_range When called on an empty array.
			 */
			T& getFront();

			/** @copydoc Boon::DynamicArray::getFront */
			const T& getFront() const;

			/**
			 * @brief Gets the last element in the Boon::DynamicArray.
			 * @return The last element in the Boon::DynamicArray
			 * @throws std::out_of_range When called on an empty array.
			 */
			T& getBack();

			/** @copydoc Boon::DynamicArray::getBack */
			const T& getBack() const;
			
			/**
			 * @brief Gets the element at @p index in the Boon::DynamicArray.
			 * @param[in] index The index to get the element at.
			 * @return The element at @p index in the Boon::DynamicArray.
			 * @throws std::out_of_range When called on an empty array. 
			 * @throws std::out_of_range When @p index is greater than or equal to the size of the array.
			 */
			T& getAt(size_t index);

			/** @copydoc Boon::DynamicArray::getAt */
			const T& getAt(size_t index) const;

			/**
			 * @brief Gets a pointer to the internal array.
			 * @return A pointer to the internal array.
			 */
			T* getData();

			/** @copydoc Boon::DynamicArray::getData */
			const T* getData() const;

			/**
			 * @brief Gets an iterator to the first element in the array.
			 * @return An iterator to the first element in the array.
			 */
			Iterator begin();

			/** @copydoc Boon::DynamicArray::begin */
			ConstIterator begin() const;

			/** @copydoc Boon::DynamicArray::begin */
			ConstIterator cbegin() const;

			/**
			 * @brief Gets an iterator to the last element in the array.
			 * @return An iterator to the last element in the array.
			 */
			ReverseIterator rbegin();

			/** @copydoc Boon::DynamicArray::rbegin */
			ConstReverseIterator rbegin() const;

			ConstReverseIterator crbegin() const;

			/**
			 * @brief Gets an iterator to one past the last element in the array.
			 * @return An iterator to one past the last element in the array.
			 */
			Iterator end();

			/** @copydoc Boon::DynamicArray::end */
			ConstIterator end() const;

			/** @copydoc Boon::DynamicArray::end */
			ConstIterator cend() const;

			/**
			 * @brief Gets an iterator to one before the first element in the array.
			 * @return An iterator to one before the first element in the array.
			 */
			ReverseIterator rend();

			/** @copydoc Boon::DynamicArray::rend */
			ConstReverseIterator rend() const;

			ConstReverseIterator crend() const;

			/**
			 * @brief swaps @p first and @p second.
			 * @tparam U The type contained in the Boon::DynamicArray.
			 * @param[in] first The first Boon::DynamicArray.
			 * @param[in] second The second Boon::DynamicArray.
			 * @return void
			 */
			template<class U>
			friend void swap(DynamicArray<U>& first, DynamicArray<U>& second) noexcept;

		private:
			/** Stores the number of elements in the array */
			size_t size = 0;

			/** Stores the capacity of the array */
			size_t capacity = 0;

			/** The internal array */
			T* data = nullptr;
		};
}

#include <Boon/DynamicArray.tpp>