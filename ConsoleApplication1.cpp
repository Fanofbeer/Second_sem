#include <iostream>

int main()
{
    unsigned char a, b, c, d, e;
    a = 29 & 102;
    printf("29 AND 102 = (4) = %i\n", a);
    c = 29 ^ -102;
    printf("29 XOR -102 = (135) = %i\n", c);
    d = 29 << 2;
    printf("29 << 2 = (116) = %i\n", d);
    e = (-29 ^ 102) & (~47 | -91);
    printf("(-29 XOR 102) AND (NOT 47 OR -91) = (133) = %i\n", e);
    return 0;

}
