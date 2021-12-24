#include <iostream>
#include "sm.h"
#include "keyType.h"

int main() {
    sm3_algo();
    sm2_algo();

    KeyType keyType = KeyType::guomi;
    (void)keyType;
}