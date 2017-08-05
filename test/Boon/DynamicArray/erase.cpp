// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: erase - index, range", "[DynamicArray][erase]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("erase is called with a invalid range") {
			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(0, 0));
				REQUIRE_THROWS(arr.erase(0, 1));
				REQUIRE_THROWS(arr.erase(0, 2));
				REQUIRE_THROWS(arr.erase(1, 0));
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr_reference = {1, 2, 4, 8, 16, 32};
		Boon::DynamicArray<int> arr = arr_reference;

		WHEN("erase is called with a valid range") {
			constexpr size_t start = 1;
			constexpr size_t end = 5;
			const auto it = arr.erase(start, end);
			
			THEN("the elements in the range are removed") {
				REQUIRE(arr.getSize() == 2);
				REQUIRE(arr[0] == 1);
				REQUIRE(arr[1] == 32);
			}

			THEN("the returned iterator is to the next element in the array") {
				REQUIRE(*it == arr_reference[end]);
			}
		}

		WHEN("erase is called over the whole range") {
			constexpr size_t start = 0;
			const size_t end = arr.getSize();
			const auto it = arr.erase(start, end);

			THEN("the elements in the range are removed") {
				REQUIRE(arr.getSize() == 0);
			}

			THEN("the returned iterator is end()") {
				REQUIRE(it == arr.end());
			}
		}

		WHEN("erase is called with a invalid range (start == end)") {
			constexpr size_t start = 2;
			constexpr size_t end = start;

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}

		WHEN("erase is called with a invalid range (start > end)") {
			constexpr size_t start = 5;
			constexpr size_t end = 1;
			
			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}

		WHEN("erase is called with a invalid range (start > size)") {
			constexpr size_t start = 7;
			constexpr size_t end = 8;

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: erase - index", "[DynamicArray][erase]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("erase is called with a invalid index") {
			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(0));
				REQUIRE_THROWS(arr.erase(1));
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr_reference = {1, 2, 4, 8, 16, 32};
		Boon::DynamicArray<int> arr = arr_reference;

		WHEN("erase is called with a valid index") {
			constexpr size_t index = 1;
			const auto it = arr.erase(index);

			THEN("the element is removed and the other elements are unchanged") {
				REQUIRE(arr.getSize() == arr_reference.getSize() - 1);
				for (size_t i = 0; i < arr.getSize(); ++i) {
					REQUIRE(arr[i] ==  arr_reference[i >= index ? i + 1 : i]);
				}
			}

			THEN("the returned iterator is to the next element in the array") {
				REQUIRE(*it == arr_reference[index + 1]);
			}
		}

		WHEN("erase is called with a invalid index") {
			const size_t index = arr.getSize();

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(index));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: erase - iterator", "[DynamicArray][erase]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("erase is called with a invalid iterator") {
			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(arr.begin()));
				REQUIRE_THROWS(arr.erase(arr.end()));
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr_reference = {1, 2, 4, 8, 16, 32};
		Boon::DynamicArray<int> arr = arr_reference;

		WHEN("erase is called with a valid iterator") {
			const auto it = arr.begin() + 1;
			const size_t index = it - arr.begin();
			const auto ret = arr.erase(it);

			THEN("the element is removed and the other elements are unchanged") {
				REQUIRE(arr.getSize() == arr_reference.getSize() - 1);

				for (size_t i = 0; i < arr.getSize(); ++i) {
					REQUIRE(arr[i] == arr_reference[i >= index ? i + 1 : i]);
				}
			}


			THEN("the returned iterator is to the next element in the array") {
				REQUIRE(*ret == arr_reference[index + 1]);
			}
		}

		WHEN("erase is called with a invalid iterator") {
			const auto it = arr.end();

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(it));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: erase - iterator, range", "[DynamicArray][erase]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("erase is called with a invalid range") {
			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(arr.begin(), arr.begin()));
				REQUIRE_THROWS(arr.erase(arr.begin(), arr.end()));
				REQUIRE_THROWS(arr.erase(arr.end(), arr.begin()));
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr_reference = {1, 2, 4, 8, 16, 32};
		Boon::DynamicArray<int> arr = arr_reference;

		WHEN("erase is called with a valid range") {
			const auto start = arr.begin() + 1;
			const auto end = arr.begin() + 5;
			const size_t index = end - arr.begin();
			const auto it = arr.erase(start, end);

			THEN("the elements in the range are removed") {
				REQUIRE(arr.getSize() == 2);
				REQUIRE(arr[0] == 1);
				REQUIRE(arr[1] == 32);
			}

			THEN("the returned iterator is to the next element in the array") {
				REQUIRE(*it == arr_reference[index]);
			}
		}

		WHEN("erase is called over the whole range") {
			const auto start = arr.begin();
			const auto end = arr.end();
			const auto it = arr.erase(start, end);

			THEN("the elements in the range are removed") {
				REQUIRE(arr.getSize() == 0);
			}

			THEN("the returned iterator is end()") {
				REQUIRE(it == arr.end());
			}
		}

		WHEN("erase is called with a invalid range (start == end)") {
			const auto start = arr.begin() + 2;
			const auto end = start;

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}

		WHEN("erase is called with a invalid range (start > end)") {
			const auto start = arr.begin() + 5;
			const auto end = arr.begin() + 1;

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}

		WHEN("erase is called with a invalid range (start > size)") {
			const auto start = arr.begin() + 7;
			const auto end = arr.end() + 8;

			THEN("an exception is thrown") {
				REQUIRE_THROWS(arr.erase(start, end));

				THEN("the elements in the array are not modified") {
					REQUIRE(arr.getSize() == arr_reference.getSize());

					for (size_t i = 0; i < arr.getSize(); ++i) {
						REQUIRE(arr[i] == arr_reference[i]);
					}
				}
			}
		}
	}
}