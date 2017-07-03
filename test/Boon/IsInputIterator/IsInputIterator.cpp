// Catch
#include <catch.hpp>

// STD
#include <type_traits>
#include <vector>
#include <iostream>

// Boon
#include <Boon/IsInputIterator.hpp>

namespace {
	// As specified in §27.2.3 of the ISO C++ standard.
	template<class T>
	class InputIterator {
		public:
		InputIterator(const InputIterator<T>&);
		InputIterator& operator=(const InputIterator&);
		~InputIterator();
		T& operator*();
		InputIterator& operator++();
		bool operator==(const InputIterator<T>&);
		bool operator!=(const InputIterator<T>&);
		T* operator->();
		InputIterator operator++(int);
	};
}

TEST_CASE("IsInputIterator", "[IsInputIterator]") {
	using T = int;
	using It = InputIterator<T>;

	GIVEN("an input iterator type") {
		THEN("then value is defined to true") {
			REQUIRE(Boon::IsInputIterator<It>::value == true);
		}
	}

	GIVEN("an input iterator (from std)") {
		using ItStd = std::vector<int>::iterator;

		THEN("then value is defined to true") {
			REQUIRE(Boon::IsInputIterator<ItStd>::value == true);
		}
	}

	GIVEN("an non input iterator type (not CopyConstructible)") {
		class NonIt : public It {
			public: NonIt(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (not CopyAssignable)") {
		class NonIt : public It {
			public: NonIt& operator=(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (not Destructible)") {
		class NonIt : public It {
			public: ~NonIt() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (no operator*)") {
		class NonIt : public It {
			public: T& NonIt::operator*() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (no operator++)") {
		class NonIt : public It {
			public: NonIt& operator++() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (wrong return type operator++)") {
		class NonIt : public It {
			public: float& operator++();
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (not EqualityComparable)") {
		class NonIt : public It {
			public: bool operator==(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (no operator!=)") {
		class NonIt : public It {
			public: bool operator!=(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (wrong return type operator!=)") {
		class NonIt : public It {
			public: float& operator!=(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (wrong return type operator*)") {
		class NonIt : public It {
			public: T operator*();
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (no operator->)") {
		class NonIt : public It {
			public: T* operator->() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non input iterator type (no operator++(int))") {
		class NonIt : public It {
			public: NonIt operator++(int) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsInputIterator<NonIt>::value == false);
		}
	}
}