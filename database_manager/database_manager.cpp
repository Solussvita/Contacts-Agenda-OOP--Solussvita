#include "database_manager.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

database_manager::database_manager() : last_database_error(database_error::NONE), filename("database.txt") {}

void database_manager::save_database(std::vector<Contact>& contacts) {
    std::ofstream file(filename);
  
    if (!file) { //is_open() only checks if the file was opened, !symbolic_name checks if the stream is safe to use
      last_database_error = database_error::FILE_CANNOT_OPEN;
      return;
    } else {
      last_database_error = database_error::NONE;
      for (size_t it = 0; it < contacts.size(); it++) {
      file << contacts[it].getName() << "_" << contacts[it].getEmail() << "_" << std::to_string(contacts[it].getAge()) << "_" << std::to_string(contacts[it].getId()) << "\n";
    }
  }
}     

void database_manager::read_database(std::vector<Contact>& contacts) {
  std::ifstream file(filename);
  if (!fs::exists(filename)) {
    last_database_error = database_error::FILE_NOT_FOUND;
    return;
  }
    if (!file) { //is_open() only checks if the file was opened, !symbolic_name checks if the stream is safe to use
     last_database_error = database_error::FILE_CANNOT_OPEN;
     return;
    }
    last_database_error = database_error::NONE;
    std::string line;
    std::string name, email, age_str, id_str;
    while (std::getline(file, line)) { //take a line from the file (until '\n')
      std::stringstream ss(line);
      Contact new_contact;

      std::getline(ss, name, '_');
      std::getline(ss, email, '_');
      std::getline(ss, age_str, '_');
      std::getline(ss, id_str, '_');

      new_contact.setName(name);
      new_contact.setEmail(email);
      new_contact.setAge(age_str);
      new_contact.setId(id_str);

      contacts.push_back(new_contact);
    }
  }