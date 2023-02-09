#include "tests.hpp"

void constructors(void)
{
	{
		test_name("Testing the default constructor");
		ft::vector<int> test;
		assert(0 == test.capacity());
		assert(0 == test.size());

		test_name("Testing the fill constructor");
		ft::vector<int> test1(4, 69);
		assert(4 == test1.capacity());
		assert(4 == test1.size());
		for (size_t i = 0; i < test1.size(); i++)
			assert(69 == *(test1.begin()));
	
		test_name("Testing the range constructor");
        std::vector<int> numbersx(6,33);
        std::vector<int>::iterator itx = numbersx.begin();
        std::vector<int>::iterator itx2 = numbersx.end();
		ft::vector<int> numbers(6, 33);
		ft::vector<int>::iterator it = numbers.begin();
		ft::vector<int>::iterator it2 = numbers.end();

		for (int i = 0; i < 5; i++)
			numbersx[i] = i;
		for (int i = 0; i < 5; i++)
			numbers[i] = i;

		std::vector<int> numbersx2(itx,itx2);
		ft::vector<int> numbers2(it, it2);

        assert(numbersx2.capacity() == numbers2.capacity());
        assert(numbersx2.size() == numbers2.size());
		for (int i = 0; i < 5; i++)
			assert(i == *(numbers2.begin() + i));
		assert(33 == *(numbers2.begin() + 5));
	}

	{
		test_name("Testing the copy constructor");
		std::vector<int> og_numbers(6, 33);
		ft::vector<int> my_numbers(6, 33);
		og_numbers.reserve(17);
		my_numbers.reserve(17);
		std::vector<int> new_vec_og(og_numbers);
		ft::vector<int> new_vec(my_numbers);

		for (size_t i = 0; i < new_vec.size(); i++)
			assert((new_vec[i] == og_numbers[i]) == (my_numbers[i] == new_vec_og[i]));
		assert(my_numbers.size() == new_vec.capacity());
		assert(og_numbers.size() == new_vec_og.capacity());
		assert(my_numbers.size() == new_vec_og.capacity());
	}

}
