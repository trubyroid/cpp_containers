
void    map_lookup(void)
{
    std::map<int,int>   std_map;
    ft::map<int,int>    my_map;

    for (int i = 0; i < 8; i++) {
        std_map[i] = i + 1;
        my_map[i] = i + 1;
    }

    const std::map<int,int>   const_std_map(std_map);
    const ft::map<int,int>    const_my_map(my_map);

    {
        test_name("Testing method .find()");
        assert(std_map.find(3)->second == my_map.find(3)->second);
        assert(std_map.find(7)->second == my_map.find(7)->second);

        test_name("Testing const method .find()");
        assert(const_std_map.find(3)->second == const_my_map.find(3)->second);
        assert(const_std_map.find(7)->second == const_my_map.find(7)->second);
    }

    {
        test_name("Testing method .count()");
        assert(std_map.count(2) == my_map.count(2));
        assert(std_map.count(22) == my_map.count(22));
    }

    {
        test_name("Testing method .lower_bound()");
        assert(std_map.lower_bound(5)->second == my_map.lower_bound(5)->second);
        assert(std_map.lower_bound(7)->second == my_map.lower_bound(7)->second);

        test_name("Testing const method .lower_bound()");
        assert(const_std_map.lower_bound(5)->second == const_my_map.lower_bound(5)->second);
        assert(const_std_map.lower_bound(7)->second == const_my_map.lower_bound(7)->second);
    }

    {
        test_name("Testing method .upper_bound()");
        assert(std_map.upper_bound(6)->second == my_map.upper_bound(6)->second);
        assert(std_map.upper_bound(3)->second == my_map.upper_bound(3)->second);

        test_name("Testing const method .upper_bound()");
        assert(const_std_map.upper_bound(6)->second == const_my_map.upper_bound(6)->second);
        assert(const_std_map.upper_bound(3)->second == const_my_map.upper_bound(3)->second);
    }

    {
        test_name("Testing method .equal_range()");
        std::pair<std::map<int,int>::iterator,std::map<int,int>::iterator>  std_p = std_map.equal_range(4);
        ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator>   my_p = my_map.equal_range(4);

        assert(std_p.first->first == my_p.first->first);
        assert(std_p.first->second == my_p.first->second);
        assert(std_p.second->first == my_p.second->first);
        assert(std_p.second->second == my_p.second->second);

        test_name("Testing const method .equal_range()");

        std::pair<std::map<int,int>::const_iterator,std::map<int,int>::const_iterator>  const_std_p = const_std_map.equal_range(4);
        ft::pair<ft::map<int,int>::const_iterator,ft::map<int,int>::const_iterator>     const_my_p = const_my_map.equal_range(4);

        assert(const_std_p.first->first == const_my_p.first->first);
        assert(const_std_p.first->second == const_my_p.first->second);
        assert(const_std_p.second->first == const_my_p.second->first);
        assert(const_std_p.second->second == const_my_p.second->second);
    }
}
