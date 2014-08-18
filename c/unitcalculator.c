#include <stdio.h>
main()
{
    char i[12], j[2] = {0xff}, *k[8] = {"m", "in", "yd", "apc", "kg", "lb", "oz", "hhdBe"};
    float value, m[32] = {1.f, 39.37f, 1.094f, 32.41f, 2.54e-2f, 1.f, 2.778e-2f, 8.232e-1f, 9.144e-1f, 36.f, 1.f, 2.963e1f, 3.086e-2f,  1.215f, 3.375e-2f, 1.f, 1.f, 2.205f, 3.527e1f, 2.269e-3f, 0.454f, 1.f, 16.f, 1.029e-3f, 2.835e-2f, 6.25e-2f, 1.f, 6.433e-5f, 440.7f, 9.7158e+2f, 15545.f, 1.f};
    scanf("%f %s to %s", &value, i, i + 6);
    for(j[0] = 0; j[0] < 8; j[0]++)
    {
        if(*i == *k[j[0]])
            j[1] |= j[0] & 0xf;
        if(i[6] == *k[j[0]])
            j[1] += j[0] << 4;
    }
    if((j[1] ^ (j[1] >> 4)) & 4)
    {
        printf("%f %s can't be converted to %s\n", value, k[j[1] & 0xf], k[(j[1] & 0xf0) >> 4]);
    }
    else
    {
        printf("%f %s is ", value, k[j[1] & 0xf]);
        value *= m[((j[1] & 0x3) << 2) + ((j[1] & 0x30) >> 4) + 16];
        printf("%f %s\n", value, k[(j[1] & 0xf0) >> 4]);
    }
}
