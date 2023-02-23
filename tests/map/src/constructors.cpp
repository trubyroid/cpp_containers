
void    map_members_n_elements(void)
{
    test_name("Default constructors test");
    ft::map<int, int>                           my_map_1;
    std::map<int, int>                          std_map_1;

    ft::map<std::string, std::string>           my_map_2;
    std::map<std::string, std::string>          std_map_2;

    test_name("Operator [] test");
    for (int i = 0; i < 8; i++) {
        my_map_1[i] = i + 1;
        std_map_1[i] = i + 1;
    }

    my_map_2["Hello"] = "test";
    std_map_2["Hello"] = "test";
    my_map_2["How are you"] = "test";
    std_map_2["How are you"] = "test";
    my_map_2["Thanks"] = "I'm fine";
    std_map_2["Thanks"] = "I'm fine";

    {
        test_name("Testing method .at()");
        assert(my_map_1.at(3) == std_map_1.at(3));
        assert(my_map_1.at(6) == std_map_1.at(6));
        assert(my_map_2.at("Hello") == std_map_2.at("Hello"));
        assert(my_map_2.at("How are you") == std_map_2.at("How are you"));
        assert(my_map_2.at("Thanks") == std_map_2.at("Thanks"));

    }

    {
        test_name("Testing method .at() when out_of_range");
        try {
            std_map_1.at(15);
        }
        catch (std::exception & error) {
            std::cout << COLOUR_DEFAULT << "Original: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;
        }
        try {
            my_map_1.at(15);
        }
        catch (std::exception & error) {
			std::cout << "Mine:     " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;
		}
    }
    
    {
        test_name("Range constructor test (int)");
        ft::map<int,int>::iterator              my_it_beg = my_map_1.begin();
        ft::map<int,int>::iterator              my_it_end = my_map_1.end();
        std::map<int,int>::iterator             std_it_beg = std_map_1.begin();
        std::map<int,int>::iterator             std_it_end = std_map_1.end();

        ft::map<int, int>                       my_map_3(my_it_beg, my_it_end);
        std::map<int, int>                      std_map_3(std_it_beg, std_it_end);

        assert(my_map_3.size() == std_map_3.size());
        for (size_t i = 0; i < 4; i++) {
            assert(my_map_3[i] == std_map_3[i]);
        }

        test_name("Testing const method .at()");
        const ft::map<int, int>                           my_map_1_const(my_it_beg, my_it_end);
        const std::map<int, int>                          std_map_1_const(std_it_beg, std_it_end);

        assert(my_map_1_const.at(3) == std_map_1_const.at(3));

        test_name("Testing const method .at() when out_of_range");
        try {
            std_map_1_const.at(15);
        }
        catch (std::exception & error) {
            std::cout << COLOUR_DEFAULT << "Original: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;
        }
        try {
            my_map_1_const.at(15);
        }
        catch (std::exception & error) {
			std::cout << "Mine:     " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;
		}
    }

    {
	    test_name("Copy constructor test (int)");

        ft::map<int, int>                       my_map_4(my_map_1);
        std::map<int, int>                      std_map_4(std_map_1);

        assert(my_map_4.size() == my_map_1.size());
        assert(std_map_4.size() == std_map_1.size());
        assert(my_map_4.size() == std_map_4.size());
        assert(my_map_4[1] == std_map_4[1]);

    }

    {
	    test_name("Operator= test (int)");

        ft::map<int, int>                       my_map_5;
        std::map<int, int>                      std_map_5;

        my_map_5 = my_map_1;
        std_map_5 = std_map_1;

        assert(my_map_5.size() == my_map_5.size());
        assert(std_map_5.size() == std_map_5.size());
        assert(my_map_5.size() == std_map_5.size());
        assert(my_map_5[1] == std_map_5[1]);

    }


    {
        test_name("Range constructor test (string)");
        ft::map<std::string,std::string>::iterator              my_it_beg = my_map_2.begin();
        ft::map<std::string,std::string>::iterator              my_it_end = my_map_2.end();
        std::map<std::string,std::string>::iterator             std_it_beg = std_map_2.begin();
        std::map<std::string,std::string>::iterator             std_it_end = std_map_2.end();

        ft::map<std::string,std::string>                      my_map_3(my_it_beg, my_it_end);
        std::map<std::string,std::string>                     std_map_3(std_it_beg, std_it_end);

        assert(my_map_3.size() == std_map_3.size());

        assert(my_map_3["Hello"] == std_map_3["Hello"]);
        assert(my_map_3["How are you"] == std_map_3["How are you"]);
        assert(my_map_3["Thanks"] == std_map_3["Thanks"]);
    }

    {
	    test_name("Copy constructor test (string)");
        ft::map<std::string,std::string>                       my_map_4(my_map_2);
        std::map<std::string,std::string>                     std_map_4(std_map_2);

        assert(my_map_4.size() == std_map_4.size());
        assert(my_map_4["Hello"] == std_map_4["Hello"]);
    }

    {
	    test_name("Operator= test (string)");

        ft::map<std::string,std::string>                      my_map_5;
        std::map<std::string,std::string>                     std_map_5;

        my_map_5 = my_map_2;
        std_map_5 = std_map_2;

        assert(my_map_5.size() == my_map_5.size());
        assert(std_map_5.size() == std_map_5.size());
        assert(my_map_5.size() == std_map_5.size());
        assert(my_map_5["Hello"] == std_map_5["Hello"]);

    }

    {
        test_name("Get allocator test");
        assert(my_map_1.get_allocator() == std_map_1.get_allocator());
    }
}