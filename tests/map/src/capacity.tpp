
void    map_capacity(void)
{
    ft::map<int, int>                           my_map;
    std::map<int, int>                          std_map;

    ft::map<std::string, std::string>           my_map_2;
    std::map<std::string, std::string>          std_map_2;

    test_name("Testing method .empty()");
    assert(my_map.empty() == std_map.empty());
    for (int i = 0; i < 8; i++) {
        my_map[i] = i + 1;
        std_map[i] = i + 1;
    }
    assert(my_map.empty() == std_map.empty());

    {
        test_name("Testing method .size()");
        assert(my_map.size() == std_map.size());
        my_map[8] = 9;
        std_map[8] = 9;
        assert(my_map.size() == std_map.size());
    }

    {
        test_name("Testing method .max_size()");
        assert(my_map.max_size() == std_map.max_size());
    }
}
