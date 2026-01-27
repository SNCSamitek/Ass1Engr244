#include "reservation_manager.h"
#include "guests_res_request.h"
#include <iostream>
#include <array>

Reservation_Manager::Reservation_Manager(){
    for(int i = 0; i < no_of_rooms; i++){
        for(int j = 0; j < max_no_of_nights; j++){
            reservation_table [j][i] = 0;
        }
    }
}

Reservation_Manager::~Reservation_Manager(){
    for(Guests_Res_Request* ptr : arr){
        delete ptr;
    }
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

int Reservation_Manager::processReservation(Guests_Res_Request* req){
    size_t dur = req->get_no_of_nights();
    int* stayPtr = new int[dur];
    bool canBook;

    for(int i = 0; i < no_of_rooms; i++){
        for(int j = 0; j < max_no_of_nights - dur; j++){
            canBook = true;

            for(int k = 0; k < dur; k++){
                if(reservation_table[i][j+k] != 0){
                    canBook= false;
                    break;
                }
            }

            if(canBook){
                for(int k = 0; k < dur; k++){
                    stayPtr[k] = req->get_reservation_id();
                    reservation_table[i][j+k] += stayPtr[k];
                }
                delete[] stayPtr;
                arr.push_back(req);
                return req->get_reservation_id();
            }
        }
    }
    
    delete req;
    delete[] stayPtr;
    return -1;
}

void Reservation_Manager::cancelReservation(int id){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]->get_reservation_id() == id){
            delete arr[i];
            arr.erase(arr.begin() + i);
        }
    }

    for(size_t i = 0; i < no_of_rooms; i++){ 
        for(size_t j = 0; j < max_no_of_nights; j++){ 
            if(id == reservation_table[j][i]){
                reservation_table[j][i] = 0;
            } 
        }
    }
}