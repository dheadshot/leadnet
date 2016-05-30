#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int streq(char *astr, char *bstr)
{
  long alen, blen;
  if (astr == NULL || bstr == NULL) return 0;
  alen = strlen(astr);
  blen = strlen(bstr);
  if (alen != blen) return 0;
  if (memcmp(astr, bstr, alen)==0) return 1;
  return 0;
}

void strltrim(char *outstring, char *instring)
{
  char *isptr;
  isptr = instring;
  while (isptr[0] == ' ') isptr++;
  strcpy(outstring,isptr);
}

void strrtrim(char *astring)
{
  long i = strlen(astring) - 1;
  if (i<0) return;
  while ((astring[i]==' ') && (i>=0)) i--;
  i++;
  astring[i] = 0;
}

void strtrim(char *outstring, char *instring)
{
  strltrim(outstring, instring);
  strrtrim(outstring);
}

void strleft(char *outstring, char *instring, long islength)
{
  long i;
  for (i=0;i<islength;i++) outstring[i] = instring[i];
  outstring[islength] = 0;
}

void strtoupper(char *outstring, char *instring)
{
  long i = 0;
  while (instring[i] != 0)
  {
    outstring[i] = toupper(instring[i]);
    i++;
  }
  outstring[i] = 0;
}

long getmax(long l1, long l2)
{
  return ((l1>l2)?l1:l2);
}

long getmin(long l1, long l2)
{
  return ((l1<l2)?l1:l2);
}

void strnlrtrim(char *astring)
{
  long i = strlen(astring) - 1;
  if (i<0) return;
  while (((astring[i] == '\r') || (string[i] == '\n')) && (i >= 0)) i--;
  i++;
  astring[i] = 0;
}

int startsame(char *astr, char *bstr)
{
  long minlen = getmin(strlen(astr), strlen(bstr));
  if (memcmp(str1,str2,minlen) == 0) return 1;
  return 0;
}
