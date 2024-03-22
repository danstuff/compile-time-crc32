#include "ct_crc32.h"

#define TEST_MESSAGE "this message is a test message!"

uint32_t crc32(const void *buf, size_t size)
{
	const uint8_t *p = buf;
	uint32_t crc;

	crc = ~0U;
	while (size--)
		crc = CT_CRC32_TABLE[(crc ^ *p++) & 0xFF] ^ (crc >> 8);
	return crc ^ ~0U;
}

int main(void)
{
    const uint32_t ct_hash = CT_CRC32(TEST_MESSAGE, 8);
    const uint32_t rt_hash = crc32(TEST_MESSAGE, 8);
    printf("%x == %x\n", ct_hash, rt_hash);
    return ct_hash != rt_hash;
}
