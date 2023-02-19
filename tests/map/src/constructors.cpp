#include <string>

void map_constructors(void)
{
    test_name("Default constructors test");
    ft::map<int, int>                           my_map_1;
    ft::map<std::string, std::string>           my_map_2;

    std::map<int, int>                          std_map_1;
    std::map<std::string, std::string>          std_map_2;

    my_map_1[1] = 532;
    std_map_1[1] = 532;
    my_map_1[2] = 533;
    std_map_1[2] = 533;
    my_map_1[3] = 534;
    std_map_1[3] = 534;

    {
        test_name("Range constructor test (int)");
        ft::map<int,int>::iterator              my_it_beg = my_map_1.begin();
        ft::map<int,int>::iterator              my_it_end = my_map_1.end();
        std::map<int,int>::iterator             std_it_beg = std_map_1.begin();
        std::map<int,int>::iterator             std_it_end = std_map_1.end();

        ft::map<int, int>                       my_map_3(my_it_beg, my_it_end);
        std::map<int, int>                      std_map_3(std_it_beg, std_it_end);

        assert(my_map_3.size() == std_map_3.size());
        for (size_t i = 0; i < 4; i++)
            assert(my_map_3[i] == std_map_3[i]);
    }

    {
	    test_name("Copy constructor test (int)");

        ft::map<int, int>                       my_map_4(my_map_1);
        std::map<int, int>                      std_map_4(std_map_1);

        assert(my_map_4.size() == std_map_4.size());
        assert(my_map_4[1] == std_map_4[1]);
    }

    my_map_2["Hello"] = "test";
    // std_map_2["Hello"] = "test";
    // my_map_2["How are you"] = "test";
    // std_map_2["How are you"] = "test";
    // my_map_2["Thanks"] = "I'm fine";
    // std_map_2["Thanks"] = "I'm fine";

    // {
    //     test_name("Range constructor test (string)");
    //     ft::map<std::string,std::string>::iterator              my_it_beg = my_map_2.begin();
    //     ft::map<std::string,std::string>::iterator              my_it_end = my_map_2.end();
    //     std::map<std::string,std::string>::iterator             std_it_beg = std_map_2.begin();
    //     std::map<std::string,std::string>::iterator             std_it_end = std_map_2.end();

    //     ft::map<int, int>                       my_map_3(my_it_beg, my_it_end);
    //     std::map<int, int>                      std_map_3(std_it_beg, std_it_end);

    //     assert(my_map_3.size() == std_map_3.size());

    //     assert(my_map_3["Hello"] == std_map_3["Hello"])
    //     assert(my_map_3["How are you"] == std_map_3["How are you"])
    //     assert(my_map_3["Thanks"] == std_map_3["Thanks"])
    // }

    // {
	//     test_name("Copy constructor test (string)");

    //     ft::map<int, int>                       my_map_4(my_map_2);
    //     std::map<int, int>                      std_map_4(std_map_2);

    //     assert(my_map_4.size() == std_map_4.size());
    //     assert(my_map_4["Hello"] == std_map_4["Hello"]);
    // }
}