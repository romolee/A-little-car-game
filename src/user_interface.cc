#include <unistd.h>

#include "user_interface.h"


using namespace Racing;



UserInterface::UserInterface(RacingCar& rc) : Process("user input"), _racingcar(rc) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    int c = getch();

    switch ( c ) {  
        case 's':
            st = true;
            scr =0;
            break;
        case 'd':
            emit(Event("right"));
            break;
        case 'a':
            emit(Event("left"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
        case 'r':
            st =false;
            scr = 0;
            for (int i=4; i<23; i++){
                mvprintw(line1/3+5,i," "); 
            }
            for (int i=23; i<41; i++){
                mvprintw(line2/3+5,i," "); 
            }
            for (int i=41; i<59; i++){
                mvprintw(line3/3+5,i," "); 
            }
            for (int i=59; i<79; i++){
                mvprintw(line4/3+5,i," "); 
            }
            line1=0;
            line2=0;
            line3=0;
            line4=0;
            state1=false;
            state2=false;
            state3=false;
            state4=false;
            break;
    }
    mvprintw(1,2, "A little car game");
    mvprintw(2,2,"start(S),reset(R),quite(Q), left(A), right(D)");
    mvprintw(3,2,"Your score: %02d",scr);
    mvprintw(3,25,"Highest score: %02d",highest);

    // provide higheest score
    if (scr>highest){
        highest = scr;
    }

    // start the game
    if (st == true){
        // random drop
        randomtime +=1;
        if (randomtime%37==0){
            ran = _racingcar.getran();
        }
        if (ran ==0){
            state1=true;
        } else if(ran ==1){
            state2=true;
        }else if (ran ==2){
            state3=true;
        }else{
            state4=true;
        }
        //line 1 drop 
        if (state1 == true){
            line1 = line1 +1;
            for (int i=4; i<23; i++){
                mvprintw(line1/3+4,i," "); 
            }
            for (int i=4; i<23; i++){
                mvprintw(line1/3+5,i,"-"); 
            }
            if (line1/3 == 40){
                line1 =0;
                state1 =false;
                scr +=1;
            }
        }
        // line 2 drop
        if (state2 == true){
            line2 = line2 +1;
            for (int i=23; i<41; i++){
                mvprintw(line2/3+4,i," "); 
            }
            for (int i=23; i<41; i++){
                mvprintw(line2/3+5,i,"-"); 
            }
            if (line2/3 == 40){
                line2 =0;
                state2 == false;
                scr +=1;
            }
        }
        //line 3 drop
        if (state3 == true){
            line3 = line3 +1;
            for (int i=41; i<59; i++){
                mvprintw(line3/3+4,i," "); 
            }
            for (int i=41; i<59; i++){
                mvprintw(line3/3+5,i,"-"); 
            }
            if (line3/3 == 40){
                line3 =0;
                state3 ==false;
                scr+=1;
            }
        }
        //line 4 drop 
        if (state4 == true){    
            line4 = line4 +1;
            for (int i=59; i<77; i++){
                mvprintw(line4/3+4,i," "); 
            }
            for (int i=59; i<77; i++){
                mvprintw(line4/3+5,i,"-"); 
            }
            if (line4/3 == 40){
                line4 =0;
                state4 == false;
                scr+=1;
            }
        }
    }
    // crush condition
    if (line1/3>=37 && line1/3<40 && b==0){
        mvprintw(30,80,"crash at line 1");
        mvprintw(32,80,"               ");
        mvprintw(34,80,"               ");
        mvprintw(36,80,"               "); 
        st = false;
    }else if (line2/3>=37 && line2/3<40 && b==1){
        mvprintw(32,80,"crash at line 2");
        mvprintw(30,80,"               ");
        mvprintw(34,80,"               ");
        mvprintw(36,80,"               ");
        st = false;
    }else if (line3/3>37 && line3/3<40 && b==2){
        mvprintw(34,80,"crash at line 3");
        mvprintw(30,80,"               ");
        mvprintw(32,80,"               ");
        mvprintw(36,80,"               ");
        st = false;
    }else if (line4/3>37 && line4/3<40 && b==3){
        mvprintw(36,80,"crash at line 4");
        mvprintw(30,80,"               ");
        mvprintw(32,80,"               ");
        mvprintw(34,80,"               ");
        st = false;
    }

    // frame of racing game
    for (int i =4; i<76;i++){
        mvprintw(4,i,"-"); 
        mvprintw(45,i,"-"); 
    }
    for(int i= 4;i<45;i++){
        mvprintw(i,4,"|");
        mvprintw(i,76,"|");
    }
    for(int i= 4;i<45;i++){
        mvprintw(i,22,"|");
        mvprintw(i,40,"|");
        mvprintw(i,58,"|");
    }
    // car in line 1
    if(_racingcar.getcar()==0){
        for(int i = 42; i<45;i++){
            mvprintw(i,12,"|");
            mvprintw(i,13,"|");
        }
        mvprintw(42,11,"O");
        mvprintw(42,14,"O");
        mvprintw(44,11,"O");
        mvprintw(44,14,"O");
        b=0;
        ////////////////////
        //clear car 2
        for(int i = 42; i<45;i++){
            mvprintw(i,31," ");
            mvprintw(i,32," ");
        }
        mvprintw(42,30," ");
        mvprintw(42,33," ");
        mvprintw(44,30," ");
        mvprintw(44,33," ");
        //clear car 3
        for(int i = 42; i<45;i++){
            mvprintw(i,49," ");
            mvprintw(i,50," ");
        }
        mvprintw(42,48," ");
        mvprintw(42,51," ");
        mvprintw(44,48," ");
        mvprintw(44,51," ");
        //clear car 4
        for(int i = 42; i<45;i++){
            mvprintw(i,67," ");
            mvprintw(i,68," ");
        }
        mvprintw(42,66," ");
        mvprintw(42,69," ");
        mvprintw(44,66," ");
        mvprintw(44,69," ");
        ////////////////////
    }
    //car in line 2
    if(_racingcar.getcar()==1){
        for(int i = 42; i<45;i++){
            mvprintw(i,31,"|");
            mvprintw(i,32,"|");
        }
        mvprintw(42,30,"O");
        mvprintw(42,33,"O");
        mvprintw(44,30,"O");
        mvprintw(44,33,"O");
        b=1;
        ////////////////////
        //clear car 1
        for(int i = 42; i<45;i++){
            mvprintw(i,12," ");
            mvprintw(i,13," ");
        }
        mvprintw(42,11," ");
        mvprintw(42,14," ");
        mvprintw(44,11," ");
        mvprintw(44,14," ");
        //clear car 3
        for(int i = 42; i<45;i++){
            mvprintw(i,49," ");
            mvprintw(i,50," ");
        }
        mvprintw(42,48," ");
        mvprintw(42,51," ");
        mvprintw(44,48," ");
        mvprintw(44,51," ");
        //clear car 4
        for(int i = 42; i<45;i++){
            mvprintw(i,67," ");
            mvprintw(i,68," ");
        }
        mvprintw(42,66," ");
        mvprintw(42,69," ");
        mvprintw(44,66," ");
        mvprintw(44,69," ");
        ////////////////////
    }
    //car in line 3
    if(_racingcar.getcar()==2){
        for(int i = 42; i<45;i++){
            mvprintw(i,49,"|");
            mvprintw(i,50,"|");
        }
        mvprintw(42,48,"O");
        mvprintw(42,51,"O");
        mvprintw(44,48,"O");
        mvprintw(44,51,"O");
        b=2;
        ////////////////////
        //clear car 1
        for(int i = 42; i<45;i++){
            mvprintw(i,12," ");
            mvprintw(i,13," ");
        }
        mvprintw(42,11," ");
        mvprintw(42,14," ");
        mvprintw(44,11," ");
        mvprintw(44,14," ");
        //clear car 2
        for(int i = 42; i<45;i++){
            mvprintw(i,31," ");
            mvprintw(i,32," ");
        }
        mvprintw(42,30," ");
        mvprintw(42,33," ");
        mvprintw(44,30," ");
        mvprintw(44,33," ");
        //clear car 4
        for(int i = 42; i<45;i++){
            mvprintw(i,67," ");
            mvprintw(i,68," ");
        }
        mvprintw(42,66," ");
        mvprintw(42,69," ");
        mvprintw(44,66," ");
        mvprintw(44,69," ");
        ////////////////////
    }
    //car in line 4
    if(_racingcar.getcar()==3){
        for(int i = 42; i<45;i++){
            mvprintw(i,67,"|");
            mvprintw(i,68,"|");
        }
        mvprintw(42,66,"O");
        mvprintw(42,69,"O");
        mvprintw(44,66,"O");
        mvprintw(44,69,"O");
        b=3;
        ////////////////////
        //clear car 1
        for(int i = 42; i<45;i++){
            mvprintw(i,12," ");
            mvprintw(i,13," ");
        }
        mvprintw(42,11," ");
        mvprintw(42,14," ");
        mvprintw(44,11," ");
        mvprintw(44,14," ");
        //clear car 2
        for(int i = 42; i<45;i++){
            mvprintw(i,31," ");
            mvprintw(i,32," ");
        }
        mvprintw(42,30," ");
        mvprintw(42,33," ");
        mvprintw(44,30," ");
        mvprintw(44,33," ");
        //clear car 3
        for(int i = 42; i<45;i++){
            mvprintw(i,49," ");
            mvprintw(i,50," ");
        }
        mvprintw(42,48," ");
        mvprintw(42,51," ");
        mvprintw(44,48," ");
        mvprintw(44,51," ");
        ////////////////////
    }


    // NOTE: Since the stopwatch is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}