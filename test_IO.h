#ifndef test_io_h_
#define test_io_h_

int get_last_initialized_IO(IO_control IO_type[8]){
    for (int i=1; i<8; i++){
        bool actual_status;
        actual_status = IO_type [i].get_initialized_status ();
        if (actual_status == false){
            return i;
        } 
    }
    return 0;
}
int get_first_initialized_IO(IO_control IO_type[8]){
    if (IO_type [0].get_initialized_status() == true){
        return 0;
    }else if (IO_type [0].get_initialized_status() == false){
        return 1;
    }
    return 10;
}


void test_sets_of_outputs (IO_control IO_type_to_be_tested [8]){
    int last_IO_in_group=(get_last_initialized_IO(IO_type_to_be_tested));
    int first_initialized_IO = (get_first_initialized_IO(IO_type_to_be_tested));
    for (int i=first_initialized_IO; i<last_IO_in_group; i++){
        IO_type_to_be_tested [i].set_high();
        my_delay ();
        IO_type_to_be_tested [i].set_low();
        my_delay ();
    }
}
void test_sets_of_inputs (IO_control IO_type_to_be_tested [8]){
    int last_IO_in_group = (get_last_initialized_IO(IO_type_to_be_tested));
    int first_initialized_IO = (get_first_initialized_IO(IO_type_to_be_tested));
    for (int i = first_initialized_IO; i<last_IO_in_group; i++){
        relays [3].set_low();
        bool status = IO_type_to_be_tested [i].get_status();
        my_delay();
        relays [3].set_high ();
        status = IO_type_to_be_tested [i].get_status();
        my_delay();
    }
}

void test_all_relay_outputs (){
    printf ("testing relays");
    test_sets_of_outputs (relays);
    printf ("testing relays end");
}
void test_all_digital_inputs(){
    printf ("testing inputs");
    test_sets_of_outputs (inputs);
    printf ("testing inputs end");
}
void test_all_digital_outputs(){
    test_sets_of_outputs (outputs);
}
void test_all_internal_LEDs(){
    test_sets_of_outputs (internal_LEDs);
}
void test_all_IOs(){
    test_all_relay_outputs();
    test_all_digital_outputs();
    test_all_internal_LEDs();
    test_all_digital_inputs();
}
#endif