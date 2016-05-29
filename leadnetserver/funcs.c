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
