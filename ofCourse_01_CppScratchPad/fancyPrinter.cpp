#include "fancyPrinter.h"

void fancyPrinter::fancyPrint( std::string input){  
    std::cout << "\t[" << counter++ << "] " << input << std::endl;
}