#include "mystring.hpp"
#include <iostream>

void constructor_dem(){
    std::cout<<"Об`єкт може створюватись на основі c-str:"<<std::endl;
    my_str_t mystr_cs("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_cs << std::endl << std::endl;

    std::cout<<"На основі c++ str:"<<std::endl;
    my_str_t mystr(std::string("World!"));
    std::cout<<">>> my_str_t mystr(std::string(\"World\"))"<<std::endl;
    std::cout<<">>> std::cout<< mystr <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr << std::endl << std::endl;

    std::cout<<"На основі об'єкту цього ж типу:"<<std::endl;
    const my_str_t& mystr_copy(mystr);
    std::cout<<">>> my_str_t mystr_copy(mystr)"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_copy << std::endl << std::endl;

    std::cout<<"На основі кількості літер:"<<std::endl;
    my_str_t mystr_char(5, 'c');
    std::cout<<">>> my_str_t mystr_char(5, 'c');"<<std::endl;
    std::cout<<">>> std::cout<< mystr_char <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_char << std::endl << std::endl;
}

void appropriation_swap_dem(){
    std::cout<<"Оператор присвоєння:"<<std::endl;
    my_str_t mystr_cs("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;
    my_str_t mystr_copy = mystr_cs;
    std::cout<<">>> my_str_t mystr_copy = mystr_cs"<<std::endl;
    std::cout<<">>> std::cout<< mystr_cs <<std::endl"<<std::endl;
    std::cout<<">>> std::cout<< mystr_copy <<std::endl"<<std::endl;
    std::cout<<"Output: "<<  std::endl << mystr_cs << std::endl<<mystr_cs << std::endl << std::endl;

    std::cout<<"Оператор обміну:"<<std::endl;
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
    std::cout<<"Оператори індексації:"<<std::endl;
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
    std::cout<<"Метод для збільшення розіміру блоку:"<<std::endl;
    my_str_t mystr_1("Hello");
    std::cout<<">>> my_str_t mystr_cs(\"Hello\")"<<std::endl;

    std::cout<<">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<< "Output: "<< mystr_1.capacity() <<std::endl;

    std::cout<<">>> mystr_1.reserve(50)"<<std::endl;
    mystr_1.reserve(50);

    std::cout<< ">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.capacity() <<std::endl <<std::endl;

    std::cout<<"Метод зменшення до мінімального:"<<std::endl;
    std::cout<<">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<< "Output: "<< mystr_1.capacity() <<std::endl;

    std::cout<<">>> mystr_1.shrink_to_fit()"<<std::endl;
    mystr_1.shrink_to_fit();

    std::cout<< ">>> std::cout<< mystr_1.capacity() <<std::endl"<<std::endl;
    std::cout<<"Output: "<< mystr_1.capacity() <<std::endl <<std::endl;

    std::cout<<"Метод зміни фактичного розміру:"<<std::endl;
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

    std::cout<<"Метод очищення:"<<std::endl;
    std::cout<<">>> mystr_1.clear()"<<std::endl;
    mystr_1.clear();

    std::cout<<">>> std::cout<< mystr_1.size()<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<< std::endl<< mystr_1.size()<< std::endl << mystr_1 <<std::endl;
}

void insert_dem(){
    std::cout<<"Методи вставки:"<<std::endl;
    my_str_t mystr_1("I love C++");
    std::cout<<">>> my_str_t mystr_cs(\"I love C++\")"<<std::endl;

    std::cout<<">>> mystr_1.insert(1, \" really\")"<<std::endl;
    mystr_1.insert(1, " really");

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.insert(14, std::string(\"Sharp and \"))"<<std::endl;
    mystr_1.insert(14, std::string("Sharp and "));

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;

    std::cout<<">>> mystr_1.insert(8, 'C')"<<std::endl;
    mystr_1.insert(14, 'C');

    std::cout<<">>> std::cout<< mystr_1 <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr_1 <<std::endl <<std::endl;
}

void append_dem(){
    std::cout<<"Методи апенду:"<<std::endl;
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
    std::cout<<"Методи для видалення літер:"<<std::endl;
    my_str_t mystr("Life is not beautiful");
    std::cout<<">>> my_str_t mystr(\"Life is not beautiful\")"<<std::endl;

    std::cout<<">>> mystr.erase(8, 3)"<<std::endl;
    mystr.erase(8, 4);

    std::cout<<">>> std::cout<< mystr <<std::endl"<<std::endl;
    std::cout<< "Output: "<<  mystr <<std::endl <<std::endl;
}

void add_product_dem(){
    std::cout<<"Додати дві стрічки:"<<std::endl;
    my_str_t mystr_1("Hello");
    std::cout<<">>> my_str_t mystr_1(\"Hello\")"<<std::endl;

    my_str_t mystr_2(std::string("World!"));
    std::cout<<">>> my_str_t mystr_2(std::string(\"World\"))"<<std::endl;

    std::cout<<">>> my_str_t my_str_sum = mystr_1 + mystr_2"<<std::endl;
    my_str_t my_str_sum = mystr_1 + mystr_2;

    std::cout<<">>> std::cout<< my_str_sum <<std::endl"<<std::endl;
    std::cout<<"Output: "<< my_str_sum << std::endl << std::endl;

    std::cout<<"Кілька копій стрічки:"<<std::endl;
    std::cout<<">>> my_str_t mystr(\"Hello\")"<<std::endl;
    std::cout<<">>> my_str_t my_str_prdct = mystr_1 * 5"<<std::endl;
    my_str_t my_str_prdct = mystr_1 * 5;

    std::cout<<">>> std::cout<< my_str_prdct <<std::endl"<<std::endl;
    std::cout<<"Output: "<< my_str_prdct << std::endl << std::endl;
}

int main(){
    std::cout<<"Конструктори класу:"<<std::endl;
    constructor_dem();
    std::cout<<"Методи класу:"<<std::endl<<std::endl;
    appropriation_swap_dem();
    by_index_dem();
    change_size_dem();
    insert_dem();
    append_dem();
    erase_dem();
    add_product_dem();
    return 0;
};
