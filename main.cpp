#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int pulses_per_revolution = 800;
int min_pulse_delay = 10; //microseconds
void test_motor_enable_bit();
void rotate_stepper(int turn_degrees);
void enable_motor_control();
void accelerate_motor_to_speed (int speed_in_percent);
void set_motor_direction_clockwise();
void set_motor_direction_counterClockwise();


int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();

  //  test_motor_enable_bit();
    enable_motor_control();
    set_motor_direction_clockwise();
    //set_motor_direction_counterClockwise();
    rotate_stepper(7);

    set_motor_direction_counterClockwise();
    rotate_stepper(7);
  //  for (int i=1; i<=20; i++){
      //  rotate_stepper(10);
        my_delay(2);
 //   }
    printf ("\n END program main  \n");
    return 0;
}

void enable_motor_control (){
    outputs [1].set_low();
    printf ("\n motor enabled");
    sleep_for (milliseconds (400));
}

void disable_motor_control (){
    outputs [1].set_high();
    printf ("\n motor disabled");
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
/*
void rotate_stepper (){
    for (int i=1; i<10000; i++){  //100x pulse
        outputs[3].set_high(); 
        sleep_for(microseconds (100));
        outputs[3].set_low();
        sleep_for(microseconds (100));
    }
}
*/
void rotate_stepper (int turn_degrees){
    int mimimum_pulse_delay = 5;
    int number_of_pulses = 0;
    for (int x=1; x<=turn_degrees; x++){
        for (int i=1; i<=pulses_per_revolution; i++){
            outputs[3].set_high();
            sleep_for(microseconds (mimimum_pulse_delay));
            outputs[3].set_low();
            sleep_for(microseconds (mimimum_pulse_delay));
            number_of_pulses ++;
        }
        cout<< number_of_pulses;
    }
}
void set_motor_direction_clockwise(){
    outputs[2].set_high();
    sleep_for (milliseconds (400));
}

void set_motor_direction_counterClockwise(){
    outputs[2].set_low();
    sleep_for (milliseconds (400));
}
bool stepper_driver_in_error (){
    if (inputs[1].get_status() == true){
        return true;
    }else{
        return false;
    }
}

void open_door(){
    if (stepper_driver_in_error () == true){
        printf ("\n error stepper driver");
        return;
    }else{

    }

}

void accelerate_motor_to_speed (int speed_in_percent) {
    int initial_pulse_delay = 500;
    int variable_pulse_delay = initial_pulse_delay;
    int terminal_pulse_delay = ((min_pulse_delay *100)/speed_in_percent);   
    printf ("\n terminal_pulse_delay in microseconds:");
    cout<< terminal_pulse_delay;
 
    for (int i=1; i <= (pulses_per_revolution*3); i++){
        outputs [3].set_high();
        sleep_for(microseconds (variable_pulse_delay));
        outputs [3].set_low();
        sleep_for(microseconds (variable_pulse_delay));
        if (variable_pulse_delay > terminal_pulse_delay){
            variable_pulse_delay --;
            printf ("\n variable_pulse_delay");
            cout<< variable_pulse_delay;
        }
    }


}

