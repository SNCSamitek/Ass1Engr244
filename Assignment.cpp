#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu();

int main()
{
    displayMenu();
}

void displayMenu(){
    cout << "Select your choice: " << endl;
    cout << setw(2) << "1) Add a reservation." << endl;
    cout << setw(2) << "2) Cancel a reservation." << endl;
    cout << setw(2) << "3) Display information of a reservation." << endl;
    cout << setw(2) << "4) Check if the bathroom is empty." << endl;
}
