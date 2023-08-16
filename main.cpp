#include "my_definitions.h"


using namespace std;

void delay ();


int main (){
    test_all_digital_outputs();
    cout << "\n START program main \n";
    output_4.set_low();
    delay();
    relay_1.set_high();
    relay_2.set_high();
    delay ();
    output_1.set_high();
    output_4.set_high();
    output_3.set_high();
        
    bool input_1_status = input_1.get_status();
    cout << "\n  input 1  " + to_string (input_1_status) + "\n";
    delay();
      
    delay ();

    for (int i=1; i<5; i++){            
        if (input_1.get_status()== true){
            printf ("input 1 is in HIGH state");
        }
    }
        
    printf ("\n END program main  \n");

    return 0;
};

void delay (){
    uint64_t timer1= 0;
    printf ("wait  \n");
    while (timer1< 499000000){
        timer1 ++;
    }
}