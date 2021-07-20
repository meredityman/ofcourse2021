#include <vector>
#include <deque>
#include <iostream>
#include <sstream>

#include "fancyPrinter.h"

float multiplyByTen(float x){
    return x * 10;
}

int main(){
    std::cout << "Hello World" << std::endl;

    int a = 4;
    // std::cout << "A " << a << std::endl;
    // int a(4);
    // int a{4};

    fancyPrinter printer0;
    fancyPrinter printer1;

    // Link for the full list of opperators.
    // https://en.cppreference.com/w/cpp/language/operator_arithmetic

    // float b = 1.5;
    // std::cout << "B " << b << std::endl;

    // float c = a * b;
    // std::cout << "A * B " <<  c << std::endl;

    // c = a / b;
    // std::cout << "A/B " <<  c << std::endl;

    // c = a + b;
    // std::cout << "A + B " <<  c << std::endl;
    
    // c = a - b;
    // std::cout << "A - B " <<  c << std::endl;

    // c = 9 % a;
    // std::cout << "A % B " <<  c << std::endl;

    std::string c = "'Hello World'";
    std::cout << c << std::endl;

    // bool f = true;
    // std::cout << f << std::endl;

    // fancyPrint("Fancy string");
     
    // std::cout << multiplyByTen(a) << std::endl;

    // std::deque<int> list;

    // for( int i = 0; i < 10; i++){
    //     list.push_front(i*2);
    // }


    // for( int i = 0; i < 10; i++){
    //     std::cout << "Index: " << i << " Value: " << list[i] << std::endl;
    // }

    // std::cout << "\n" << std::endl;

    // for( auto & item : list){
    //     std::cout << " Value: " << item << std::endl;
    // }



    std::vector<std::string> lines {
        "Some text",
        "Some more text",
        "A bit more text"
    };

    std::ostringstream str;
    str << "Size of array is " << lines.size() << std::endl;
    printer0.fancyPrint(str.str());

    for( int i = 0; i < lines.size(); i++){

        str = std::ostringstream();

        str << "Index: " << i << " Value: " << lines[i] << std::endl;
        printer1.fancyPrint(str.str());
    }

    return 0;
}