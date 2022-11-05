#include "../library/mystring.hpp"
#include <iostream>
#include <sstream>

void constructor_dem(){
    std::cout<<"The object can be created based on c-str:"<<std::endl;
    const char *str = "Hello";
    my_str_t mystr_cs(str);
    std::cout<<">>> const char *str = \"Hello\";)"<<std::endl;
    std::cout<<">>> my_str_t mystr_cs(str)"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_cs << std::endl << std::endl;

    str = nullptr;
    std::cout<<">>> str = nullptr;"<<std::endl;
    std::cout<<">>> my_str_t mystr_cs_null(str)"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    try {
        my_str_t mystr_cs_null(str);
    }
    catch (const std::runtime_error &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<"Based on c++ str:"<<std::endl;
    my_str_t mystr(std::string("World!"));
    std::cout<<">>> my_str_t mystr(std::string(\"World\"))"<<std::endl;
    std::cout<<">>> std::cout<< mystr <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr << std::endl << std::endl;

    std::cout<<"Based on my_str_t object:"<<std::endl;
    const my_str_t& mystr_copy(mystr);
    std::cout<<">>> my_str_t mystr_copy(mystr)"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_copy << std::endl << std::endl;

    std::cout<<"Based on number of some letter:"<<std::endl;
    my_str_t mystr_char(5, 'c');
    std::cout<<">>> my_str_t mystr_char(5, 'c');"<<std::endl;
    std::cout<<">>> std::cout<< mystr_char <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_char << std::endl << std::endl;
}

void appropriation_swap_dem(){
    std::cout<<"The assignment operator:"<<std::endl;
    my_str_t mystr_cs("Hello");
    my_str_t mystr_copy("");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    std::cout<<">>> my_str_t mystr_copy(\"\")"<<std::endl;
    mystr_copy = mystr_cs;
    std::cout<<">>> mystr_copy = mystr_cs"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<<  std::endl << mystr_cs << std::endl<< mystr_copy << std::endl << std::endl;

    std::cout<<"Assignment itself:"<<std::endl;
    mystr_copy = mystr_copy;
    std::cout<<">>> mystr_copy = mystr_copy"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<<  std::endl << mystr_copy << std::endl << std::endl;

    std::cout<<"The swap operator:"<<std::endl;
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    my_str_t mystr_2(7, 'f');
    std::cout<<">>> my_str_t mystr_2(7, 'f')"<<std::endl;
    mystr_cs.swap(mystr_2);
    std::cout<<">>> mystr_cs.swap(mystr_2)"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<">>> std::cout<< mystr_2 <<std::endl"<<std::endl;
    std::cout<<"Output: "<<  std::endl << mystr_cs << std::endl<< mystr_2 << std::endl << std::endl;
}

void by_index_dem(){
    std::cout<<"Index operators:"<<std::endl;
    my_str_t mystr_1("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    std::cout<<">>> std::cout<< mystr_1[3] <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1[3] <<std::endl << std::endl;

    std::cout<<">>> std::cout<< mystr_1[8] <<std::endl"<<std::endl;
    try {
        mystr_1[8];
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<">>> std::cout<< mystr_1.at(0) <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.at(0) <<std::endl << std::endl;

    std::cout<<">>> std::cout<< mystr_1.at(7) <<std::endl"<<std::endl;
    try {
        mystr_1.at(7);
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    my_str_t const mystr_2(std::string("World!"));
    std::cout<<">>> my_str_t const mystr_2(std::string(\"World!\"))"<<std::endl;
    std::cout<<">>> std::cout<< mystr_2[1] <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_2[1] <<std::endl<< std::endl;

    std::cout<<">>> std::cout<< mystr_2[10] <<std::endl"<<std::endl;
    try {
        mystr_2[10];
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<">>> std::cout<< mystr_2.at(5) <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_2.at(5) <<std::endl<< std::endl;

    std::cout<<">>> std::cout<< mystr_2.at(20) <<std::endl"<<std::endl;
    try {
        mystr_2.at(20);
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }
}

void change_size_dem(){
    std::cout<<"Method for reserving bigger memory block:"<<std::endl;
    my_str_t mystr_1("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;

    std::cout<<">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<< "Output: "<< mystr_1.capacity() <<std::endl;

    std::cout<<">>> mystr_1.reserve(50)"<<std::endl;
    mystr_1.reserve(50);

    std::cout<< ">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.capacity() <<std::endl <<std::endl;

    std::cout<<"Method for decreasing memory block to minimal:"<<std::endl;
    std::cout<<">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<< "Output: "<< mystr_1.capacity() <<std::endl;

    std::cout<<">>> mystr_1.shrink_to_fit()"<<std::endl;
    mystr_1.shrink_to_fit();

    std::cout<< ">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.capacity() <<std::endl <<std::endl;

    std::cout<<"Method for changing real string size:"<<std::endl;
    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.resize(3)"<<std::endl;
    mystr_1.resize(3);

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.resize(5, 'a')"<<std::endl;
    mystr_1.resize(5, 'a');

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.resize(30, 'a')"<<std::endl;
    mystr_1.resize(30, 'a');

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl <<std::endl;

    std::cout<<"Clear method:"<<std::endl;
    std::cout<<">>> mystr_1.clear()"<<std::endl;
    mystr_1.clear();

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl;
}

void insert_dem(){
    std::cout<<"Insert methods:"<<std::endl;
    my_str_t mystr_1("I love C++");
    std::cout<<">>> my_str_t mystr_cs(\"I love C++\")"<<std::endl;

    std::cout<<">>> mystr_1.insert(1, \" really\")"<<std::endl;
    mystr_1.insert(1, " really");

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    my_str_t mystr_2("Sharp and ");
    std::cout<<">>> my_str_t mystr_cs(\"Sharp and \")"<<std::endl;

    std::cout<<">>> mystr_1.insert(14, mystr_2)"<<std::endl;
    mystr_1.insert(14, mystr_2);

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 << std::endl <<std::endl;

    std::cout<<">>> mystr_1.insert(8, 'C')"<<std::endl;
    mystr_1.insert(14, 'C');

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 << std::endl <<std::endl;

    my_str_t mystr_3(15, 'a');
    mystr_3.insert(1, 'a');
    std::cout<<">>> my_str_t mystr_3(15, 'a')"<<std::endl;
    std::cout<<">>> mystr_3.insert(1, 'a')"<<std::endl<<std::endl;

    std::cout<<">>> mystr_1.insert(50, \"aba\")"<<std::endl;
    try {
        mystr_1.insert(50, "aba");
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<">>> mystr_1.insert(50, \'a\')"<<std::endl;
    try {
        mystr_1.insert(50, 'a');
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<">>> mystr_1.insert(50, mystr_2)"<<std::endl;
    try {
        mystr_1.insert(50, mystr_2);
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }
}

void append_dem(){
    std::cout<<"Append methods:"<<std::endl;
    my_str_t mystr_1("I love C++");
    std::cout<<">>> my_str_t mystr_cs(\"I love C++\")"<<std::endl;

    std::cout<<">>> mystr_1.append(\" and C\")"<<std::endl;
    mystr_1.append(" and C");

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.append(std::string(\" and Python\"))"<<std::endl;
    mystr_1.append(std::string(" and Python"));

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.append('!')"<<std::endl;
    mystr_1.append('!');

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    my_str_t mystr_3(15, 'a');
    mystr_3.append('a');
    std::cout<<">>> my_str_t mystr_3(15, 'a')"<<std::endl;
    std::cout<<">>> mystr_3.append('a')"<<std::endl<<std::endl;
}

void erase_dem(){
    std::cout<<"Erase method:"<<std::endl;
    my_str_t mystr("Life is not beautiful");
    std::cout<<">>> my_str_t mystr(\"Life is not beautiful\")"<<std::endl;

    std::cout<<">>> mystr.erase(8, 3)"<<std::endl;
    mystr.erase(8, 4);

    std::cout<<">>> std::cout<< mystr <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr <<std::endl <<std::endl;

    std::cout<<">>> mystr.erase(20, 3)"<<std::endl;
    try {
        mystr.erase(20, 4);
    }
    catch (const std::out_of_range &a) {
        std::cout <<"Output: "<< a.what() << std::endl << std::endl;
    }

    std::cout<<">>> mystr.erase(10, 20)"<<std::endl;
    mystr.erase(10, 20);

    std::cout<<">>> std::cout<< mystr <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr <<std::endl <<std::endl;
}

void add_product_dem(){
    std::cout<<"Sum of to string:"<<std::endl;
    my_str_t mystr_1("Hello");
    std::cout<<">>> my_str_t mystr_1(\"Hello\")"<<std::endl;

    my_str_t mystr_2(std::string("World!"));
    std::cout<<">>> my_str_t mystr_2(std::string(\"World\"))"<<std::endl;

    std::cout<<">>> my_str_t my_str_sum = mystr_1 + mystr_2"<<std::endl;
    my_str_t my_str_sum = mystr_1 + mystr_2;

    std::cout<<">>> std::cout<< my_str_sum <<std::endl"<<std::endl;
    std::cout<<"Output: "<< my_str_sum << std::endl << std::endl;

    std::cout<<"Multiplying string:"<<std::endl;
    std::cout<<">>> my_str_t mystr(\"Hello\")"<<std::endl;
    std::cout<<">>> my_str_t my_str_prdct = mystr_1 * 5"<<std::endl;
    my_str_t my_str_prdct = mystr_1 * 5;

    std::cout<<">>> std::cout<< my_str_prdct <<std::endl"<<std::endl;
    std::cout<<"Output: "<< my_str_prdct << std::endl << std::endl;
}

void cstr_test() {
    std::cout << "my_str_t mystr(\"Hello world!\");" << std::endl;
    my_str_t mystr("Hello world!");
    std::cout << "std::cout << mystr.c_str();" << std::endl;
    std::cout << mystr.c_str() << std::endl;
}

void find_str_demonstration() {
    std::cout << "Find string method with char" << std::endl;
    std::cout << "my_str_t str(\"Hello\");" << std::endl;
    my_str_t str1("Hello");
    std::cout << "str.find(\"e\")" << std::endl;
    std::cout << "Output: " << str1.find("e") << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Find string method with c++ string" << std::endl;
    std::cout << "my_str_t str(\"Hello world!\");" << std::endl;
    my_str_t str2("Hello world");
    std::cout << "str.find(\"world\")" << std::endl;
    std::cout << "Output: " << str2.find("world") << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Find string method with c string" << std::endl;
    std::cout << "my_str_t str(\"Hello world!\");" << std::endl;
    my_str_t str3("Hello world");
    std::cout << "const char *cstr = \"abs\";" << std::endl;
    const char *cstr = "abs";
    std::cout << "str.find(\"world\")" << std::endl;
    std::cout << "Output: " << str3.find(cstr) << std::endl;
}

void operators_demonstration_references() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello = \"hello\";" << std::endl;
    my_str_t hello = "hello";
    std::cout << "my_str_t not_hello = \"not_hello\";" << std::endl;
    my_str_t not_hello = "not_hello";
    my_str_t word = "hellz";
    my_str_t word2 = "heads";

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == not_hello" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res1 = hello == not_hello;
    std::cout << "Outcome: " << equal_res1 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == hello" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res2 = hello == hello;
    std::cout << "Outcome: " << equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == word" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res3 = hello == word;
    std::cout << "Outcome: " << equal_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = hello != not_hello" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res = hello != not_hello;
    std::cout << "Outcome: " << not_equal_res << std::endl;

    std::cout << "bool not_equal_res = hello != hello" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res2 = hello != hello;
    std::cout << "Outcome: " << not_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > not_hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res = hello > not_hello;
    std::cout << "Outcome: " << more_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > not_hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res2 = not_hello > hello;
    std::cout << "Outcome: " << more_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > heads" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res3 = hello > word;
    std::cout << "Outcome: " << more_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > hellz" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res4 = hello > word2;
    std::cout << "Outcome: " << more_res4 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_equal_res = hello >= not_hello" << std::endl;
    std::cout << "std::cout << more_equal_res" << std::endl;
    bool more_equal_res = hello >= not_hello;
    std::cout << "Outcome: " << more_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_equal_res = not_hello >= hello" << std::endl;
    std::cout << "std::cout << more_equal_res" << std::endl;
    bool more_equal_res2 = not_hello >= hello;
    std::cout << "Outcome: " << more_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello < not_hello" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_res = hello < not_hello;
    std::cout << "Outcome: " << less_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = not_hello < hello" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_res2 = not_hello < hello;
    std::cout << "Outcome: " << less_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = hello <= not_hello" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_equal_res = hello <= not_hello;
    std::cout << "Outcome: " << less_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = not_hello <= hello" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_equal_res2 = not_hello <= hello;
    std::cout << "Outcome: " << less_equal_res2 << std::endl;
}

void operators_demonstration_first_c() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello(\"hello\");" << std::endl;
    my_str_t hello("hello");
    std::cout << "my_str_t not_hello = \"not_hello\";" << std::endl;
    my_str_t not_hello = "not_hello";
    my_str_t word = "heads";
    my_str_t word2 = "hellz";

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == hello_cstring" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res = hello == hello.c_str();
    std::cout << "Outcome: " << equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == not_hello_cstring" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res2 = hello == not_hello.c_str();
    std::cout << "Outcome: " << equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == word_cstring" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res3 = hello == word.c_str();
    std::cout << "Outcome: " << equal_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = hello != hello_cstring" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res = hello != hello.c_str();
    std::cout << "Outcome: " << not_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = hello != not_hello_cstring" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res2 = hello != not_hello.c_str();
    std::cout << "Outcome: " << not_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > not_hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res = hello > not_hello.c_str();
    std::cout << "Outcome: " << more_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = not_hello > hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res5 = not_hello > hello.c_str();
    std::cout << "Outcome: " << more_res5 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res6 = hello > hello.c_str();
    std::cout << "Outcome: " << more_res6 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > word_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res7 = hello > word.c_str();
    std::cout << "Outcome: " << more_res7 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > word2_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res8 = hello > word2.c_str();
    std::cout << "Outcome: " << more_res8 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello >= hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res1 = hello >= hello.c_str();
    std::cout << "Outcome: " << more_equal_res1 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello >= word_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res2 = hello >= word.c_str();
    std::cout << "Outcome: " << more_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello >= word2_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res3 = hello >= word2.c_str();
    std::cout << "Outcome: " << more_equal_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello >= not_hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res4 = hello >= not_hello.c_str();
    std::cout << "Outcome: " << more_equal_res4 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = not_hello >= hello_cstring" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res5 = not_hello >= hello.c_str();
    std::cout << "Outcome: " << more_equal_res5 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello < not_hello.cstring" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_res = hello < not_hello.c_str();
    std::cout << "Outcome: " << less_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = not_hello <= hello_cstring" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_equal_res = not_hello <= hello.c_str();
    std::cout << "Outcome: " << less_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello <= not_hello.cstring" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_equal_res2 = hello <= not_hello.c_str();
    std::cout << "Outcome: " << less_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = not_hello < hello_cstring" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_res2 = not_hello < hello.c_str();
    std::cout << "Outcome: " << less_res2 << std::endl;
}

void operators_demonstration_second_c() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello = \"hello\";" << std::endl;
    my_str_t hello = "hello";
    std::cout << "my_str_t not_hello(\"not_hello\");" << std::endl;
    my_str_t not_hello("not_hello");
    my_str_t word = "hellz";
    my_str_t word2 = "heads";
    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello_cstring == hello" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res = hello.c_str() == hello;
    std::cout << "Outcome: " << equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = not_hello_cstring == hello" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res2 = not_hello.c_str() == hello;
    std::cout << "Outcome: " << equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = word_cstring == hello " << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res3 = word.c_str() == hello ;
    std::cout << "Outcome: " << equal_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = hello_cstring != hello" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res = hello.c_str() != hello;
    std::cout << "Outcome: " << not_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = not_hello_cstring != hello" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res2 = not_hello.c_str() != hello;
    std::cout << "Outcome: " << not_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello_cstring > not_hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res = hello.c_str() > not_hello;
    std::cout << "Outcome: " << more_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = not_hello_cstring > hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res2 = not_hello.c_str() > hello;
    std::cout << "Outcome: " << more_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello_cstring > hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res3 = hello.c_str() > hello;
    std::cout << "Outcome: " << more_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() > word" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res4 = hello.c_str() > word;
    std::cout << "Outcome: " << more_res4 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() > word2" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res5 = hello.c_str() > word2;
    std::cout << "Outcome: " << more_res5 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() >= hello;" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res1 = hello.c_str() >= hello;
    std::cout << "Outcome: " << more_equal_res1 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() >= word;" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res2 = hello.c_str() >= word;
    std::cout << "Outcome: " << more_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() >= word2" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res3 = hello.c_str() >= word2;
    std::cout << "Outcome: " << more_equal_res3 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello.c_str() >= not_hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res4 = hello.c_str() >= not_hello;
    std::cout << "Outcome: " << more_equal_res4 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = not_hello.c_str() >= hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_equal_res5 = not_hello.c_str() >= hello;
    std::cout << "Outcome: " << more_equal_res5 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello.c_str() < not_hello" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_res = hello.c_str() < not_hello;
    std::cout << "Outcome: " << less_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = not_hello.c_str() < hello" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_res2 = not_hello.c_str() < hello;
    std::cout << "Outcome: " << less_res2 << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = not_hello.c_str() <= hello" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_equal_res = not_hello.c_str() <= hello;
    std::cout << "Outcome: " << less_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello.c_str() <= not_hello" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_equal_res2 = hello.c_str() <= not_hello;
    std::cout << "Outcome: " << less_equal_res2 << std::endl;

    std::cout << "\n" << std::endl;


}

void operators_demonstration_second_c() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello = \"hello\";" << std::endl;
    my_str_t hello = "hello";
    std::cout << "my_str_t not_hello(\"not_hello\");" << std::endl;
    my_str_t not_hello("not_hello");

    std::cout << "\n" << std::endl;

    std::cout << "bool equal_res = hello == not_hello" << std::endl;
    std::cout << "std::cout << equal_res" << std::endl;
    bool equal_res = hello == not_hello;
    std::cout << "Outcome: " << equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool not_equal_res = hello != not_hello" << std::endl;
    std::cout << "std::cout << not_equal_res" << std::endl;
    bool not_equal_res = hello != not_hello;
    std::cout << "Outcome: " << not_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_res = hello > not_hello" << std::endl;
    std::cout << "std::cout << more_res" << std::endl;
    bool more_res = hello > not_hello;
    std::cout << "Outcome: " << more_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool more_equal_res = hello >= not_hello" << std::endl;
    std::cout << "std::cout << more_equal_res" << std::endl;
    bool more_equal_res = hello >= not_hello;
    std::cout << "Outcome: " << more_equal_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_res = hello < not_hello" << std::endl;
    std::cout << "std::cout << less_res" << std::endl;
    bool less_res = hello < not_hello;
    std::cout << "Outcome: " << less_res << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "bool less_equal_res = hello <= not_hello" << std::endl;
    std::cout << "std::cout << less_equal_res" << std::endl;
    bool less_equal_res = hello <= not_hello;
    std::cout << "Outcome: " << less_equal_res << std::endl;
}

void stream_operators_test() {
    std::cout << "my_str_t word = \"abc\";" << std::endl;
    my_str_t word1 = "abc";
    std::cout << "std::cout << word;" << std::endl;
    std::cout << word1;

    std::cout << "\n" << std::endl;

    std::cout << "my_std_t word2 = \"\" " << std::endl;
    my_str_t word2 = "";
    std::cout << "std::stringstream stream3 {\"abcd asf\"};" << std::endl;
    std::stringstream stream2 {"abcd asf"};
    std::cout << "stream3 >> word2;" << std::endl;
    stream2 >> word2;
    std::cout << "std::cout << word2;" << std::endl;
    std::cout << word2;

    std::cout << "\n" << std::endl;

    std::cout << "my_std_t word2 = \"\" " << std::endl;
    my_str_t word3 = "";
    std::cout << "std::stringstream stream3 {\"abcd \n asf\"};" << std::endl;
    std::stringstream stream3 {"abcd \n asf"};
    std::cout << "stream3 >> word2;" << std::endl;
    readline(stream3, word3);
    std::cout << "std::cout << word2;" << std::endl;
    std::cout << word3;
}

int main(){
    std::cout<<"Class constructors:"<<std::endl;
    constructor_dem();
    std::cout<<"Class methods:"<<std::endl<<std::endl;
    appropriation_swap_dem();
    by_index_dem();
    change_size_dem();
    insert_dem();
    append_dem();
    erase_dem();
    add_product_dem();
    cstr_test();
    find_str_demonstration();
    operators_demonstration_references();
    operators_demonstration_first_c();
    operators_demonstration_second_c();
    stream_operators_test();
    return 0;
}
