#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();
    outputs[1].set_high();
    sleep_for (milliseconds (400)); //enable
    outputs[2].set_high(); //direction
    sleep_for (microseconds (100));

    
    
    
    my_delay(4);
   // outputs[1].set_low();


    for (int i=1; i<100; i++){  //100x pulse
        outputs[3].set_high(); 
        sleep_for(microseconds (50));
        outputs[3].set_low();
        sleep_for(microseconds (50));
        
    }
    printf ("\n END program main  \n");
    return 0;
};
