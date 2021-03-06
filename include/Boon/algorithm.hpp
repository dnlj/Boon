#pragma once

// STD
#include <type_traits>
#include <iterator>

// Boon
#include <Boon/type_traits.hpp>

namespace Boon {
	/**
	 * @brief Gets @p first. @see the variadic version of Boon::min.
	 * @tparam T The type of @p first.
	 * @param[in] first The item to return.
	 * @return @p first.
	 */
	template<class T>
	inline constexpr const T& min(const T& first);

	/**
	 * @brief Gets the minimum of @p first, @p second, and @p other.
	 * @note This function is enabled only if the types of @p first, @p second, and @p other are the same.
	 * @tparam T The type of @p first, @p second, and @p other.
	 * @tparam Args The same as @p T. Variadic.
	 * @param[in] first The first item to compare.
	 * @param[in] second The second item to compare.
	 * @param[in] other The other items to compare. Variadic.
	 * @return The minimum of @p first, @p second, and @p other.
	 */
	template<class T, class... Args, std::enable_if_t<std::conjunction_v<std::is_same<T, Args>...>, nullptr_t> = nullptr>
	constexpr const T& min(const T& first, const T& second, const Args&... other);

	/**
	 * @brief Gets the minimum of the items in @p list.
	 * @tparam T The type of the items in @p list.
	 * @param[in] list The items to compare.
	 * @return The minimum of the items in @p list.
	 */
	template<class T>
	constexpr T min(const std::initializer_list<T>& list);

	/**
	 * @brief Gets @p first. @see the variadic version of Boon::max.
	 * @tparam T The type of @p first.
	 * @param[in] first The item to return.
	 * @return @p first.
	 */
	template<class T>
	inline constexpr const T& max(const T& first);

	/**
	 * @brief Gets the maximum of @p first, @p second, and @p other.
	 * @note This function is enabled only if the types of @p first, @p second, and @p other are the same.
	 * @tparam T The type of @p first, @p second, and @p other.
	 * @tparam Args The same as @p T. Variadic.
	 * @param[in] first The first item to compare.
	 * @param[in] second The second item to compare.
	 * @param[in] other The other items to compare. Variadic
	 * @return The maximum of @p first, @p second, and @p other.
	 */
	template<class T, class... Args, std::enable_if_t<std::conjunction_v<std::is_same<T, Args>...>, nullptr_t> = nullptr>
	constexpr const T& max(const T& first, const T& second, const Args&... other);

	/**
	 * @brief Gets the maximum of the items in @p list.
	 * @tparam T The type of the items in @p list.
	 * @param[in] list The items to compare.
	 * @return The maximum of the items in @p list.
	 */
	template<class T>
	constexpr T max(const std::initializer_list<T>& list);

	/**
	 * @brief Copies all elements from @p inStart until @p inEnd into @p outStart.
	 * @tparam InIt The iterator type for @p inStart and @p inEnd.
	 * @tparam OutIt The iterator type for @p outStart.
	 * @param[in] inStart The iterator to start copying from.
	 * @param[in] inEnd The iterator to copy until.
	 * @param[out] outStart The start iterator to copy into.
	 * @return void
	 */
	template<class InIt, class OutIt>
	void copy(InIt inStart, InIt inEnd, OutIt outStart);

	/**
	 * @brief Moves all elements from @p inStart until @p inEnd into @p outStart.
	 * @tparam InIt The iterator type for @p inStart and @p inEnd.
	 * @tparam OutIt The iterator type for @p outStart.
	 * @param[in] inStart The iterator to start moving from.
	 * @param[in] inEnd The iterator to move until.
	 * @param[out] outStart The start iterator to move into.
	 * @return void
	 */
	template<class InIt, class OutIt>
	void move(InIt inStart, InIt inEnd, OutIt outStart);

	/**
	 * @brief Sorts the elements in the range [@p begin, @p end) using a bubble sort.
	 * @tparam ForwardIt The forward iterator type.
	 * @param[in] begin The beginning of the range of elements to sort.
	 * @param[in] end The end of the range of elements to sort.
	 */
	template<
		class ForwardIt,
		class = std::enable_if_t<
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt>::iterator_category>
		>
	>
	void bubble_sort(ForwardIt begin, ForwardIt end);

	/**
	 * @brief Sorts the elements in the range [@p begin, @p end) using an insertion sort.
	 * @tparam ForwardIt The forward iterator type.
	 * @param[in] begin The beginning of the range of elements to sort.
	 * @param[in] end The end of the range of elements to sort.
	 */
	template<
		class ForwardIt,
		class = std::enable_if_t<
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt>::iterator_category>
		>
	>
	void insertion_sort(ForwardIt begin, ForwardIt end);

	/**
	 * @brief Merges the two ranges specified by [\p begin1, \p end1) U [\p begin2, \p end2).
	 * The merge is destructive to the input ranges (elements are moved, not copied).
	 * @tparam ForwardIt1 The forward iterator type of the first range.
	 * @tparam ForwardIt2 The forward iterator type of the second range.
	 * @tparam ForwardIt3 The forward iterator type of the output range.
	 * @param[in] begin1 The start of the first range.
	 * @param[in] end1 The end of the first range.
	 * @param[in] begin2 The start of the second range.
	 * @param[in] end2 The end of the second range.
	 * @param[out] output The start of the output range. The output range must be large enough to hold [\p begin1, \p end1) U [\p begin2, \p end2).
	 */
	template<
		class ForwardIt1,
		class ForwardIt2,
		class ForwardIt3,
		class = std::enable_if_t<
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt1>::iterator_category>
			&& 
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt2>::iterator_category>
			&&
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt3>::iterator_category>
		>
	>
	void merge_ranges(const ForwardIt1 begin1, const ForwardIt1 end1, const ForwardIt2 begin2, const ForwardIt2 end2, ForwardIt3 output);

	/**
	 * @brief Sorts the elements in the range [@p begin, @p end) using an merge sort.
	 * @tparam ForwardIt The forward iterator type.
	 * @param[in] begin The beginning of the range of elements to sort.
	 * @param[in] end The end of the range of elements to sort.
	 */
	template<
		class ForwardIt,
		class = std::enable_if_t<
			std::is_base_of_v<std::forward_iterator_tag, std::iterator_traits<ForwardIt>::iterator_category>
		>
	>
	void merge_sort(ForwardIt begin, ForwardIt end);

	/**
	 * @brief Finds @p value in the range [@p begin, @p end) using an linear search.
	 * @tparam InputIt The input iterator type.
	 * @tparam T The type of @p value.
	 * @param[in] begin The beginning of the range of elements to search.
	 * @param[in] end The end of the range of elements to search.
	 * @param[in] value The value to search for.
	 * @return An iterator to the first found element, or @p 
	 */
	template<
		class InputIt,
		class T,
		class = std::enable_if_t<
			std::is_base_of_v<std::input_iterator_tag, std::iterator_traits<InputIt>::iterator_category>
			&&
			Boon::is_equal_comparable_v<T, std::iterator_traits<InputIt>::value_type>
		>
	>
	InputIt linear_search(InputIt begin, InputIt end, const T& value);
}

#include <Boon/algorithm.ipp>