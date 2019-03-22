#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>
#include "user_interface.h"



using namespace std::chrono;
using namespace elma;
//using namespace stopwatch;
using namespace Racing;

int main() {

    Manager m;
    //StopWatch stopwatch;
    //UserInterface ui(stopwatch);

    RacingCar racingcar("car");
    UserInterface ui(racingcar);

    m.schedule(ui, 10_ms)
     //.schedule(stopwatch, 10_ms)   
     .schedule(racingcar, 10ms)  
     .init()
     .run();

    endwin();     
     
}