#include "../../includes/vector/vector.hpp"
#include "colours.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "../../includes/utils/utils.hpp"
#include <assert.h>

void test_name(std::string name)
{
	std::cout << COLOUR_BLUE << name << COLOUR_RED << std::endl;
}

int main(void)
{
	ft::vector<int>						my_v;
	std::vector<int>					og_v;
	for (int i = 1; i < 5; i++){
		og_v.push_back(i);
		my_v.push_back(i);	
	}
	ft::vector<int>::iterator			my_it;
	std::vector<int>::iterator			og_it;
	const ft::vector<int>				my_v_const(3, 33);
	const std::vector<int>				og_v_const(3, 33);
	ft::vector<int>::const_iterator		my_const_it;
	std::vector<int>::const_iterator	og_const_it;
	
	{
		test_name("vector.begin()");
		my_it = my_v.begin();
		og_it = og_v.begin();
		assert(*(og_it) == *(my_it) );
	}
	
	{
		test_name("const_vector.begin()");
		my_const_it = my_v_const.begin();
		og_const_it = og_v_const.begin();
		assert(*(og_const_it) == *(my_const_it));
	}

	{
		test_name("vector.end()");
		my_it = my_v.end() - 1;
		og_it = og_v.end() - 1;
		assert(*(og_it) ==*(my_it));
	}
	{
		test_name("const_vector.end()");
		my_const_it = my_v_const.end() - 1;
		og_const_it = og_v_const.end() - 1;
		assert(*(og_const_it) == *(my_const_it));
	}
	
	{
		ft::vector<int>::reverse_iterator	my_r_it(my_v.rbegin());
		std::vector<int>::reverse_iterator	og_r_it(og_v.rbegin());

		test_name("rev_it(vector.rbegin())");
		assert(*(og_r_it) == *(my_r_it));

		test_name("rev_it(vector.rend())");
		my_r_it = my_v.rend() - 1;
		og_r_it = og_v.rend() - 1;
		assert(*(og_r_it) == *(my_r_it));

	}

	{
		ft::vector<int>::const_reverse_iterator		my_r_it_const(my_v_const.rbegin());
		std::vector<int>::const_reverse_iterator	og_r_it_const(og_v_const.rbegin());
		ft::vector<int>::const_reverse_iterator		my_r_it_const_end(my_v_const.rend() - 1);
		std::vector<int>::const_reverse_iterator	og_r_it_const_end(og_v_const.rend() - 1);

		test_name("const_rev_it(vector.rbegin())");
		assert(*(og_r_it_const) == *(my_r_it_const));

		test_name("const_rev_it(vector.rend())");
		assert(*(og_r_it_const_end) == *(my_r_it_const_end));
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	{
	    ft::vector<int> nums;
	    ft::vector<int> nums2(nums);

	    test_name("Testing logical operator ==");
	    assert(true == (nums == nums2));
	
	    test_name("Testing logical operator !=");
	    assert(false == (nums != nums2));

	    test_name("Testing logical operator <");
	    assert(false == (nums < nums2));

	    test_name("Testing logical operator <=");
	    assert(true == (nums <= nums2));

	    test_name("Testing logical operator >");
	    assert(false == (nums > nums2));

	    test_name("Testing logical operator >=");
	    assert(true == (nums >= nums2));
	
}

}