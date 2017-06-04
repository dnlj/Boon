#pragma once

// TODO: Document
namespace Boon {
	template<class T>
	class DynamicArray {
		public:
			using Iterator = T*; // TODO: implement proper iterators

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
			 * @return A iterator to the inserted value.
			 */
			Iterator insert(size_t index, T value);
			
			// Iterator insert(Iterator it, T value);
			// Iterator insert(size_t index, size_t count, T value);
			// Iterator insert(Iterator it, size_t count, T value);
			// Iterator pushBack(T value); // TODO: make this use insert?

			// void popBack(); // TODO: make this use erase?
			// void erase(size_t index); // Just make this use start with end = start for simplicity and consitency
			// void erase(size_t start, size_t end);
			
			/**
			 * @brief Clears the Boon::DynamicArray
			 * @return void
			 */
			void clear();
			
			// void shrinkToFit(); // TODO: Changes capacity to size
			
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
			 */
			T& getFront();

			/**
			 * @brief Gets the first element in the Boon::DynamicArray.
			 * @return The first element in the Boon::DynamicArray
			 */
			const T& getFront() const;

			/**
			* @brief Gets the last element in the Boon::DynamicArray.
			* @return The last element in the Boon::DynamicArray
			*/
			T& getBack();

			// const T& getBack() const; // TODO: inline?
			// T& getAt(size_t index);
			// const T& getAt(size_t index) const;
			// T* getData(); // TODO: inline?
			// const T* getData() const; // TODO: inline?

			// TODO: begin/end begin_reverse/end_reverse begin_const/end_const begin_reverse_const/end_reverse_const

			/**
			 * @brief Gets a reference to the value at @p index.
			 * @param[in] index The index to get the reference to.
			 * @return A reference to the value at @p index.
			 */
			T& operator[](size_t index); // TODO: noexcept?
			
			/**
			 * @brief Gets a reference to the value at @p index.
			 * @param[in] index The index to get the reference to.
			 * @return A reference to the value at @p index.
			 */
			const T& operator[](size_t index) const; // TODO: noexcept?
			
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