
void vector_iterators()
{
	std::vector<int>					og_v;
	ft::vector<int>						my_v;
	const std::vector<int>				og_v_const(3, 33);
	const ft::vector<int>				my_v_const(3, 33);

	for (int i = 0; i < 5; i++){
		og_v.push_back(i + 1);
		my_v.push_back(i + 1);	
	}

	std::vector<int>::iterator					og_it;
	ft::vector<int>::iterator					my_it;
	std::vector<int>::const_iterator			og_const_it;
	ft::vector<int>::const_iterator				my_const_it;
	std::vector<int>::reverse_iterator			og_r_it;
	ft::vector<int>::reverse_iterator			my_r_it;
	std::vector<int>::const_reverse_iterator	og_r_it_const;
	ft::vector<int>::const_reverse_iterator		my_r_it_const;


	{
		test_name("Testing vector.end()");
		my_it = my_v.end() - 1;
		og_it = og_v.end() - 1;
		assert(*(og_it) ==*(my_it));
	}

	{
		test_name("Testing vector.begin()");
		og_it = og_v.begin();
		my_it = my_v.begin();
		assert(*(og_it) == *(my_it) );
	}

	{
		test_name("Testing const_vector.end()");
		my_const_it = my_v_const.end() - 1;
		og_const_it = og_v_const.end() - 1;
		assert(*(og_const_it) == *(my_const_it));
	}
	
	{
		test_name("Testing const_vector.begin()");
		og_const_it = og_v_const.begin();
		my_const_it = my_v_const.begin();
		assert(*(og_const_it) == *(my_const_it));
	}
	
	{
		test_name("Testing vector.rend()");
		my_r_it = my_v.rend() - 1;
		og_r_it = og_v.rend() - 1;
		assert(*(og_r_it) == *(my_r_it));\

		test_name("Testing vector.rbegin()");
		og_r_it = og_v.rbegin();
		my_r_it = my_v.rbegin();
		assert(*(og_r_it) == *(my_r_it));
	}

	std::vector<int>::const_reverse_iterator	og_r_it_const_end;
	ft::vector<int>::const_reverse_iterator		my_r_it_const_end;

	{
		test_name("Testing vector.rend() const");
		og_r_it_const_end = og_v_const.rend() - 1;
		my_r_it_const_end = my_v_const.rend() - 1;
		assert(*(og_r_it_const_end) == *(my_r_it_const_end));

		test_name("Testing vector.rbegin() const");
		og_r_it_const = og_v_const.rbegin();
		my_r_it_const = my_v_const.rbegin();
		assert(*(og_r_it_const) == *(my_r_it_const));
	}

	{
		test_name("Testing iterator (increment and decrement operators).");
		og_it++;
		my_it++;
		og_it += 2;
		my_it += 2;
		assert(*og_it == *my_it);
		og_it--;
		my_it--;
		og_it -= 2;
		my_it -= 2;
		assert(*og_it == *my_it);

		test_name("Testing const iterator (increment and decrement operators).");
		og_const_it++;
		my_const_it++;
		og_const_it += 2;
		my_const_it += 2;
		assert(*og_const_it == *my_const_it);
		og_const_it--;
		my_const_it--;
		og_const_it -= 2;
		my_const_it -= 2;
		assert(*og_const_it == *my_const_it);

		test_name("Testing reverse iterator (increment and decrement operators).");
		og_r_it++;
		my_r_it++;
		og_r_it += 2;
		my_r_it += 2;
		assert(*og_r_it == *my_r_it);
		og_r_it--;
		my_r_it--;
		og_r_it -= 2;
		my_r_it -= 2;
		assert(*og_r_it == *my_r_it);

		test_name("Testing const reverse iterator (increment and decrement operators).");
		og_r_it_const++;
		my_r_it_const++;
		og_r_it_const -= 2;
		my_r_it_const -= 2;
		assert(*og_r_it_const == *my_r_it_const);
		og_r_it_const--;
		my_r_it_const--;
		og_r_it_const += 2;
		my_r_it_const += 2;
		assert(*og_r_it_const == *my_r_it_const);
	}

	std::vector<int>::iterator					copy_og_it(og_it);
	ft::vector<int>::iterator					copy_my_it(my_it);
	std::vector<int>::const_iterator			copy_og_const_it(og_const_it);
	ft::vector<int>::const_iterator				copy_my_const_it(my_const_it);
	std::vector<int>::reverse_iterator			copy_og_r_it(og_r_it);
	ft::vector<int>::reverse_iterator			copy_my_r_it(my_r_it);
	std::vector<int>::const_reverse_iterator	copy_og_r_it_const(og_r_it_const);
	ft::vector<int>::const_reverse_iterator		copy_my_r_it_const(my_r_it_const);

	{
		test_name("Testing copy constructors.");
		assert(og_it == copy_og_it);
		assert(my_it == copy_my_it);
		assert(og_const_it == copy_og_const_it);
		assert(my_const_it == copy_my_const_it);
		assert(og_r_it == copy_og_r_it);
		assert(my_r_it == copy_my_r_it);
		assert(og_r_it_const == copy_og_r_it_const);
		assert(my_r_it_const == copy_my_r_it_const);

		copy_og_it++;
		copy_my_it++;
		copy_og_const_it++;
		copy_my_const_it++;
		copy_og_r_it++;
		copy_my_r_it++;
		copy_og_r_it_const++;
		copy_my_r_it_const++;

		copy_og_it = og_it;
		copy_my_it = my_it;
		copy_og_const_it = og_const_it;
		copy_my_const_it = my_const_it;
		copy_og_r_it = og_r_it;
		copy_my_r_it = my_r_it;
		copy_og_r_it_const = og_r_it_const;
		copy_my_r_it_const = my_r_it_const;

		assert(og_it == copy_og_it);
		assert(my_it == copy_my_it);
		assert(og_const_it == copy_og_const_it);
		assert(my_const_it == copy_my_const_it);
		assert(og_r_it == copy_og_r_it);
		assert(my_r_it == copy_my_r_it);
		assert(og_r_it_const == copy_og_r_it_const);
		assert(my_r_it_const == copy_my_r_it_const);
	}

	{
		test_name("Testing iterator (comparison operators).");
		assert(og_it >= copy_og_it);
		assert(my_it >= copy_my_it);
		assert(og_it <= copy_og_it);
		assert(my_it <= copy_my_it);
		og_it++;
		my_it++;
		assert(og_it != copy_og_it);
		assert(my_it != copy_my_it);
		assert(og_it > copy_og_it);
		assert(my_it > copy_my_it);
		assert(copy_og_it < og_it);
		assert(copy_my_it < my_it);

		test_name("Testing const iterator (comparison operators).");
		assert(og_const_it >= copy_og_const_it);
		assert(my_const_it >= copy_my_const_it);
		assert(og_const_it <= copy_og_const_it);
		assert(my_const_it <= copy_my_const_it);
		og_const_it++;
		my_const_it++;
		assert(og_const_it != copy_og_const_it);
		assert(my_const_it != copy_my_const_it);
		assert(og_const_it > copy_og_const_it);
		assert(my_const_it > copy_my_const_it);
		assert(og_const_it >= copy_og_const_it);
		assert(my_const_it >= copy_my_const_it);
		assert(copy_og_const_it < og_const_it);
		assert(copy_my_const_it < my_const_it);
		assert(copy_og_const_it <= og_const_it);
		assert(copy_my_const_it <= my_const_it);

		test_name("Testing reverse iterator (comparison operators).");
		assert(og_r_it >= copy_og_r_it);
		assert(my_r_it >= copy_my_r_it);
		assert(og_r_it <= copy_og_r_it);
		assert(my_r_it <= copy_my_r_it);
		og_r_it++;
		my_r_it++;
		assert(og_r_it != copy_og_r_it);
		assert(my_r_it != copy_my_r_it);
		assert(og_r_it > copy_og_r_it);
		assert(my_r_it > copy_my_r_it);
		assert(og_r_it >= copy_og_r_it);
		assert(my_r_it >= copy_my_r_it);
		assert(copy_og_r_it < og_r_it);
		assert(copy_my_r_it < my_r_it);
		assert(copy_og_r_it <= og_r_it);
		assert(copy_my_r_it <= my_r_it);

		test_name("Testing const reverse iterator (comparison operators).");
		assert(og_r_it_const >= copy_og_r_it_const);
		assert(my_r_it_const >= copy_my_r_it_const);
		assert(og_r_it_const <= copy_og_r_it_const);
		assert(my_r_it_const <= copy_my_r_it_const);
		og_r_it_const++;
		my_r_it_const++;
		assert(og_r_it_const != copy_og_r_it_const);
		assert(my_r_it_const != copy_my_r_it_const);
		assert(og_r_it_const > copy_og_r_it_const);
		assert(my_r_it_const > copy_my_r_it_const);
		assert(og_r_it_const >= copy_og_r_it_const);
		assert(my_r_it_const >= copy_my_r_it_const);
		assert(copy_og_r_it_const < og_r_it_const);
		assert(copy_my_r_it_const < my_r_it_const);
		assert(copy_og_r_it_const <= og_r_it_const);
		assert(copy_my_r_it_const <= my_r_it_const);
	}

	{
		test_name("Testing all iterators (other operators).");
		assert(og_it[1] == my_it[1]);
		assert(og_const_it[1] == my_const_it[1]);
		assert(og_r_it[1] == my_r_it[1]);
		assert(og_r_it_const[1] == my_r_it_const[1]);

		copy_og_it = og_v.begin() + 2;
		copy_my_it = my_v.begin() + 2;
		og_it = og_v.begin();
		my_it = my_v.begin();
		assert(copy_my_it - my_it == copy_og_it - og_it);

		copy_og_const_it = og_v_const.begin() + 2;
		copy_my_const_it = my_v_const.begin() + 2;
		og_const_it = og_v_const.begin();
		my_const_it = my_v_const.begin();
		assert(copy_my_const_it - my_const_it == copy_og_const_it - og_const_it);

		copy_og_r_it = og_v.rbegin() + 2;
		copy_my_r_it = my_v.rbegin() + 2;
		og_r_it = og_v.rbegin();
		my_r_it = my_v.rbegin();
		assert(copy_my_r_it - my_r_it == copy_og_r_it - og_r_it);

		copy_og_r_it_const = og_v_const.rbegin() + 2;
		copy_my_r_it_const = my_v_const.rbegin() + 2;
		og_r_it_const = og_v_const.rbegin();
		my_r_it_const = my_v_const.rbegin();
		assert(copy_my_r_it_const - my_r_it_const == copy_og_r_it_const - og_r_it_const);
	}
}