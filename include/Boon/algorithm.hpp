#pragma once

// STD
#include <type_traits>
#include <iterator>

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
	 * @brief Sorts the elements in the range [@p first, @p last) using a bubble sort.
	 * @tparam BiIt The bidirectional iterator type.
	 * @param[in] first The first element to sort.
	 * @param[in] last One past the last element to sort.
	 */
	template<
		class BiIt,
		class = std::enable_if_t<
			std::is_base_of_v<
				std::bidirectional_iterator_tag,
				std::iterator_traits<BiIt>::iterator_category
			>
		>
	>
	void bubble_sort(BiIt first, BiIt last);

}

#include <Boon/algorithm.tpp>