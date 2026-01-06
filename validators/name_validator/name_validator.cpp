#include "name_validator.h"
#include <cctype>
#include <sstream>

  name_validator::name_validator() : last_name_error(name_error::NONE),
       _alpha("abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ"),
       _chars("-' ") {}

  bool name_validator::name_verification(std::string st_name) {
      if (st_name.empty()) {
          last_name_error = name_error::MISSING_NAME;
          return false;
      }
      for (char k : st_name) {
        if ((_alpha.find(k) == std::string::npos) && 
            (_chars.find(k) == std::string::npos)) {
               last_name_error = name_error::NAME_INVALID_CHAR;
               return false;
          }
      }
      if (st_name.length() < 2 || st_name.length() > 50) {
          last_name_error = name_error::NAME_LENGTH_OUT_OF_RANGE;
          return false;
      }
      if (st_name.front() == '-' || st_name.back() == '-') {
          last_name_error = name_error::NAME_DASH_AT_EDGES;
          return false;
      }
      if (st_name.find("--") != std::string::npos) {
          last_name_error = name_error::NAME_DOUBLE_DASH;
          return false;
      }
      if (st_name.find("  ") != std::string::npos) {
          last_name_error = name_error::NAME_DOUBLE_SPACE;
          return false;
      }
      if (st_name.front() == '\'' || st_name.back() == '\'') {
          last_name_error = name_error::NAME_APOSTROPHE_AT_EDGES;
          return false;
      }
      last_name_error = name_error::NONE;
      return true;

  }

  name_error name_validator::getLast_name_error() const {
      return last_name_error;
  }