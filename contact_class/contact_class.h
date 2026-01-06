#pragma once
#include <string>

class name_validator;
class email_validator;
class age_validator;
class id_validator;

class Contact {
    private:
      name_validator* name_valid;
      email_validator* email_valid;
      age_validator* age_valid;
      id_validator* id_valid;
      std::string name;
      std::string email;
      int age;
      int id;
    public:
        Contact();
        bool setName(std::string& name);
        bool setEmail(std::string& email);
        bool setAge(std::string& age);
        bool setId(std::string& id);

        std::string getName() const;
        std::string getEmail() const;
        int getAge() const;
        int getId() const;

};