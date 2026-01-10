#include "Application.h"
#include <iostream>
#include <string>
#include "../contact_class/contact_class.h"
#include "../database_manager/database_manager.h"
#include "../error_translator/error_translator.h"


int Application::run() {
    database_manager dbManager;
    error_translator translator;
    email_validator emailValidator;
    Contact newContact;
    std::string email, name, id, age;
    bool isValid = false;

    do {
        std::cout << "Enter email:" << std::endl;
        std::getline(std::cin, email);
        if (email == "exit") {
            return EXIT_SUCCESS;
        }
        if (newContact.setEmail(email)) {
            isValid = true;
            break;
        }
        
        std::cout << "invalid email: "<< translator.strEmail_last_error(newContact.show_last_email_error()) << std::endl;
        std::cout << "             name       @   gmail    .   com.ar \n"
                    << "            │─────│       │─────│       │──────│\n"
                    << "            local          domain         extension\n"
                    << "                                         com / ar = labels" << std::endl;
        std::cout << "Invalid email. Please try again or type 'exit' to quit." << std::endl;
        
    } while (!isValid);
    std::cout << "Final email set: " << newContact.getEmail() << std::endl;
    isValid = false;

    do {
        std::cout << "Enter name:" << std::endl;
        std::getline(std::cin, name);
        if (name == "exit") {
            return EXIT_SUCCESS;
        }
        if (newContact.setName(name)) {
            isValid = true;
            break;
        } 
        std::cout << "invalid name: "<< translator.strName_last_error(newContact.show_last_name_error()) << std::endl;
    } while (!isValid);
    std::cout << "Final name set: " << newContact.getName() << std::endl;
    isValid = false;

    do {
        std::cout << "Enter ID:" << std::endl;
        std::getline(std::cin, id);
        if (id == "exit") {
            return EXIT_SUCCESS;
        }
        if (newContact.setId(id)) {
            isValid = true;
            break;
        } 
        std::cout << "invalid ID: "<< translator.strID_last_error(newContact.show_last_id_error()) << std::endl;
    } while (!isValid);
    std::cout << "Final ID set: " << newContact.getId() << std::endl;
    isValid = false;

    do {
        std::cout << "Enter age:" << std::endl;
        std::getline(std::cin, age);
        if (age == "exit") {
            return EXIT_SUCCESS;
        }
        if (newContact.setAge(age)) {
            isValid = true;
            break;
        } 
        std::cout << "invalid age: "<< translator.strAge_last_error(newContact.show_last_age_error()) << std::endl;
    } while (!isValid);
    std::cout << "Final age set: " << newContact.getAge() << std::endl;

    return EXIT_SUCCESS;
}