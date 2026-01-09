#pragma once
#include "../validators/email_validator/email_validator.h"
#include <string>

class error_translator {
    public:
        std::string strEmail_last_error(mail_error error) const;
};

