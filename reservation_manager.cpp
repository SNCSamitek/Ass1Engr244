#include "reservation_manager.h"
#include "guests_res_request.h"
#include <iostream>
#include <array>
#include <iomanip>

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
	std::cout << "-------------------------------------------------------------" << std::endl; 
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
    std::cout << "Reserved for: " << arr.at(id-1)->get_no_of_nights() << " night(s)";
    std::cout << " in room " << arr.at(id-1)->getPeople()->getRoomId() << std::endl;
    
	Date checkIn = arr[id-1]->getPeople()->getCheckIn();
    std::cout << "Check In Date (y, m, d): " << checkIn.toString();
    std::cout << std::endl;

	Date checkOut = arr[id-1]->getPeople()->getCheckOut();
    std::cout << "Check Out Date (y, m, d): " << checkOut.toString();
    std::cout << std::endl;

    std::cout << "Names under the reservation are: " << std::endl << std::endl;
    for(int i = 0; i < arr[id-1]->getPeople()->getNo_of_people(); i++){
        const Information* pplPtr = arr[id-1]->getPeople()->getInformation();
        std::cout << "Person " << i+1 << ": ";
		std::cout << (pplPtr+i)->getFirstName() << " ";
        std::cout << (pplPtr+i)->getLastName() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl; 
}

int Reservation_Manager::processReservation(Guests_Res_Request* req){
    short id = req->get_reservation_id();
    short room = req->getPeople()->getRoomId();
    short startNight = req->getPeople()->getCheckIn().getDay();
    short dur = req->get_no_of_nights();

    bool isAvailable = true;
    for(int i = 0; i < dur; i++){
        if(reservation_table[room][startNight+i] != 0){
            isAvailable = false;
            break;
        }
    }
    if(isAvailable){
        for(int i = 0; i < dur; i++){
            reservation_table[room][startNight+i] = id;
        }
        arr.push_back(req);
        return id;
    }

    std::cout << "Booking not available!" << std::endl;
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

    for(Guests_Res_Request* request : arr){
        std::cout << "-------------------" << std::endl;
        request->printGuestsRequests();
    }

    std::cout << "Reservation table" << std::endl;
    for(int i = 0; i < max_no_of_nights; i++){
        for(int j = 0; j < no_of_rooms; j++){
            std::cout << reservation_table[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
//----------------------------------------------------------------------------------