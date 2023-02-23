
void    map_modifiers(void)
{
    ft::map<int,int>    my_map;
    std::map<int,int>   std_map;

    ft::map<int,int>    my_map_1;
    std::map<int,int>   std_map_1;

    for (int i = 0; i < 8; i++) {
        my_map[i] = i + 1;
        std_map[i] = i + 1;
    }

    {
        test_name("Testing method .clear()");
        my_map.clear();
        std_map.clear();
        assert(my_map.size() == std_map.size());
        for (int i = 0; i < 8; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }

    for (int i = 0; i < 8; i++) {
        my_map[i] = i + 1;
        std_map[i] = i + 1;
    }

    for (int i = 15; i > 9; i--) {
        my_map_1[i] = i;
        std_map_1[i] = i;
    }

    {
        test_name("Testing method .insert(one argument)");
        std::pair<int,int>          std_pair(8,9);
        ft::pair<int,int>           my_pair(8,9);

        std::pair<std::map<int,int>::iterator,bool> std_rv = std_map.insert(std_pair);
        ft::pair<ft::map<int,int>::iterator,bool> my_rv = my_map.insert(my_pair);

        assert(std_rv.first->first == my_rv.first->first);
        assert(std_rv.first->second == my_rv.first->second);
        assert(std_rv.second == my_rv.second);

        for(int i = 0; i < 9; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }

    {
        test_name("Testing method .insert(two arguments)");
        std::pair<int,int>          std_pair(9,3);
        ft::pair<int,int>           my_pair(9,3);

        std::map<int,int>::iterator          std_it = std_map.begin();
        ft::map<int,int>::iterator           my_it = my_map.begin();


        assert(std_map.insert(std_it, std_pair)->first == my_map.insert(my_it, my_pair)->first);

        for(int i = 0; i < 9; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }

    {
        test_name("Testing method .insert(range)");
       
        std::map<int,int>::iterator          std_it_beg = std_map_1.begin();
        ft::map<int,int>::iterator           my_it_beg = my_map_1.begin();

        std::map<int,int>::iterator          std_it_end = std_map_1.end();
        ft::map<int,int>::iterator           my_it_end = my_map_1.end();

        std_map.insert(std_it_beg, std_it_end);
        my_map.insert(my_it_beg, my_it_end);

        for(int i = 0; i < 16; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }

    {
        test_name("Testing method .erase(iterator)");

        std_map.erase(std_map.begin());
        my_map.erase(my_map.begin());
        assert(std_map[0] == my_map[0]);
    }

    {
        test_name("Testing method .erase(key_type)");

        assert(std_map.erase(4) == my_map.erase(4));
        assert(std_map[4] == my_map[4]);
    }

    {
        test_name("Testing method .erase(range)");
        
        std::map<int,int>::iterator          std_it_beg = std_map.begin();
        ft::map<int,int>::iterator           my_it_beg = my_map.begin();

        std::map<int,int>::iterator          std_it_end = std_map.end();
        ft::map<int,int>::iterator           my_it_end = my_map.end();
        
        std_map.erase(std_it_beg, std_it_end);
        my_map.erase(my_it_beg, my_it_end);

        for(int i = 0; i < 16; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }

    {
        test_name("Testing method .swap()");
        std_map.swap(std_map_1);
        my_map.swap(my_map_1);
        for(int i = 0; i < 16; i++) {
            assert(my_map[i] == std_map[i]);
        }
    }
}
