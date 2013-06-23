#ifndef __nutt_glue_h__
#define __nutt_glue_h__


extern void nutt_dbgmsg2(const char *s1, const char *s2);

#define DBGMSG2(a,b) nutt_dbgmsg2(a,b)

#endif //__nutt_glue_h__