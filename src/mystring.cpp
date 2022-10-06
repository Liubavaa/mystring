#include <iostream>
#include "mystring.hpp"

my_str_t::my_str_t(size_t size, char initial) {
    //made by Oleksiuk
    size_m = size;
    set_capacity();
    data_m = new char[capacity_m+1];
    for (int i = 0; i<size_m; ++i) {
        *(data_m + i) = initial;
    }
    *(data_m + size_m) = '\0';
};

my_str_t::my_str_t(const char* cstr ) {
    //made by Oleksiuk
    size_t size= get_cstr_size(cstr);
    size_m = size;
    set_capacity();
    data_m = new char[capacity_m+1];
    for (int i = 0; i<size_m; i++)
        *(data_m + i) = *(cstr + i);
    *(data_m + size_m) = '\0';
};

size_t my_str_t::get_cstr_size(const char* cstr){
    //made by Oleksiuk
    if (cstr == nullptr) {
        throw std::runtime_error("Data of object is nullptr");
    }
    size_t size= 0;
    while(*(cstr+size) != '\0')
        size++;
    return size;
};

my_str_t::my_str_t(const std :: string& str ):size_m {str.size()} {
    //made by Oleksiuk
    set_capacity();
    data_m = new char[capacity_m+1];

    for (int i = 0; i < size_m; i++)
        *(data_m + i) = str[i];
    *(data_m + size_m) = '\0';
}

void my_str_t::set_capacity(){
    //made by Oleksiuk
    capacity_m = size_m+1;
    while (capacity_m%16!=0) {
        capacity_m ++;
    }
    capacity_m --;
}

my_str_t::my_str_t(const my_str_t& mystr): size_m {mystr.size_m}, capacity_m {mystr.capacity_m}{
    //made by Oleksiuk
    data_m = new char [capacity_m+1];
    std::memcpy(data_m, mystr.data_m, size_m);
    *(data_m + size_m) = '\0';
}

my_str_t& my_str_t::operator=(const my_str_t& mystr){
    //made by Oleksiuk
    if (&mystr == this)
        return *this;

    my_str_t temp(mystr);
    this->swap(temp);
    return *this ;
}

void my_str_t::swap(my_str_t& other ) noexcept{
    //made by Oleksiuk
    char* temp_data = data_m;
    data_m = other.data_m;
    other.data_m = temp_data;

    size_t temp = capacity_m;
    capacity_m = other.capacity_m;
    other.capacity_m = temp;

    temp = size_m;
    size_m = other.size_m;
    other.size_m = temp;
}

char& my_str_t::operator[](size_t idx){
    //made by Oleksiuk
    if (idx >= size_m){
        throw std::out_of_range("Index is out of range");
    }
    return *(data_m+idx);
};

const char& my_str_t::operator[] ( size_t idx ) const {
    //made by Oleksiuk
    if (idx >= size_m){
        throw std::out_of_range("Index is out of range");
    }
    return const_cast <char&> (*(data_m+idx));
};

char& my_str_t::at(size_t idx){
    //made by Oleksiuk
    if (idx >= size_m){
        throw std::out_of_range("Index is out of range");
    }
    return *(data_m+idx);
};

const char& my_str_t::at( size_t idx ) const{
    //made by Oleksiuk
    if (idx >= size_m){
        throw std::out_of_range("Index is out of range");
    }
    return const_cast <char&> (*(data_m+idx));
};

void my_str_t::reserve(size_t new_capacity){
    //made by Oleksiuk
    if (new_capacity > capacity_m){
        char *new_data = new char[new_capacity+1];
        std::memcpy(new_data, data_m, size_m);
        delete [] data_m;
        data_m = new_data;
        capacity_m = new_capacity;
        *(data_m + size_m) = '\0';
    }
};

void my_str_t::shrink_to_fit(){
    //made by Oleksiuk
    set_capacity();
    char *new_data = new char[capacity_m+1];
    std::memcpy(new_data, data_m, size_m);
    delete [] data_m;
    data_m = new_data;
    *(data_m + size_m) = '\0';
};

void my_str_t::resize(size_t new_size, char new_char){
    //made by Oleksiuk
    if (new_size>size_m){
        if (new_size>capacity_m)
            this->reserve(new_size+1);
        for (int i = (int) size_m; i < new_size; ++i)
            *(data_m + i) = new_char;
    }
    size_m = new_size;
    *(data_m + size_m) = '\0';
};

void my_str_t::clear(){
    //made by Oleksiuk
    size_m = 0;
};

void my_str_t::insert(size_t idx, const my_str_t &str){
    //made by Oleksiuk
    if (idx >= size_m)
        throw std::out_of_range("Index is out of range");
    if ((size_m+str.size_m)>capacity_m)
        this->reserve(capacity_m+str.size_m);
    std::memmove(data_m+idx+str.size_m, data_m+idx, size_m-idx);
    std::memmove(data_m+idx, str.data_m, str.size_m);
    size_m+=str.size_m;
    *(data_m + size_m) = '\0';
};

void my_str_t::insert(size_t idx, char c){
    //made by Oleksiuk
    if (idx >= size_m)
        throw std::out_of_range("Index is out of range");
    if ((size_m+1)>capacity_m)
        this->reserve(capacity_m+1);
    std::memmove(data_m+idx+1, data_m+idx, size_m-idx);
    *(data_m+idx) = c;
    size_m+=1;
    *(data_m + size_m) = '\0';
};

void my_str_t::insert(size_t idx , const char* cstr ){
    //made by Oleksiuk
    if (idx >= size_m)
        throw std::out_of_range("Index is out of range");
    size_t size = get_cstr_size(cstr);
    if ((size_m+size)>capacity_m)
        this->reserve(capacity_m+size);
    std::memmove(data_m+idx+size, data_m+idx, size_m-idx);
    std::memmove(data_m+idx, cstr, size);
    size_m+=size;
    *(data_m + size_m) = '\0';
};

void my_str_t::append(const my_str_t& str ){
    //made by Oleksiuk
    if ((size_m+str.size_m)>capacity_m)
        this->reserve(capacity_m+str.size_m);
    std::memmove(data_m+size_m, str.data_m, str.size_m);
    size_m+=str.size_m;
    *(data_m + size_m) = '\0';
};

void my_str_t::append ( char c ){
    //made by Oleksiuk
    if ((size_m+1)>capacity_m)
        this->reserve(capacity_m+1);
    *(data_m+size_m) = c;
    size_m+=1;
    *(data_m + size_m) = '\0';
};

void my_str_t::append(const char* cstr ){
    //made by Oleksiuk
    size_t size = get_cstr_size(cstr);
    if ((size_m+size)>capacity_m)
        this->reserve(capacity_m+size);
    std::memmove(data_m+size_m, cstr, size);
    size_m+=size;
    *(data_m + size_m) = '\0';
};

void my_str_t::erase(size_t begin , size_t size ) {
    //made by Oleksiuk
    if (begin >= size_m) {
        throw std::out_of_range("Begin index is out of range");
    }
    else if ((size+begin) > size_m) {
        *(data_m + begin) = '\0';
        size_m = begin;
    }
    else {
        std::memmove(data_m + begin, data_m + begin + size, size_m - begin - size);
        for (size_t i = (size_m - size); i < size_m; ++i)
            *(data_m + i) = '\0';
        size_m -= size;
    }
    *(data_m + size_m) = '\0';
};

size_t my_str_t::size () const noexcept{
    //made by Oleksiuk
    return size_m;
};

size_t my_str_t::capacity () const noexcept{
    //made by Oleksiuk
    return capacity_m;
};

const char* my_str_t::c_str() const{
    //made by Oleksiuk
    *(data_m+size_m) = '\0';
    return data_m;
};

my_str_t& my_str_t::operator+=(const my_str_t& mystr){
    //made by Oleksiuk
    this->append(mystr);
    return *this;
};

my_str_t operator+(my_str_t mystr_l, my_str_t& mystr_r){
    //made by Oleksiuk
    return mystr_l+=mystr_r;
};

my_str_t& my_str_t::operator*=(size_t size){
    //made by Oleksiuk
    my_str_t str_copy(*this);
    for (size_t i = 1; i < size; ++i) {
        this->append(str_copy);
    }
    return *this;
};

my_str_t operator*(my_str_t mystr, size_t time) {
    //made by Oleksiuk
    return mystr*=time;
}

my_str_t::~my_str_t(){
    //made by Oleksiuk
    delete [] data_m;
}

std::ostream& operator<<(std::ostream& stream, const my_str_t& str) {
    stream << str.c_str();
    return stream;
}
