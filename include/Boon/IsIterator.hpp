#pragma once

// STD
#include <type_traits>

namespace {
	template<class>
	class PassThrough { public: using Type = void; };
}

namespace Boon {
	/**
	 * @brief If @p T is an iterator then IsIterator<T>::value is true, otherwise it is false.
	 * An iterator is defined in §27.2.2 of the ISO C++ standard.
	 * @tparam T The type to check.
	 * @tparam SFINAE Used for SFINAE.
	 */
	template<class T, class SFINAE = void>
	class IsIterator : public std::false_type {};

	/** @copydoc Boon::IsIterator */
	template<class T>
	class IsIterator<T, typename PassThrough<
		decltype(
			// Check for operator*
			std::declval<T>().operator*(),

			// Check for operator++
			std::declval<T>().operator++(),

			// Check operator++ return type
			std::enable_if<std::is_same<T&, decltype(std::declval<T>().operator++())>::value>::type(),

			// Check that T is CopyConstructible
			std::enable_if<std::is_copy_constructible<T>::value>::type(),

			// Check that T is CopyAssignable
			std::enable_if<std::is_copy_assignable<T>::value>::type(),

			// Check that T is Destructible
			std::enable_if<std::is_destructible<T>::value>::type()
		)>::Type
	> : public std::true_type {};
}