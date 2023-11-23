#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

const int internal_led_3 = 2;
const int internal_led_4 = 3;
const int optical_sensor_door_down = 1;
const int optical_sensor_door_up = 2;
const int siemens_open_door = 3;
const int siemens_close_door = 4;
const int arduino_open_door = 4;
const int arduino_close_door = 5;


void test_open_closed (){
    relays [3].set_high();
}

int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();
    bool run_program = true;
  //  test_relays ();
  test_open_closed();
   // my_delay (30);
  //  test_relays2 ();
    while (run_program == true){
        internal_LEDs [3].set_high();
        internal_LEDs [2].blink_internal_user_led(); 
        if ((inputs2 [1].get_status() == true) && (inputs2 [3].get_status() == true)){
            relays [4].set_high();
            sleep_for (milliseconds (500));
            relays [4].set_low();

        }else{
            relays [4].set_low();
        }
        if ((inputs2 [2].get_status() == true) && (inputs2 [4].get_status() == true)){
            relays [5].set_high();
            sleep_for (milliseconds (500));
            relays [5].set_low();
        }else{
            relays [5].set_low();
        }
        if (inputs2 [1].get_status() == true){
            relays [2].set_high();
        }else {
            relays [2].set_low();
        }
        if (inputs2 [2].get_status() == true){
            relays [3].set_high();
        }else {
            relays [3].set_low();
        }
    sleep_for (milliseconds(5));
    }

    return 0;
}



void test_relays (){
    
   // relays [1].set_high();
    
   // relays [2].set_high();
    
   // relays [3].set_high();
    
    relays [4].set_high();
    
    relays [5].set_high();

}
void test_relays2 (){
   // relays [1].set_low();
    
  //  relays [2].set_low();
    
   // relays [3].set_low();
    
    relays [4].set_low();
    
    relays [5].set_low();

}