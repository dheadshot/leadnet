#include <stdlib.h>
#include <stdio.h>

#include "terms.h"

#include "termcode.h"

char ind_s[] = {ESC, ESC_IND, 0};
char nel_s[] = {ESC, ESC_NEL, 0};
char hts_s[] = {ESC, ESC_HTS, 0};
char ri_s[]  = {ESC, ESC_RI,  0};
char ss2_s[] = {ESC, ESC_SS2, 0};
char ss3_s[] = {ESC, ESC_SS3, 0};
char dcs_s[] = {ESC, ESC_DCS, 0};
char spa_s[] = {ESC, ESC_SPA, 0};
char epa_s[] = {ESC, ESC_EPA, 0};
char sos_s[] = {ESC, ESC_SOS, 0};
char decid_s[] = {ESC, ESC_DECID, 0};
char csi_s[] = {ESC, ESC_CSI, 0};
char st_s[]  = {ESC, ESC_ST,  0};
char osc_s[] = {ESC, ESC_OSC, 0};
char pm_s[]  = {ESC, ESC_PM,  0};
char apc_s[] = {ESC, ESC_APC, 0};

char S7C1T_s[] = {ESC, SPA, 'F', 0};
char S8C1T_s[] = {ESC, SPA, 'G', 0};
char ANSI1_s[] = {ESC, SPA, 'L', 0};
char ANSI2_s[] = {ESC, SPA, 'M', 0};
char ANSI3_s[] = {ESC, SPA, 'N', 0};
char DHL_top_s[] = {ESC, '#', '3', 0};
char DHL_bottom_s[] = {ESC, '#', '4', 0};
char SWL_s[] = {ESC, '#', '5', 0};
char DWL_s[] = {ESC, '#', '6', 0};
char SALN_s[] = {ESC, '#', '8', 0};
char DefCharSet_s = {ESC, '%', '@', 0};
char UTF8CharSet_s = {ESC, '%', 'G', 0};
char CharSetG0_100_St_s = {ESC, '(', 0};
char CharSetG1_100_St_s = {ESC, ')', 0};
char CharSetG2_100_St_s = {ESC, '*', 0};
char CharSetG3_100_St_s = {ESC, '+', 0};
char CharSetG1_300_St_s = {ESC, '-', 0};
char CharSetG2_300_St_s = {ESC, '.', 0};
char CharSetG3_300_St_s = {ESC, '/', 0};
char BI_420_s = {ESC, '6', 0};
char DECSC_s = {ESC, '7', 0};
char DECRC_s = {ESC, '8', 0};
char FI_420_s = {ESC, '9', 0};
char AppKeypad_s = {ESC, '=', 0};
char DefKeypad_s = {ESC, '>', 0};
char MovBottomLeft_s = {ESC, 'F', 0};
char RIS_s = {ESC, 'c', 0};
char MemLock_s = {ESC, 'l', 0};
char MemUnlock_s = {ESC, 'm', 0};
char LS2_s = {ESC, 'n', 0};
char LS3_s = {ESC, 'o', 0};
char LS3R_s = {ESC, '|', 0};
char LS2R_s = {ESC, '}', 0};
char LS1R_s = {ESC, '~', 0};


char Get_1PsCSI(unsigned long times, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 2) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s%ul%c",csi_s, times, endchar);
  return rets;
}

char Get_2PsCSI(unsigned long times1, unsigned long times2, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 8 + 3) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s%ul;%ul%c",csi_s, times1, times2, endchar);
  return rets;
}

char Get_1PsCSISel(unsigned long times, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 3) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s?%ul%c",csi_s, times, endchar);
  return rets;
}

char Get_ICH(unsigned long times)
{
  return Get_1PsCSI(times, '@');
}

char Get_CUU(unsigned long times)
{
  return Get_1PsCSI(times, 'A');
}

char Get_CUD(unsigned long times)
{
  return Get_1PsCSI(times, 'B');
}

char Get_CUF(unsigned long times)
{
  return Get_1PsCSI(times, 'C');
}

char Get_CUB(unsigned long times)
{
  return Get_1PsCSI(times, 'D');
}

char Get_CNL(unsigned long times)
{
  return Get_1PsCSI(times, 'E');
}

char Get_CPL(unsigned long times)
{
  return Get_1PsCSI(times, 'F');
}

char Get_CHA(unsigned long column)
{
  return Get_1PsCSI(column, 'G');
}

char Get_CUP(unsigned long column, unsigned long row)
{
  return Get_2PsCSI(row, column, 'H');
}

char Get_CHT(unsigned long stops)
{
  return Get_1PsCSI(stops, 'I');
}

char Get_ED_Below()
{
  return Get_1PsCSI(0,'J');
}

char Get_ED_Above()
{
  return Get_1PsCSI(1,'J');
}

char Get_ED_All()
{
  return Get_1PsCSI(2,'J');
}

char Get_ED_Saved()
{
  return Get_1PsCSI(3,'J');
}

char Get_SED_Below()
{
  return Get_1PsCSISel(0,'J');
}

char Get_SED_Above()
{
  return Get_1PsCSISel(1,'J');
}

char Get_SED_All()
{
  return Get_1PsCSISel(2,'J');
}

char Get_EL_Below()
{
  return Get_1PsCSI(0,'K');
}

char Get_EL_Above()
{
  return Get_1PsCSI(1,'K');
}

char Get_EL_All()
{
  return Get_1PsCSI(2,'K');
}

char Get_SEL_Below()
{
  return Get_1PsCSISel(0,'K');
}

char Get_SEL_Above()
{
  return Get_1PsCSISel(1,'K');
}

char Get_SEL_All()
{
  return Get_1PsCSISel(2,'K');
}

char Get_IL(unsigned long times)
{
  return Get_1PsCSI(times, 'L');
}

char Get_DL(unsigned long times)
{
  return Get_1PsCSI(times, 'M');
}

char Get_DCH(unsigned long times)
{
  return Get_1PsCSI(times, 'P');
}
