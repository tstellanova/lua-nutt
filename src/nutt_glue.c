
#include <string.h> /* strlen() strcpy() size_t */
#include <stdio.h>

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

void nutt_dbgmsg2(const char *s1, const char *s2)
{
	printf("%s : %s \n", s1,s2);
	fflush(stdout);
	// fprintf(stderr,"%s : %s\n", s1,s2);
	// fflush(stderr);
}

int nutt_exec_system(const char *aCmd)
{
	//TODO split into argv etc
	nutt_dbgmsg2("nutt_exec_system",aCmd);
	int ret = exec_builtin(aCmd, (FAR const char **)NULL, NULL, 0);

	return 0;
}
