/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/kcv/Class_Work/CPE690/hw2/q1/pr_encoder/pr_encoder.vhd";



static void work_a_0814139655_3990940387_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    int64 t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB7;

LAB8:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB9;

LAB10:
LAB3:    t1 = (t0 + 3144);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(34, ng0);
    t5 = (5 * 1000LL);
    t1 = (t0 + 4996);
    t7 = (t0 + 3224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_delta(t7, 0U, 2U, t5);
    t12 = (t0 + 3224);
    xsi_driver_intertial_reject(t12, t5, t5);
    goto LAB3;

LAB5:    xsi_set_current_line(36, ng0);
    t5 = (5 * 1000LL);
    t1 = (t0 + 4998);
    t7 = (t0 + 3224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_delta(t7, 0U, 2U, t5);
    t12 = (t0 + 3224);
    xsi_driver_intertial_reject(t12, t5, t5);
    goto LAB3;

LAB7:    xsi_set_current_line(38, ng0);
    t5 = (5 * 1000LL);
    t1 = (t0 + 5000);
    t7 = (t0 + 3224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_delta(t7, 0U, 2U, t5);
    t12 = (t0 + 3224);
    xsi_driver_intertial_reject(t12, t5, t5);
    goto LAB3;

LAB9:    xsi_set_current_line(40, ng0);
    t5 = (5 * 1000LL);
    t1 = (t0 + 5002);
    t7 = (t0 + 3224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_delta(t7, 0U, 2U, t5);
    t12 = (t0 + 3224);
    xsi_driver_intertial_reject(t12, t5, t5);
    goto LAB3;

}


extern void work_a_0814139655_3990940387_init()
{
	static char *pe[] = {(void *)work_a_0814139655_3990940387_p_0};
	xsi_register_didat("work_a_0814139655_3990940387", "isim/pr_encoder_tb_isim_beh.exe.sim/work/a_0814139655_3990940387.didat");
	xsi_register_executes(pe);
}
