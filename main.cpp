#include <iostream>
#include <sstream>
#include <random>
#include <thread>
#include <vector>
#include <chrono>


class PhilosopherClass 
{
public:

    static bool end;
    static std::default_random_engine generator;

    static void runPhilosopher(int philosopherNumber)
    {
        std::uniform_int_distribution<int> distribution(2,5);

        while(!end)
        {

            std::stringstream stream;
            long timeForAction = distribution(generator);

            stream << "Filozof " << philosopherNumber << " mysli " << timeForAction << " s." << std::endl;
            std::cout << stream.str();
            stream.str("");
            std::this_thread::sleep_for(std::chrono::seconds(timeForAction));

            stream << "Filozof " <<  philosopherNumber << " bierze widelce." << std::endl;
            std::cout << stream.str();
            stream.str("");

            timeForAction = distribution(generator);
            stream << "Filozof " << philosopherNumber << " je " << timeForAction << " sekund." << std::endl;
            std::cout << stream.str();
            stream.str("");
            std::this_thread::sleep_for(std::chrono::seconds(timeForAction));

            stream << "Filozof " << philosopherNumber << " odklada widelce." << std::endl;
            std::cout << stream.str();
            stream.str("");
        }

        std::stringstream stream;
        stream << "Filozof " << philosopherNumber << " konczy dzialanie." << std::endl;
        std::cout << stream.str();
    }


};

std::default_random_engine PhilosopherClass::generator;
bool PhilosopherClass::end = false;

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

    PhilosopherClass::end = true;

    for(int i = 0; i < threadCount; i++) {
        t[i].join();
    }

    std::cout<< "Koniec Programu!"<< std::endl;

    return 0;
};