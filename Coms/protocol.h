
#ifndef __PROTOCOL__H__
#define __PROTOCOL__H__

#include <cstdint>
#include <cstring>
#include <iostream>

using namespace std;

enum class command : uint8_t {
   ERROR = 0, EXIT, GET, HELP, LS, PUT, RM, FILE, LSOUT, ACK, NAK,
};
size_t constexpr FILENAME_SIZE = 59;
struct header {
   uint32_t nbytes {0};
   command com {command::ERROR};
   char filename[FILENAME_SIZE] {};
};


