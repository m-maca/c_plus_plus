#ifndef relay_control_h_
#define relay_control_h_

using namespace std;

class IO_control {
    public:
        IO_control ();
        IO_control (int type_number, int group_number, int io_number);
        void initialize_IO (int type_number, int group_number, int io_number);
        void set_output (bool status);
        bool get_status ();
        void set_high ();
        void set_low ();
        bool get_initialized_status ();
        void blink_led_internal_user_led ();

    private: 
        int type_num, group_num, io_num;
        string IO_name = "not initialized";
        string address = "not initialized";
        bool initialized = false;
        string get_io_address ();
        string get_io_type ();
        string get_IO_name ();
        string initialize_name ();
        void print_me (string to_be_printed);
        int internal_counter_1;
        bool tick_tock;
        void increment_internal_counter ();
        void reset_internal_counter ();
        void get_internal_counter ();
};
void IO_control::increment_internal_counter(){
    internal_counter_1 ++;
}
void IO_control::reset_internal_counter(){
    internal_counter_1 = 0;
}
int IO_control::get_internal_counter(){
    return internal_counter_1 = 0;
}
void IO_control::blink_led_internal_user_led(){
    check_internal_counter_for_overflow();
    increment_internal_counter();
    blink_led ();
}
void IO_control::check_internal_counter_for_overflow(){
    if (internal_counter_1> 30000){
        internal_counter_1 = 0;
    }
}

void IO_control::blink_led(){
    if (internal_counter_1 > 20000){
        internal_counter_1 = 0;
        if (tick_tock == true){
            tick_tock == false;
        }else{
            tick_tock = true;
        }
    }
    if (tick_tock == true){
        this.set_low;
    }else{
        this.set_high;
    }
}

IO_control::IO_control(){
    
}
IO_control::IO_control(int type_number, int group_number, int io_number){
    initialize_IO(type_number, group_number, io_number);
}
void IO_control::initialize_IO(int type_number, int group_number, int io_number){
    type_num = type_number;
    group_num = group_number;
    io_num = io_number;
    address = get_io_address ();
    IO_name = initialize_name ();
    initialized = true;
}
string IO_control::get_io_address (){
    string Sio_type = get_io_type ();
    string Sgroup_number = to_string (group_num);
    string Sio_num = to_string (io_num);
    string register_address;
    if (type_num==3){
        register_address = "/run/unipi/io_group" + Sgroup_number + "/leds/unipi:green:uled-x"  + Sio_num + "/brightness";
    }else {
        register_address = "/run/unipi/io_group" + Sgroup_number + "/" + Sio_type + "_" + Sgroup_number + "_0" + Sio_num + "/" + Sio_type + "_value";
    };
    print_me (register_address);
    return register_address;
}
string IO_control::get_io_type (){
    const static string IO_type_array []= {"di","do","ro","xled"};

    string io_type = IO_type_array [type_num];
    
    return io_type;
}
string IO_control::get_IO_name (){
    
    return IO_name;
}

void IO_control::set_output(bool status){
    if (status == true){
        set_high ();
    }else{
        set_low ();
    }
}


bool IO_control::get_status (){
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
    string print_status = IO_name + " __ state " + to_string (io_state);
    print_me (print_status);
    return io_state;
}
void IO_control::set_high (){
    if (initialized == true){
        ofstream output_control (address);
        output_control << "1";
       // print_me(IO_name + " __ state 1");
        output_control.close();
    } else {
        print_me ("this IO has not been initialized");
    }
}
void IO_control::set_low (){
    if (initialized == true){
        ofstream output_control (address);
        output_control << "0";
      //  print_me (IO_name +" __ state 0");
        output_control.close();
    } else {

    }
}
void IO_control::print_me (string to_be_printed){
    cout << to_be_printed + "\n";
}

bool IO_control::get_initialized_status (){
    return initialized;
}

string IO_control::initialize_name (){
    string name_string;
    const static string IO_type_name [] = {"digital input ", "digital output", "relay output  " , "user LED      "};
    name_string = IO_type_name [type_num] + " - " + to_string (group_num) + "." + to_string (io_num);
    return name_string;
}

#endif
