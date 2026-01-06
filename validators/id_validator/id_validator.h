#pragma once
#include <string>
#include <cctype>

enum class id_error {
    NONE,
    ID_INVALID_CHAR,
    ID_OUT_OF_RANGE,
    MISSING_ID
};

class id_validator {
    private:
      id_error last_id_error;
    public:
      id_validator();
      bool id_verification(std::string id);
      id_error getLast_id_error() const;
};