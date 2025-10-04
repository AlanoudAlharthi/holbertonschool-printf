#include "main.h"

int main(void)
{
    _printf("%hd\n", (short)32000);         /* 32000 */
    _printf("%ld\n", 2147483648L);          /* 2147483648 */
    _printf("%lu\n", 4294967296UL);         /* 4294967296 */
    _printf("%hx\n", (unsigned short)255);  /* ff */
    return (0);
}
