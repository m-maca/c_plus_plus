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
        relays [3].set_high();
        my_delay();
        bool status = IO_type_to_be_tested [i].get_status();
        my_delay();
        relays [3].set_low ();
        my_delay();
        status = IO_type_to_be_tested [i].get_status();
        my_delay();
    }
}

void test_all_relay_outputs (){
    printf ("testing relays\n");
    test_sets_of_outputs (relays);
    printf ("testing relays end\n");
    printf ("----------------------------\n");
}
void test_all_digital_inputs(){
    printf ("testing inputs\n");
    test_sets_of_inputs (inputs);
    printf ("testing inputs end\n");
    printf ("----------------------------\n");
}
void test_all_digital_outputs(){
    printf ("testing outputs\n");
    test_sets_of_outputs (outputs);
    printf ("testing outputs end\n");
    printf ("----------------------------\n");
}
void test_all_internal_LEDs(){
    printf ("testing user LEDs \n");
    test_sets_of_outputs (internal_LEDs);
    printf ("testing user LEDs end\n");
    printf ("----------------------------\n");
}
void test_all_IOs(){
    printf ("test all IOs function started \n");
    printf ("----------------------------\n");
    test_all_relay_outputs();
    test_all_digital_outputs();
    test_all_internal_LEDs();
    test_all_digital_inputs();
    printf ("test all IOs function end\n");
    printf ("----------------------------\n");
}
#endif