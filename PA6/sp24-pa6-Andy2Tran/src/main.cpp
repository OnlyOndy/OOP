// Title  : main.cpp
// Desc   : Testing
// Name   : An Tran

#include "Address.h"
#include "Pet.h"
#include "Person.h"
#include <iostream>
    using std::cout;
    using std::cin;
    using std::getline;
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <limits>

void clearScreen() {
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system("clear"); // Assuming UNIX-based system
    #endif
}

int main() {
    std::vector<Person> people;
    int choice;

    do {
        clearScreen();
        cout << "Veterinary Clinic Management System\n"
                  << std::setfill('-') << std::setw(35) << std::setfill(' ') << '\n'
                  << "1. Enter a new person\n"
                  << "2. Enter a new pet for a person\n"
                  << "3. Delete a pet\n"
                  << "4. List all people and pets\n"
                  << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1: {
                // Add a new person
                std::string fName, lName;
                std::string street, city, state; // to create address
                size_t zipCode;

                // Prompt for first name
                std::cout << "Enter first name: ";
                getline(cin, fName);

                // Prompt for last name
                std::cout << "Enter last name: ";
                getline(cin, lName);

                // Prompt for address details
                std::cout << "Enter street: ";
                getline(cin, street);

                std::cout << "Enter city: ";
                getline(cin, city);

                std::cout << "Enter state: ";
                getline(cin, state);

                std::cout << "Enter zip code: ";
                cin >> zipCode;
                cin.ignore(); // Ignore newline character

                Address address(street, city, state, zipCode);

                Person person(fName, lName, address);
                
                people.push_back(person);
                break;
            }
            case 2: {
                // Add a new pet to an existing person
                std::string fName, lName;
                cout << "Enter the first name of the person: ";
                getline(cin, fName);
                cout << "Enter the last name of the person: ";
                getline(cin, lName);

                auto it = std::find_if(people.begin(), people.end(), [&](Person& person) {
                    return person.getFName() == fName && person.getLName() == lName;
                });

                if (it != people.end()) {
                    cout << "Enter details for the new pet:\n";
                    try {
                        it->addPet();
                    } catch (const std::runtime_error& e) {
                        cout << e.what() << std::endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    }
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 3: {
                // Delete a pet
                std::string fName, lName, petName;
                cout << "Enter the first name of the person: ";
                getline(cin, fName);
                cout << "Enter the last name of the person: ";
                getline(cin, lName);

                auto it = std::find_if(people.begin(), people.end(), [&](Person& person) {
                    return person.getFName() == fName && person.getLName() == lName;
                });

                if (it != people.end()) {
                    cout << "Enter the name of the pet to delete: ";
                    getline(cin, petName);
                    try {
                        it->deletePet(petName);
                    } catch (const std::runtime_error& e) {
                        cout << e.what() << std::endl;
                    }
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 4: {
                // List all people and their pets
                for (auto& person : people) {
                    cout << person << "\n";
                }
                break;
            }
            case 5: {
                // Exit
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

        cout << "Press Enter to continue...";
        cin.get(); // Pause the program until the user presses enter

    } while (choice != 5);

    return 0;
}



