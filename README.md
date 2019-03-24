# A-little-car-game
## Project Goals:

This is a small game. The user interface will generate a car and a four-line road. When we press the start button, the user interface will geterate random obstacles. The goal for this game is to avoid those obstacles and stay as long as possible to achieve highest score.


## Project Architecture:
-Car process
    * control car's turning.
    
-User interface process
    * Car design
    * Interface Design
    * Collision conditions
    * Buttoms.


## User Operation guide:

-operation rule

-Instruction Set:

-**s** : Start

-**a** : turn left

-**d** : turn right

-**q** : quit

-**r** : reset

    
## Installation :

To install the car simulator, type
 ```
   git clone 
   https://github.com/romolee/A-little-car-game.git
   cd Car_driving_simulator
   docker run -v $PWD:/source -it klavins/elma:latest bash
   make
 ```

  
## Execution :

To run the the little car game, type

    bin/stopwatch


## References

[elma](https://github.com/klavinslab/elma)
