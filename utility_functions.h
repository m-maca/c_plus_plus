#ifndef utility_functions_h_
#define utility_functions_h_

void my_delay (uint64_t timer_multiplier = 1){
    uint64_t timer1= 0;
    printf ("\n wait  \n");
    while (timer1< (119000000*timer_multiplier)){
        timer1 ++;
    }
}

#endif