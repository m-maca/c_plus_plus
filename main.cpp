#include "my_definitions.h"


using namespace std;



int main (){
    initialize_all_IOs();
    test_all_IOs();
/*
    cout << "\n START program main \n";
    for (int i = 1; i<8; i++){
        relays [i].set_high();
        outputs [i].set_high();
        my_delay ();
        relays [i].set_low();
        outputs [i].set_low();
        my_delay ();
    }
*/      
    printf ("\n END program main  \n");

    return 0;
};


void old_testing_commands_from_main (){
    my_delay();
    for (int i=0; i<4; i++){
        outputs [i].set_low();
    }
    relays[0].set_high();
    relays[1].set_high();
    my_delay ();

    outputs [1].set_high();
        
    bool input_1_status = inputs [1].get_status();
    cout << "\n  input 1  " + to_string (input_1_status) + "\n";
    my_delay();
      
    my_delay ();
    for (int i = 0; i<4; i++){
        outputs [i].set_high();
    }


    for (int i=1; i<5; i++){            
        if (inputs [1].get_status()== true){
            printf ("input 1 is in HIGH state");
        }
    }
}