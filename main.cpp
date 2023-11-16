#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void blink_user_led ();



int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();

    while (){
        blink_user_led (); 
        if ((inputs2 [1].get_status() == HIGH) && (inputs2 [3].get_status() == HIGH)){
            relays [4].set_high();
        }
        if ((inputs2 [2].get_status() == HIGH) && (inputs2 [4].get_status() == HIGH)){
            relays [5].set_high();
        }
    }

    return 0;
}

void blink_user_led (){
    internal_LEDs [2].set_high();
    
}
