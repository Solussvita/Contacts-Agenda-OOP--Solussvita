#pragma once
#include <string>

enum class name_error {
    NONE,
    MISSING_NAME,
    NAME_INVALID_CHAR,
    NAME_LENGTH_OUT_OF_RANGE,
    NAME_DASH_AT_EDGES,
    NAME_DOUBLE_DASH,
    NAME_DOUBLE_SPACE,
    NAME_APOSTROPHE_AT_EDGES
};

class name_validator {
    private:
      name_error last_name_error;
      const std::string _alpha;
      const std::string _chars;
    public:
      name_validator();

      bool name_verification(std::string name);
      name_error getLast_name_error() const;
};
