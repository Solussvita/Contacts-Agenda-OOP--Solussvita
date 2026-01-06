#include "age_validator.h"
#include <cctype>


age_validator::age_validator() : last_age_error(age_error::NONE) {}

bool age_validator::age_verification(std::string st_age) {
    for (char n : st_age) {
        if (!isdigit(n)) {
            last_age_error = age_error::AGE_INVALID_CHAR;
            return false;
        }
   }
    int int_age = std::stoi(st_age);
    if (int_age < 0 || int_age > 150 ) {
        last_age_error = age_error::AGE_OUT_OF_RANGE;
        return false;
    }
    last_age_error = age_error::NONE;
    return true;
}


age_error age_validator::getLast_age_error() const {
    return last_age_error;
}