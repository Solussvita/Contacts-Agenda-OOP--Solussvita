#include "error_translator.h"
#include <string>

std::string error_translator::strEmail_last_error(mail_error error) const{
        switch (error) {
                //EMAIL ERRORS 
            case mail_error::MISSING_MAIL:  //BASICS          
                return "the email is empty";  
            case mail_error::MISSING_AT:                 
                return "there's no at in the text";
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
                return "no error in the e-mail";
        }
    }

std::string error_translator::strName_last_error(name_error error) const {
        switch (error) {
            case name_error::MISSING_NAME:
                return "the name is empty";
            case name_error::NAME_INVALID_CHAR:
                return "the name contains invalid character(s)";
            case name_error::NAME_LENGTH_OUT_OF_RANGE:
                return "the name is out of range (2-50 chars)";
            case name_error::NAME_DASH_AT_EDGES:
                return "the name starts or ends with a dash";
            case name_error::NAME_DOUBLE_DASH:
                return "the name contains double dashes";
            case name_error::NAME_DOUBLE_SPACE:
                return "the name contains double spaces";
            case name_error::NAME_APOSTROPHE_AT_EDGES:
                return "the name starts or ends with an apostrophe";
            default:
                return "no error in the name";
        }
    }

std::string error_translator::strID_last_error(id_error error) const {
        switch (error) {
            case id_error::ID_INVALID_CHAR:
                return "invalid character(s) in the ID";
            case id_error::ID_OUT_OF_RANGE:
                return "the ID is out of range (7-8 digits)";
            case id_error::MISSING_ID:
                return "the ID is empty";
            default:
                return "no error in the ID";
        }
}

std::string error_translator::strAge_last_error(age_error error) const {
        switch (error) {
            case age_error::AGE_INVALID_CHAR:
                return "invalid character(s) in the age";
            case age_error::AGE_OUT_OF_RANGE:
                return "the age is out of range (0-150)";
            default:
                return "no error in the age";
        }
}