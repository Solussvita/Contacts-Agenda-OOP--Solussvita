#include "contact_class.h"
#include <algorithm>
#include "../validators/age_validator/age_validator.h"
#include "../validators/email_validator/email_validator.h"
#include "../validators/id_validator/id_validator.h"
#include "../validators/name_validator/name_validator.h"

Contact::Contact() : name(""), email(""), age(0), id(0) {
    name_valid = new name_validator();
    email_valid = new email_validator();
    age_valid = new age_validator();
    id_valid = new id_validator();
}

bool Contact::setName(std::string& name) {
  if (name_valid->name_verification(name)) {
    this -> name = name;
    return true;
  }
  return false;
}

bool Contact::setEmail(std::string& email) {
  if (email_valid->email_verification(email)) { //transform doesn't return a value, it modifies the string in place
    std::transform(email.begin(), email.end(), email.begin(), [](unsigned char c){ return std::tolower(c); });
    this -> email = email; //that's why we assign the new email here
    return true;
  }
  return false;
}

bool Contact::setAge(std::string& age) {
    if (age_valid->age_verification(age)) {
        this -> age = std::stoi(age);
        return true;
    }
    return false;
}

bool Contact::setId(std::string& id) {
    if (id_valid->id_verification(id)) {
        this -> id = std::stoi(id);
        return true;
    }
    return false;
}

std::string Contact::getName() const { return name; }

std::string Contact::getEmail() const { return email; }

int Contact::getAge() const { return age; }

int Contact::getId() const { return id; }