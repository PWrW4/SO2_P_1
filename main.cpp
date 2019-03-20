#include <iostream>
#include <stdlib.h>

int main(int argc, char **argv) {
    
    int threadCount;

    if (argc != 2) {

        std::cout << "Brak argumentu z liczba watkow" << std::endl;
        return 1;
    }
    else {

        std::string str = argv[1];
        threadCount = std::stoi(str);
    }

    if(threadCount<1 || threadCount > 20){
        std::cout << "Liczba watkow miedzy 1 a 20" << std::endl;
        return 2;
    }

    char c = 's';
    while(c != 'q')
    {
        std::cin >> c;
    }

    std::cout<< "Koniec Programu!"<< std::endl;

    return 0;
}