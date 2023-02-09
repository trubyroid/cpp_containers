#include "../../includes/vector/vector.hpp"
# include "colours.hpp"
# include <vector>
# include <iterator>
# include <iostream>
#include "../../includes/utils/utils.hpp"

void test_name(std::string name)
{
	std::cout << COLOUR_BLUE << name << COLOUR_RED << std::endl;
}

int main(void)
{
	ft::vector<int> my_v(3, 3);
	std::vector<int> og_v(3, 3);
	const ft::vector<int> my_v_const(3, 4);
	const std::vector<int> og_v_const(3, 4);

	{
		test_name("Testing operator[]");
		for (int i = 0; i < 3; i++)
		{
			my_v[i] = i + 1;
			og_v.at(i) = i + 1;
		}
		assert(1 == my_v[0]);
		assert(2 == my_v[1]);
		assert(3 == my_v[2]);

		test_name("Testing const operator[]");
		assert(4 == my_v_const[2]);
	}

	{
		test_name("Testing method .at()");
		assert(1 == my_v.at(0));

		test_name("Testing const method .at()");
		assert(4 == my_v_const.at(0));
	}

	{
		test_name("Testing method .at() when out_of_range");
		try{
			og_v.at(3);}
		catch(std::exception & error){
			std::cout << "OG:   " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
		try{
			my_v.at(3);}
		catch(std::exception & error){
			std::cout << "Mine: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	}

	{
		test_name("Testing const method .at() when out_of_range");
		try{
			og_v_const.at(4);}
		catch(std::exception & error){
			std::cout << "OG:   " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
		try{
			my_v_const.at(4);}
		catch(std::exception & error){
			std::cout << "Mine: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	}

	{
		test_name("Testing method .front()");
		assert(1 == my_v.front());

		test_name("Testing const method .front()");
		assert(4 == my_v_const.front());
	}

	{
		test_name("Testing method .back()");
		assert(3 == my_v.back());

		test_name("Testing const method .back()");
		assert(4 == my_v_const.back());
	}

	std::cout << COLOUR_DEFAULT;
	return (0);
}