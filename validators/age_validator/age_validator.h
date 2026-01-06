#pragma once
#include <string>

enum class age_error {
    NONE,
    AGE_INVALID_CHAR,
    AGE_OUT_OF_RANGE
};

class age_validator {
    private:
      age_error last_age_error;
    public:
      
      age_validator();

      bool age_verification(std::string age);
      age_error getLast_age_error() const;
};
