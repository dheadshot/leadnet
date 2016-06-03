#ifndef __TERMCODE_H__
#define __TERMCODE_H__ 1

#define FUNC_LEN 2

char Get_1PsCSI(unsigned long times, char endchar);
char Get_2PsCSI(unsigned long times1, unsigned long times2, char endchar);
char Get_3PsCSI(unsigned long times1, unsigned long times2, unsigned long times3, char endchar);
char Get_1PsCSISel(unsigned long times, char endchar);
char Get_3PsCSIGra(unsigned long times1, unsigned long times2, unsigned long times3, char endchar);
char Get_ICH(unsigned long times);
char Get_CUU(unsigned long times);
char Get_CUD(unsigned long times);
char Get_CUF(unsigned long times);
char Get_CUB(unsigned long times);
char Get_CNL(unsigned long times);
char Get_CPL(unsigned long times);
char Get_CHA(unsigned long column);
char Get_CUP(unsigned long column, unsigned long row);
char Get_CHT(unsigned long stops);
char Get_ED_Below();
char Get_ED_Above();
char Get_ED_All();
char Get_ED_Saved();
char Get_SED_Below();
char Get_SED_Above();
char Get_SED_All();
char Get_EL_Below();
char Get_EL_Above();
char Get_EL_All();
char Get_SEL_Below();
char Get_SEL_Above();
char Get_SEL_All();
char Get_IL(unsigned long times);
char Get_DL(unsigned long times);
char Get_DCH(unsigned long times);
char Get_SU(unsigned long lines);
char Get_SetGraphics(unsigned long item, unsigned long action, unsigned long value);
char Get_SD(unsigned long lines)
char Get_ECH(unsigned long chars)
char Get_CBT(unsigned long stops)

char Get_VT52_Cmd(char ACmd);
char Get_VT52_Move_Cursor(unsigned long X, unsigned long Y);
char Get_VT52_CUU();
char Get_VT52_CUD();
char Get_VT52_CUF();
char Get_VT52_CUB();
char Get_VT52_GMS();
char Get_VT52_GME();
char Get_VT52_CUH();
char Get_VT52_RLF();
char Get_VT52_ED_Below();
char Get_VT52_EL_Below();
char Get_VT52_DECID();
char Get_VT52_App();
char Get_VT52_Num();
char Get_VT52_VT100();

#endif
