
void vector_elements(void)
{
	std::vector<int> 		og_v(3, 3);
	ft::vector<int> 		my_v(3, 3);
	const std::vector<int> 	og_v_const(3, 4);
	const ft::vector<int> 	my_v_const(3, 4);

	{
		test_name("Testing method .at()");
		assert(og_v.at(0) == my_v.at(0));

		test_name("Testing const method .at()");
		assert(og_v_const.at(0) == my_v_const.at(0));
	}

	{
		test_name("Testing method .at() when out_of_range");
		try{
			og_v.at(3);}
		catch(std::exception & error){
			std::cout << COLOUR_DEFAULT << "Original: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
		try{
			my_v.at(3);}
		catch(std::exception & error){
			std::cout << "Mine:     " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	}

	{
		test_name("Testing const method .at() when out_of_range");
		try{
			og_v_const.at(4);}
		catch(std::exception & error){
			std::cout << COLOUR_DEFAULT << "Original: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
		try{
			my_v_const.at(4);}
		catch(std::exception & error){
			std::cout << "Mine:     " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	}

	{
		test_name("Testing method .front()");
		assert(og_v.front() == my_v.front());

		test_name("Testing const method .front()");
		assert(og_v_const.front() == my_v_const.front());
	}

	{
		test_name("Testing method .back()");
		assert(og_v.back() == my_v.back());

		test_name("Testing const method .back()");
		assert(og_v_const.back() == my_v_const.back());
	}

}