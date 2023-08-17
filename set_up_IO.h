#ifndef set_up_io_h
#define set_up_io_h

/*IO_control parametrs (io_type, io_group_number, io_number)*/
/*io_type : 0 - digital input
            1 - digital output
            2 - relay output
                                io_group 1-2
                                relay 1-5 io_group 2
                                digital OUTPUT 1-4 group 1
                                digital INPUT 1-4 group 1*/
//old version of IO setup
/*
IO_control relay_1 (2,2,1);
IO_control relay_2 (2,2,2);
IO_control relay_3 (2,2,3);
IO_control relay_4 (2,2,4);
IO_control relay_5 (2,2,5);

IO_control input_1 (0,1,1);
IO_control input_2 (0,1,2);
IO_control input_3 (0,1,3);
IO_control input_4 (0,1,4);

IO_control output_1 (1,1,1);
IO_control output_2 (1,1,2);
IO_control output_3 (1,1,3);
IO_control output_4 (1,1,4);
*/

IO_control relays [5] = {IO_control (2,2,1), IO_control (2,2,2), IO_control (2,2,3), IO_control (2,2,4),IO_control(2,2,5)};
IO_control inputs [4] = {IO_control (0,1,1), IO_control (0,1,2), IO_control (0,1,3), IO_control (0,1,4)};
//IO_control outputs [4]= {IO_control (1,1,1), IO_control (1,1,2), IO_control (1,1,3), IO_control (1,1,4)};
IO_control outputs [4];

void initialize_digital_inputs (){
    
}

void initialize_digital_outputs (){
    for (int i= 0; i<4; i++){
        outputs [i].set_up_IO (1,1,(i+1));  
    }
}
//this is the newest change

#endif