#ifndef relay_control_h
#define realy_control_h

#include "my_definitions.h"


using namespace std;

void delay ();

class IO_control {
    public:
        IO_control (){

        }
        void set_up_IO (int type_number, int group_number, int io_number){
            type_num = type_number;
            group_num = group_number;
            io_num = io_number;
            address = get_io_address ();
        }
        IO_control (int type_number, int group_number, int io_number){
            set_up_IO(type_number, group_number,io_number);
        } 
        void set_output (bool status){
            if (status == true){
                set_high ();
            }else{
                set_low ();
            }
        }
        bool get_status (){
            string status;
            ifstream stat (address);
            getline (stat,status);
            bool io_state;
            if (status == "1"){
                io_state = true;
            }else if (status == "0"){
                io_state = false;
            }else{
                print_me ("error input status");
            }
            return io_state;
        }
        void set_high (){
            ofstream output_control (address);
            output_control << "1";
            print_me(address+" - 1");
            output_control.close();
        }
        void set_low (){
            ofstream output_control (address);
            output_control << "0";
            print_me (address+" - 0");
            output_control.close();
        }

    private: 
        int type_num, group_num, io_num;
        string IO_name;
        string address;
        string get_io_address (){
            string Sio_type = get_io_type ();
            string Sgroup_number = to_string (group_num);
            string Sio_num = to_string (io_num);
            string register_address = "/run/unipi/io_group" + Sgroup_number + "/" + Sio_type + "_" + Sgroup_number + "_0" + Sio_num + "/" + Sio_type + "_value";
            print_me (register_address);
            return register_address;
        }
        string get_io_type (){
            const static string type_array []= {"di","do","ro"};

            string io_type = type_array [type_num];
            
            return io_type;
        }
        string get_IO_name (){
            
            return IO_name;
        }
        void print_me (string to_be_printed){
            cout << to_be_printed + "\n";
        }
};



#endif
