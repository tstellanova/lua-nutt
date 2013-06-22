
#include <string.h> /* strlen() strcpy() size_t */

size_t strxfrm(char *dest, const char *src, size_t n)
{
    /* This implementation does not know about any locale but "C"... */
    size_t n2=strlen(src);
    if(n>n2)
        strcpy(dest,src);
    return n2;
}

int strcoll(const char *s1, const char *s2)
{
    char t1[1 + strxfrm(0, s1, 0)];
    strxfrm(t1, s1, sizeof(t1));
    char t2[1 + strxfrm(0, s2, 0)];
    strxfrm(t2, s2, sizeof(t2));
    return strcmp(t1, t2);
}

