#pragma once
#include "../validators/email_validator/email_validator.h"
#include "../validators/name_validator/name_validator.h"
#include "../validators/id_validator/id_validator.h"
#include "../validators/age_validator/age_validator.h"
#include <string>

class error_translator {
    public:
        std::string strEmail_last_error(mail_error error) const;
        std::string strName_last_error(name_error error) const;
        std::string strID_last_error(id_error error) const;
        std::string strAge_last_error(age_error error) const;
};

