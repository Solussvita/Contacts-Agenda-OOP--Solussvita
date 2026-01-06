#pragma once
#include <string>
#include <vector>
#include "../contact_class/contact_class.h"

enum class database_error {
    NONE,
    FILE_NOT_FOUND,
    FILE_CANNOT_OPEN
};

class database_manager {
    private:
      database_error last_database_error;
      std::string filename;
    public:
      database_manager();
      void save_database(std::vector<Contact>& contacts);
      void read_database(std::vector<Contact>& contacts );
};

