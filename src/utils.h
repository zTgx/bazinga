char HexLookUp[] = "0123456789abcdef";    
void bytes2hex (unsigned char *src, char *out, int len)
{
    while(len--)
    {
        *out++ = HexLookUp[*src >> 4];
        *out++ = HexLookUp[*src & 0x0F];
        src++;
    }
    *out = 0;
}

