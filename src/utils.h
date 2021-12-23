uint8_t HexLookUp[] = "0123456789abcdef";    
void bytes2hex (uint8_t *src, uint8_t *out, int len)
{
    while(len--)
    {
        *out++ = HexLookUp[*src >> 4];
        *out++ = HexLookUp[*src & 0x0F];
        src++;
    }
    *out = 0;
}

