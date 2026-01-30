#include "reservation_manager.h"
#include "guests_res_request.h"
#include <iostream>
#include <array>


//constructors and destructor ---------------------------------------------------
Reservation_Manager::Reservation_Manager(){
    for(int room = 0; room < no_of_rooms; room++){
        for(int night = 0; night < max_no_of_nights; night++){
            reservation_table [room][night] = 0;
        }
    }
}

Reservation_Manager::~Reservation_Manager(){
    for(Guests_Res_Request* ptr : arr){
        delete ptr;
    }
}
//----------------------------------------------------------------------------------

//core functions ----------------------------------------------------------------------------------
void Reservation_Manager::displayDetails(int id){ 
    std::cout << "The details of reservation " << id << " are the following:" << std::endl;
    short room = 0; 

    for(int i = 0; i < no_of_rooms; i++){
        for(int j = 0; j < max_no_of_nights; j++){
            if(id == reservation_table[i][j]){
                room = i++;
                break;
            }
        }
    }


    std::cout << "Reservation table" << std::endl;
    for(int i = 0; i < max_no_of_nights; i++){
        for(int j = 0; j < no_of_rooms; j++){
            std::cout << reservation_table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Reserved for: " << arr.at(id-1)->get_no_of_nights() << " night(s)";
    std::cout << " in room " << room << std::endl; 
    
    std::cout << "Check In Date: ";
    arr[id-1]->getPeople()->getCheckIn().printDate();
    std::cout << std::endl;

    std::cout << "Check Out Date: ";
    arr[id-1]->getPeople()->getCheckOut().printDate();
    std::cout << std::endl;

    std::cout << " Names under the reservation are: " << std::endl << std::endl;
    for(int i = 0; i < arr[id-1]->getPeople()->getNo_of_people(); i++){
        const Information* pplPtr = arr[id-1]->getPeople()->getInformation();
        std::cout << "First name: ";
        std::cout << (pplPtr+i)->getFirstName() << std::endl;
        std::cout << "Last name: ";
        std::cout << (pplPtr+i)->getLastName() << std::endl;
        std::cout << std::endl;
    }
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


//others ----------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------