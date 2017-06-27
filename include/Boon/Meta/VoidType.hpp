#pragma once

namespace Boon::Meta {
	/**
	 * @brief A template class with nested type VoidType::Type = void.
	 */
	template<class>
	class VoidType {
		public:
			using Type = void;
	};
}