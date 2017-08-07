// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: default constructor", "[DynamicArray]") {
	GIVEN("an empty array") {
		Boon::DynamicArray<int> arr;

		THEN("the size is zero") {
			REQUIRE(arr.size() == 0);
		}

		THEN("the capacity is zero") {
			REQUIRE(arr.capacity() == 0);
		}
	}
}

TEST_CASE("DynamicArray: size constructor", "[DynamicArray]") {
	GIVEN("an array constructed with the size constructor") {
		// The size of the array we want to create
		constexpr size_t size = 4;

		WHEN("an default value is not provided") {
			// Construct an array using the size constructor
			Boon::DynamicArray<int> arr(size);

			THEN("the size is the size that was passed to it") {
				REQUIRE(arr.size() == size);
			}
		
			THEN("the capacity is at least as large as the size") {
				REQUIRE(arr.capacity() >= arr.size());
			}
		}

		WHEN("an default value is provided") {
			// The default value for each element
			constexpr int value = -17;

			// Construct an array using the size constructor
			Boon::DynamicArray<int> arr(size, value);

			THEN("the size is the size that was passed to it") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is at least as large as the size") {
				REQUIRE(arr.capacity() >= arr.size());
			}

			THEN("each element has been initialized to the value passed") {
				for (size_t i = 0; i < arr.size(); ++i) {
					REQUIRE(arr[i] == value);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: list initialization constructor", "[DynamicArray]") {
	GIVEN("an array constructed with the list initialization constructor") {
		// The size of the array
		constexpr size_t size = 9;

		// Construct an array, with list initialization, of the first nine powers of two
		Boon::DynamicArray<int> arr = {1, 2, 4, 8, 16, 32, 64, 128, 256};

		THEN("the size is equal to the number of item in the initialization list") {
			REQUIRE(arr.size() == size);
		}

		THEN("the capacity is at least as large as the size") {
			REQUIRE(arr.capacity() >= arr.size());
		}

		THEN("each element has been initialized to the appropriate value") {
			for (size_t i = 0; i < arr.size(); ++i) {
				int value = 1 << i;
				REQUIRE(arr[i] == value);
			}
		}
	}
}

TEST_CASE("DynamicArray: copy constructor", "[DynamicArray]") {
	GIVEN("an array to copy") {
		// The size of the array to copy
		constexpr size_t size = 9;

		// Construct an array, with list initialization, of the first nine powers of two
		Boon::DynamicArray<int> toCopy = {1, 2, 4, 8, 16, 32, 64, 128, 256};

		WHEN("an array is copy constructed from it") {
			Boon::DynamicArray<int> arr(toCopy);

			THEN("the sizes of both arrays are the equal") {
				REQUIRE(toCopy.size() == arr.size());
			}

			THEN("the arrays do not point to the same internal array") {
				REQUIRE(&toCopy[0] != &arr[0]);
			}

			THEN("the contents of both arrays are equal") {
				for (int i = 0; i < arr.size(); ++i) {
					REQUIRE(toCopy[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: move constructor", "[DynamicArray]") {
	GIVEN("an array to move") {
		// The size of the array to move
		constexpr size_t size = 9;

		// Construct an array, with list initialization, of the first nine powers of two
		Boon::DynamicArray<int> toCopy = {1, 2, 4, 8, 16, 32, 64, 128, 256};

		WHEN("an array is move constructed from it") {

			// Since we are using a move constructor we need to get these values before the move
			const auto toCopySize = toCopy.size();
			const auto toCopyCapacity = toCopy.capacity();
			const auto toCopyData = &toCopy[0];

			// Construct an array with the move constructor
			Boon::DynamicArray<int> arr(std::move(toCopy));

			THEN("the size of the moved to array is equal to the size of the moved array") {
				REQUIRE(arr.size() == toCopySize);
			}

			THEN("the capacity of the moved to array is equal to the capacity of the moved array") {
				REQUIRE(arr.capacity() == toCopyCapacity);
			}

			THEN("the internal data of the moved to array is equal to the internal data of the moved array") {
				REQUIRE(&arr[0] == toCopyData);
			}

			THEN("the internal data of the moved array is null") {
				REQUIRE(&toCopy[0] == nullptr);
			}
		}
	}
}

TEST_CASE("DynamicArray: move assignment operator", "[DynamicArray]") {
	GIVEN("a DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16, 32, 64};

		WHEN("the DynamicArray is move assigned") {
			size_t size;
			int* internalArr;

			{ // This is to ensure that arr.data isnt deleted when toCopy is deconstructed
				decltype(arr) toCopy{64, 32, 16, 8, 4, 2, 1};
				size = toCopy.size();
				internalArr = &toCopy[0];

				arr = std::move(toCopy);
			}

			THEN("the sizes of both arrays are the equal") {
				REQUIRE(size == arr.size());
			}

			THEN("the arrays point to the same internal array") {
				REQUIRE(internalArr == &arr[0]);
			}
		}
	}
}

TEST_CASE("DynamicArray: copy assignment operator", "[DynamicArray]") {
	GIVEN("a DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16, 32, 64};

		WHEN("the DynamicArray is copy assigned") {
			decltype(arr) toCopy{64, 32, 16, 8, 4, 2, 1};
			arr = toCopy;

			THEN("the sizes of both arrays are the equal") {
				REQUIRE(toCopy.size() == arr.size());
			}

			THEN("the arrays do not point to the same internal array") {
				REQUIRE(&toCopy[0] != &arr[0]);
			}

			THEN("the contents of both arrays are equal") {
				for (int i = 0; i < arr.size(); ++i) {
					REQUIRE(toCopy[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: equality operator", "[DynamicArray]") {
	GIVEN("a DynamicArray") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};

		THEN("it is equal to itself") {
			REQUIRE(arr1 == arr1);
		}
	}

	GIVEN("two equivalent DynamicArrays") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};
		Boon::DynamicArray<int> arr2{1, 2, 4, 8, 16, 32, 64};
		
		THEN("they are equal") {
			REQUIRE(arr1 == arr2);
		}
	}

	GIVEN("two non-equivalent DynamicArrays") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};
		Boon::DynamicArray<int> arr2{64, 32, 16, 8, 4, 2, 1};

		THEN("they are not equal") {
			REQUIRE(!(arr1 == arr2));
		}
	}
}

TEST_CASE("DynamicArray: inequality operator", "[DynamicArray]") {
	GIVEN("a DynamicArray") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};

		THEN("it is equal to itself") {
			REQUIRE(!(arr1 != arr1));
		}
	}

	GIVEN("two equivalent DynamicArrays") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};
		Boon::DynamicArray<int> arr2{1, 2, 4, 8, 16, 32, 64};

		THEN("they are equal") {
			REQUIRE(!(arr1 != arr2));
		}
	}

	GIVEN("two non-equivalent DynamicArrays") {
		Boon::DynamicArray<int> arr1{1, 2, 4, 8, 16, 32, 64};
		Boon::DynamicArray<int> arr2{64, 32, 16, 8, 4, 2, 1};

		THEN("they are not equal") {
			REQUIRE(arr1 != arr2);
		}
	}
}

TEST_CASE("DynamicArray: operator[]", "[DynamicArray]") {
	GIVEN("an non empty array") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("we read via the subscript operator") {
			THEN("all value are at the expected index") {
				for (size_t i = 0; i < arr.size(); ++i) {
					REQUIRE(arr[i] == 1 << i);
				}
			}
		}

		WHEN("we write via the subscript operator") {
			constexpr int value = 32;
			arr[2] = value;

			THEN("the written value is at the index written to") {
				REQUIRE(arr[2] == value);
			}
		}
	}
}

TEST_CASE("DynamicArray: operator[] const", "[DynamicArray]") {
	GIVEN("an non empty array") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("we read via the subscript operator") {
			THEN("all value are at the expected index") {
				for (size_t i = 0; i < arr.size(); ++i) {
					REQUIRE(arr[i] == 1 << i);
				}
			}
		}
	}
}