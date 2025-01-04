//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_withPIC.h
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.323
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:58:07 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_withPIC_h_
#define RTW_HEADER_motion_controller_withPIC_h_
#include <cstring>
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_withPIC_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtGetNaN.h"
#include "rtGetInf.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S8>/Current Time'
struct B_CurrentTime_motion_controll_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S8>/Current Time'
};

// Block states (default storage) for system '<S8>/Current Time'
struct DW_CurrentTime_motion_control_T {
  ros_slros2_internal_block_Cur_T obj; // '<S8>/Current Time'
  boolean_T objisempty;                // '<S8>/Current Time'
};

// Block signals (default storage)
struct B_motion_controller_withPIC_T {
  real_T Qp[14400];
  sT1ziU4p6vTWuD880X9yNJ_motion_T WorkingSet;
  real_T W_m[9600];                    // '<S48>/predict'
  s2uO2c2bmaUl7sY5vOWIzHG_motio_T QRManager;
  sFlCINAYeIgPgx0UwEHpaMF_motio_T memspace;
  real_T B[6601];
  s8kZFjDlzP6eNfOekUiP5MF_motio_T CholRegManager;
  real_T y_mb[4800];
  real_T b_y[4800];
  real_T H_e[4800];                    // '<S48>/predict'
  real_T rtb_H_e_c[4800];
  real_T rtb_H_e_k[4800];
  real_T Qp_c[3600];
  real_T y_b[3200];
  sVIU4VBONGRsUytHTQmMJFH_motio_T WorkingSet_p;
  sVIU4VBONGRsUytHTQmMJFH_motio_T b_workingset;
  sTy13TWZ7KObOACj8wDaLQC_motio_T CholRegManager_c;
  real_T W[2400];                      // '<S49>/predict'
  sIZAIOglGM5dPDQlNukc9SD_motio_T QRManager_f;
  s3cSGkBdKxRj6Qn3zsJRowG_motio_T memspace_g;
  real_T B_g[1701];
  real_T Rp[1600];
  real_T rtb_H_e_m[1600];
  real_T y_n[1200];
  real_T b_y_p[1200];
  real_T H[1200];                      // '<S49>/predict'
  real_T rtb_H_l[1200];
  real_T rtb_H_j[1200];
  real_T y_d[800];
  real_T G_e[720];                     // '<S48>/predict'
  real_T Rp_g[400];
  real_T rtb_H_ld[400];
  real_T G[360];                       // '<S49>/predict'
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S59>/In1'
  SL_Bus_custom_interfaces_ActuatorState In1_j;// '<S22>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  s5cJJO9CAPQxuVG0iaeiP4F_motio_T solution;
  real_T rtb_H_e_d[240];
  int8_T K[1600];
  real_T work[161];
  real_T vn1[161];
  real_T vn2[161];
  real_T work_d[161];
  sYqpSPVJXu9aOn60zG4DpzD_motio_T solution_l;
  real_T rtb_H_o[120];
  SL_Bus_nav_msgs_Odometry In1_je;     // '<S20>/In1'
  SL_Bus_nav_msgs_Odometry b_varargout_2_b;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S8>/Bus Assignment1' 
  sKnhLiTH4yv7eF1oV2a74RG_motio_T QPObjective;
  real_T work_n[81];
  real_T vn1_b[81];
  real_T vn2_l[81];
  real_T work_h[81];
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S27>/Bus Assignment1' 
  real_T T_c[80];                      // '<S48>/predict'
  real_T rtb_T_b[80];
  real_T b_b[60];
  SL_Bus_sensor_msgs_Imu In1_f;        // '<S21>/In1'
  SL_Bus_sensor_msgs_Imu b_varargout_2_d;
  int8_T K_e[400];
  s3PrFoa9w5ssw8XLEJooNqH_motio_T QPObjective_b;
  real_T work_j[41];
  real_T V[40];
  real_T T[40];                        // '<S49>/predict'
  real_T b_K[40];
  real_T rtb_H_e_f[40];
  real_T rtb_Gain1_c_a[40];
  real_T b_value_j[40];
  real_T t[36];
  real_T Q[36];                        // '<S10>/MATLAB Function'
  real_T A1[36];                       // '<S10>/update'
  real_T t_j[36];
  SL_Bus_sbus_interface_Sbus In1_m;    // '<S58>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_o;
  real_T c_t[24];
  real_T rtb_A1_n[24];
  real_T work_i[21];
  real_T V_o[20];
  real_T b_K_n[20];
  real_T c_K[20];
  real_T rtb_H_m[20];
  real_T rtb_Gain1_cz[20];
  real_T b_value_m[20];
  sSOeZ9WO10chPn9Si6PKiCB_motio_T options;
  sSOeZ9WO10chPn9Si6PKiCB_motio_T options_m;
  real_T ImpAsg_InsertedFor_Out1_a_k[16];
  real_T B1[12];                       // '<S10>/update'
  real_T rtb_A1_j[12];
  real_T B0[8];
  SL_Bus_geometry_msgs_Twist BusAssignment2;// '<S4>/Bus Assignment2'
  real_T y_h[6];                       // '<S10>/MATLAB Function2'
  real_T Reshape[6];                   // '<S10>/Reshape'
  real_T Merge[4];                     // '<S46>/Merge'
  real_T R[4];                         // '<S10>/MATLAB Function'
  real_T gama[4];                      // '<S10>/update'
  real_T rtb_Add_c[4];
  sL9bDKomAYkxZSVrG9w6En_motion_T expl_temp;
  int8_T b_I[16];
  real_T Ay;                           // '<S10>/update'
  real_T out;                          // '<S33>/Chart2'
  real_T GetParameter1;                // '<S9>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S9>/Chart'
  real_T spd_cmd[4];                   // '<S9>/Chart'
  real_T effort_cmd[4];                // '<S9>/Chart'
  real_T y;                            // '<S5>/Chart'
  real_T yaw;                          // '<S5>/Chart'
  real_T effort;
  real_T y_m;
  real_T b_value;
  real_T b_value_c;
  real_T b_value_k;
  real_T b_value_cx;
  real_T d;
  real_T b_value_ct;
  real_T b_value_p;
  real_T b_value_p5;
  real_T b_value_a;
  real_T b_value_e;
  real_T b_value_ax;
  real_T b_value_as;
  real_T b_value_i;
  real_T b_value_l;
  real_T b_value_o;
  real_T b_value_o2;
  real_T b_value_ip;
  real_T b_value_f;
  real_T b_value_iz;
  real_T Fy2;
  real_T Fy3;
  real_T Fy4;
  real_T e_a;
  real_T f_a;
  real_T k_a;
  real_T n_a;
  real_T s_a;
  real_T bb_a;
  real_T hb_a;
  real_T lb_a;
  real_T rb_a;
  real_T yb_a;
  real_T ec_a;
  real_T hc_a;
  real_T mc_a;
  real_T rc_a;
  real_T wc_a;
  real_T ed_a;
  real_T jd_a;
  real_T pd_a;
  real_T td_a;
  real_T ae_a;
  real_T ie_a;
  real_T ne_a;
  real_T qe_a;
  real_T ve_a;
  real_T df_a;
  real_T ef_a;
  real_T ff_a;
  real_T gf_a;
  real_T hf_a;
  real_T if_a;
  real_T jf_a;
  real_T kf_a;
  real_T lf_a;
  real_T b_value_ff;
  real_T b_value_g;
  real_T yp;                           // '<S5>/MATLAB Function'
  real_T df_j;                         // '<Root>/MATLAB Function'
  real_T dr_i;                         // '<Root>/MATLAB Function'
  real_T A0_tmp;
  real_T A0_tmp_c;
  real_T A0_tmp_o;
  real_T rtb_Add_im;
  real_T rtb_Add_re;
  real_T rtb_Add_im_l;
  real_T rtb_Add_re_m;
  real_T rtb_Add_im_m;
  real_T rtb_Add_re_c;
  real_T rtb_Add_im_f;
  real_T rtb_Add_re_p;
  real_T rtb_Add_im_e;
  real_T rtb_Add_re_o;
  real_T rtb_Add_im_h;
  real_T rtb_Add_re_l;
  real_T rtb_Add_im_h2;
  real_T rtb_Add_re_me;
  real_T rtb_Add_im_mc;
  real_T rtb_Add_im_h3;
  real_T rtb_Add_re_cs;
  real_T rtb_Add_im_k;
  real_T rtb_Add_re_pc;
  real_T rtb_Add_im_p;
  real_T rtb_Add_re_p4;
  real_T rtb_Add_im_a;
  real_T rtb_Add_re_j;
  real_T rtb_Add_im_ek;
  real_T rtb_Add_re_ol;
  real_T rtb_Add_im_b;
  real_T rtb_Add_re_a;
  real_T rtb_Add_im_g;
  real_T rtb_Add_re_e;
  real_T rtb_Add_im_fi;
  real_T rtb_Add_re_h;
  real_T rtb_Add_im_ei;
  real_T rtb_Add_re_ch;
  real_T rtb_Add_im_ax;
  real_T rtb_Add_re_d;
  real_T rtb_Add_im_af;
  real_T rtb_Add_re_pb;
  real_T rtb_Add_im_ms;
  real_T rtb_Add_im_o;
  real_T rtb_Add_re_n;
  real_T rtb_Add_im_lu;
  real_T rtb_Add_re_pe;
  real_T rtb_Add_im_pt;
  real_T rtb_Add_re_f;
  real_T rtb_Add_im_i;
  real_T rtb_Add_re_ox;
  real_T rtb_Add_im_kk;
  real_T rtb_Add_re_i;
  real_T rtb_Add_im_oc;
  real_T rtb_Add_re_m4;
  real_T rtb_Add_im_c;
  real_T rtb_Add_re_fb;
  real_T rtb_Add_im_hc;
  real_T rtb_Add_im_m4;
  real_T rtb_Add_re_ad;
  real_T rtb_Add_im_kb;
  real_T rtb_Add_re_pcr;
  real_T rtb_Add_im_bp;
  real_T rtb_Add_re_chp;
  real_T rtb_Add_im_n;
  real_T rtb_Add_re_ij;
  real_T rtb_Add_im_my;
  real_T rtb_Add_re_jg;
  real_T rtb_Add_im_ev;
  real_T rtb_Add_re_mv;
  real_T rtb_Add_im_m0;
  real_T rtb_Add_re_jgs;
  real_T rtb_Add_im_fo;
  real_T rtb_Add_im_a5;
  real_T rtb_Add_re_g;
  real_T rtb_Add_im_nr;
  real_T rtb_Add_re_d3;
  real_T rtb_Add_im_na;
  real_T rtb_Add_re_cg;
  real_T rtb_Add_im_fx;
  real_T rtb_Add_re_pm;
  real_T rtb_Add_im_p2;
  real_T rtb_Add_re_nj;
  real_T rtb_Add_im_kt;
  real_T rtb_Add_re_n3;
  real_T rtb_Add_im_oy;
  real_T rtb_Add_re_gg;
  real_T rtb_Add_im_cq;
  real_T rtb_Add_im_cj;
  real_T rtb_Add_re_m1;
  real_T rtb_Add_im_j;
  real_T rtb_Add_re_k;
  real_T rtb_Add_im_mx;
  real_T rtb_Add_re_pr;
  real_T rtb_Add_im_d;
  real_T rtb_Add_re_g4;
  real_T rtb_Add_im_c3;
  real_T rtb_Add_re_cx;
  real_T rtb_Add_im_if;
  real_T rtb_Add_re_dx;
  real_T rtb_Add_im_g4;
  real_T rtb_Add_re_lg;
  real_T rtb_Add_im_f1;
  real_T rtb_Add_im_db;
  real_T rtb_Add_re_jr;
  real_T rtb_Add_im_i3;
  real_T rtb_Add_re_h2;
  real_T rtb_Add_im_nm;
  real_T rtb_Add_re_o3;
  real_T rtb_Add_im_ch;
  real_T rtb_Add_re_b;
  real_T rtb_Add_im_er;
  real_T rtb_Add_re_dd;
  real_T rtb_Add_im_ik;
  real_T rtb_Add_im_gs;
  real_T rtb_Add_re_nn;
  real_T rtb_Add_im_l0;
  real_T rtb_Add_re_ce;
  real_T rtb_Add_im_nc;
  real_T rtb_Add_re_ph;
  real_T rtb_Add_im_dk;
  real_T rtb_Add_re_oi;
  real_T rtb_Add_im_jr;
  real_T rtb_Add_re_c2;
  real_T rtb_Add_im_hp;
  real_T rtb_Add_im_da;
  real_T rtb_Add_re_c5;
  real_T rtb_Add_im_pw;
  real_T rtb_Add_re_pi;
  real_T rtb_Add_im_a4;
  real_T rtb_Add_re_ow;
  real_T rtb_Add_im_jw;
  real_T rtb_Add_re_pie;
  real_T rtb_Add_im_ob;
  real_T rtb_Add_re_lm;
  real_T rtb_Add_im_kv;
  real_T rtb_Add_im_jk;
  real_T rtb_Add_re_fz;
  real_T rtb_Add_im_cm;
  real_T rtb_Add_re_fq;
  real_T rtb_Add_im_nl;
  real_T rtb_Add_re_iu;
  real_T rtb_Add_im_l4;
  real_T rtb_Add_re_i3;
  real_T rtb_Add_im_k1;
  real_T rtb_Add_re_fc;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_a;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_d;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_e;
  real_T rtb_ImpAsg_InsertedFor_Out1__eh;
  real_T A0_tmp_tmp;
  real_T A0_tmp_tmp_b;
  real_T e_a_tmp;
  real_T n_a_tmp;
  real_T q_a_tmp;
  real_T n_a_tmp_a;
  real_T o_a_tmp;
  real_T i_a_tmp;
  real_T Fy1_tmp;
  real_T Fy1_tmp_tmp;
  real_T Fy1_tmp_tmp_i;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_f;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_j;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_o;
  real_T rtb_ImpAsg_InsertedFor_Out1__fr;
  real_T rtb_ImpAsg_InsertedFor_Out1__oy;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_l;
  real_T rtb_ImpAsg_InsertedFor_Out1__lu;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_g;
  real_T e_a_tmp_d;
  real_T rtb_Add_tmp_tmp_tmp;
  real_T b_value_tmp;
  real_T rtb_Add_re_tmp;
  real_T rtb_Add_re_tmp_d;
  real_T rtb_Add_re_tmp_j;
  real_T rtb_Add_re_tmp_f;
  real_T rtb_Add_re_tmp_js;
  real_T rtb_Add_re_tmp_h;
  real_T rtb_Add_re_tmp_c;
  real_T rtb_Add_re_tmp_n;
  real_T rtb_Add_re_tmp_k;
  real_T rtb_ImpAsg_InsertedFor_Out1__av;
  real_T rtb_ImpAsg_InsertedFor_Out1__fn;
  real_T rtb_ImpAsg_InsertedFor_Out1__jz;
  real_T rtb_ImpAsg_InsertedFor_Out1__kl;
  real_T i_a_tmp_tmp_tmp;
  real_T rtb_Add_tmp_tmp;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_b;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_h;
  real_T rtb_ImpAsg_InsertedFor_Out1__eg;
  real_T rtb_ImpAsg_InsertedFor_Out1__hn;
  real_T rtb_ImpAsg_InsertedFor_Out1__ku;
  real_T rtb_ImpAsg_InsertedFor_Out1__jw;
  real_T rtb_ImpAsg_InsertedFor_Out1__oo;
  real_T rtb_ImpAsg_InsertedFor_Out1_a_c;
  real_T exitflag;
  real_T colSum;
  real_T f_infnrm;
  real_T b_colSum;
  real_T maxConstr_new;
  real_T d_h;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T temp2;
  real_T temp;
  real_T s;
  real_T b_atmp;
  real_T tau;
  real_T xnorm;
  real_T a;
  real_T scale;
  real_T absxk;
  real_T t_i;
  real_T exitflag_p;
  real_T colSum_f;
  real_T f_infnrm_e;
  real_T b_colSum_n;
  real_T maxConstr_new_h;
  real_T constrViolation_h;
  real_T tol_f;
  real_T temp2_i;
  real_T temp_f;
  real_T s_c;
  real_T b_atmp_n;
  real_T tau_h;
  real_T xnorm_k;
  real_T a_h;
  real_T scale_b;
  real_T absxk_o;
  real_T t_n;
  real_T tolDelta;
  real_T normDelta;
  real_T s_m;
  real_T temp_k;
  real_T temp_tmp;
  real_T tempMaxConstr;
  real_T c;
  real_T d_v;
  real_T u1;
  real_T b_c;
  real_T tolDelta_j;
  real_T normDelta_h;
  real_T s_f;
  real_T temp_d;
  real_T temp_tmp_l;
  real_T c_k;
  real_T d_v_i;
  real_T u1_h;
  real_T b_c_m;
  real_T smax;
  real_T s_g;
  real_T temp_l;
  real_T alpha1;
  real_T temp_m;
  real_T smax_n;
  real_T s_gv;
  real_T temp_dj;
  real_T alpha1_m;
  real_T temp_ft;
  real_T p_max;
  real_T denomTol;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T b_c_g;
  real_T workspace;
  real_T c_j;
  real_T c_c;
  real_T b_s;
  real_T b_temp;
  real_T b_temp_tmp;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_c;
  real_T ads;
  real_T bds;
  real_T p_max_e;
  real_T denomTol_m;
  real_T phaseOneCorrectionX_o;
  real_T phaseOneCorrectionP_a;
  real_T pk_corrected_j;
  real_T ratio_g;
  real_T b_c_j;
  real_T workspace_e;
  real_T c_jy;
  real_T constrViolation_j;
  real_T c_g;
  real_T c_o;
  real_T a_hm;
  real_T b;
  real_T denomTol_c;
  real_T phaseOneCorrectionX_a;
  real_T phaseOneCorrectionP_l;
  real_T pk_corrected_jc;
  real_T ratio_i;
  real_T b_c_mi;
  real_T scale_f;
  real_T absxk_on;
  real_T t_iz;
  real_T denomTol_e;
  real_T phaseOneCorrectionX_j;
  real_T phaseOneCorrectionP_o;
  real_T pk_corrected_f;
  real_T ratio_m;
  real_T b_c_a;
  real_T scale_h;
  real_T absxk_oc;
  real_T t_h;
  real_T c_j3;
  real_T c_g3;
  real_T c_jz;
  real_T c_l;
  int8_T c_I[4];
  int32_T j;
  int32_T d_i;
  int32_T b_j;
  int32_T l;
  int32_T k;
  int32_T kidx;
  int32_T b_kidx;
  int32_T isPicEnable;                 // '<Root>/Chart'
  int32_T isMpcEnable;                 // '<Root>/Chart'
  int32_T ForEach_itr_c;
  int32_T ForEach_itr;
  int32_T ForEach_itr_j_k;
  int32_T ForEach_itr_p_d;
  int32_T i;
  int32_T loop_ub;
  int32_T f_idx_0;
  int32_T f_idx_1;
  int32_T idxFillStart;
  int32_T colOffsetATw;
  int32_T e;
  int32_T c_k_n;
  int32_T i_j;
  int32_T c_a;
  int32_T idx;
  int32_T i_h;
  int32_T b_i;
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T idxStartIneq_tmp;
  int32_T mWorkingFixed;
  int32_T mTotalWorkingEq;
  int32_T idx_row;
  int32_T idx_col;
  int32_T b_tmp;
  int32_T totalRank;
  int32_T b_d;
  int32_T ix;
  int32_T nfxd;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T ix_b;
  int32_T iy;
  int32_T c_ix;
  int32_T c_k_h;
  int32_T u1_p;
  int32_T i_n;
  int32_T temp_tmp_j;
  int32_T b_temp_tmp_o;
  int32_T ii;
  int32_T mmi_b;
  int32_T b_jk;
  int32_T i_e;
  int32_T knt;
  int32_T d_i4;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  int32_T kend;
  int32_T k_n;
  int32_T idxFillStart_i;
  int32_T colOffsetATw_p;
  int32_T e_o;
  int32_T c_k_m;
  int32_T i_o;
  int32_T mConstr;
  int32_T idxStartIneq_g;
  int32_T idxEndIneq_e;
  int32_T b_idxStartIneq;
  int32_T b_idxEndIneq;
  int32_T i_i;
  int32_T mWorkingFixed_g;
  int32_T idxStartIneq_ge;
  int32_T idxEndIneq_g;
  int32_T c_tmp;
  int32_T iy0_tmp;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T nFixedConstr;
  int32_T nVar;
  int32_T nDepIneq;
  int32_T c_gr;
  int32_T nActiveConstr_tmp;
  int32_T iy0_tmp_c;
  int32_T nfxd_k;
  int32_T mmi_d;
  int32_T pvt_k;
  int32_T itemp_p;
  int32_T ix_p;
  int32_T iy_m;
  int32_T c_ix_k;
  int32_T c_k_a;
  int32_T u1_f;
  int32_T i_c;
  int32_T temp_tmp_jk;
  int32_T b_temp_tmp_k;
  int32_T ii_h;
  int32_T mmi_d1;
  int32_T b_j1;
  int32_T i_np;
  int32_T knt_j;
  int32_T d_l;
  int32_T scalarLB_p;
  int32_T vectorUB_p;
  int32_T vectorUB_tmp_l;
  int32_T kend_l;
  int32_T k_h;
  int32_T PROBTYPE_ORIG;
  int32_T nVar_c;
  int32_T mConstr_g;
  int32_T idxStartIneq_e;
  int32_T idxEndIneq_n;
  int32_T idxStartIneq_tmp_f;
  int32_T activeSetChangeID;
  int32_T nVar_n;
  int32_T localActiveConstrIdx;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T Qk0;
  int32_T iyend;
  int32_T i_e2;
  int32_T jjA;
  int32_T d_ix;
  int32_T e_tmp;
  int32_T idx_b;
  int32_T d_a;
  int32_T iac;
  int32_T jBcol;
  int32_T iAcol;
  int32_T br;
  int32_T ar;
  int32_T h;
  int32_T l_i;
  int32_T mWConstr_tmp_tmp;
  int32_T nVar_tmp_tmp;
  int32_T iQR0;
  int32_T idx_n;
  int32_T ia;
  int32_T itau;
  int32_T lastc;
  int32_T f;
  int32_T coltop;
  int32_T c_ia;
  int32_T jA;
  int32_T i_f;
  int32_T activeSetChangeID_i;
  int32_T nVar_k;
  int32_T localActiveConstrIdx_b;
  int32_T globalActiveConstrIdx_d;
  int32_T TYPE_h;
  int32_T Qk0_n;
  int32_T iy0;
  int32_T iyend_f;
  int32_T l_a;
  int32_T m;
  int32_T idx_m;
  int32_T d_g;
  int32_T iac_n;
  int32_T jBcol_c;
  int32_T iAcol_d;
  int32_T br_k;
  int32_T ar_c;
  int32_T h_j;
  int32_T l_m;
  int32_T mWConstr_tmp_tmp_i;
  int32_T nVar_tmp_tmp_b;
  int32_T iQR0_o;
  int32_T idx_g;
  int32_T ia_e;
  int32_T itau_i;
  int32_T lastc_e;
  int32_T f_i;
  int32_T coltop_m;
  int32_T c_ia_d;
  int32_T jA_j;
  int32_T i_p;
  int32_T nVar_b;
  int32_T idxStartIneq_p;
  int32_T idxEndIneq_nm;
  int32_T i_ce;
  int32_T idxStartIneq_tmp_n;
  int32_T nVar_d;
  int32_T nullStartIdx;
  int32_T nVars;
  int32_T A_maxDiag_idx;
  int32_T b_A_maxDiag_idx;
  int32_T lastColC;
  int32_T br_i;
  int32_T ar_n;
  int32_T ic;
  int32_T h_b;
  int32_T i_b;
  int32_T b_ar;
  int32_T e_ix;
  int32_T vectorUB_j;
  int32_T mNull_tmp;
  int32_T LD_diagOffset;
  int32_T subMatrixDim;
  int32_T lastDiag;
  int32_T b_k;
  int32_T jA_n;
  int32_T b_f;
  int32_T ijA;
  int32_T nVar_e;
  int32_T nullStartIdx_i;
  int32_T nVars_a;
  int32_T A_maxDiag_idx_f;
  int32_T b_A_maxDiag_idx_k;
  int32_T lastColC_c;
  int32_T br_j;
  int32_T ar_l;
  int32_T ic_a;
  int32_T h_i;
  int32_T i_ok;
  int32_T b_ar_b;
  int32_T e_ix_a;
  int32_T vectorUB_a;
  int32_T mNull_tmp_i;
  int32_T LD_diagOffset_i;
  int32_T subMatrixDim_l;
  int32_T lastDiag_o;
  int32_T b_k_p;
  int32_T jA_o;
  int32_T b_cm;
  int32_T ijA_o;
  int32_T k_o;
  int32_T d_he;
  int32_T ia_i;
  int32_T b_iy;
  int32_T b_g;
  int32_T ia_c;
  int32_T i_ok1;
  int32_T k_g;
  int32_T idxRotGCol;
  int32_T QRk0;
  int32_T b_n;
  int32_T e_k;
  int32_T temp_tmp_o;
  int32_T b_temp_tmp_g;
  int32_T k_ad;
  int32_T d_gy;
  int32_T ia_b;
  int32_T b_iy_k;
  int32_T b_ca;
  int32_T ia_j;
  int32_T idx_row_a;
  int32_T idxStartIneq_d;
  int32_T idxEndIneq_c;
  int32_T i_d;
  int32_T d_tmp;
  int32_T iy0_tmp_a;
  int32_T k_b;
  int32_T i_g;
  int32_T ix0_tmp;
  int32_T lastv;
  int32_T lastc_f;
  int32_T d_c;
  int32_T coltop_p;
  int32_T b_ia;
  int32_T jA_a;
  int32_T k_no;
  int32_T i_hl;
  int32_T ix0_tmp_m;
  int32_T lastv_f;
  int32_T lastc_b;
  int32_T d_e;
  int32_T coltop_n;
  int32_T b_ia_p;
  int32_T jA_i;
  int32_T k_j;
  int32_T d_lj;
  int32_T ia_ce;
  int32_T b_gr;
  int32_T k_c;
  int32_T k_l;
  int32_T d_ev;
  int32_T ia_d;
  int32_T b_m;
  int32_T k_f;
  int32_T b_iy_n;
  int32_T b_o;
  int32_T ia_en;
  int32_T b_iy_m;
  int32_T b_ch;
  int32_T ia_g;
  int32_T b_iy_b;
  int32_T b_p;
  int32_T ia_p;
  int32_T b_iy_a;
  int32_T b_fm;
  int32_T ia_gr;
  int8_T d_b[2];
  int16_T i_k;
  int8_T mode;                         // '<S9>/Chart'
  int8_T A;
  int8_T B_k;
  int8_T B_b;
  boolean_T b_value_ix;
  boolean_T Compare;                   // '<S23>/Compare'
  boolean_T LogicalOperator_j;         // '<S11>/Logical Operator'
  boolean_T okWorkingSet;
  boolean_T b_bool;
  boolean_T okWorkingSet_n;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  boolean_T newBlocking;
  boolean_T nonDegenerateWset;
  boolean_T subProblemChanged_h;
  boolean_T updateFval_n;
  boolean_T newBlocking_m;
  boolean_T okWorkingSet_g;
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S8>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S8>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_withPIC_T {
  sSOeZ9WO10chPn9Si6PKiCB_motio_T opts;// '<S48>/solvex'
  sSOeZ9WO10chPn9Si6PKiCB_motio_T opts_j;// '<S49>/solvex'
  ros_slros2_internal_block_Get_T obj; // '<S10>/Get Parameter6'
  ros_slros2_internal_block_Get_T obj_l;// '<S10>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_p;// '<S10>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_a;// '<S35>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_lw;// '<S35>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_ae;// '<S35>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_d;// '<S35>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_g;// '<S33>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_e;// '<S33>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l4;// '<S33>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_c;// '<S33>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o;// '<S33>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_m;// '<S33>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_f;// '<S9>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_p3;// '<S6>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_ls;// '<S6>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_i;// '<S6>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_n;// '<Root>/Get Parameter9'
  ros_slros2_internal_block_Get_T obj_k;// '<Root>/Get Parameter8'
  ros_slros2_internal_block_Get_T obj_b;// '<Root>/Get Parameter7'
  ros_slros2_internal_block_Get_T obj_j;// '<Root>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_ny;// '<Root>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_pw;// '<Root>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_di;// '<Root>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_ma;// '<Root>/Get Parameter16'
  ros_slros2_internal_block_Get_T obj_kx;// '<Root>/Get Parameter15'
  ros_slros2_internal_block_Get_T obj_h;// '<Root>/Get Parameter14'
  ros_slros2_internal_block_Get_T obj_e5;// '<Root>/Get Parameter13'
  ros_slros2_internal_block_Get_T obj_co;// '<Root>/Get Parameter12'
  ros_slros2_internal_block_Get_T obj_ff;// '<Root>/Get Parameter11'
  ros_slros2_internal_block_Get_T obj_ba;// '<Root>/Get Parameter10'
  ros_slros2_internal_block_Get_T obj_hm;// '<Root>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_ay;// '<Root>/Get Parameter'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S29>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_bq;// '<S28>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_ng;// '<S13>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_mo;// '<S56>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_nf;// '<S55>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_dp;// '<S19>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_en;// '<S18>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_az;// '<S17>/SourceBlock'
  real_T UnitDelay_DSTATE;             // '<S10>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S10>/Unit Delay1'
  real_T x0[20];                       // '<S49>/solvex'
  real_T A[800];                       // '<S49>/solvex'
  real_T Umin;                         // '<S49>/solvex'
  real_T Umax;                         // '<S49>/solvex'
  real_T x0_i[40];                     // '<S48>/solvex'
  real_T A_j[3200];                    // '<S48>/solvex'
  real_T Umin_c;                       // '<S48>/solvex'
  real_T Umax_n;                       // '<S48>/solvex'
  real_T angle_out;                    // '<S33>/MATLAB Function'
  real_T sum;                          // '<S9>/Chart'
  real_T counter;                      // '<S9>/Chart'
  real_T check;                        // '<S9>/Chart'
  real_T delay;                        // '<S5>/Chart'
  real_T y_ini;                        // '<S5>/Chart'
  real_T yaw_ini;                      // '<S5>/Chart'
  real_T yaw_l;                        // '<S5>/Chart'
  real_T delta;                        // '<S5>/Chart'
  real_T delay_a;                      // '<Root>/Chart'
  real_T r_l;                          // '<Root>/Chart'
  real_T enable_b;                     // '<Root>/Chart'
  real_T Ay_l;                         // '<Root>/Chart'
  uint8_T is_active_c6_motion_controller_;// '<S33>/Chart2'
  uint8_T is_active_c3_motion_controller_;// '<S9>/Chart'
  uint8_T is_Is_ready;                 // '<S9>/Chart'
  uint8_T is_cmd;                      // '<S9>/Chart'
  uint8_T is_effort_mode;              // '<S9>/Chart'
  uint8_T is_active_c7_motion_controller_;// '<S5>/Chart'
  uint8_T is_c7_motion_controller_withPIC;// '<S5>/Chart'
  uint8_T is_active_c18_motion_controller;// '<Root>/Chart'
  uint8_T is_c18_motion_controller_withPI;// '<Root>/Chart'
  boolean_T x0_not_empty;              // '<S49>/solvex'
  boolean_T x0_not_empty_k;            // '<S48>/solvex'
  boolean_T ready;                     // '<S9>/Chart'
  boolean_T picController_MODE;        // '<Root>/picController'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S8>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S8>/Current Time'
};

// Parameters for system: '<S8>/For Each Subsystem'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S30>/Constant'

};

// Parameters for system: '<S8>/For Each Subsystem1'
struct P_CoreSubsys_motion_contro_gm_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S31>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_withPIC_T_ {
  real_T B;                            // Variable: B
                                          //  Referenced by: '<S10>/update'

  real_T Izz;                          // Variable: Izz
                                          //  Referenced by: '<S10>/update'

  real_T Krsf;                         // Variable: Krsf
                                          //  Referenced by: '<S10>/update'

  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S10>/update'
                                          //    '<S34>/MATLAB Function'
                                          //    '<S36>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S34>/MATLAB Function'
                                          //    '<S36>/MATLAB Function'

  real_T a;                            // Variable: a
                                          //  Referenced by: '<S10>/update'

  real_T b;                            // Variable: b
                                          //  Referenced by:
                                          //    '<S10>/update'
                                          //    '<S36>/MATLAB Function'

  real_T g;                            // Variable: g
                                          //  Referenced by: '<S10>/update'

  real_T hCG;                          // Variable: hCG
                                          //  Referenced by: '<S10>/update'

  real_T m;                            // Variable: m
                                          //  Referenced by: '<S10>/update'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S42>/Constant'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S23>/Constant'

  int16_T CompareToConstant_const_m;// Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S2>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S22>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                      //  Referenced by: '<S59>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S19>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                             //  Referenced by: '<S56>/Constant'

  SL_Bus_nav_msgs_Odometry Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S20>/Out1'

  SL_Bus_nav_msgs_Odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S17>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S25>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S24>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S21>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_e;// Computed Parameter: Constant_Value_e
                                             //  Referenced by: '<S18>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S58>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S55>/Constant'

  SL_Bus_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                 //  Referenced by: '<S12>/Constant'

  real_T Gain2_Gain;                   // Expression: 0
                                          //  Referenced by: '<S6>/Gain2'

  real_T Gain1_Gain;                   // Expression: 0.4
                                          //  Referenced by: '<S6>/Gain1'

  real_T Gain_Gain;                    // Expression: 0
                                          //  Referenced by: '<S6>/Gain'

  real_T Constant_Value_b;             // Expression: 2
                                          //  Referenced by: '<S6>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S8>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S8>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S8>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S8>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S8>/Saturation'

  real_T MATLABFunction_J;             // Expression: J
                                          //  Referenced by: '<S35>/MATLAB Function'

  real_T MATLABFunction_Re;            // Expression: Re
                                          //  Referenced by: '<S35>/MATLAB Function'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S35>/Constant4'

  real_T Gain_Gain_m;                  // Expression: 0
                                          //  Referenced by: '<S36>/Gain'

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S33>/Constant2'

  real_T Gain1_Gain_k;                 // Expression: 1/500
                                          //  Referenced by: '<S33>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S33>/Constant'

  real_T Gain_Gain_f;                  // Expression: 1/500
                                          //  Referenced by: '<S33>/Gain'

  real_T Gain2_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S33>/Gain2'

  real_T Constant_Value_o;             // Expression: 0
                                          //  Referenced by: '<S9>/Constant'

  real_T Gain1_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S48>/Gain1'

  real_T Gain1_Gain_c;                 // Expression: -1
                                          //  Referenced by: '<S49>/Gain1'

  real_T Constant2_Value_g;            // Expression: 1e-9
                                          //  Referenced by: '<S10>/Constant2'

  real_T Ay_check_Y0;                  // Computed Parameter: Ay_check_Y0
                                          //  Referenced by: '<S10>/Ay_check'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S10>/Unit Delay'

  real_T UnitDelay1_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S10>/Unit Delay1'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S46>/Merge'

  real_T Constant1_Value;              // Expression: 500
                                          //  Referenced by: '<S7>/Constant1'

  real_T Constant_Value_j;             // Expression: 0.411
                                          //  Referenced by: '<S5>/Constant'

  real_T Constant2_Value_e;            // Expression: 0.01
                                          //  Referenced by: '<Root>/Constant2'

  real_T Saturation_UpperSat_h;        // Expression: 0.4
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -0.4
                                          //  Referenced by: '<S6>/Saturation'

  P_CoreSubsys_motion_contro_gm_T CoreSubsys_pn;// '<S8>/For Each Subsystem1'
  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S8>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_motion_controller_wit_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_withPIC
class motion_controller_withPIC
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_motion_controller_wi_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  motion_controller_withPIC();

  // Destructor
  ~motion_controller_withPIC();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_withPIC_T motion_controller_withPIC_B;

  // Block states
  DW_motion_controller_withPIC_T motion_controller_withPIC_DW;

  // Tunable parameters
  static P_motion_controller_withPIC_T motion_controller_withPIC_P;

  // private member function(s) for subsystem '<S8>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_w_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S9>/get_angle_4w'
  void motion_controller__get_angle_4w(real_T rtu_delta_f, real_T rtu_delta_r,
    real_T rty_angle_cmd[4]) const;

  // private member function(s) for subsystem '<S9>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_wi_get_effort(real_T rtu_longdrive, real_T rtu_vx,
    real_T rtu_dvx, const real_T rtu_omega4w[4], real_T rty_effort_cmd[4]);
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S9>/get_spd'
  void motion_controller_withP_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

  // private member function(s) for subsystem '<Root>'
  void motio_modifyOverheadPhaseOne__j(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj);
  void motion_control_setProblemType_k(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj,
    int32_T PROBLEM_TYPE);
  real_T motion_controlle_xnrm2_hNM7iFHJ(int32_T n, const real_T x[1701],
    int32_T ix0);
  real_T motion_controller_rt_hypotd_snf(real_T u0, real_T u1);
  real_T motion_control_xzlarfg_Bt3Hq0Z4(int32_T n, real_T *alpha1, real_T x
    [1701], int32_T ix0);
  void motion_controll_xzlarf_ROZS8xVG(int32_T m, int32_T n, int32_T iv0, real_T
    tau, real_T C[1701], int32_T ic0, real_T work[81]);
  void motion_controller__qrf_nGv3LI5p(real_T A[1701], int32_T m, int32_T n,
    int32_T nfxd, real_T tau[21]);
  void motion_controller_w_factorQRE_c(sIZAIOglGM5dPDQlNukc9SD_motio_T *obj,
    int32_T mrows, int32_T ncols);
  void motion_controller_w_computeQ__l(sIZAIOglGM5dPDQlNukc9SD_motio_T *obj,
    int32_T nrows);
  int32_T motion_ComputeNumDependentEq__d(sIZAIOglGM5dPDQlNukc9SD_motio_T
    *qrmanager, const real_T beqf[81], int32_T mConstr, int32_T nVar);
  void motion_controlle_removeConstr_n(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj,
    int32_T idx_global);
  void motion_control_removeEqConstr_i(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj,
    int32_T idx_global);
  void motion_c_RemoveDependentIneq__e(sVIU4VBONGRsUytHTQmMJFH_motio_T
    *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager,
    s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, real_T tolfactor);
  void motion_controller_wi_factorQR_c(sIZAIOglGM5dPDQlNukc9SD_motio_T *obj,
    const real_T A[1701], int32_T mrows, int32_T ncols);
  void motion_controlle_xgemv_7iafTBwP(int32_T m, const real_T A[840], const
    real_T x[1701], real_T y[81]);
  void motion_controlle_xgemv_vyHQ2Zvi(int32_T m, const real_T A[840], const
    real_T x[1701], real_T y[81]);
  boolean_T motio_feasibleX0ForWorkingSet_c(real_T workspace[1701], real_T
    xCurrent[21], sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
    sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager);
  real_T motion_maxConstraintViolation_n(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj,
    const real_T x[21]);
  void motion_co_PresolveWorkingSet_gj(sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
    s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T
    *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager);
  void motion_controller_linearForm__l(int32_T obj_nvar, real_T workspace[1701],
    const real_T H[400], const real_T f[20], const real_T x[21]);
  real_T motion_controller_computeFval_n(const s3PrFoa9w5ssw8XLEJooNqH_motio_T
    *obj, real_T workspace[1701], const real_T H[400], const real_T f[20], const
    real_T x[21]);
  void motion_co_computeGrad_StoreHx_k(s3PrFoa9w5ssw8XLEJooNqH_motio_T *obj,
    const real_T H[400], const real_T f[20], const real_T x[21]);
  real_T motion_co_computeFval_ReuseHx_n(const s3PrFoa9w5ssw8XLEJooNqH_motio_T
    *obj, real_T workspace[1701], const real_T f[20], const real_T x[21]);
  void motion_controlle_xrotg_ds3XgDMS(real_T *a, real_T *b, real_T *c, real_T
    *s);
  void motion_contr_deleteColMoveEnd_a(sIZAIOglGM5dPDQlNukc9SD_motio_T *obj,
    int32_T idx);
  void motion_controlle_fullColLDL2__a(sTy13TWZ7KObOACj8wDaLQC_motio_T *obj,
    int32_T NColsRemain, real_T REG_PRIMAL);
  void motion_control_compute_deltax_o(const real_T H[400],
    sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
    *memspace, const sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager,
    sTy13TWZ7KObOACj8wDaLQC_motio_T *cholmanager, const
    s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective);
  real_T motion_controlle_xnrm2_rY1rIeLd(int32_T n, const real_T x[21]);
  void motion_controlle_xgemv_BberjsMK(int32_T m, const real_T A[840], const
    real_T x[21], real_T y[1701]);
  void motion_controller_w_ratiotest_f(const real_T solution_xstar[21], const
    real_T solution_searchDir[21], real_T workspace[1701], int32_T
    workingset_nVar, const real_T workingset_Aineq[840], const real_T
    workingset_bineq[40], const real_T workingset_lb[21], const real_T
    workingset_ub[21], const int32_T workingset_indexLB[21], const int32_T
    workingset_indexUB[21], const int32_T workingset_sizes[5], const int32_T
    workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[81],
    const int32_T workingset_nWConstr[5], real_T *toldelta, real_T *alpha,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void motion_cont_feasibleratiotest_d(const real_T solution_xstar[21], const
    real_T solution_searchDir[21], real_T workspace[1701], int32_T
    workingset_nVar, const real_T workingset_Aineq[840], const real_T
    workingset_bineq[40], const real_T workingset_lb[21], const real_T
    workingset_ub[21], const int32_T workingset_indexLB[21], const int32_T
    workingset_indexUB[21], const int32_T workingset_sizes[5], const int32_T
    workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[81],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void mo_addBoundToActiveSetMatrix__i(sVIU4VBONGRsUytHTQmMJFH_motio_T *obj,
    int32_T TYPE, int32_T idx_local);
  void motion_controlle_compute_lambda(real_T workspace[1701],
    sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, const
    s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective, const
    sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager);
  void motion_controller_wit_iterate_b(const real_T H[400], const real_T f[20],
    sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
    *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
    sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, sTy13TWZ7KObOACj8wDaLQC_motio_T *
    cholmanager, s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective, real_T
    options_ObjectiveLimit, real_T options_StepTolerance, real_T
    runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
    boolean_T runTimeOptions_RemainFeasible);
  void motion_c_PresolveWorkingSet_gjp(sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
    s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T
    *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager);
  void motion_c_computeFirstOrderOpt_k(sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
    const s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective, int32_T workingset_nVar,
    const real_T workingset_ATwset[1701], int32_T workingset_nActiveConstr,
    real_T workspace[1701]);
  void motion_controller_with_driver_e(const real_T H[400], const real_T f[20],
    sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
    *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
    sTy13TWZ7KObOACj8wDaLQC_motio_T *cholmanager,
    sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, real_T
    runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
    sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, s3PrFoa9w5ssw8XLEJooNqH_motio_T *
    objective);
  void motion_controller_wi_quadprog_k(const real_T H[400], const real_T f[20],
    const real_T Aineq[800], const real_T bineq[40], const real_T lb[20], const
    real_T ub[20], real_T x0[20], const sSOeZ9WO10chPn9Si6PKiCB_motio_T *options);
  void motion__modifyOverheadPhaseOne_(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj);
  void motion_controlle_setProblemType(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj,
    int32_T PROBLEM_TYPE);
  real_T motion_controlle_xnrm2_h59MJ9zm(int32_T n, const real_T x[6601],
    int32_T ix0);
  real_T motion_control_xzlarfg_91xlzxZq(int32_T n, real_T *alpha1, real_T x
    [6601], int32_T ix0);
  void motion_controll_xzlarf_xH4hoCMV(int32_T m, int32_T n, int32_T iv0, real_T
    tau, real_T C[6601], int32_T ic0, real_T work[161]);
  void motion_controller__qrf_ELz1YOWw(real_T A[6601], int32_T m, int32_T n,
    int32_T nfxd, real_T tau[41]);
  void motion_controller_wit_factorQRE(s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj,
    int32_T mrows, int32_T ncols);
  void motion_controller_wit_computeQ_(s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj,
    int32_T nrows);
  int32_T motion_c_ComputeNumDependentEq_(s2uO2c2bmaUl7sY5vOWIzHG_motio_T
    *qrmanager, const real_T beqf[161], int32_T mConstr, int32_T nVar);
  void motion_controller__removeConstr(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj,
    int32_T idx_global);
  void motion_controlle_removeEqConstr(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj,
    int32_T idx_global);
  void motion_contr_RemoveDependentEq_(sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace,
    sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset, int32_T *nDepInd,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager);
  void motion_con_RemoveDependentIneq_(sT1ziU4p6vTWuD880X9yNJ_motion_T
    *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
    sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, real_T tolfactor);
  void motion_controller_with_factorQR(s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj,
    const real_T A[6601], int32_T mrows, int32_T ncols);
  void motion_controlle_xgemv_kCjzUKKr(int32_T m, const real_T A[3280], const
    real_T x[6601], real_T y[161]);
  void motion_controlle_xgemv_vsfN2o0d(int32_T m, const real_T A[3280], const
    real_T x[6601], real_T y[161]);
  boolean_T motion__feasibleX0ForWorkingSet(real_T workspace[6601], real_T
    xCurrent[41], sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager);
  real_T motion_c_maxConstraintViolation(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj,
    const real_T x[41]);
  void motion_contr_PresolveWorkingSet(s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
    sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
    *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager);
  void motion_controller_w_linearForm_(int32_T obj_nvar, real_T workspace[6601],
    const real_T H[1600], const real_T f[40], const real_T x[41]);
  real_T motion_controller_w_computeFval(const sKnhLiTH4yv7eF1oV2a74RG_motio_T
    *obj, real_T workspace[6601], const real_T H[1600], const real_T f[40],
    const real_T x[41]);
  void motion_cont_computeGrad_StoreHx(sKnhLiTH4yv7eF1oV2a74RG_motio_T *obj,
    const real_T H[1600], const real_T f[40], const real_T x[41]);
  real_T motion_cont_computeFval_ReuseHx(const sKnhLiTH4yv7eF1oV2a74RG_motio_T
    *obj, real_T workspace[6601], const real_T f[40], const real_T x[41]);
  void motion_control_deleteColMoveEnd(s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj,
    int32_T idx);
  void motion_controller__fullColLDL2_(s8kZFjDlzP6eNfOekUiP5MF_motio_T *obj,
    int32_T NColsRemain, real_T REG_PRIMAL);
  void motion_controlle_compute_deltax(const real_T H[1600],
    s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, const s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
    s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager, const
    sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective);
  real_T motion_controlle_xnrm2_DlmxxpnG(int32_T n, const real_T x[41]);
  void motion_controlle_xgemv_pKPSQiPT(int32_T m, const real_T A[3280], const
    real_T x[41], real_T y[6601]);
  void motion_controller_wit_ratiotest(const real_T solution_xstar[41], const
    real_T solution_searchDir[41], real_T workspace[6601], int32_T
    workingset_nVar, const real_T workingset_Aineq[3280], const real_T
    workingset_bineq[80], const real_T workingset_lb[41], const real_T
    workingset_ub[41], const int32_T workingset_indexLB[41], const int32_T
    workingset_indexUB[41], const int32_T workingset_sizes[5], const int32_T
    workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[161],
    const int32_T workingset_nWConstr[5], real_T *toldelta, real_T *alpha,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void motion_contro_feasibleratiotest(const real_T solution_xstar[41], const
    real_T solution_searchDir[41], real_T workspace[6601], int32_T
    workingset_nVar, const real_T workingset_Aineq[3280], const real_T
    workingset_bineq[80], const real_T workingset_lb[41], const real_T
    workingset_ub[41], const int32_T workingset_indexLB[41], const int32_T
    workingset_indexUB[41], const int32_T workingset_sizes[5], const int32_T
    workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[161],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void moti_addBoundToActiveSetMatrix_(sT1ziU4p6vTWuD880X9yNJ_motion_T *obj,
    int32_T TYPE, int32_T idx_local);
  void moti_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const real_T
    f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
    sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, const
    sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective, sT1ziU4p6vTWuD880X9yNJ_motion_T *
    workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, real_T
    options_ObjectiveLimit, real_T runTimeOptions_ConstrRelTolFact, boolean_T
    updateFval);
  void motion_controller_withP_iterate(const real_T H[1600], const real_T f[40],
    s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, s8kZFjDlzP6eNfOekUiP5MF_motio_T *
    cholmanager, sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective, real_T
    options_ObjectiveLimit, real_T options_StepTolerance, real_T
    runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
    boolean_T runTimeOptions_RemainFeasible);
  void motion_controller_with_phaseone(const real_T H[1600], const real_T f[40],
    s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, s8kZFjDlzP6eNfOekUiP5MF_motio_T *
    cholmanager, sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, const
    sL9bDKomAYkxZSVrG9w6En_motion_T *runTimeOptions,
    sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective);
  int32_T motion_con_RemoveDependentEq__j(sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager);
  void motion_con_PresolveWorkingSet_g(s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
    sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
    *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager);
  void motion_con_computeFirstOrderOpt(s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
    const sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective, int32_T workingset_nVar,
    const real_T workingset_ATwset[6601], int32_T workingset_nActiveConstr,
    real_T workspace[6601]);
  void motion_controller_wi_phaseone_e(const real_T H[1600], const real_T f[40],
    s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, s8kZFjDlzP6eNfOekUiP5MF_motio_T *
    cholmanager, sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective,
    sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, const
    sL9bDKomAYkxZSVrG9w6En_motion_T *runTimeOptions);
  void motion_controller_withPI_driver(const real_T H[1600], const real_T f[40],
    s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
    *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
    s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager,
    sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, sL9bDKomAYkxZSVrG9w6En_motion_T
    runTimeOptions, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
    sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective);
  void motion_controller_with_quadprog(const real_T H[1600], const real_T f[40],
    const real_T Aineq[3200], const real_T bineq[80], const real_T lb[40], const
    real_T ub[40], real_T x0[40], const sSOeZ9WO10chPn9Si6PKiCB_motio_T *options);
  void motion_co_SystemCore_setup_fxdc(ros_slros2_internal_block_Pub_T *obj);
  void motion_c_SystemCore_setup_fxdcj(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_f(ros_slros2_internal_block_Sub_T *obj);
  void motion_cont_SystemCore_setup_fx(ros_slros2_internal_block_Sub_T *obj);
  void motion__SystemCore_setup_fxdcji(ros_slros2_internal_block_Sub_T *obj);
  void motion_con_SystemCore_setup_fxd(ros_slros2_internal_block_Sub_T *obj);
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_SystemCore_setup_fxdcjik(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_wi_T motion_controller_withPIC_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display12' : Unused code path elimination
//  Block '<S33>/Display' : Unused code path elimination
//  Block '<S33>/Display1' : Unused code path elimination
//  Block '<S35>/Display' : Unused code path elimination
//  Block '<S35>/Display1' : Unused code path elimination
//  Block '<S57>/Display' : Unused code path elimination
//  Block '<S57>/Display1' : Unused code path elimination
//  Block '<S57>/Display10' : Unused code path elimination
//  Block '<S57>/Display11' : Unused code path elimination
//  Block '<S57>/Display12' : Unused code path elimination
//  Block '<S57>/Display13' : Unused code path elimination
//  Block '<S57>/Display14' : Unused code path elimination
//  Block '<S57>/Display15' : Unused code path elimination
//  Block '<S57>/Display2' : Unused code path elimination
//  Block '<S57>/Display3' : Unused code path elimination
//  Block '<S57>/Display4' : Unused code path elimination
//  Block '<S57>/Display5' : Unused code path elimination
//  Block '<S57>/Display6' : Unused code path elimination
//  Block '<S57>/Display7' : Unused code path elimination
//  Block '<S57>/Display8' : Unused code path elimination
//  Block '<S57>/Display9' : Unused code path elimination
//  Block '<S9>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'motion_controller_withPIC'
//  '<S1>'   : 'motion_controller_withPIC/Chart'
//  '<S2>'   : 'motion_controller_withPIC/Compare To Constant'
//  '<S3>'   : 'motion_controller_withPIC/MATLAB Function'
//  '<S4>'   : 'motion_controller_withPIC/StateFlow'
//  '<S5>'   : 'motion_controller_withPIC/Subsystem1'
//  '<S6>'   : 'motion_controller_withPIC/Subsystem2'
//  '<S7>'   : 'motion_controller_withPIC/Subsystem3'
//  '<S8>'   : 'motion_controller_withPIC/cmd_pub'
//  '<S9>'   : 'motion_controller_withPIC/controller'
//  '<S10>'  : 'motion_controller_withPIC/picController'
//  '<S11>'  : 'motion_controller_withPIC/subscription'
//  '<S12>'  : 'motion_controller_withPIC/StateFlow/Blank Message1'
//  '<S13>'  : 'motion_controller_withPIC/StateFlow/Publish2'
//  '<S14>'  : 'motion_controller_withPIC/Subsystem1/Chart'
//  '<S15>'  : 'motion_controller_withPIC/Subsystem1/For Each Subsystem'
//  '<S16>'  : 'motion_controller_withPIC/Subsystem1/MATLAB Function'
//  '<S17>'  : 'motion_controller_withPIC/Subsystem1/Subscribe'
//  '<S18>'  : 'motion_controller_withPIC/Subsystem1/Subscribe1'
//  '<S19>'  : 'motion_controller_withPIC/Subsystem1/Subscribe2'
//  '<S20>'  : 'motion_controller_withPIC/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S21>'  : 'motion_controller_withPIC/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S22>'  : 'motion_controller_withPIC/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S23>'  : 'motion_controller_withPIC/Subsystem3/Compare To Constant1'
//  '<S24>'  : 'motion_controller_withPIC/cmd_pub/Blank Message1'
//  '<S25>'  : 'motion_controller_withPIC/cmd_pub/Blank Message2'
//  '<S26>'  : 'motion_controller_withPIC/cmd_pub/For Each Subsystem'
//  '<S27>'  : 'motion_controller_withPIC/cmd_pub/For Each Subsystem1'
//  '<S28>'  : 'motion_controller_withPIC/cmd_pub/Publish'
//  '<S29>'  : 'motion_controller_withPIC/cmd_pub/Publish2'
//  '<S30>'  : 'motion_controller_withPIC/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S31>'  : 'motion_controller_withPIC/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S32>'  : 'motion_controller_withPIC/controller/Chart'
//  '<S33>'  : 'motion_controller_withPIC/controller/Subsystem'
//  '<S34>'  : 'motion_controller_withPIC/controller/get_angle_4w'
//  '<S35>'  : 'motion_controller_withPIC/controller/get_effort'
//  '<S36>'  : 'motion_controller_withPIC/controller/get_spd'
//  '<S37>'  : 'motion_controller_withPIC/controller/Subsystem/Chart2'
//  '<S38>'  : 'motion_controller_withPIC/controller/Subsystem/MATLAB Function'
//  '<S39>'  : 'motion_controller_withPIC/controller/get_angle_4w/MATLAB Function'
//  '<S40>'  : 'motion_controller_withPIC/controller/get_effort/MATLAB Function'
//  '<S41>'  : 'motion_controller_withPIC/controller/get_spd/MATLAB Function'
//  '<S42>'  : 'motion_controller_withPIC/picController/Compare To Constant'
//  '<S43>'  : 'motion_controller_withPIC/picController/MATLAB Function'
//  '<S44>'  : 'motion_controller_withPIC/picController/MATLAB Function2'
//  '<S45>'  : 'motion_controller_withPIC/picController/Subsystem'
//  '<S46>'  : 'motion_controller_withPIC/picController/Subsystem1'
//  '<S47>'  : 'motion_controller_withPIC/picController/update'
//  '<S48>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem'
//  '<S49>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem1'
//  '<S50>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem/predict'
//  '<S51>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem/solvex'
//  '<S52>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem1/predict'
//  '<S53>'  : 'motion_controller_withPIC/picController/Subsystem1/If Action Subsystem1/solvex'
//  '<S54>'  : 'motion_controller_withPIC/subscription/For Each Subsystem'
//  '<S55>'  : 'motion_controller_withPIC/subscription/Subscribe'
//  '<S56>'  : 'motion_controller_withPIC/subscription/Subscribe1'
//  '<S57>'  : 'motion_controller_withPIC/subscription/display'
//  '<S58>'  : 'motion_controller_withPIC/subscription/Subscribe/Enabled Subsystem'
//  '<S59>'  : 'motion_controller_withPIC/subscription/Subscribe1/Enabled Subsystem'

#endif                               // RTW_HEADER_motion_controller_withPIC_h_

//
// File trailer for generated code.
//
// [EOF]
//
