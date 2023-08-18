#ifndef set_up_io_h
#define set_up_io_h
#include "my_definitions.h"

enum IOs {digital_input=0, digital_output, relay_output,internal_LED};
enum section_number {first_section = 1, second_section = 2, third_section = 3};
/*IO_control parametrs (io_type, io_group_number, io_number)*/
/*
    digital IOs numbered from 1, easier to work with
    IO with number 0 is empty - does nothing
    io_group 1-2
    relay 1-5 io_group 2
    digital OUTPUT 1-4 group 1
    digital INPUT 1-4 group 1*/

IO_control inputs [8];
IO_control inputs2 [8];
IO_control outputs [8];
IO_control relays [8];
IO_control internal_LEDs [8];

void initialize_set_of_IOs (IO_control IO_name[8], int IO_type, int group_number, int number_of_IOs, int start_number){
    number_of_IOs ++;
    cout << number_of_IOs + "\n";
    for (int i = start_number; i<number_of_IOs; i++){
        IO_name [i].initialize_IO (IO_type,group_number, i);
    }
}
void initialize_digital_inputs (){
    printf ("initializing inputs \n");
    initialize_set_of_IOs (inputs, digital_input, first_section, 4, 1);
    initialize_set_of_IOs (inputs2, digital_input, second_section, 4, 1);
    printf ("init inputs end \n");
}

void initialize_digital_outputs (){
    printf ("initializing outputs \n");
    initialize_set_of_IOs (outputs, digital_output, first_section, 4, 1);
    printf ("init outputs end \n");
}

void initialize_relay_outputs (){
    printf ("initializing relays \n");
    initialize_set_of_IOs (relays, relay_output, second_section, 5, 1);
    printf ("init relays end \n");
} 
void initialize_internal_LEDs(){
    printf ("initializing internal LEDs \n");
    initialize_set_of_IOs (internal_LEDs, internal_LED, first_section, 3, 0); 
    printf ("init LEDs end \n");
}
void initialize_all_IOs(){
    initialize_digital_inputs();
    initialize_digital_outputs();
    initialize_relay_outputs();
    initialize_internal_LEDs();
}



//this is the newest change

#endif