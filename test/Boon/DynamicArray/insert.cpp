// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: insert - index", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning/end") {
			const auto it = arr.insert(0, value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == 1);
			}
			
			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(1, value), std::out_of_range);
			}
			
			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			const auto it = arr.insert(0, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - 1] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			const auto it = arr.insert(initialSize, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[initialSize] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			constexpr size_t index = 2;
			const auto it = arr.insert(index, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[index] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i == index) { continue; }
					REQUIRE(reference[i - (i > index ? 1 : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(initialSize + 1, 32),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: insert - index, move", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		int valueCopy = value;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning/end") {
			const auto it = arr.insert(0, std::move(valueCopy));

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(1, std::move(valueCopy)), std::out_of_range);
			}

			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			int valueCopy = value;
			const auto it = arr.insert(0, std::move(valueCopy));

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - 1] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			int valueCopy = value;

			const auto it = arr.insert(initialSize, std::move(valueCopy));

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[initialSize] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			int valueCopy = value;
			constexpr size_t index = 2;
			const auto it = arr.insert(index, std::move(valueCopy));

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[index] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i == index) { continue; }
					REQUIRE(reference[i - (i > index ? 1 : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			constexpr int value = 64;
			int valueCopy = value;

			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(initialSize + 1, std::move(valueCopy)),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: insert - iterator", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning") {
			const auto it = arr.insert(arr.begin(), value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}
		}

		WHEN("an item is inserted at the end") {
			const auto it = arr.insert(arr.end(), value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(arr.end() + 1, value), std::out_of_range);
			}

			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			const auto it = arr.insert(arr.begin(), value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - 1] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			const auto it = arr.insert(arr.end(), value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[initialSize] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			constexpr size_t index = 2;
			const auto it = arr.insert(arr.begin() + index, value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[index] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i == index) { continue; }
					REQUIRE(reference[i - (i > index ? 1 : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(arr.end() + 1, 32),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: insert - index, count", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		constexpr int count = 8;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning/end") {
			auto it = arr.insert(0, count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[i] == value);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(1, count, value), std::out_of_range);
			}

			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		constexpr int count = 8;
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			auto it = arr.insert(0, count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = count; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - count] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			auto it = arr.insert(initialSize, count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[initialSize + i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			constexpr size_t index = 2;
			auto it = arr.insert(index, count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[index + i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i >= index && i <= index + count) { continue; }
					REQUIRE(reference[i - (i > index ? count : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(initialSize + 1, count, 32),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: insert - iterator, count", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		constexpr int count = 8;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning") {
			auto it = arr.insert(arr.begin(), count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[i] == value);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			auto it = arr.insert(arr.end(), count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[i] == value);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(arr.end() + 1, count, value), std::out_of_range);
			}

			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		constexpr int count = 8;
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			auto it = arr.insert(arr.begin(), count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = count; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - count] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			auto it = arr.insert(arr.end(), count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[initialSize + i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			constexpr size_t index = 2;
			auto it = arr.insert(arr.begin() + index, count, value);

			THEN("the first count values of the returned iterator are equal to the value inserted") {
				for (int i = 0; i < count; ++i, ++it) {
					REQUIRE(*it == value);
				}
			}

			THEN("the size of the array increases by count") {
				REQUIRE(arr.getSize() == initialSize + count);
			}

			THEN("the item at that position has the corresponding value") {
				for (int i = 0; i < count; ++i) {
					REQUIRE(arr[index + i] == value);
				}
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i >= index && i <= index + count) { continue; }
					REQUIRE(reference[i - (i > index ? count : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(arr.end() + 1, count, 32),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}