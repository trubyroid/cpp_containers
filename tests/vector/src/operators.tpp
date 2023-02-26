
void vector_operators() {
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

	{
		test_name("Testing the assignment operator");
		ft::vector<int> my_numbers(6, 33);
		ft::vector<int> my_empty;
		my_empty = my_numbers;
		assert(my_empty == my_numbers);
		for (size_t i = 0; i < my_empty.size(); i++)
			assert(33 == my_empty[i]);

		ft::vector<int> my_non_empty(7, 7);
		my_non_empty = my_numbers;
		assert(my_non_empty == my_numbers);
		for (size_t i = 0; i < my_non_empty.size(); i++)
			assert(33 == my_non_empty[i]);

		ft::vector<int> my_new_empty;
		ft::vector<int> my_newer_empty;
		my_new_empty = my_newer_empty;
		// assert(my_new_empty == my_newer_empty);
	}

    {
	    std::vector<int> og_v(3, 3);
        ft::vector<int> my_v(3, 3);
	    const std::vector<int> og_v_const(3, 4);
	    const ft::vector<int> my_v_const(3, 4);

		test_name("Testing operator[]");
		for (int i = 0; i < 3; i++)
		{
			my_v.at(i) = i + 1;
			og_v.at(i) = i + 1;
		}
		assert(og_v[0] == my_v[0]);
		assert(og_v[1] == my_v[1]);
		assert(og_v[2] == my_v[2]);

		test_name("Testing const operator[]");
		assert(og_v_const[2] == my_v_const[2]);
	}
}