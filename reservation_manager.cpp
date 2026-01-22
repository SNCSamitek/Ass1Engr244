#include "reservation_manager.h"
#include "guests_res_request.h"
#include <iostream>
#include <array>

Reservation_Manager::Reservation_Manager(){
	int reservation_table [max_no_of_nights][no_of_rooms] = {};
}

Reservation_Manager::~Reservation_Manager(){
    delete arr;
}

void Reservation_Manager::displayDetails(int id){ 
    std::cout << "The details of reservation " << id << " are the following:" << std::endl;
    short lengthOfStay = 0;
    short room = 0; 
    for(size_t i = 0; i < no_of_rooms; i++){ 
        for(size_t j = 0; j < max_no_of_nights; j++){ 
            if(id == reservation_table[j][i]){
                room = i + 1;
                lengthOfStay++; 
            } 
        }
    } 
    std::cout << "Room number: " << room << std::endl; 
    std::cout << "Reserved for: " << lengthOfStay << std:: endl; 
}

int Reservation_Manager::processReservation(const Guests_Res_Request &req){
    int* stayPtr;
    stayPtr = new 
}

void Reservation_Manager::cancelReservation(int id){
    for(size_t i = 0; i < no_of_rooms; i++){ 
        for(size_t j = 0; j < max_no_of_nights; j++){ 
            if(id == reservation_table[j][i]){
                reservation_table[j][i] = 0;
            } 
        }
    } 
}