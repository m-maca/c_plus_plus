#ifndef test_io_h_
#define test_io_h_



void test_sets_of_outputs (IO_control test_type[8]){
    for (int i=1; i<8; i++){
        test_type [i].set_high();
        my_delay ();
        test_type [i].set_low();
    }
}
uint64_t my_new_variable = 10;

void test_all_relay_outputs (){
    test_sets_of_outputs (relays);
}
void test_all_digital_inputs(){
    test_sets_of_outputs (inputs);
}
void test_all_digital_outputs(){
    test_sets_of_outputs (outputs);
}
void test_all_IOs(){
    test_all_relay_outputs();
    test_all_digital_outputs();
}
#endif