#include "../library/mystring.hpp"
#include <iostream>
#include <sstream>

void constructor_dem(){
    std::cout<<"The object can be created based on c-str:"<<std::endl;
    my_str_t mystr_cs("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_cs << std::endl << std::endl;

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
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    my_str_t mystr_copy = mystr_cs;
    std::cout<<">>> my_str_t mystr_copy = mystr_cs"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<<  std::endl << mystr_cs << std::endl<<mystr_cs << std::endl << std::endl;

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

    std::cout<<">>> std::cout<< mystr_1.at(0) <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.at(0) <<std::endl << std::endl;

    my_str_t const mystr_2(std::string("World!"));
    std::cout<<">>> my_str_t const mystr_2(std::string(\"World!\"))"<<std::endl;
    std::cout<<">>> std::cout<< mystr_2[1] <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_2[1] <<std::endl<< std::endl;

    std::cout<<">>> std::cout<< mystr_2.at(5) <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_2.at(5) <<std::endl<< std::endl;
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
    std::cout<< "Output: "<< mystr_1 <<std::endl;

    std::cout<<">>> mystr_1.resize(3)"<<std::endl;
    mystr_1.resize(3);

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl;

    std::cout<<">>> mystr_1.resize(5, 'a')"<<std::endl;
    mystr_1.resize(5, 'a');

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl;

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
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.insert(8, 'C')"<<std::endl;
    mystr_1.insert(14, 'C');

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;
}

void append_dem(){
    std::cout<<"Append methods:"<<std::endl;
    my_str_t mystr_1("I love C++");
    std::cout<<">>> my_str_t mystr_cs(\"I love C++\")"<<std::endl;

    std::cout<<">>> mystr_1.append(\" and C\")"<<std::endl;
    mystr_1.append(" and C");

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.insert(14, std::string(\"Sharp and \"))"<<std::endl;
    mystr_1.append(std::string(" and Python"));

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.append('!')"<<std::endl;
    mystr_1.append('!');

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;
}

void erase_dem(){
    std::cout<<"Erase method:"<<std::endl;
    my_str_t mystr("Life is not beautiful");
    std::cout<<">>> my_str_t mystr(\"Life is not beautiful\")"<<std::endl;

    std::cout<<">>> mystr.erase(8, 3)"<<std::endl;
    mystr.erase(8, 4);

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
    std::cout << "str.find(\"e\", 3)" << std::endl;
    std::cout << "Output: " << str1.find("e", 3) << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Find string method with c++ string" << std::endl;
    std::cout << "my_str_t str(\"Hello world!\");" << std::endl;
    my_str_t str2("Hello world");
    std::cout << "str.find(\"world\")" << std::endl;
    std::cout << "Output: " << str2.find("world", 0) << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Find string method with c string" << std::endl;
    std::cout << "my_str_t str(\"Hello world!\");" << std::endl;
    my_str_t str3("Hello world");
    std::cout << "const char *cstr = \"abs\";" << std::endl;
    const char *cstr = "abs";
    std::cout << "str.find(\"world\")" << std::endl;
    std::cout << "Output: " << str3.find(cstr, 8) << std::endl;
}

void operators_demonstration_references() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello = \"hello\";" << std::endl;
    my_str_t hello = "hello";
    std::cout << "my_str_t not_hello = \"not_hello\";" << std::endl;
    my_str_t not_hello = "not_hello";

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

void operators_demonstration_first_c() {
    std::cout << "Operators demonstration" << std::endl;
    std::cout << "Using references" << std::endl;
    std::cout << "my_str_t hello(\"hello\");" << std::endl;
    my_str_t hello("hello");
    std::cout << "my_str_t not_hello = \"not_hello\";" << std::endl;
    my_str_t not_hello = "not_hello";

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
