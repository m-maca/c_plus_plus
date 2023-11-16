#include "my_definitions.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int pulses_per_revolution = 800;
int pulse_delay = 2500;
int min_pulse_delay = 10; //microseconds
void test_motor_enable_bit();
void rotate_stepper();
void enable_motor_control();
void disable_motor_control();
void accelerate_motor_to_speed (int speed_in_percent);
void set_motor_direction_clockwise();
void set_motor_direction_counterClockwise();
void test_unipi_timming(){
    
}

int main (){
    printf  ("\n here the program main starts\n");
    initialize_all_IOs();


  //  if (inputs [])


    return 0;
}
