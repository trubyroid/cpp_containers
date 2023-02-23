
void    map_observers(void)
{
    std::map<int,int>   std_map;
    ft::map<int,int>    my_map;

    for (int i = 0; i < 8; i++) {
        std_map[i] = i + 1;
        my_map[i] = i + 1;
    }

    {
        test_name("Testing method .key_comp()");
        auto std_k_comp = std_map.key_comp();
        auto my_k_comp = my_map.key_comp();

        assert(std_k_comp(5,4) == my_k_comp(5,4));
        assert(std_k_comp(4,5) == my_k_comp(4,5));

    }

    {
        test_name("Testing method .value_comp()");
        auto std_v_comp = std_map.value_comp();
        auto my_v_comp = my_map.value_comp();

        std::pair<int,int>  std_p_1(5,6);
        std::pair<int,int>  std_p_2(7,8);
        ft::pair<int,int>  my_p_1(5,6);
        ft::pair<int,int>  my_p_2(7,8);

        assert(std_v_comp(std_p_1, std_p_2) == my_v_comp(my_p_1, my_p_2));
    }
}