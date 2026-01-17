//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: agent2.h
//
// Code generated for Simulink model 'agent2'.
//
// Model version                  : 2.413
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan 17 22:00:06 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_agent2_h_
#define RTW_HEADER_agent2_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "agent2_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S8>/Current Time'
struct B_CurrentTime_agent2_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S8>/Current Time'
};

// Block states (default storage) for system '<S8>/Current Time'
struct DW_CurrentTime_agent2_T {
  ros_slros2_internal_block_Cur_T obj; // '<S8>/Current Time'
  boolean_T objisempty;                // '<S8>/Current Time'
};

// Block signals (default storage)
struct B_agent2_T {
  real32_T g[65536];
  real32_T e[3840];
  SL_Bus_custom_interfaces_ActuatorState In1_j;// '<S29>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  real32_T k[512];
  real_T t_data[200];
  real_T b_x[200];
  real32_T outT_f7_0_f1[256];
  real32_T fv[256];
  real32_T fv1[256];
  SL_Bus_nav_msgs_Odometry In1_je;     // '<S27>/In1'
  SL_Bus_nav_msgs_Odometry b_varargout_2_m;
  real_T x[100];
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S8>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S35>/Bus Assignment1' 
  SL_Bus_sensor_msgs_Imu In1_f;        // '<S28>/In1'
  SL_Bus_sensor_msgs_Imu BusAssignment2;// '<S4>/Bus Assignment2'
  real_T c_x[50];
  SL_Bus_sbus_interface_Sbus In1_m;    // '<S58>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_c;
  real_T ImpAsg_InsertedFor_Out1_a_k[16];
  real32_T rtb_e_Y_k[15];
  real32_T varargin_1_Data[15];
  SL_Bus_geometry_msgs_Twist BusAssignment2_l;// '<S3>/Bus Assignment2'
  real_T delta[4];                     // '<S10>/MATLAB Function'
  real_T Divide[4];                    // '<S6>/Divide'
  real_T Saturation_o[4];              // '<S6>/Saturation'
  cell_wrap_2_agent2_T b;
  cell_wrap_2_agent2_T c;
  dlarray_1_agent2_T dlArrayOutputs;
  real_T out;                          // '<S41>/Chart2'
  real_T GetParameter1;                // '<S9>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S9>/Chart'
  real_T spd_cmd[4];                   // '<S9>/Chart'
  real_T effort_cmd[4];                // '<S9>/Chart'
  real_T y;                            // '<S5>/Chart'
  real_T yaw;                          // '<S5>/Chart'
  real_T e_yaw;
  real_T b_value;
  real_T b_value_c;
  real_T b_value_b;
  real_T b_value_p;
  real_T Yp;                           // '<S5>/MATLAB Function1'
  real_T vxp;                          // '<S5>/MATLAB Function1'
  real_T vyp;                          // '<S5>/MATLAB Function1'
  real_T rp;                           // '<S5>/MATLAB Function2'
  real_T Ayp;                          // '<S5>/MATLAB Function2'
  real_T Add1;                         // '<S13>/Add1'
  real_T e_Y;                          // '<S11>/MATLAB Function1'
  real_T e_Yd;                         // '<S11>/MATLAB Function1'
  real_T e_yawd;                       // '<S11>/MATLAB Function1'
  real_T delta_tmp_tmp;
  real_T delta_tmp;
  real_T delta_tmp_c;
  real_T rtb_e_Y_tmp;
  real32_T fv2[2];
  real32_T bTemp;
  int32_T f_k;
  int32_T h_k;
  int32_T isMpcEnable;                 // '<Root>/Chart'
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_j_f;
  int32_T ForEach_itr_p_g;
  int32_T k_g;
  int32_T heightIdx;
  int32_T i;
  int32_T i1;
  int32_T i_m;
  int32_T k_n;
  int32_T i0_ub;
  int32_T k0_ub;
  int32_T j1;
  int32_T N2;
  int32_T k0;
  int32_T K2;
  int32_T i0;
  int32_T i2;
  int32_T i_p;
  int32_T j;
  int32_T idxA;
  int32_T idxB;
  int32_T idxC;
  int32_T idxA_l;
  int32_T idxB_j;
  int32_T k_d;
  int32_T c_tmp;
  int32_T c_tmp_g;
  int32_T c_tmp_l;
  int32_T c_tmp_d;
  int32_T i3;
  int16_T i4;
  int8_T mode;                         // '<S9>/Chart'
  boolean_T b_value_d;
  boolean_T Compare;                   // '<S31>/Compare'
  boolean_T LogicalOperator_j;         // '<S12>/Logical Operator'
  B_CurrentTime_agent2_T CurrentTime1; // '<S8>/Current Time'
  B_CurrentTime_agent2_T CurrentTime;  // '<S8>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_agent2_T {
  c_rl_codegen_policy_rlDetermi_T policy;// '<S51>/PolicyWrapper'
  rl_codegen_model_DLNetworkMod_T gobj_2;// '<S51>/PolicyWrapper'
  ros_slros2_internal_block_Get_T obj; // '<S14>/Get Parameter22'
  ros_slros2_internal_block_Get_T obj_o;// '<S14>/Get Parameter21'
  ros_slros2_internal_block_Get_T obj_f;// '<S14>/Get Parameter20'
  ros_slros2_internal_block_Get_T obj_k;// '<S14>/Get Parameter19'
  ros_slros2_internal_block_Get_T obj_h;// '<S14>/Get Parameter18'
  ros_slros2_internal_block_Get_T obj_m;// '<S13>/Get Parameter20'
  ros_slros2_internal_block_Get_T obj_l;// '<S44>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_a;// '<S43>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_lw;// '<S43>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_ae;// '<S43>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_d;// '<S43>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_g;// '<S41>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_e;// '<S41>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_c;// '<S41>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o1;// '<S41>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_mf;// '<S41>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_f2;// '<S9>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_cc;// '<S6>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_p;// '<S6>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_ls;// '<S6>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_i;// '<S6>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_lv;// '<S5>/Get Parameter7'
  ros_slros2_internal_block_Get_T obj_as;// '<S5>/Get Parameter6'
  ros_slros2_internal_block_Get_T obj_mo;// '<S5>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_b;// '<S5>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_hw;// '<S5>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_fa;// '<S5>/Get Parameter22'
  ros_slros2_internal_block_Get_T obj_c4;// '<S5>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_f5;// '<S5>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_k1;// '<Root>/Get Parameter8'
  ros_slros2_internal_block_Get_T obj_b2;// '<Root>/Get Parameter7'
  ros_slros2_internal_block_Get_T obj_iv;// '<Root>/Get Parameter6'
  ros_slros2_internal_block_Get_T obj_n;// '<Root>/Get Parameter1'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S37>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_bq;// '<S36>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_ar;// '<S18>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_lp;// '<S16>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_moi;// '<S56>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_nf;// '<S55>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_dp;// '<S26>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_en;// '<S25>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_az;// '<S24>/SourceBlock'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S10>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S10>/Discrete-Time Integrator2'
  real_T yd;                           // '<S14>/MATLAB Function2'
  real_T data50[50];                   // '<S14>/MATLAB Function2'
  real_T gaussian_kernel50[50];        // '<S14>/MATLAB Function2'
  real_T data100[100];                 // '<S14>/MATLAB Function2'
  real_T gaussian_kernel100[100];      // '<S14>/MATLAB Function2'
  real_T data200[200];                 // '<S14>/MATLAB Function2'
  real_T gaussian_kernel200[200];      // '<S14>/MATLAB Function2'
  real_T angle_out;                    // '<S41>/MATLAB Function'
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
  c_coder_internal_ctarget_dlne_T gobj_1;// '<S51>/PolicyWrapper'
  uint8_T is_active_c6_agent2;         // '<S41>/Chart2'
  uint8_T is_active_c3_agent2;         // '<S9>/Chart'
  uint8_T is_Is_ready;                 // '<S9>/Chart'
  uint8_T is_cmd;                      // '<S9>/Chart'
  uint8_T is_qtest;                    // '<S9>/Chart'
  uint8_T is_active_c7_agent2;         // '<S5>/Chart'
  uint8_T is_c7_agent2;                // '<S5>/Chart'
  uint8_T is_active_c18_agent2;        // '<Root>/Chart'
  uint8_T is_c18_agent2;               // '<Root>/Chart'
  boolean_T yd_not_empty;              // '<S14>/MATLAB Function2'
  boolean_T policy_not_empty;          // '<S51>/PolicyWrapper'
  boolean_T ready;                     // '<S9>/Chart'
  boolean_T controller1_MODE;          // '<Root>/controller1'
  DW_CurrentTime_agent2_T CurrentTime1;// '<S8>/Current Time'
  DW_CurrentTime_agent2_T CurrentTime; // '<S8>/Current Time'
};

// Parameters for system: '<S8>/For Each Subsystem'
struct P_CoreSubsys_agent2_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S38>/Constant'

};

// Parameters for system: '<S8>/For Each Subsystem1'
struct P_CoreSubsys_agent2_gm_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S39>/Constant'

};

// Parameters (default storage)
struct P_agent2_T_ {
  real_T B;                            // Variable: B
                                          //  Referenced by: '<S10>/MATLAB Function'

  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S10>/MATLAB Function'
                                          //    '<S42>/MATLAB Function'
                                          //    '<S44>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S42>/MATLAB Function'
                                          //    '<S44>/MATLAB Function'

  real_T b;                            // Variable: b
                                          //  Referenced by: '<S44>/MATLAB Function'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S31>/Constant'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S30>/Constant'

  int16_T CompareToConstant_const_m;// Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S2>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S29>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                      //  Referenced by: '<S59>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S56>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                             //  Referenced by: '<S26>/Constant'

  SL_Bus_nav_msgs_Odometry Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S27>/Out1'

  SL_Bus_nav_msgs_Odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S24>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S33>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S32>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0_e;    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S28>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_e;// Computed Parameter: Constant_Value_e
                                             //  Referenced by: '<S25>/Constant'

  SL_Bus_sensor_msgs_Imu Constant_Value_m;// Computed Parameter: Constant_Value_m
                                             //  Referenced by: '<S17>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S58>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S55>/Constant'

  SL_Bus_geometry_msgs_Twist Constant_Value_ik;// Computed Parameter: Constant_Value_ik
                                                  //  Referenced by: '<S15>/Constant'

  real_T Gain2_Gain;                   // Expression: 0
                                          //  Referenced by: '<S6>/Gain2'

  real_T Gain1_Gain;                   // Expression: 0.4
                                          //  Referenced by: '<S6>/Gain1'

  real_T Gain_Gain;                    // Expression: 0
                                          //  Referenced by: '<S6>/Gain'

  real_T Constant_Value_by;            // Expression: 2
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
                                          //  Referenced by: '<S43>/MATLAB Function'

  real_T MATLABFunction_Re;            // Expression: Re
                                          //  Referenced by: '<S43>/MATLAB Function'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S43>/Constant4'

  real_T Gain_Gain_m;                  // Expression: 0
                                          //  Referenced by: '<S44>/Gain'

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S41>/Constant2'

  real_T Gain1_Gain_k;                 // Expression: 1/500
                                          //  Referenced by: '<S41>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S41>/Constant'

  real_T Gain_Gain_f;                  // Expression: 1/500
                                          //  Referenced by: '<S41>/Gain'

  real_T Gain2_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S41>/Gain2'

  real_T Constant_Value_o;             // Expression: 0
                                          //  Referenced by: '<S9>/Constant'

  real_T steer_Y0;                     // Computed Parameter: steer_Y0
                                          //  Referenced by: '<S10>/steer'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<S10>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                          //  Referenced by: '<S10>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S10>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S10>/Discrete-Time Integrator2'

  real_T Constant1_Value;              // Expression: 500
                                          //  Referenced by: '<S7>/Constant1'

  real_T Constant_Value_j;             // Expression: 0.411
                                          //  Referenced by: '<S5>/Constant'

  real_T Saturation_UpperSat_a;        // Expression: 1
                                          //  Referenced by: '<S14>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: 0
                                          //  Referenced by: '<S14>/Saturation'

  real_T Constant1_Value_n;            // Expression: 0.411
                                          //  Referenced by: '<S13>/Constant1'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S11>/Constant1'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S11>/Constant3'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S11>/Constant5'

  real_T Saturation_UpperSat_h;        // Expression: 0.4
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -0.4
                                          //  Referenced by: '<S6>/Saturation'

  real_T Gain4_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<S6>/Gain4'

  real_T Gain3_Gain[4];                // Expression: [1;1;0;0]
                                          //  Referenced by: '<S6>/Gain3'

  P_CoreSubsys_agent2_gm_T CoreSubsys_pn;// '<S8>/For Each Subsystem1'
  P_CoreSubsys_agent2_g_T CoreSubsys_p;// '<S8>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_agent2_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model agent2
class agent2
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_agent2_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  agent2();

  // Destructor
  ~agent2();

  // private data and function members
 private:
  // Block signals
  B_agent2_T agent2_B;

  // Block states
  DW_agent2_T agent2_DW;

  // Tunable parameters
  static P_agent2_T agent2_P;

  // private member function(s) for subsystem '<S8>/Current Time'
  static void agent2_CurrentTime_Init(DW_CurrentTime_agent2_T *localDW);
  void agent2_CurrentTime(B_CurrentTime_agent2_T *localB);
  static void agent2_CurrentTime_Term(DW_CurrentTime_agent2_T *localDW);

  // private member function(s) for subsystem '<S9>/get_angle_4w'
  void agent2_get_angle_4w(real_T rtu_delta_f, real_T rtu_delta_r, real_T
    rty_angle_cmd[4]) const;

  // private member function(s) for subsystem '<S9>/get_effort'
  void agent2_get_effort_Init();
  void agent2_get_effort();
  void agent2_get_effort_Term();

  // private member function(s) for subsystem '<S9>/get_spd'
  void agent2_get_spd_Init();
  void agent2_get_spd(real_T rtu_angle, real_T rtu_longdrive, real_T
                      rty_spd_cmd[4]);
  void agent2_get_spd_Term();

  // private member function(s) for subsystem '<Root>'
  void agent2_microKernel11(int32_T K, real32_T *A, int32_T LDA, const real32_T *
    B, int32_T LDB, real32_T *C, int32_T LDC);
  void agent2_macroKernel1(int32_T M, int32_T K, int32_T N, const real32_T *A,
    int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void agent2_matrixMultiply1(int32_T M, int32_T K, int32_T N, int32_T
    blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
    real32_T *B, real32_T *C);
  void age_FullyConnectedLayer_predict(real32_T layer_Weights[3840], const
    real32_T layer_Bias[256], real32_T X[15], real32_T Z[256]);
  void a_FullyConnectedLayer_predict_g(real32_T layer_Weights[65536], const
    real32_T layer_Bias[256], real32_T X[256], real32_T Z[256]);
  void agent2_elementwise_relu(const real32_T *inputTensor, real32_T
    *outputTensor, int32_T numElements);
  void agent2_unaryElementwise(real32_T X[256], real32_T Z[256]);
  void FullyConnectedLayer_predict_gl(real32_T layer_Weights[512], const
    real32_T layer_Bias[2], real32_T X[256], real32_T Z[2]);
  void agent2_dlnetwork_predict(c_coder_internal_ctarget_dlne_T *obj, const
    real32_T varargin_1_Data[15], real32_T varargout_1_Data[2]);
  void agent2_SystemCore_setup_begq2(ros_slros2_internal_block_Pub_T *obj);
  void agent2_SystemCore_setup_begq2c(ros_slros2_internal_block_Pub_T *obj);
  void agent2_SystemCore_setup_be(ros_slros2_internal_block_Sub_T *obj);
  void agent2_SystemCore_setup_beg(ros_slros2_internal_block_Sub_T *obj);
  void agent2_SystemCore_setup_begq2cx(ros_slros2_internal_block_Sub_T *obj);
  void agent2_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void agent2_SystemCore_setup_b(ros_slros2_internal_block_Pub_T *obj);
  void agent_SystemCore_setup_begq2cxu(ros_slros2_internal_block_Sub_T *obj);
  void agent2_SystemCore_setup_begq(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_agent2_T agent2_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S41>/Display' : Unused code path elimination
//  Block '<S41>/Display1' : Unused code path elimination
//  Block '<S43>/Display' : Unused code path elimination
//  Block '<S43>/Display1' : Unused code path elimination
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
//  '<Root>' : 'agent2'
//  '<S1>'   : 'agent2/Chart'
//  '<S2>'   : 'agent2/Compare To Constant'
//  '<S3>'   : 'agent2/StateFlow1'
//  '<S4>'   : 'agent2/StateFlow5'
//  '<S5>'   : 'agent2/Subsystem1'
//  '<S6>'   : 'agent2/Subsystem2'
//  '<S7>'   : 'agent2/Subsystem3'
//  '<S8>'   : 'agent2/cmd_pub'
//  '<S9>'   : 'agent2/controller'
//  '<S10>'  : 'agent2/controller1'
//  '<S11>'  : 'agent2/getErrorForRL'
//  '<S12>'  : 'agent2/subscription'
//  '<S13>'  : 'agent2/t265toCG'
//  '<S14>'  : 'agent2/yawRateFilter'
//  '<S15>'  : 'agent2/StateFlow1/Blank Message1'
//  '<S16>'  : 'agent2/StateFlow1/Publish2'
//  '<S17>'  : 'agent2/StateFlow5/Blank Message1'
//  '<S18>'  : 'agent2/StateFlow5/Publish2'
//  '<S19>'  : 'agent2/Subsystem1/Chart'
//  '<S20>'  : 'agent2/Subsystem1/For Each Subsystem'
//  '<S21>'  : 'agent2/Subsystem1/MATLAB Function'
//  '<S22>'  : 'agent2/Subsystem1/MATLAB Function1'
//  '<S23>'  : 'agent2/Subsystem1/MATLAB Function2'
//  '<S24>'  : 'agent2/Subsystem1/Subscribe'
//  '<S25>'  : 'agent2/Subsystem1/Subscribe1'
//  '<S26>'  : 'agent2/Subsystem1/Subscribe2'
//  '<S27>'  : 'agent2/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S28>'  : 'agent2/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S29>'  : 'agent2/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S30>'  : 'agent2/Subsystem2/Compare To Constant'
//  '<S31>'  : 'agent2/Subsystem3/Compare To Constant1'
//  '<S32>'  : 'agent2/cmd_pub/Blank Message1'
//  '<S33>'  : 'agent2/cmd_pub/Blank Message2'
//  '<S34>'  : 'agent2/cmd_pub/For Each Subsystem'
//  '<S35>'  : 'agent2/cmd_pub/For Each Subsystem1'
//  '<S36>'  : 'agent2/cmd_pub/Publish'
//  '<S37>'  : 'agent2/cmd_pub/Publish2'
//  '<S38>'  : 'agent2/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S39>'  : 'agent2/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S40>'  : 'agent2/controller/Chart'
//  '<S41>'  : 'agent2/controller/Subsystem'
//  '<S42>'  : 'agent2/controller/get_angle_4w'
//  '<S43>'  : 'agent2/controller/get_effort'
//  '<S44>'  : 'agent2/controller/get_spd'
//  '<S45>'  : 'agent2/controller/Subsystem/Chart2'
//  '<S46>'  : 'agent2/controller/Subsystem/MATLAB Function'
//  '<S47>'  : 'agent2/controller/get_angle_4w/MATLAB Function'
//  '<S48>'  : 'agent2/controller/get_effort/MATLAB Function'
//  '<S49>'  : 'agent2/controller/get_spd/MATLAB Function'
//  '<S50>'  : 'agent2/controller1/MATLAB Function'
//  '<S51>'  : 'agent2/controller1/Policy'
//  '<S52>'  : 'agent2/controller1/Policy/PolicyWrapper'
//  '<S53>'  : 'agent2/getErrorForRL/MATLAB Function1'
//  '<S54>'  : 'agent2/subscription/For Each Subsystem'
//  '<S55>'  : 'agent2/subscription/Subscribe'
//  '<S56>'  : 'agent2/subscription/Subscribe1'
//  '<S57>'  : 'agent2/subscription/display'
//  '<S58>'  : 'agent2/subscription/Subscribe/Enabled Subsystem'
//  '<S59>'  : 'agent2/subscription/Subscribe1/Enabled Subsystem'
//  '<S60>'  : 'agent2/yawRateFilter/MATLAB Function2'

#endif                                 // RTW_HEADER_agent2_h_

//
// File trailer for generated code.
//
// [EOF]
//
