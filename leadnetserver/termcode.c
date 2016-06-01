#include <stdlib.h>
#include <stdio.h>

#include "terms.h"
#include "funcs.h"

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

/* Key codes */
char PC_CUp_N_s = {ESC, ESC_CSI, 'A', 0};
char PC_CUp_A_s = {ESC, ESC_SS3, 'A', 0};
char PC_CDn_N_s = {ESC, ESC_CSI, 'B', 0};
char PC_CDn_A_s = {ESC, ESC_SS3, 'B', 0};
char PC_CRt_N_s = {ESC, ESC_CSI, 'C', 0};
char PC_CRt_A_s = {ESC, ESC_SS3, 'C', 0};
char PC_CLt_N_s = {ESC, ESC_CSI, 'D', 0};
char PC_CLt_A_s = {ESC, ESC_SS3, 'D', 0};
char PC_Home_N_s = {ESC, ESC_CSI, 'H', 0};
char PC_Home_A_s = {ESC, ESC_SS3, 'H', 0};
char PC_End_N_s = {ESC, ESC_CSI, 'F', 0};
char PC_End_A_s = {ESC, ESC_SS3, 'F', 0};
char PC_NSpa_A_s = {ESC, ESC_SS3, SPA, 0};
char PC_NHTa_A_s = {ESC, ESC_SS3, 'I', 0};
char PC_NCR_A_s = {ESC, ESC_SS3, 'M', 0};
char PC_PF1_s = {ESC, ESC_SS3, 'P', 0};
char PC_PF2_s = {ESC, ESC_SS3, 'Q', 0};
char PC_PF3_s = {ESC, ESC_SS3, 'R', 0};
char PC_PF4_s = {ESC, ESC_SS3, 'S', 0};
char PC_NMul_A_s = {ESC, ESC_SS3, 'j', 0};
char PC_NAdd_A_s = {ESC, ESC_SS3, 'k', 0};
char PC_NCom_A_s = {ESC, ESC_SS3, 'l', 0};
char PC_NSub_A_s = {ESC, ESC_SS3, 'm', 0};
char PC_NDel_A_s = {ESC, ESC_CSI, '3', '~', 0};
char PC_NDiv_A_s = {ESC, ESC_SS3, 'o', 0};
char PC_NIns_A_s = {ESC, ESC_CSI, '2', '~', 0};
char PC_NEnd_A_s = {ESC, ESC_SS3, 'F', 0};
char PC_NCDn_A_s = {ESC, ESC_CSI, 'B', 0};
char PC_NPDn_A_s = {ESC, ESC_CSI, '6', '~', 0};
char PC_NCLt_A_s = {ESC, ESC_CSI, 'D', 0};
char PC_N5_A_s = {ESC, ESC_CSI, 'E', 0};
char PC_NCRt_A_s = {ESC, ESC_CSI, 'C', 0};
char PC_NHome_A_s = {ESC, ESC_SS3, 'H', 0};
char PC_NCUp_A_s = {ESC, ESC_CSI, 'A', 0};
char PC_NPUp_A_s = {ESC, ESC_CSI, '5', '~', 0};
char PC_NEq_A_s = {ESC, ESC_SS3, 'X', 0};
char PC_DF1_s = {ESC, ESC_CSI, '1', '1', '~', 0};
char PC_DF2_s = {ESC, ESC_CSI, '1', '2', '~', 0};
char PC_DF3_s = {ESC, ESC_CSI, '1', '3', '~', 0};
char PC_DF4_s = {ESC, ESC_CSI, '1', '4', '~', 0};
char PC_DF5_s = {ESC, ESC_CSI, '1', '5', '~', 0};
char PC_F6_s = {ESC, ESC_CSI, '1', '7', '~', 0};
char PC_F7_s = {ESC, ESC_CSI, '1', '8', '~', 0};
char PC_F8_s = {ESC, ESC_CSI, '1', '9', '~', 0};
char PC_F9_s = {ESC, ESC_CSI, '2', '0', '~', 0};
char PC_F10_s = {ESC, ESC_CSI, '2', '1', '~', 0};
char PC_F11_s = {ESC, ESC_CSI, '2', '3', '~', 0};
char PC_F12_s = {ESC, ESC_CSI, '2', '4', '~', 0};
char VT220_F13_s = {ESC, ESC_CSI, '2', '5', '~', 0};
char VT220_F14_s = {ESC, ESC_CSI, '2', '6', '~', 0};
char VT220_F15_s = {ESC, ESC_CSI, '2', '8', '~', 0};
char VT220_F16_s = {ESC, ESC_CSI, '2', '9', '~', 0};
char VT220_F17_s = {ESC, ESC_CSI, '3', '1', '~', 0};
char VT220_F18_s = {ESC, ESC_CSI, '3', '2', '~', 0};
char VT220_F19_s = {ESC, ESC_CSI, '3', '3', '~', 0};
char VT220_F20_s = {ESC, ESC_CSI, '3', '4', '~', 0};
char PCXR6_F13_s = {ESC, ESC_CSI, '1', '1', ';', '2', '~', 0};
char PCXR6_F14_s = {ESC, ESC_CSI, '1', '2', ';', '2', '~', 0};
char PCXR6_F15_s = {ESC, ESC_CSI, '1', '3', ';', '2', '~', 0};
char PCXR6_F16_s = {ESC, ESC_CSI, '1', '4', ';', '2', '~', 0};
char PCX_F17_s = {ESC, ESC_CSI, '1', '5', ';', '2', '~', 0};
char PCX_F18_s = {ESC, ESC_CSI, '1', '7', ';', '2', '~', 0};
char PCX_F19_s = {ESC, ESC_CSI, '1', '8', ';', '2', '~', 0};
char PCX_F20_s = {ESC, ESC_CSI, '1', '9', ';', '2', '~', 0};
char PCX_F21_s = {ESC, ESC_CSI, '2', '0', ';', '2', '~', 0};
char PCX_F22_s = {ESC, ESC_CSI, '2', '1', ';', '2', '~', 0};
char PCX_F23_s = {ESC, ESC_CSI, '2', '3', ';', '2', '~', 0};
char PCX_F24_s = {ESC, ESC_CSI, '2', '4', ';', '2', '~', 0};
char PCXR6_F25_s = {ESC, ESC_CSI, '1', '1', ';', '5', '~', 0};
char PCXR6_F26_s = {ESC, ESC_CSI, '1', '2', ';', '5', '~', 0};
char PCXR6_F27_s = {ESC, ESC_CSI, '1', '3', ';', '5', '~', 0};
char PCXR6_F28_s = {ESC, ESC_CSI, '1', '4', ';', '5', '~', 0};
char PCX_F29_s = {ESC, ESC_CSI, '1', '5', ';', '5', '~', 0};
char PCX_F30_s = {ESC, ESC_CSI, '1', '7', ';', '5', '~', 0};
char PCX_F31_s = {ESC, ESC_CSI, '1', '8', ';', '5', '~', 0};
char PCX_F32_s = {ESC, ESC_CSI, '1', '9', ';', '5', '~', 0};
char PCX_F33_s = {ESC, ESC_CSI, '2', '0', ';', '5', '~', 0};
char PCX_F34_s = {ESC, ESC_CSI, '2', '1', ';', '5', '~', 0};
char PCX_F35_s = {ESC, ESC_CSI, '2', '3', ';', '5', '~', 0};
char PCX_F36_s = {ESC, ESC_CSI, '2', '4', ';', '5', '~', 0};
char PCXR6_F37_s = {ESC, ESC_CSI, '1', '1', ';', '6', '~', 0};
char PCXR6_F38_s = {ESC, ESC_CSI, '1', '2', ';', '6', '~', 0};
char PCXR6_F39_s = {ESC, ESC_CSI, '1', '3', ';', '6', '~', 0};
char PCXR6_F40_s = {ESC, ESC_CSI, '1', '4', ';', '6', '~', 0};
char PCX_F41_s = {ESC, ESC_CSI, '1', '5', ';', '6', '~', 0};
char PCX_F42_s = {ESC, ESC_CSI, '1', '7', ';', '6', '~', 0};
char PCX_F43_s = {ESC, ESC_CSI, '1', '8', ';', '6', '~', 0};
char PCX_F44_s = {ESC, ESC_CSI, '1', '9', ';', '6', '~', 0};
char PCX_F45_s = {ESC, ESC_CSI, '2', '0', ';', '6', '~', 0};
char PCX_F46_s = {ESC, ESC_CSI, '2', '1', ';', '6', '~', 0};
char PCX_F47_s = {ESC, ESC_CSI, '2', '3', ';', '6', '~', 0};
char PCX_F48_s = {ESC, ESC_CSI, '2', '4', ';', '6', '~', 0};
char PCXF86_F13_s = {ESC, ESC_SS3, '2', 'P', 0};
char PCXF86_F14_s = {ESC, ESC_SS3, '2', 'Q', 0};
char PCXF86_F15_s = {ESC, ESC_SS3, '2', 'R', 0};
char PCXF86_F16_s = {ESC, ESC_SS3, '2', 'S', 0};
char PCXF86_F25_s = {ESC, ESC_SS3, '5', 'P', 0};
char PCXF86_F26_s = {ESC, ESC_SS3, '5', 'Q', 0};
char PCXF86_F27_s = {ESC, ESC_SS3, '5', 'R', 0};
char PCXF86_F28_s = {ESC, ESC_SS3, '5', 'S', 0};
char PCXF86_F37_s = {ESC, ESC_SS3, '6', 'P', 0};
char PCXF86_F38_s = {ESC, ESC_SS3, '6', 'Q', 0};
char PCXF86_F39_s = {ESC, ESC_SS3, '6', 'R', 0};
char PCXF86_F40_s = {ESC, ESC_SS3, '6', 'S', 0};
char PCR_F13_s = {ESC, ESC_CSI, '2', '5', '~', 0};
char PCR_F14_s = {ESC, ESC_CSI, '2', '6', '~', 0};
char PCR_F15_s = {ESC, ESC_CSI, '2', '8', '~', 0};
char PCR_F16_s = {ESC, ESC_CSI, '2', '9', '~', 0};
char PCR_F17_s = {ESC, ESC_CSI, '3', '1', '~', 0};
char PCR_F18_s = {ESC, ESC_CSI, '3', '2', '~', 0};
char PCR_F19_s = {ESC, ESC_CSI, '3', '3', '~', 0};
char PCR_F20_s = {ESC, ESC_CSI, '3', '4', '~', 0};
char PCR_F21_s = {ESC, ESC_CSI, '2', '3', '$', 0};
char PCR_F22_s = {ESC, ESC_CSI, '2', '4', '$', 0};
char PCR_F23_s = {ESC, ESC_CSI, '1', '1', '^', 0};
char PCR_F24_s = {ESC, ESC_CSI, '1', '2', '^', 0};
char PCR_F25_s = {ESC, ESC_CSI, '1', '3', '^', 0};
char PCR_F26_s = {ESC, ESC_CSI, '1', '4', '^', 0};
char PCR_F27_s = {ESC, ESC_CSI, '1', '5', '^', 0};
char PCR_F28_s = {ESC, ESC_CSI, '1', '7', '^', 0};
char PCR_F29_s = {ESC, ESC_CSI, '1', '8', '^', 0};
char PCR_F30_s = {ESC, ESC_CSI, '1', '9', '^', 0};
char PCR_F31_s = {ESC, ESC_CSI, '2', '0', '^', 0};
char PCR_F32_s = {ESC, ESC_CSI, '2', '1', '^', 0};
char PCR_F33_s = {ESC, ESC_CSI, '2', '3', '^', 0};
char PCR_F34_s = {ESC, ESC_CSI, '2', '4', '^', 0};
char PCR_F35_s = {ESC, ESC_CSI, '2', '5', '^', 0};
char PCR_F36_s = {ESC, ESC_CSI, '2', '6', '^', 0};
char PCR_F37_s = {ESC, ESC_CSI, '2', '8', '^', 0};
char PCR_F38_s = {ESC, ESC_CSI, '2', '9', '^', 0};
char PCR_F39_s = {ESC, ESC_CSI, '3', '1', '^', 0};
char PCR_F40_s = {ESC, ESC_CSI, '3', '2', '^', 0};
char PCR_F41_s = {ESC, ESC_CSI, '3', '3', '^', 0};
char PCR_F42_s = {ESC, ESC_CSI, '3', '4', '^', 0};
char PCR_F43_s = {ESC, ESC_CSI, '2', '3', '@', 0};
char PCR_F44_s = {ESC, ESC_CSI, '2', '3', '@', 0};


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

char Get_3PsCSI(unsigned long times1, unsigned long times2, 
unsigned long times3, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 8 + 8 + 4) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s%ul;%ul;%ul%c",csi_s, times1, times2, times3, endchar);
  return rets;
}

char Get_1PsCSISel(unsigned long times, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 3) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s?%ul%c",csi_s, times, endchar);
  return rets;
}

char Get_3PsCSIGra(unsigned long times1, unsigned long times2, unsigned long times3, char endchar)
{
  char *rets = (char *) malloc((FUNCLEN + 8 + 8 + 8 + 5) * sizeof(char));
  if (rets == NULL) return NULL;
  sprintf(rets, "%s?%ul;%ul;%ul%c",csi_s, times1, times2, times3, endchar);
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

char Get_SU(unsigned long lines)
{
  return Get_1PsCSI(lines, 'S');
}

char Get_SetGraphics(unsigned long item, unsigned long action, unsigned long value)
{
  return Get_3PsCSIGra(item, action, value, 'S');
}

char Get_SD(unsigned long lines)
{
  return Get_1PsCSI(lines, 'T');
}

char Get_ECH(unsigned long chars)
{
  return Get_1PsCSI(chars, 'X');
}

char Get_CBT(unsigned long stops)
{
  return Get_1PsCSI(stops, 'Z');
}
