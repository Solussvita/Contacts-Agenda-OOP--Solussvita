#include "email_validator.h"
#include <cctype>
#include <sstream>
#include <vector>

email_validator::email_validator() : last_mail_error(mail_error::NONE),
     _alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"),
     _numbers("0123456789"),
     _chars("._") {}

bool email_validator::basics_verification(std::string basics) {
            if (basics.empty()) {
              last_mail_error = mail_error::MISSING_MAIL;
              return false;
            }
            if (basics.find('.') == std::string::npos) {
              last_mail_error = mail_error::MISSING_DOT;
              return false;
            }
              return true;
      }


bool email_validator::local_verification(std::string local) {
                      for (char k : local) {
                        if ((_alpha.find(k) == std::string::npos) &&
                            (_numbers.find(k) == std::string::npos) && 
                            (_chars.find(k) == std::string::npos)) {
                               last_mail_error = mail_error::LOCAL_INVALID_CHAR;
                               return false;
                       }
                      }
                        if ((local).find("..") != std::string::npos) {
                           last_mail_error = mail_error::LOCAL_DOUBLE_DOT;
                           return false;
                       }
                        if ( !(local.empty()) && (local.front() == '.' ||
                             local.back() == '.')) {
                              last_mail_error = mail_error::LOCAL_DOT_AT_EDGES;
                              return false;
                      }
                        if (local.length() >  64 || local.length() < 1) {
                           last_mail_error = mail_error::LOCAL_LENGTH_OUT_OF_RANGE;
                           return false;
                      }
                      return true;
    }
    

bool email_validator::domain_verification(std::string domain) {
                    for (char n : domain) {
                      if ((_alpha.find(n) == std::string::npos) && 
                          (_numbers.find(n) == std::string::npos) && 
                         !(n=='-')) {
                            last_mail_error = mail_error::DOMAIN_INVALID_CHAR;
                            return false;
                        }
                      }
                      if (domain.find("..") != std::string::npos) {
                           last_mail_error = mail_error::DOMAIN_DOUBLE_DOT;
                           return false;
                        }
                      if (domain.find("--") != std::string::npos) {
                           last_mail_error = mail_error::DOMAIN_DOUBLE_DASH;
                           return false;
                         }
                      if ((domain.front() == '-' || domain.back() == '-' )) {
                           last_mail_error = mail_error::DOMAIN_DASH_AT_EDGES;     
                           return false;
                     }
                      if (domain.size() > 63 || domain.size() < 1) {
                           last_mail_error = mail_error::DOMAIN_LENGTH_OUT_OF_RANGE;
                           return false;
                    }
                    return true;
    }


bool email_validator::extension_verification(std::string ext) {
                     std::vector<std::string> labels;
                     labels.clear();
                     std::string st_label = "";

                     if (ext.empty()) {
                      last_mail_error = mail_error::MISSING_EXTENSION;
                      return false;
                     }
                   for (char t : ext) {
                     if ((_alpha.find(t) == std::string::npos) && 
                         (_numbers.find(t) == std::string::npos) &&
                         !(t == '.')) {
                             last_mail_error = mail_error::EXT_INVALID_CHAR;
                             return false;
                    }
                   }
                     if (ext.find("..") != std::string::npos) {
                             last_mail_error = mail_error::EXT_DOUBLE_DOT;
                             return false;
                     }
                     if (ext.back() == '.') {
                             last_mail_error = mail_error::EXT_DOT_AT_END;
                             return false;
                     }

                     std::stringstream ss(ext);
                     while (std::getline(ss, st_label, '.')) {
                      labels.push_back(st_label);
                     }

                     for (size_t it = 0; it < labels.size(); it++) {
                      if (labels[it].length() < 2 || labels[it].length() > 63) {
                             last_mail_error = mail_error::EXT_LABEL_OUT_OF_RANGE;
                             return false;
                    }
                  }
                    return true;
} 


bool email_validator::email_verification(std::string st_email) {
       if (!basics_verification(st_email)) {
           return false;
      } 
       std::string local;
       std::string domain;
       std::string extension;

       const size_t at = st_email.find('@');
       const size_t dot = st_email.find('.', at + 1);

       if (at == std::string::npos) {
           last_mail_error = mail_error::MISSING_AT;
           return false;  
     } else if (dot == std::string::npos) {
           last_mail_error = mail_error::MISSING_EXTENSION;
     }

     local = st_email.substr(0, at);
     domain = st_email.substr(at + 1, dot - (at  + 1));
     extension = st_email.substr(dot);

      if (( local_verification(local) && domain_verification(domain) && extension_verification(extension)) == false) {
            return false;
          }
            last_mail_error = mail_error::NONE;
            return true;
}

  

mail_error email_validator::getLast_mail_error() const{
  return last_mail_error;
}