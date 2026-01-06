#pragma once
#include <string>

enum class mail_error {
    NONE,

    MISSING_MAIL,
    MISSING_AT,
    MISSING_DOT,
    MISSING_DOMAIN_OR_EXTENSION,
    MISSING_EXTENSION,

    LOCAL_INVALID_CHAR,
    LOCAL_DOUBLE_DOT,
    LOCAL_DOT_AT_EDGES,
    LOCAL_LENGTH_OUT_OF_RANGE,

    DOMAIN_INVALID_CHAR,
    DOMAIN_DOUBLE_DOT,
    DOMAIN_DOUBLE_DASH,
    DOMAIN_DASH_AT_EDGES,
    DOMAIN_LENGTH_OUT_OF_RANGE,

    EXT_INVALID_CHAR,
    EXT_DOT_AT_END,
    EXT_DOUBLE_DOT,
    EXT_LABEL_OUT_OF_RANGE
};

class email_validator {
    private:
      mail_error last_mail_error;
      const std::string _alpha;
      const std::string _numbers;
      const std::string _chars;
      
    public:

      email_validator();

      bool basics_verification(std::string basics); //@ and . finding function
      bool local_verification(std::string local);
      bool domain_verification(std::string domain);
      bool extension_verification(std::string ext);
      
      bool email_verification(std::string mail); //setEmail's inside verification: object "E-validator"
      mail_error getLast_mail_error() const;
};


     










