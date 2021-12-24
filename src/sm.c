#include <gmssl/sm2.h>
#include <gmssl/sm3.h>
#include <gmssl/sm4.h>

#include "utils.h"
#include <string.h>

int sm3_algo() {
    // use gmssl shard lib
    uint8_t dgst[SM3_DIGEST_SIZE];

    const uint8_t* data = "abc";
    const uint8_t datalen = strlen(data);

    sm3_digest(data, datalen, dgst);

    uint8_t buffer[sizeof(dgst)*2 + 1];
    bytes2hex(dgst, buffer, sizeof(dgst));
    printf("%s\n",buffer);

    const char* expected = "66c7f0f462eeedd9d1f2d46bdc10e4e24167c4875cf2f7a2297da02b8f4ba8e0";
    printf("%s\n",expected);

    const int result = memcmp(buffer, expected, sizeof(buffer));
    printf("compare result : %d", result);

    // assert(result == 0);

    return 0;
}

int sm2_algo() {
	SM2_KEY key;
	SM2_SIGN_CTX ctx;
	uint8_t msg[] = "Hello World!";
	uint8_t sig[128] = {0};
	size_t siglen = sizeof(sig);
	int i;
	int r;

	sm2_keygen(&key);
	sm2_key_print(stdout, &key, 0, 0);

	sm2_sign_init(&ctx, &key, SM2_DEFAULT_ID);
	sm2_sign_update(&ctx, msg, sizeof(msg));
	sm2_sign_finish(&ctx, sig, &siglen);

	printf("signature:\n");
	sm2_print_signature(stdout, sig, siglen, 0, 2);

	sm2_verify_init(&ctx, &key, SM2_DEFAULT_ID);
	sm2_verify_update(&ctx, msg, sizeof(msg));
	r = sm2_verify_finish(&ctx, sig, siglen);
	printf("verify %s\n", r > 0 ? "success" : "failed");

	return 0;
}