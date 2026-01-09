#include <iostream>
#include <string>
#include "../contact_class/contact_class.h"
#include "../database_manager/database_manager.h"
#include "../error_translator/error_translator.h"

int main() {
    database_manager dbManager;
    error_translator translator;
    email_validator emailValidator;
    Contact newContact;
    std::string email;
    bool isValid = false;

    do {
        //ejecutar agenda_app para correr
        std::cout << "Enter email:" << std::endl;
        std::getline(std::cin, email);
        if (email == "exit") {
            return 0;
        }
        if (newContact.setEmail(email)) {
            isValid = true;
            break;
        }
        std::cout << "invalid email: "<< translator.strEmail_last_error(newContact.show_last_email_error()) << std::endl; 
        std::cout << "Invalid email. Please try again or type 'exit' to quit." << std::endl;
    } while (!isValid);
    std::cout << "Final email set: " << newContact.getEmail() << std::endl;
    return 0;
}