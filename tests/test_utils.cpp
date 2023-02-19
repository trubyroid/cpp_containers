void test_name(std::string name)
{
	std::cout << COLOUR_BLUE << name << COLOUR_RED << std::endl;
}

void check_values(ft::vector<int> &mine, std::vector<int> &original)
{	
    assert(original.capacity() == mine.capacity());
    assert(original.size() == mine.size());
	
	for (size_t i = 0; i < original.size(); i++)
        assert(original[i] == mine[i]);
}