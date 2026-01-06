#include "id_validator.h"
#include <cctype>

id_validator::id_validator() : last_id_error(id_error::NONE) {}

bool id_validator::id_verification(std::string st_id) {
    if (st_id.empty()) {
        last_id_error = id_error::MISSING_ID;
        return false;
    }
    for (char n : st_id) {
        if (!isdigit(n)) {
            last_id_error = id_error::ID_INVALID_CHAR;
            return false;
        }
   }
    if ( st_id.length() < 7 || st_id.length() > 8 ) {
        last_id_error = id_error::ID_OUT_OF_RANGE;
        return false;
    }
    return true;
}

id_error id_validator::getLast_id_error() const {
  return last_id_error;
}