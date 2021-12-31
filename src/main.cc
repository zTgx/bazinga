#include <iostream>
#include "keyType.h"

#include <gmssl/sm3.h>
#include <gmssl/sm2.h>
#include <gmssl/sm4.h>
#include "utils.h"
#include <string.h>
#include <cassert>

int sm2_algo() {
    std::cout << "sm2 algorigthm: " << std::endl;
	
    SM2_KEY key;
	SM2_SIGN_CTX ctx;
	uint8_t msg[] = "Hello World!";
	uint8_t sig[128] = {0};
	size_t siglen = sizeof(sig);

	sm2_keygen(&key);
	sm2_key_print(stdout, &key, 0, 0);

    int r = 0;

    bool usingDefaultType = 1;
    if (usingDefaultType) {
        r = sm2_sign(&key, msg, sig, &siglen);

        printf("signature:\n");
        sm2_print_signature(stdout, sig, siglen, 0, 2);
    } else {
        sm2_sign_init(&ctx, &key, SM2_DEFAULT_ID);

        uint8_t hello[] = "Hello ";
        uint8_t world[] = "World!";
        sm2_sign_update(&ctx, hello, sizeof(hello));
        sm2_sign_update(&ctx, world, sizeof(world));

        sm2_sign_finish(&ctx, sig, &siglen);

        printf("signature:\n");
        sm2_print_signature(stdout, sig, siglen, 0, 2);

        sm2_verify_init(&ctx, &key, SM2_DEFAULT_ID);
        sm2_verify_update(&ctx, hello, sizeof(hello));
        sm2_verify_update(&ctx, world, sizeof(world));

        r = sm2_verify_finish(&ctx, sig, siglen);
    }

	printf("verify %s\n", r > 0 ? "success" : "failed");

	return 0;
}

int sm3_algo() {
    std::cout << "sm3 algorigthm: " << std::endl;

    uint8_t dgst[SM3_DIGEST_SIZE];

    std::string data{"abc"};
    const uint8_t datalen = data.size();

    sm3_digest(reinterpret_cast<const uint8_t*>(&data[0]), datalen, dgst);

    uint8_t buffer[sizeof(dgst)*2 + 1];
    bytes2hex(dgst, buffer, sizeof(dgst));
    printf("%s\n",buffer);

    const char* expected = "66c7f0f462eeedd9d1f2d46bdc10e4e24167c4875cf2f7a2297da02b8f4ba8e0";

    const int result = memcmp(buffer, expected, sizeof(buffer));
    std::cout << "compare result : " << result << std::endl;

    assert(result == 0);

    return 0;
}

int main() {
    sm2_algo();

    std::cout << "###############################################################" << std::endl;

    sm3_algo();

    KeyType keyType = KeyType::sm2p256v1;
    (void)keyType;
}