#include <iostream>
#include <sstream>
#include <random>
#include <thread>
#include <vector>
#include <chrono>


class PhilosopherClass {

public:

    static bool endKeyPressed;
    static std::default_random_engine generator;

    static void runPhilosopher(int philosopherNumber)
    {
        std::stringstream stream;

        stream << philosopherNumber << std::endl;

        std::cout << stream.str();
    }


};


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

    std::vector<std::thread> t(threadCount);
    for(int i = 0; i < threadCount; i++) {
        t[i] = std::thread(PhilosopherClass::runPhilosopher, i);
    }

    char c = 's';
    while(c != 'q')
    {
        std::cin >> c;
    }

    for(int i = 0; i < threadCount; i++) {
        t[i].join();
    }

    std::cout<< "Koniec Programu!"<< std::endl;

    return 0;
};