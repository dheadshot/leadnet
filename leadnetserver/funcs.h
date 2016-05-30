#ifndef __FUNCS_H__

#define __FUNCS_H__ 1

int streq(char *astr, char *bstr);
void strltrim(char *outstring, char *instring);
void strrtrim(char *astring);
void strtrim(char *outstring, char *instring);
void strleft(char *outstring, char *instring, long islength);
void strtoupper(char *outstring, char *instring);
long getmax(long l1, long l2);
long getmin(long l1, long l2);
void strnlrtrim(char *astring);
int startsame(char *astr, char *bstr);

#endif
