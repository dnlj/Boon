namespace Boon {
	template<class T>
	inline constexpr const T& min(const T& first) {
		return first;
	};
	
	template<class T, class... Args, std::enable_if_t<std::conjunction_v<std::is_same<T, Args>...>, nullptr_t>>
	constexpr const T& min(const T& first, const T& second, const Args&... other) {
		return min(first < second ? first : second, other...);
	};
	
	template<class T>
	constexpr T min(const std::initializer_list<T>& list) {
		if (list.size() == 1) { return *list.begin(); }
	
		auto smallest = list.begin();
		for (auto it = smallest + 1; it != list.end(); ++it) {
			if (*it < *smallest) {
				smallest = it;
			}
		}
	
		return *smallest;
	};

	template<class T>
	inline constexpr const T& max(const T& first) {
		return first;
	};

	template<class T, class... Args, std::enable_if_t<std::conjunction_v<std::is_same<T, Args>...>, nullptr_t>>
	constexpr const T& max(const T& first, const T& second, const Args&... other) {
		return max(first > second ? first : second, other...);
	};

	template<class T>
	constexpr T max(const std::initializer_list<T>& list) {
		if (list.size() == 1) { return *list.begin(); }

		auto largest = list.begin();
		for (auto it = largest + 1; it != list.end(); ++it) {
			if (*it > *largest) {
				largest = it;
			}
		}

		return *largest;
	};

	template<class InIt, class OutIt>
	void copy(InIt inStart, InIt inEnd, OutIt outStart) {
		while (inStart != inEnd) {
			*(outStart++) = *(inStart++);
		}
	}

	template<class InIt, class OutIt>
	void move(InIt inStart, InIt inEnd, OutIt outStart) {
		while (inStart != inEnd) {
			*(outStart++) = std::move(*(inStart++));
		}
	}
}