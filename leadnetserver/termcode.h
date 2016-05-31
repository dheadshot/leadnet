#ifndef __TERMCODE_H__
#define __TERMCODE_H__ 1

#define FUNC_LEN 2

char Get_1PsCSI(unsigned long times, char endchar);
char Get_2PsCSI(unsigned long times1, unsigned long times2, char endchar);
char Get_1PsCSISel(unsigned long times, char endchar);
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


#endif
