#pragma once

#include <string>

enum class KeyType {
    secp256k1 = 0,
    ed25519 = 1,
    guomi = 2,
};

inline char const*
to_string(KeyType type)
{
    if (type == KeyType::secp256k1)
        return "secp256k1";

    if (type == KeyType::ed25519)
        return "ed25519";

    if (type == KeyType::guomi)
        return "guomi";

    return "INVALID";
}

template <class Stream>
inline Stream&
operator<<(Stream& s, KeyType type)
{
    return s << to_string(type);
}