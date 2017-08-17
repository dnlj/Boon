// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

namespace {
	using T = int;
	using ArrayType = Boon::DynamicArray<T>;
	using Iterator = ArrayType::iterator;
}

TEST_CASE("DynamicArray::Iterator: Constructor (empty)", "[Iterator][DynamicArray::Iterator]") {
	REQUIRE_NOTHROW(Iterator{});
}

TEST_CASE("DynamicArray::Iterator: Constructor (from pointer)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an DynamicArray") {
		ArrayType arr{0, 1, 2, 4, 8};

		THEN("an iterator can be constructed from a pointer to a object in the array") {
			REQUIRE_NOTHROW(Iterator{&arr[2]});
		}
	}
}

TEST_CASE("DynamicArray::Iterator: Copy Constructor", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an Iterator") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		const Iterator it{&arr[loc]};

		THEN("a new Iterator can be copy constructed from that iterator") {
			REQUIRE_NOTHROW(Iterator{it});
			REQUIRE(Iterator{it} == it);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: Copy Assignment", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an Iterator") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		const Iterator it{&arr[loc]};

		THEN("a new Iterator can be copy assigned from that iterator") {
			auto a = it;
			REQUIRE(a == it);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator*", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is dereferenced") {
			THEN("the returned reference is equal to the value in the array at that location") {
				REQUIRE(*it == arr[loc]);
			}

			THEN("the returned reference can be assigned to") {
				constexpr T val = 32;
				*it = val;

				THEN("the value of in the array at that location is equal to the assigned value") {
					REQUIRE(*it == val);
					REQUIRE(arr[loc] == val);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator* const", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		const Iterator it{&arr[loc]};

		WHEN("the iterator is dereferenced") {
			THEN("the returned reference is equal to the value in the array at that location") {
				REQUIRE(*it == arr[loc]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator++ (pre)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is incremented with the pre-increment operator") {
			++it;

			THEN("the value pointed to by the iterator is equal to the next element in the array") {
				REQUIRE(*it == arr[loc + 1]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator++ (post)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is incremented with the post-increment operator") {
			auto before = it++;

			THEN("the value returned is equal to the original element in the array") {
				REQUIRE(*before == arr[loc]);
			}

			THEN("the value pointed to by the iterator is equal to the next element in the array") {
				REQUIRE(*it == arr[loc + 1]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator-- (pre)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is decremented with the pre-decrement operator") {
			--it;

			THEN("the value pointed to by the iterator is equal to the previous element in the array") {
				REQUIRE(*it == arr[loc - 1]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator-- (post)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is decremented with the post-decrement operator") {
			auto before = it--;

			THEN("the value returned is equal to the original element in the array") {
				REQUIRE(*before == arr[loc]);
			}

			THEN("the value pointed to by the iterator is equal to the previous element in the array") {
				REQUIRE(*it == arr[loc - 1]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator+=", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		constexpr size_t inc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is increased") {
			it += inc;

			THEN("the value pointed to by the iterator is equal to that item in the array") {
				REQUIRE(*it == arr[loc + inc]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator-=", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		constexpr size_t inc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is decreased") {
			it -= inc;

			THEN("the value pointed to by the iterator is equal to that item in the array") {
				REQUIRE(*it == arr[loc - inc]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator==", "[Iterator][DynamicArray::Iterator]") {
	constexpr size_t loc1 = 2;
	constexpr size_t loc2 = 0;
	ArrayType arr{0, 1, 2, 4, 8};

	GIVEN("two iterators to the same element in an array") {
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc1]};

		THEN("the iterators are equal") {
			REQUIRE(it1 == it2);
		}
	}

	GIVEN("two iterators to different elements in an array") {
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		THEN("the iterators are not equal") {
			REQUIRE(!(it1 == it2));
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator!=", "[Iterator][DynamicArray::Iterator]") {
	constexpr size_t loc1 = 2;
	constexpr size_t loc2 = 0;
	ArrayType arr{0, 1, 2, 4, 8};

	GIVEN("two iterators to the same element in an array") {
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc1]};

		THEN("the iterators are equal") {
			REQUIRE(!(it1 != it2));
		}
	}

	GIVEN("two iterators to different elements in an array") {
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		THEN("the iterators are not equal") {
			REQUIRE(it1 != it2);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator->", "[Iterator][DynamicArray::Iterator]") {
	struct Test {
		int a = 2;
		float b = 32.0f;
	};

	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		Boon::DynamicArray<Test> arr = {
			{2, 4.0f},
			{8, 16.0f},
			{32, 64.0f},
			{128, 256.0f},
			{512, 1024.0f},
		};

		decltype(arr)::iterator it{&arr[loc]};

		THEN("the members of that element can be read from") {
			REQUIRE(it->a == arr[loc].a);
			REQUIRE(it->b == arr[loc].b);
		}

		THEN("the members of that element can assigned to") {
			constexpr decltype(Test::a) aValue = 3;
			constexpr decltype(Test::b) bValue = 7.3f;

			it->a = aValue;
			it->b = bValue;

			REQUIRE(it->a == aValue);
			REQUIRE(it->b == bValue);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator-> const", "[Iterator][DynamicArray::Iterator]") {
	struct Test {
		int a = 2;
		float b = 32.0f;
	};

	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		Boon::DynamicArray<Test> arr = {
			{2, 4.0f},
			{8, 16.0f},
			{32, 64.0f},
			{128, 256.0f},
			{512, 1024.0f},
		};

		const decltype(arr)::iterator it{&arr[loc]};

		THEN("the members of that element can be read from") {
			REQUIRE(it->a == arr[loc].a);
			REQUIRE(it->b == arr[loc].b);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: friend operator+", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		constexpr size_t inc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is increased") {
			auto it2 = it + inc;
			auto it3 = inc + it;

			THEN("the value pointed to by the iterator is equal to that item in the array") {
				REQUIRE(it3 == it2);
				REQUIRE(*it2 == arr[loc + inc]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: friend operator-", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an iterator to an element in an array") {
		constexpr size_t loc = 2;
		constexpr size_t inc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		WHEN("the iterator is decreased") {
			auto it2 = it - inc;

			THEN("the value pointed to by the iterator is equal to that item in the array") {
				REQUIRE(*it2 == arr[loc - inc]);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: friend operator- (difference)", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("two iterators to elements in an array") {
		constexpr size_t loc1 = 2;
		constexpr size_t loc2 = 4;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		WHEN("the iterators are subtracted") {
			auto diff = it2 - it1;

			THEN("the first + diff is equal to the second") {
				REQUIRE(it1 + diff == it2);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator[]", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an Iterator") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it{&arr[loc]};

		THEN("the subscript operator returns the value at that location") {
			REQUIRE(it[0] == arr[loc + 0]);
			REQUIRE(it[2] == arr[loc + 2]);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator[] const", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("an Iterator") {
		constexpr size_t loc = 2;
		ArrayType arr{0, 1, 2, 4, 8};
		const Iterator it{&arr[loc]};

		THEN("the subscript operator returns the value at that location") {
			REQUIRE(it[0] == arr[loc + 0]);
			REQUIRE(it[2] == arr[loc + 2]);
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator<", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("two iterators to elements in an array") {
		constexpr size_t loc1 = 2;
		constexpr size_t loc2 = 4;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		WHEN("the iterators are compared") {
			THEN("the first is less than the second") {
				REQUIRE(it1 < it2);
			}

			THEN("the first is not less than the first") {
				REQUIRE_FALSE(it1 < it1);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator>", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("two iterators to elements in an array") {
		constexpr size_t loc1 = 2;
		constexpr size_t loc2 = 4;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		WHEN("the iterators are compared") {
			THEN("the second is greater than the first") {
				REQUIRE(it2 > it1);
			}

			THEN("the second is not greater than the second") {
				REQUIRE_FALSE(it2 > it2);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator<=", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("two iterators to elements in an array") {
		constexpr size_t loc1 = 2;
		constexpr size_t loc2 = 4;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		WHEN("the iterators are compared") {
			THEN("the first is less than or equal to the second") {
				REQUIRE(it1 <= it2);
			}

			THEN("the first is less than or equal to the first") {
				REQUIRE(it1 <= it1);
			}
		}
	}
}

TEST_CASE("DynamicArray::Iterator: operator>=", "[Iterator][DynamicArray::Iterator]") {
	GIVEN("two iterators to elements in an array") {
		constexpr size_t loc1 = 2;
		constexpr size_t loc2 = 4;
		ArrayType arr{0, 1, 2, 4, 8};
		Iterator it1{&arr[loc1]};
		Iterator it2{&arr[loc2]};

		WHEN("the iterators are compared") {
			THEN("the second is greater than or equal to the first") {
				REQUIRE(it2 >= it1);
			}

			THEN("the second is greater than or equal to the second") {
				REQUIRE(it2 >= it2);
			}
		}
	}
}