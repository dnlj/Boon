#pragma once

// STD
#include <type_traits>

// Boon
#include <Boon/Meta/VoidType.hpp>

namespace Boon {
	/**
	 * @brief If @p T is EqualityComparable then IsEqualityComparable<T>::value is true, otherwise it is false.
	 * EqualityComparable is defined in §20.5.3.1 of the ISO C++ standard.
	 * @tparam T The type to check.
	 * @tparam SFINAE Used for SFINAE.
	 */
	template<class T, class SFINAE = void>
	class IsEqualityComparable : public std::false_type {};

	/** @copydoc Boon::IsEqualityComparable */
	template<class T>
	class IsEqualityComparable<T, typename Boon::Meta::VoidType<
		decltype(
			// Check for operator==
			std::declval<T>().operator==(std::declval<T>()),

			// Check for operator== return type
			std::enable_if<
				std::is_convertible<
					decltype(std::declval<T>().operator==(std::declval<T>())),
					bool
				>::value
			>::type()
		)>::Type
	> : public std::true_type{};
}
