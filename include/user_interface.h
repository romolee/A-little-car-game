#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

//#include "stopwatch.h"
#include "car.h"

//namespace stopwatch {
namespace Racing{

    using namespace std::chrono;
    using namespace elma;

    using namespace Racing;

    //! A user interface for the a car object

    class UserInterface : public Process {

        public:

        //! Create a new stopwatch user interface using curses
        //! \param sw A reference to a StopWatch object
        //UserInterface(StopWatch& sw);
        UserInterface(RacingCar& rc);

        void init() {}
        void start() {}

        //! Display the time at the given x,y position on the screen
        //void show_time(int x, int y, high_resolution_clock::duration d);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        //StopWatch& _stopwatch;
        RacingCar& _racingcar;
        int line1=0;
        int line2=0;
        int line3=0;
        int line4=0;
        int ran;
        int b=0;
        int scr=0;
        int highest=0;
        int randomtime;
        bool st=false;
        bool state1=false;
        bool state2=false; 
        bool state3=false;
        bool state4=false;
    };

}