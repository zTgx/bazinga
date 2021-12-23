#include <iostream>
#include <gmssl/sm3.h>
#include <iterator>
#include <sstream>  // std::ostringstream
#include "utils.h"

int main() {
    // use gmssl shard lib
    uint8_t dgst[SM3_DIGEST_SIZE];

    std::string src = "abc";
    const uint8_t* data = reinterpret_cast<const uint8_t*>(&src[0]);
    const uint8_t datalen = src.size();

    sm3_digest(data, datalen, dgst);

    // std::ostringstream ss;
    // std::copy(dgst, dgst+sizeof(dgst), std::ostream_iterator<int>(ss, ","));
    // std::cout << std::hex << ss.str() << std::endl;

    char buffer[sizeof(dgst)*2 + 1];
    bytes2hex(dgst, buffer, sizeof(dgst));
    printf("%s\n",buffer);
}