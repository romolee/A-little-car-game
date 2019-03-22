#ifndef _ELMA_CAR_H
#define _ELMA_CAR_H
#include "elma/elma.h"
using namespace std::chrono;
using namespace elma;


 // Note installation directory for elma
namespace Racing {
    class RacingCar : public Process {
        public:
            //! Make a Rnew acingCar 

        RacingCar(std::string name) : Process(name) {}

        void init(){        
            watch("left",[this](Event& e){
                if(a>0){
                    a=a-1;
                }
            });
            watch("right",[this](Event& e){
                if(a<4){
                    a=a+1;
                }
            });
        }
        void start(){}
        void update(){

        }
        void stop(){}

        int getcar(){
            return a;
        }
        
        int getran(){
            return random()%4;
        }
        private:
            int a=0;
            high_resolution_clock::time_point _start_time;
            high_resolution_clock::duration _elapsed;

    };

}

#endif