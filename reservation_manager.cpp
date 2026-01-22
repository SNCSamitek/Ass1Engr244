#include "reservation_manager.h"

Reservation_Manager::Reservation_Manager(){
	int reservation_table [max_no_of_nights][no_of_rooms] = {};
}

Reservation_Manager::~Reservation_Manager(){
    delete arr;
}

void Reservation_Manager::displayDetails(int id){
    for(int i = 0; i < no_of_rooms; i++){
        if(id == reservation_table[j][i]){
            
        }
    }
}

int Reservation_Manager::processReservation(const Guests_Res_Request){

}

void Reservation_Manager::cancelReservation(int id){

}