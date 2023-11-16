#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();
    bool run_program = true;
    while (run_program == true){
        internal_LEDs [3].set_high();
        internal_LEDs [2].blink_internal_user_led(); 
        if ((inputs2 [1].get_status() == true) && (inputs2 [3].get_status() == true)){
            relays [4].set_high();
        }
        if ((inputs2 [2].get_status() == true) && (inputs2 [4].get_status() == true)){
            relays [5].set_high();
        }
    }

    return 0;
}
