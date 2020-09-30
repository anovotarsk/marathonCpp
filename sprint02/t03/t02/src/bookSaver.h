#ifndef COUNTUNIQUEWORDS

#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <fstream>
#include <map>
#include <regex>

std::string* strsplit(std::string str, char del, int *len);
void addBook(std::multimap<std::string, std::string> &books);
void deleteBook(std::string *mas, int len, std::map<std::string, std::string> &books);
void readBook(std::string *mas, int len, std::map<std::string, std::string> &books);
void list(std::string *mas, int len, std::map<std::string, std::string> &books);
void bookSaver();

#endif
