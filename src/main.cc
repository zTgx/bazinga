#include <iostream>
#include <gmssl/sm3.h>
#include <iterator>
#include <sstream>  // std::ostringstream
#include "utils.h"
#include <cstring> // std::memcmp
#include <cassert> // assert
#include "hex.h"

int main() {
    // use gmssl shard lib
    uint8_t dgst[SM3_DIGEST_SIZE];

    std::string src = "abc";
    const uint8_t* data = reinterpret_cast<const uint8_t*>(&src[0]);
    const uint8_t datalen = src.size();

    sm3_digest(data, datalen, dgst);

    uint8_t buffer[sizeof(dgst)*2 + 1];
    bytes2hex(dgst, buffer, sizeof(dgst));
    printf("%s\n",buffer);

    const uint8_t* expected = reinterpret_cast<const uint8_t*>("66c7f0f462eeedd9d1f2d46bdc10e4e24167c4875cf2f7a2297da02b8f4ba8e0");
    printf("%s\n",expected);

    const bool result = std::memcmp(buffer, expected, sizeof(buffer));
    std::cout << "compare result : " << result << std::endl;

    assert(result == 0);

    std::cout << "sm3 equal." << std::endl;
}