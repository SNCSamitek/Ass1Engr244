#include "reservation_manager.h"
#include "guests_res_request.h"
#include <iostream>
#include <array>

Reservation_Manager::Reservation_Manager(){
    for(int i = 0; i < no_of_rooms; i++){
        for(int j = 0; j < max_no_of_nights; j++){
            reservation_table [i][j] = 0;
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
    short room = 0; 

    for(int i = 0; i < no_of_rooms; i++){
        for(int j = 0; j < max_no_of_nights; j++){
            if(id == reservation_table[i][j]){
                room = i+1;
                break;
            }
        }
    }

    std::cout << "Reserved for: " << arr.at(id-1)->get_no_of_nights() << " night(s)";
    std::cout << " in room " << room << std::endl; 
    
    std::cout << " Names under the reservation are: " << std::endl << std::endl;


    arr[id-1]->getPeople()->getInformation()->printInformation();

}

int Reservation_Manager::processReservation(Guests_Res_Request* req){
    short dur = req->get_no_of_nights();
    short id = req->get_reservation_id();
    
    for(int room = 0; room < no_of_rooms; room++){
        for(int startNight = 0; startNight <= max_no_of_nights - dur; startNight++){
            bool allNightsAvailable = true;

            for(int night = 0; night < dur; night++){
                if(reservation_table[room][startNight + night] != 0){
                    allNightsAvailable = false;
                    break;  
                }
            }
            
            if(allNightsAvailable){
                for(int night = 0; night < dur; night++){
                    reservation_table[room][startNight + night] = id;
                }
                arr.push_back(req);
                return id;
            }
        }
    }
    
    delete req;
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

void Reservation_Manager::printResMan(){
    std::cout << max_no_of_nights << std::endl;
    std::cout << no_of_rooms << std::endl;

    for(auto request : arr){
        std::cout << "-------------------" << std::endl;
        request->printGuestsRequests();
    }

    std::cout << "Reservation table" << std::endl;
    for(int i = 0; i < max_no_of_nights; i++){
        for(int j = 0; j < no_of_rooms; j++){
            std::cout << reservation_table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}