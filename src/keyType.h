#pragma once

#include <string>

enum class KeyType {
    secp256k1 = 0,
    ed25519 = 1,
    sm2p256v1 = 2,
};

inline char const*
to_string(KeyType type)
{
    if (type == KeyType::secp256k1)
        return "secp256k1";

    if (type == KeyType::ed25519)
        return "ed25519";

    if (type == KeyType::sm2p256v1)
        return "sm2p256v1";

    return "INVALID";
}

template <class Stream>
inline Stream&
operator<<(Stream& s, KeyType type)
{
    return s << to_string(type);
}