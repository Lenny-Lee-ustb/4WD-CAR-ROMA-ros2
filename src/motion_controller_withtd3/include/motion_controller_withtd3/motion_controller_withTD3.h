//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_withTD3.h
//
// Code generated for Simulink model 'motion_controller_withTD3'.
//
// Model version                  : 2.376
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Apr  4 17:41:57 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_withTD3_h_
#define RTW_HEADER_motion_controller_withTD3_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_withTD3_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtGetNaN.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S12>/Current Time'
struct B_CurrentTime_motion_controll_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S12>/Current Time'
};

// Block states (default storage) for system '<S12>/Current Time'
struct DW_CurrentTime_motion_control_T {
  ros_slros2_internal_block_Cur_T obj; // '<S12>/Current Time'
  boolean_T objisempty;                // '<S12>/Current Time'
};

// Block signals (default storage)
struct B_motion_controller_withTD3_T {
  real32_T g[65536];
  real32_T e[3840];
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S59>/In1'
  SL_Bus_custom_interfaces_ActuatorState In1_j;// '<S31>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  real32_T k[512];
  real_T t_data[200];
  real_T b_x[200];
  real32_T outT_f7_0_f1[256];
  real32_T fv[256];
  real32_T fv1[256];
  SL_Bus_nav_msgs_Odometry In1_je;     // '<S29>/In1'
  SL_Bus_nav_msgs_Odometry b_varargout_2_m;
  real_T x[100];
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S12>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S36>/Bus Assignment1' 
  SL_Bus_sensor_msgs_Imu In1_f;        // '<S30>/In1'
  SL_Bus_sensor_msgs_Imu BusAssignment2;// '<S7>/Bus Assignment2'
  real_T c_x[50];
  SL_Bus_sbus_interface_Sbus In1_m;    // '<S58>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_c;
  real_T ImpAsg_InsertedFor_Out1_at_[16];
  real32_T rtb_e_Y_k[15];
  real32_T varargin_1_Data[15];
  SL_Bus_geometry_msgs_Twist BusAssignment2_i;// '<S5>/Bus Assignment2'
  real_T delta[4];                     // '<S14>/MATLAB Function'
  real_T Switch2[4];                   // '<S9>/Switch2'
  real_T Switch1[4];                   // '<S9>/Switch1'
  real_T rtb_ImpAsg_InsertedFor_Out1_a_c[4];
  cell_wrap_2_motion_controller_T b;
  cell_wrap_2_motion_controller_T c;
  dlarray_1_motion_controller_w_T dlArrayOutputs;
  real_T out;                          // '<S42>/Chart2'
  real_T GetParameter1;                // '<S13>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S13>/Chart'
  real_T spd_cmd[4];                   // '<S13>/Chart'
  real_T effort_cmd[4];                // '<S13>/Chart'
  real_T y;                            // '<S8>/Chart'
  real_T yaw;                          // '<S8>/Chart'
  real_T effort;
  real_T y_m;
  real_T b_value;
  real_T b_value_c;
  real_T b_value_k;
  real_T b_value_cx;
  real_T d;
  real_T e_yaw;
  real_T b_value_b;
  real_T b_value_p;
  real_T b_value_cv;
  real_T b_value_f;
  real_T direction;
  real_T yp;                           // '<S8>/MATLAB Function'
  real_T vxp;                          // '<S8>/MATLAB Function1'
  real_T Add1;                         // '<S11>/Add1'
  real_T e_Yd;                         // '<Root>/MATLAB Function1'
  real_T e_yawd;                       // '<Root>/MATLAB Function1'
  real_T Gain2;                        // '<S42>/Gain2'
  real_T delta_tmp;
  real32_T fv2[2];
  real32_T bTemp;
  int32_T f_k;
  int32_T h_k;
  int32_T isMpcEnable;                 // '<Root>/Chart'
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_j_g;
  int32_T ForEach_itr_p_g;
  int32_T k_m;
  int32_T heightIdx;
  int32_T i;
  int32_T i1;
  int32_T i_n;
  int32_T k_p;
  int32_T i0_ub;
  int32_T k0_ub;
  int32_T j1;
  int32_T N2;
  int32_T k0;
  int32_T K2;
  int32_T i0;
  int32_T i2;
  int32_T i_l;
  int32_T j;
  int32_T idxA;
  int32_T idxB;
  int32_T idxC;
  int32_T idxA_j;
  int32_T idxB_d;
  int32_T k_g;
  int32_T c_tmp;
  int32_T c_tmp_l;
  int32_T c_tmp_d;
  int32_T c_tmp_dy;
  int32_T i3;
  int16_T i4;
  int8_T mode;                         // '<S13>/Chart'
  boolean_T b_value_l;
  boolean_T Compare;                   // '<S32>/Compare'
  boolean_T LogicalOperator_j;         // '<S15>/Logical Operator'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S12>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S12>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_withTD3_T {
  c_rl_codegen_policy_rlDetermi_T policy;// '<S52>/PolicyWrapper'
  rl_codegen_model_DLNetworkMod_T gobj_2;// '<S52>/PolicyWrapper'
  ros_slros2_internal_block_Get_T obj; // '<S44>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_l;// '<S44>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_a;// '<S44>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_d;// '<S44>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_g;// '<S42>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_e;// '<S42>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l4;// '<S42>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_c;// '<S42>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o;// '<S42>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_m;// '<S42>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_f;// '<S13>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_my;// '<S11>/Get Parameter20'
  ros_slros2_internal_block_Get_T obj_p;// '<S9>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_ls;// '<S9>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_i;// '<S9>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_fa;// '<S8>/Get Parameter22'
  ros_slros2_internal_block_Get_T obj_f5;// '<S8>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_k;// '<Root>/Get Parameter8'
  ros_slros2_internal_block_Get_T obj_b;// '<Root>/Get Parameter7'
  ros_slros2_internal_block_Get_T obj_iv;// '<Root>/Get Parameter6'
  ros_slros2_internal_block_Get_T obj_cp;// '<Root>/Get Parameter22'
  ros_slros2_internal_block_Get_T obj_ou;// '<Root>/Get Parameter21'
  ros_slros2_internal_block_Get_T obj_f0;// '<Root>/Get Parameter20'
  ros_slros2_internal_block_Get_T obj_ka;// '<Root>/Get Parameter19'
  ros_slros2_internal_block_Get_T obj_h;// '<Root>/Get Parameter18'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S38>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_bq;// '<S37>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_ar;// '<S21>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_lp;// '<S19>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_n;// '<S17>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_mo;// '<S56>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_nf;// '<S55>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_dp;// '<S28>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_en;// '<S27>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_az;// '<S26>/SourceBlock'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S14>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S14>/Discrete-Time Integrator2'
  real_T angle_out;                    // '<S42>/MATLAB Function'
  real_T sum;                          // '<S13>/Chart'
  real_T counter;                      // '<S13>/Chart'
  real_T check;                        // '<S13>/Chart'
  real_T delay;                        // '<S8>/Chart'
  real_T y_ini;                        // '<S8>/Chart'
  real_T yaw_ini;                      // '<S8>/Chart'
  real_T yaw_l;                        // '<S8>/Chart'
  real_T delta;                        // '<S8>/Chart'
  real_T yd;                           // '<Root>/MATLAB Function2'
  real_T data50[50];                   // '<Root>/MATLAB Function2'
  real_T gaussian_kernel50[50];        // '<Root>/MATLAB Function2'
  real_T data100[100];                 // '<Root>/MATLAB Function2'
  real_T gaussian_kernel100[100];      // '<Root>/MATLAB Function2'
  real_T data200[200];                 // '<Root>/MATLAB Function2'
  real_T gaussian_kernel200[200];      // '<Root>/MATLAB Function2'
  real_T delay_a;                      // '<Root>/Chart'
  real_T r_l;                          // '<Root>/Chart'
  real_T enable_b;                     // '<Root>/Chart'
  real_T Ay_l;                         // '<Root>/Chart'
  c_coder_internal_ctarget_dlne_T gobj_1;// '<S52>/PolicyWrapper'
  uint8_T is_active_c6_motion_controller_;// '<S42>/Chart2'
  uint8_T is_active_c3_motion_controller_;// '<S13>/Chart'
  uint8_T is_Is_ready;                 // '<S13>/Chart'
  uint8_T is_cmd;                      // '<S13>/Chart'
  uint8_T is_effort_mode;              // '<S13>/Chart'
  uint8_T is_active_c7_motion_controller_;// '<S8>/Chart'
  uint8_T is_c7_motion_controller_withTD3;// '<S8>/Chart'
  uint8_T is_active_c18_motion_controller;// '<Root>/Chart'
  uint8_T is_c18_motion_controller_withTD;// '<Root>/Chart'
  boolean_T policy_not_empty;          // '<S52>/PolicyWrapper'
  boolean_T ready;                     // '<S13>/Chart'
  boolean_T yd_not_empty;              // '<Root>/MATLAB Function2'
  boolean_T controller1_MODE;          // '<Root>/controller1'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S12>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S12>/Current Time'
};

// Parameters for system: '<S12>/For Each Subsystem'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S39>/Constant'

};

// Parameters for system: '<S12>/For Each Subsystem1'
struct P_CoreSubsys_motion_contro_gm_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S40>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_withTD3_T_ {
  real_T B;                            // Variable: B
                                          //  Referenced by: '<S14>/MATLAB Function'

  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S14>/MATLAB Function'
                                          //    '<S43>/MATLAB Function'
                                          //    '<S45>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S43>/MATLAB Function'
                                          //    '<S45>/MATLAB Function'

  real_T b;                            // Variable: b
                                          //  Referenced by: '<S45>/MATLAB Function'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S32>/Constant'

  int16_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S2>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S31>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                      //  Referenced by: '<S59>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S56>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                             //  Referenced by: '<S28>/Constant'

  SL_Bus_nav_msgs_Odometry Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S29>/Out1'

  SL_Bus_nav_msgs_Odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S26>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S34>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S33>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S30>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_e;// Computed Parameter: Constant_Value_e
                                             //  Referenced by: '<S27>/Constant'

  SL_Bus_sensor_msgs_Imu Constant_Value_m;// Computed Parameter: Constant_Value_m
                                             //  Referenced by: '<S20>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S58>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S55>/Constant'

  SL_Bus_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                 //  Referenced by: '<S16>/Constant'

  SL_Bus_geometry_msgs_Twist Constant_Value_ik;// Computed Parameter: Constant_Value_ik
                                                  //  Referenced by: '<S18>/Constant'

  real_T Gain2_Gain;                   // Expression: 0
                                          //  Referenced by: '<S9>/Gain2'

  real_T Gain1_Gain;                   // Expression: 0.4
                                          //  Referenced by: '<S9>/Gain1'

  real_T Gain_Gain;                    // Expression: 0
                                          //  Referenced by: '<S9>/Gain'

  real_T Constant_Value_by;            // Expression: 2
                                          //  Referenced by: '<S9>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S12>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S12>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S12>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S12>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S12>/Saturation'

  real_T MATLABFunction_J;             // Expression: J
                                          //  Referenced by: '<S44>/MATLAB Function'

  real_T MATLABFunction_Re;            // Expression: Re
                                          //  Referenced by: '<S44>/MATLAB Function'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S44>/Constant4'

  real_T Gain_Gain_m;                  // Expression: 0
                                          //  Referenced by: '<S45>/Gain'

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S42>/Constant2'

  real_T Gain1_Gain_k;                 // Expression: 1/500
                                          //  Referenced by: '<S42>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S42>/Constant'

  real_T Gain_Gain_f;                  // Expression: 1/500
                                          //  Referenced by: '<S42>/Gain'

  real_T Gain2_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S42>/Gain2'

  real_T Constant_Value_o;             // Expression: 0
                                          //  Referenced by: '<S13>/Constant'

  real_T steer_Y0;                     // Computed Parameter: steer_Y0
                                          //  Referenced by: '<S14>/steer'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S14>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<S14>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                          //  Referenced by: '<S14>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S14>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S14>/Discrete-Time Integrator2'

  real_T Constant1_Value;              // Expression: 500
                                          //  Referenced by: '<S10>/Constant1'

  real_T Constant_Value_j;             // Expression: 0.411
                                          //  Referenced by: '<S8>/Constant'

  real_T Saturation_UpperSat_a;        // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<Root>/Saturation'

  real_T Constant_Value_af;            // Expression: 167
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant1_Value_n;            // Expression: 0.411
                                          //  Referenced by: '<S11>/Constant1'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant5'

  real_T Saturation_UpperSat_h;        // Expression: 0.4
                                          //  Referenced by: '<S9>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -0.4
                                          //  Referenced by: '<S9>/Saturation'

  P_CoreSubsys_motion_contro_gm_T CoreSubsys_pn;// '<S12>/For Each Subsystem1'
  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S12>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_motion_controller_wit_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_withTD3
class motion_controller_withTD3
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
  motion_controller_withTD3();

  // Destructor
  ~motion_controller_withTD3();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_withTD3_T motion_controller_withTD3_B;

  // Block states
  DW_motion_controller_withTD3_T motion_controller_withTD3_DW;

  // Tunable parameters
  static P_motion_controller_withTD3_T motion_controller_withTD3_P;

  // private member function(s) for subsystem '<S12>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_w_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S13>/get_angle_4w'
  void motion_controller__get_angle_4w(real_T rtu_delta_f, real_T rtu_delta_r,
    real_T rty_angle_cmd[4]) const;

  // private member function(s) for subsystem '<S13>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_wi_get_effort(real_T rtu_longdrive, real_T rtu_vx,
    real_T rtu_dvx, const real_T rtu_omega4w[4], real_T rty_effort_cmd[4]);
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S13>/get_spd'
  void motion_controller_withT_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

  // private member function(s) for subsystem '<Root>'
  void motion_controller_microKernel11(int32_T K, real32_T *A, int32_T LDA,
    const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void motion_controller__macroKernel1(int32_T M, int32_T K, int32_T N, const
    real32_T *A, int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C,
    int32_T LDC);
  void motion_controll_matrixMultiply1(int32_T M, int32_T K, int32_T N, int32_T
    blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
    real32_T *B, real32_T *C);
  void mot_FullyConnectedLayer_predict(real32_T layer_Weights[3840], const
    real32_T layer_Bias[256], real32_T X[15], real32_T Z[256]);
  void m_FullyConnectedLayer_predict_g(real32_T layer_Weights[65536], const
    real32_T layer_Bias[256], real32_T X[256], real32_T Z[256]);
  void motion_control_elementwise_relu(const real32_T *inputTensor, real32_T
    *outputTensor, int32_T numElements);
  void motion_control_unaryElementwise(real32_T X[256], real32_T Z[256]);
  void FullyConnectedLayer_predict_gl(real32_T layer_Weights[512], const
    real32_T layer_Bias[2], real32_T X[256], real32_T Z[2]);
  void motion_contro_dlnetwork_predict(c_coder_internal_ctarget_dlne_T *obj,
    const real32_T varargin_1_Data[15], real32_T varargout_1_Data[2]);
  void motion__SystemCore_setup_il4ksq(ros_slros2_internal_block_Pub_T *obj);
  void motion_SystemCore_setup_il4ksqt(ros_slros2_internal_block_Pub_T *obj);
  void motion_con_SystemCore_setup_il4(ros_slros2_internal_block_Sub_T *obj);
  void motion_co_SystemCore_setup_il4k(ros_slros2_internal_block_Sub_T *obj);
  void motio_SystemCore_setup_il4ksqtk(ros_slros2_internal_block_Sub_T *obj);
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_i(ros_slros2_internal_block_Pub_T *obj);
  void motion_cont_SystemCore_setup_il(ros_slros2_internal_block_Pub_T *obj);
  void moti_SystemCore_setup_il4ksqtkm(ros_slros2_internal_block_Sub_T *obj);
  void motion_c_SystemCore_setup_il4ks(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_wi_T motion_controller_withTD3_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S42>/Display' : Unused code path elimination
//  Block '<S42>/Display1' : Unused code path elimination
//  Block '<S44>/Display' : Unused code path elimination
//  Block '<S44>/Display1' : Unused code path elimination
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
//  Block '<S13>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'motion_controller_withTD3'
//  '<S1>'   : 'motion_controller_withTD3/Chart'
//  '<S2>'   : 'motion_controller_withTD3/Compare To Constant'
//  '<S3>'   : 'motion_controller_withTD3/MATLAB Function1'
//  '<S4>'   : 'motion_controller_withTD3/MATLAB Function2'
//  '<S5>'   : 'motion_controller_withTD3/StateFlow'
//  '<S6>'   : 'motion_controller_withTD3/StateFlow1'
//  '<S7>'   : 'motion_controller_withTD3/StateFlow5'
//  '<S8>'   : 'motion_controller_withTD3/Subsystem1'
//  '<S9>'   : 'motion_controller_withTD3/Subsystem2'
//  '<S10>'  : 'motion_controller_withTD3/Subsystem3'
//  '<S11>'  : 'motion_controller_withTD3/Subsystem5'
//  '<S12>'  : 'motion_controller_withTD3/cmd_pub'
//  '<S13>'  : 'motion_controller_withTD3/controller'
//  '<S14>'  : 'motion_controller_withTD3/controller1'
//  '<S15>'  : 'motion_controller_withTD3/subscription'
//  '<S16>'  : 'motion_controller_withTD3/StateFlow/Blank Message1'
//  '<S17>'  : 'motion_controller_withTD3/StateFlow/Publish2'
//  '<S18>'  : 'motion_controller_withTD3/StateFlow1/Blank Message1'
//  '<S19>'  : 'motion_controller_withTD3/StateFlow1/Publish2'
//  '<S20>'  : 'motion_controller_withTD3/StateFlow5/Blank Message1'
//  '<S21>'  : 'motion_controller_withTD3/StateFlow5/Publish2'
//  '<S22>'  : 'motion_controller_withTD3/Subsystem1/Chart'
//  '<S23>'  : 'motion_controller_withTD3/Subsystem1/For Each Subsystem'
//  '<S24>'  : 'motion_controller_withTD3/Subsystem1/MATLAB Function'
//  '<S25>'  : 'motion_controller_withTD3/Subsystem1/MATLAB Function1'
//  '<S26>'  : 'motion_controller_withTD3/Subsystem1/Subscribe'
//  '<S27>'  : 'motion_controller_withTD3/Subsystem1/Subscribe1'
//  '<S28>'  : 'motion_controller_withTD3/Subsystem1/Subscribe2'
//  '<S29>'  : 'motion_controller_withTD3/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S30>'  : 'motion_controller_withTD3/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S31>'  : 'motion_controller_withTD3/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S32>'  : 'motion_controller_withTD3/Subsystem3/Compare To Constant1'
//  '<S33>'  : 'motion_controller_withTD3/cmd_pub/Blank Message1'
//  '<S34>'  : 'motion_controller_withTD3/cmd_pub/Blank Message2'
//  '<S35>'  : 'motion_controller_withTD3/cmd_pub/For Each Subsystem'
//  '<S36>'  : 'motion_controller_withTD3/cmd_pub/For Each Subsystem1'
//  '<S37>'  : 'motion_controller_withTD3/cmd_pub/Publish'
//  '<S38>'  : 'motion_controller_withTD3/cmd_pub/Publish2'
//  '<S39>'  : 'motion_controller_withTD3/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S40>'  : 'motion_controller_withTD3/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S41>'  : 'motion_controller_withTD3/controller/Chart'
//  '<S42>'  : 'motion_controller_withTD3/controller/Subsystem'
//  '<S43>'  : 'motion_controller_withTD3/controller/get_angle_4w'
//  '<S44>'  : 'motion_controller_withTD3/controller/get_effort'
//  '<S45>'  : 'motion_controller_withTD3/controller/get_spd'
//  '<S46>'  : 'motion_controller_withTD3/controller/Subsystem/Chart2'
//  '<S47>'  : 'motion_controller_withTD3/controller/Subsystem/MATLAB Function'
//  '<S48>'  : 'motion_controller_withTD3/controller/get_angle_4w/MATLAB Function'
//  '<S49>'  : 'motion_controller_withTD3/controller/get_effort/MATLAB Function'
//  '<S50>'  : 'motion_controller_withTD3/controller/get_spd/MATLAB Function'
//  '<S51>'  : 'motion_controller_withTD3/controller1/MATLAB Function'
//  '<S52>'  : 'motion_controller_withTD3/controller1/Policy'
//  '<S53>'  : 'motion_controller_withTD3/controller1/Policy/PolicyWrapper'
//  '<S54>'  : 'motion_controller_withTD3/subscription/For Each Subsystem'
//  '<S55>'  : 'motion_controller_withTD3/subscription/Subscribe'
//  '<S56>'  : 'motion_controller_withTD3/subscription/Subscribe1'
//  '<S57>'  : 'motion_controller_withTD3/subscription/display'
//  '<S58>'  : 'motion_controller_withTD3/subscription/Subscribe/Enabled Subsystem'
//  '<S59>'  : 'motion_controller_withTD3/subscription/Subscribe1/Enabled Subsystem'

#endif                               // RTW_HEADER_motion_controller_withTD3_h_

//
// File trailer for generated code.
//
// [EOF]
//
