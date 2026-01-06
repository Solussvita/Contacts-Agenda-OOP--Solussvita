#include <iostream>
#include <string>
#include "contact_class/contact_class.h"
#include "database_manager/database_manager.h"
#include "validators/age_validator/age_validator.h"
#include "validators/email_validator/email_validator.h"
#include "validators/id_validator/id_validator.h"
#include "validators/name_validator/name_validator.h"

int main() {
    database_manager dbManager;
    email_validator emailValidator;
    Contact newContact;
    std::string email;

    do {
        //ejecutar agenda_app para correr
        std::cout << "Enter email:" << std::endl;
        std::getline(std::cin, email);

        if (!newContact.setEmail(email)) {
            std::cout << "Invalid email. Error code: ";
        }


    } while (!newContact.setEmail(email));


    return 0;
}