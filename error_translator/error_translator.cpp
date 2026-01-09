#include "error_translator.h"
#include <string>

    std::string error_translator::strEmail_last_error(mail_error error) const{
        switch (error) {
                //EMAIL ERRORS 
            case mail_error::MISSING_MAIL:  //BASICS          
                return "the email is empty";  
            case mail_error::MISSING_AT:                 
                return "there's no at in the string";
            case mail_error::MISSING_DOT:
                return "there's no dot in the text";
            case mail_error::MISSING_DOMAIN_OR_EXTENSION:
                return "the email just has the local-part";
            case mail_error::MISSING_EXTENSION:
                return "there's no extension in the string";
            case mail_error::LOCAL_INVALID_CHAR: //LOCAL
                return "invalid character(s) in the local-part";
            case mail_error::LOCAL_DOUBLE_DOT:
                return "the local-part contains double dots";
            case mail_error::LOCAL_DOT_AT_EDGES:
                return "the local-part starts or ends with a dot";
            case mail_error::LOCAL_LENGTH_OUT_OF_RANGE:
                return "the local-part is out of range (1-64 chars)";
            case mail_error::DOMAIN_INVALID_CHAR: //DOMAIN
                return "invalid character(s) in the domain";
            case mail_error::DOMAIN_DOUBLE_DOT:
                return "the domain contains double dots";
            case mail_error::DOMAIN_DOUBLE_DASH:
                return "the domain contains double dashes";
            case mail_error::DOMAIN_DASH_AT_EDGES:
                return "the domain starts or ends with a dash";
            case mail_error::DOMAIN_LENGTH_OUT_OF_RANGE:
                return "the domain is out of range (1-63 chars)";
            case mail_error::EXT_INVALID_CHAR: //EXTENSION (LABELS)
                return "invalid character(s) in the extension";
            case mail_error::EXT_DOT_AT_END:
                return "the extension ends with a dot";
            case mail_error::EXT_DOUBLE_DOT:
                return "the extension contains double dots";
            case mail_error::EXT_LABEL_OUT_OF_RANGE:
                return "the extension label is out of range (1-63 chars)";
            default:
                return "no error";
        }
    }
