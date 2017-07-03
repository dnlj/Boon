#pragma once

// STD
#include <type_traits>

// Boon
#include <Boon/IsIterator.hpp>
#include <Boon/IsEqualityComparable.hpp>

namespace Boon {
	/**
	 * @brief If @p T is an input iterator then IsInputIterator<T>::value is true, otherwise it is false.
	 * An input iterator is defined in §27.2.3 of the ISO C++ standard.
	 * @tparam T The type to check.
	 * @tparam SFINAE Used for SFINAE.
	 */
	template<class T, class SFINAE = void>
	class IsInputIterator : public std::false_type {};

	/** @copydoc Boon::IsInputIterator */
	template<class T>
	class IsInputIterator<T, typename Boon::Meta::VoidType<
		decltype(
			// Check EqualityComparable
			std::enable_if<Boon::IsEqualityComparable<T>::value>::type(),

			// Check for operator!=
			std::declval<T>().operator!=(std::declval<T>()),

			// Check operator!= return type
			std::enable_if<
				std::is_convertible<
					decltype(std::declval<T>().operator!=(std::declval<T>())),
					bool
				>::value
			>::type(),

			// Check operator* return type
			std::enable_if<
				std::is_reference<
					decltype(std::declval<T>().operator*())
				>::value
			>::type(),

			// Check for operator->
			std::declval<T>().operator->(),

			// Check for operator++(int)
			std::declval<T>().operator++(std::declval<int>())
		)>::Type
	> : public IsIterator<T> {};
}