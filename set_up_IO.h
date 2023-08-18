#ifndef set_up_io_h
#define set_up_io_h

enum IOs {digital_input, digital_output, relay_output};

/*IO_control parametrs (io_type, io_group_number, io_number)*/
/*
    digital IOs numbered from 1, easier to work with
    IO with number 0 is empty - does nothing
    io_group 1-2
    relay 1-5 io_group 2
    digital OUTPUT 1-4 group 1
    digital INPUT 1-4 group 1*/

IO_control inputs [8];
IO_control outputs [8];
IO_control relays [8];

void initialize_set_of_IOs (IO_control IO_name[8], int IO_type, int group_number, int number_of_IOs){
    number_of_IOs ++;
    cout << number_of_IOs + "\n";
    for (int i = 1; i<number_of_IOs; i++){
        IO_name [i].initialize_IO (IO_type,group_number, i);
    }
}
void initialize_digital_inputs (){
    initialize_set_of_IOs (inputs, 1, digital_input,4);
}

void initialize_digital_outputs (){
    initialize_set_of_IOs (outputs, 1, digital_output,4);
}

void initialize_relay_outputs (){
    initialize_set_of_IOs (relays, 2, relay_output,5);
} 
void initialize_all_IOs(){
    initialize_digital_inputs();
    initialize_digital_outputs();
    initialize_relay_outputs();
}



//this is the newest change

#endif