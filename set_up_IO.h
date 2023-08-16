#ifndef set_up_io_h
#define set_up_io_h

/*IO_control parametrs (io_type, io_group_number, io_number)*/
/*io_type : 0 - digital input
            1 - digital output
            2 - relay output*/

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

#endif