#include <iostream>
#include <iomanip>
#include "reservation_manager.h"
#include "guests_res_request.h"
#include "information.h"
#include "guests.h"
#include "date.h"

using namespace std;

void displayMenu(Reservation_Manager &rm);
bool userInput(Reservation_Manager &rm);

int main()
{
	Reservation_Manager rm;
    displayMenu(rm);
}


// Shows the user their choices for input
void displayMenu(Reservation_Manager &rm){
	bool exit = false;
	while (!exit) {
		cout << "\nSelect your choice: " << endl;
		cout << "\t1) Add a reservation." << endl;
		cout << "\t2) Cancel a reservation." << endl;
		cout << "\t3) Display information of a reservation." << endl;
		cout << "\t4) Display information of all reservations." << endl;
		cout << "\t5) Display Reservation Table." << endl;
		cout << "\t6) Exit the program." << endl << endl;
		exit = userInput(rm);
	}

}

// The input loop which will ask the user to provide input to their choice
// then does the actions required for that choice
bool userInput(Reservation_Manager &rm){
	char choice;
	cin >> choice;

	// Must have initialization before the switch
	int id;
	int temp;
	short userCheckIn;
	short userCheckOut;
	int no_of_people;
	int no_of_nights;
	Date checkIn;
	Date checkOut;
	Information list_people[4];
	short room_id;
	char firstName[25];
	char lastName[25];
	Date dateOfBirth;
	Guests* people;
	Guests_Res_Request* new_req;

	switch (choice) {
		case '1':
		// Input for number of nights
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nHow many nights are they staying: ";
			cin >> no_of_nights;
			if(no_of_nights > 7) cout << "Max of 7 nights available!" << endl;
			else if(no_of_nights < 1) cout << "Must stay for at least 1 night!" << endl;
		}while(no_of_nights > 7 || no_of_nights < 1);

		// Input for number of people
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nHow many people: ";
			cin >> no_of_people;
			if(no_of_people > 4) cout << "There is a max of 4 people per room!" << endl;
			else if(no_of_people < 1) cout << "Must have at least one person in the room!" << endl;
		}while(no_of_people > 4 || no_of_people < 1);

		// Input for names of people and their birth dates
		for (int i = 0; i < no_of_people && i < 4; i++) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Person " << i+1 << ":\n";
			cout << "First name? ";
			cin >> firstName;
			cout << "Last name? ";
			cin >> lastName;

			cout << "Date Of Birth: \n\tday:";
			cin >> temp;
			dateOfBirth.setDay(temp);
			cout << "\tmonth:";
			cin >> temp;
			dateOfBirth.setMonth(temp);
			cout << "\tyear:";
			cin >> temp;
			dateOfBirth.setYear(temp);

			list_people[i] = Information(firstName, lastName, dateOfBirth);
		}

		// Input for which room
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Which room?" << endl;
			cin >> room_id;
			if(room_id < 1 || room_id > 20) cout << "Rooms go from 1 to 20!" << endl << endl;
		}while(room_id < 1 || room_id > 20);

		// Input for check in day
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Check in date: \n\tday:";
			cin >> userCheckIn;
			userCheckOut = no_of_nights + userCheckIn;
			if(userCheckIn < 1 || userCheckIn > 6) cout << "Check in dates go from 1 to 6!" << endl;
			else if(userCheckOut > 8) cout << "Check in day and duration of stay bypass hotel's last available day!" << endl;
		}while(userCheckIn < 1 || userCheckIn > 6 || userCheckOut > 8);

		checkIn.setDay(userCheckIn);
		checkIn.setMonth(3);
		checkIn.setYear(2026);

		cout << "Check out will be on day " << userCheckOut << endl;
		checkOut.setDay(userCheckOut);
		checkOut.setMonth(3);
		checkOut.setYear(2026);

		// The processing of the request
		people = new Guests(checkIn, checkOut, list_people, no_of_people, room_id);
		new_req = new Guests_Res_Request(no_of_nights, people);
		id = rm.processReservation(new_req);

		if (id != -1) {
			cout << "Reservation created at id: " << id << endl;
		} else {
			cout << "Reservation not created!" << endl;
		}
		
		return false;
		break;

		case '2':

		// Cancelling Reservation Process
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID of reservation (0 to exit): ";
			cin >> id;
			if(rm.getNoGuestsRequest() == 0) cout << "There are currently no assigned hotel IDs (0 to exit)" << endl;
			else if(id < 1) cout << "IDs must be positive " << endl;
			else{
				
			}
		}while(id < 1);

		if(id > 0){
			rm.cancelReservation(id);
		}else if(id == 0) cout << "Exiting cancelling.";
		return false;
		break;

		case '3':

		// Display Details of a singular reservation based on user choice
		do{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ID of reservation (0 to exit): ";
			cin >> id;
			if(rm.getNoGuestsRequest() == 0) cout << "There are currently no assigned hotel IDs (0 to exit)" << endl;
			else if(id < 1) cout << "IDs must be positive." << endl;
		} while(id < 0);

		if(id > 0){
			rm.displayDetails(id);
		} else if(id == 0) cout << "Exiting display.";
		return false;
		break;

		case '4':
		// Display Details of All Reservations
		if(rm.getNoGuestsRequest() == 0){
			cout << "There are currently no reservations";
		}
		for(id = 1; id <= rm.getNoGuestsRequest(); id++){
			rm.displayDetails(id);
		}

		return false;
		break;

		case '5':
		// Show the reservation table
		rm.printResMan();
		return false;
		break;

		case '6':
		// Exit the Program
		cout << "Exiting..." << endl;
		return true;
		break;

		default:
		// Safety in Case user inputs invalid choice
		cout << "Invalid input" << endl;
		return false;
		break;
	}
}

