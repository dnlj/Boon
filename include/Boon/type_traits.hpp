#pragma once

// STD
#include <type_traits>

namespace Boon {
	/**
	 * @brief Use the member @c value to check if the types @p Left and @p Right are comparable using operator==.
	 * @tparam Left The left hand type.
	 * @tparam Left The right hand type.
	 */
	template<class Left, class Right, class = void>
	class is_equal_comparable : public std::false_type {};

	/** @copydoc Boon::is_equal_comparable */
	template<class Left, class Right>
	class is_equal_comparable<
		Left,
		Right,
		std::void_t<
			decltype(std::declval<Left>() == std::declval<Right>())
		>
	> : public std::true_type {};

	/** @brief True if the types @p Left and @p Right are comparable using operator==; otherwise false. */
	template<class Left, class Right>
	constexpr auto is_equal_comparable_v = is_equal_comparable<Left, Right>::value;
}
