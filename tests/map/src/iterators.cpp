
void map_iterators(void) {
    std::map<int, int>					    og_m;
	ft::map<int, int>						my_m;

    for (int i = 0; i < 8; i++) {
        og_m[i] = i + 1;
        my_m[i] = i + 1;
    }
    
	std::map<int, int>::iterator					og_it;
	ft::map<int, int>::iterator					    my_it;
	std::map<int, int>::reverse_iterator			og_r_it;
	ft::map<int, int>::reverse_iterator			    my_r_it;


	{
		test_name("Testing map.end()");
		og_it = og_m.end();
		my_it = my_m.end();
        og_it--;
        my_it--;
		assert(og_it->first == my_it->first );
		assert(og_it->second == my_it->second );
	}

	{
		test_name("Testing map.begin()");
		og_it = og_m.begin();
		my_it = my_m.begin();
		assert(og_it->first == my_it->first );
		assert(og_it->second == my_it->second );
	}

	{
		test_name("Testing map.rend()");
		my_r_it = my_m.rend();
		og_r_it = og_m.rend();
        my_r_it--;
        og_r_it--;
		assert(og_r_it->first == my_r_it->first );
		assert(og_r_it->second == my_r_it->second );

		test_name("Testing map.rbegin()");
		my_r_it = my_m.rbegin();
		og_r_it = og_m.rbegin();
		assert(og_r_it->first == my_r_it->first );
		assert(og_r_it->second == my_r_it->second );
	}

    std::map<int, int>::iterator					og_it_beg = og_m.begin();
	ft::map<int, int>::iterator					    my_it_beg = my_m.begin();
    std::map<int, int>::iterator					og_it_end = og_m.end();
	ft::map<int, int>::iterator					    my_it_end = my_m.end();

	const std::map<int, int>				        og_m_const(og_it_beg, og_it_end);
	const ft::map<int, int>				            my_m_const(my_it_beg, my_it_end);
    
	std::map<int, int>::const_iterator			    og_const_it;
	ft::map<int, int>::const_iterator				my_const_it;
	std::map<int, int>::const_reverse_iterator	    og_r_it_const;
	ft::map<int, int>::const_reverse_iterator		my_r_it_const;

	{
		test_name("Testing const_map.end()");
		og_const_it = og_m_const.end();
		my_const_it = my_m_const.end();
        og_const_it--;
        my_const_it--;
		assert(og_const_it->first == my_const_it->first );
		assert(og_const_it->second == my_const_it->second );
	}
	
	{
		test_name("Testing const_map.begin()");
		og_const_it = og_m_const.begin();
		my_const_it = my_m_const.begin();
		assert(og_const_it->first == my_const_it->first );
		assert(og_const_it->second == my_const_it->second );
	}

	{
		test_name("Testing map.rend() const");
		og_r_it_const = og_m_const.rend();
		my_r_it_const = my_m_const.rend();
        og_r_it_const--; 
        my_r_it_const--; 
		assert(og_r_it_const->first == my_r_it_const->first );
		assert(og_r_it_const->second == my_r_it_const->second );

		test_name("Testing map.rbegin() const");
		og_r_it_const = og_m_const.rbegin();
		my_r_it_const = my_m_const.rbegin();
		assert(og_r_it_const->first == my_r_it_const->first );
		assert(og_r_it_const->second == my_r_it_const->second );
	}

	{
		test_name("Testing iterator (increment and decrement operators).");
		og_it++;
		my_it++;
		assert(og_it->first == my_it->first );
		assert(og_it->second == my_it->second );
		og_it--;
		my_it--;
		assert(og_it->first == my_it->first );
		assert(og_it->second == my_it->second );

		test_name("Testing reverse iterator (increment and decrement operators).");
		og_r_it++;
		my_r_it++;
		assert(og_r_it->first == my_r_it->first );
		assert(og_r_it->second == my_r_it->second );
		og_r_it--;
		my_r_it--;
		assert(og_r_it->first == my_r_it->first );
		assert(og_r_it->second == my_r_it->second );

		test_name("Testing const iterator (increment and decrement operators).");
		og_const_it++;
		my_const_it++;
		assert(og_const_it->first == my_const_it->first );
		assert(og_const_it->second == my_const_it->second );
		og_const_it--;
		my_const_it--;
		assert(og_const_it->first == my_const_it->first );
		assert(og_const_it->second == my_const_it->second );


		test_name("Testing const reverse iterator (increment and decrement operators).");
		og_r_it_const++;
		my_r_it_const++;
		assert(og_r_it_const->first == my_r_it_const->first );
		assert(og_r_it_const->second == my_r_it_const->second );
		og_r_it_const--;
		my_r_it_const--;
		assert(og_r_it_const->first == my_r_it_const->first );
		assert(og_r_it_const->second == my_r_it_const->second );
	}

	std::map<int, int>::iterator					copy_og_it(og_it);
	ft::map<int, int>::iterator					    copy_my_it(my_it);
	std::map<int, int>::const_iterator			    copy_og_const_it(og_const_it);
	ft::map<int, int>::const_iterator				copy_my_const_it(my_const_it);
	std::map<int, int>::reverse_iterator			copy_og_r_it(og_r_it);
	ft::map<int, int>::reverse_iterator			    copy_my_r_it(my_r_it);
	std::map<int, int>::const_reverse_iterator	    copy_og_r_it_const(og_r_it_const);
	ft::map<int, int>::const_reverse_iterator		copy_my_r_it_const(my_r_it_const);

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
}
