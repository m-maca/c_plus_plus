#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void test_motor_enable_bit();
void rotate_stepper();
void enable_motor_control();

int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();

  //  test_motor_enable_bit();
    enable_motor_control();
    rotate_stepper();
    outputs [2].set_high();
    rotate_stepper();

    printf ("\n END program main  \n");
    return 0;
}

void enable_motor_control (){
    outputs [1].set_low();
    printf ("/n motor enabled");
    sleep_for (milliseconds (400));
}

void disable_motor_control (){
    outputs [1].set_high();
    printf ("/n motor disabled");
    sleep_for (milliseconds (400));
}

void test_motor_enable_bit (){
    enable_motor_control();
    my_delay (4);
    disable_motor_control();
    my_delay(4);
    enable_motor_control();
    my_delay(4);
}

void rotate_stepper (){
    for (int i=1; i<10000; i++){  //100x pulse
        outputs[3].set_high(); 
        sleep_for(microseconds (100));
        outputs[3].set_low();
        sleep_for(microseconds (100));
    }
}

void rotate_stepper (int degrees){
    int mimimum_pulse_delay = 100;
    for (int i=1; i<200; i++){
        outputs[3].set_high();
        sleep_for(microseconds (mimimum_pulse_delay));
        outputs[3].set_low();
        sleep_for(microseconds (mimimum_pulse_delay));
    }
}