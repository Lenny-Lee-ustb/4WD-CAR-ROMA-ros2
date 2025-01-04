//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: td3_test1.h
//
// Code generated for Simulink model 'td3_test1'.
//
// Model version                  : 1.18
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Jun 28 10:47:56 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_td3_test1_h_
#define RTW_HEADER_td3_test1_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "td3_test1_types.h"

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

// Block signals for system '<S4>/Current Time'
struct B_CurrentTime_td3_test1_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S4>/Current Time'
};

// Block states (default storage) for system '<S4>/Current Time'
struct DW_CurrentTime_td3_test1_T {
  ros_slros2_internal_block_Cur_T obj; // '<S4>/Current Time'
  boolean_T objisempty;                // '<S4>/Current Time'
};

// Block signals (default storage)
struct B_td3_test1_T {
  real32_T g[65536];
  real32_T e[3840];
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S18>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  real32_T k[512];
  real32_T outT_f7_0_f1[256];
  real32_T fv[256];
  real32_T fv1[256];
  SL_Bus_nav_msgs_Odometry In1_e;      // '<S16>/In1'
  SL_Bus_nav_msgs_Odometry b_varargout_2_m;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S4>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S22>/Bus Assignment1' 
  SL_Bus_sensor_msgs_Imu In1_j;        // '<S17>/In1'
  SL_Bus_sensor_msgs_Imu b_varargout_2_c;
  SL_Bus_sbus_interface_Sbus In1_i;    // '<S31>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_k;
  real_T ImpAsg_InsertedFor_Out1_at_[16];
  real32_T fv2[15];
  real32_T varargin_1_Data[15];
  real_T delta[4];                     // '<S5>/MATLAB Function'
  cell_wrap_2_td3_test1_T b;
  cell_wrap_2_td3_test1_T c;
  dlarray_1_td3_test1_T dlArrayOutputs;
  real_T y;                            // '<S3>/Chart'
  real_T yaw;                          // '<S3>/Chart'
  real_T cf;
  real_T cr;
  real_T b_value;
  real_T rtb_delta_tmp_tmp;
  real_T rtb_delta_tmp_tmp_c;
  real_T rtb_delta_tmp;
  real_T rtb_delta_tmp_b;
  real32_T fv3[2];
  real32_T bTemp;
  int32_T mode;                        // '<Root>/Chart'
  int32_T ForEach_itr_k_p;
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_p_f;
  int32_T heightIdx;
  int32_T i;
  int32_T i1;
  int32_T i_g;
  int32_T k_g;
  int32_T i0_ub;
  int32_T k0_ub;
  int32_T j1;
  int32_T N2;
  int32_T k0;
  int32_T K2;
  int32_T i0;
  int32_T i2;
  int32_T i_m;
  int32_T j;
  int32_T idxA;
  int32_T idxB;
  int32_T idxC;
  int32_T idxA_n;
  int32_T idxB_p;
  int32_T k_l;
  int32_T c_tmp;
  int32_T c_tmp_j;
  int32_T c_tmp_d;
  int32_T c_tmp_g;
  int32_T i3;
  boolean_T Compare;                   // '<S7>/Compare'
  boolean_T rtb_steer_activated_l;
  B_CurrentTime_td3_test1_T CurrentTime1;// '<S4>/Current Time'
  B_CurrentTime_td3_test1_T CurrentTime;// '<S4>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_td3_test1_T {
  c_rl_codegen_policy_rlDetermi_T policy;// '<S28>/PolicyWrapper'
  rl_codegen_model_DLNetworkMod_T gobj_2;// '<S28>/PolicyWrapper'
  ros_slros2_internal_block_Get_T obj; // '<Root>/Get Parameter'
  ros_slros2_internal_block_Sub_T obj_o;// '<S30>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_b;// '<S15>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_bc;// '<S14>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_d;// '<S13>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_n;// '<S24>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_p;// '<S23>/SinkBlock'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S5>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S5>/Discrete-Time Integrator1'
  real_T delay;                        // '<S3>/Chart'
  real_T y_ini;                        // '<S3>/Chart'
  real_T yaw_ini;                      // '<S3>/Chart'
  real_T delay_k;                      // '<Root>/Chart'
  c_coder_internal_ctarget_dlne_T gobj_1;// '<S28>/PolicyWrapper'
  int8_T DiscreteTimeIntegrator2_PrevRes;// '<S5>/Discrete-Time Integrator2'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S5>/Discrete-Time Integrator1'
  uint8_T is_active_c4_td3_test1;      // '<S3>/Chart'
  uint8_T is_c4_td3_test1;             // '<S3>/Chart'
  uint8_T is_active_c5_td3_test1;      // '<Root>/Chart'
  uint8_T is_c5_td3_test1;             // '<Root>/Chart'
  boolean_T policy_not_empty;          // '<S28>/PolicyWrapper'
  DW_CurrentTime_td3_test1_T CurrentTime1;// '<S4>/Current Time'
  DW_CurrentTime_td3_test1_T CurrentTime;// '<S4>/Current Time'
};

// Parameters for system: '<S4>/For Each Subsystem'
struct P_CoreSubsys_td3_test1_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S25>/Constant'

};

// Parameters for system: '<S4>/For Each Subsystem1'
struct P_CoreSubsys_td3_test1_gm_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S26>/Constant'

};

// Parameters (default storage)
struct P_td3_test1_T_ {
  real_T B;                            // Variable: B
                                          //  Referenced by: '<S5>/MATLAB Function'

  real_T L;                            // Variable: L
                                          //  Referenced by: '<S5>/MATLAB Function'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S10>/Constant'

  int16_T ctc1_const;                  // Mask Parameter: ctc1_const
                                          //  Referenced by: '<S7>/Constant'

  int16_T ctc_const;                   // Mask Parameter: ctc_const
                                          //  Referenced by: '<S6>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S18>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S15>/Constant'

  SL_Bus_nav_msgs_Odometry Out1_Y0_h;  // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S16>/Out1'

  SL_Bus_nav_msgs_Odometry Constant_Value_p;// Computed Parameter: Constant_Value_p
                                               //  Referenced by: '<S13>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                               //  Referenced by: '<S20>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                               //  Referenced by: '<S19>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0_l;    // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S17>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_d;// Computed Parameter: Constant_Value_d
                                             //  Referenced by: '<S14>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S31>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_nd;// Computed Parameter: Constant_Value_nd
                                                  //  Referenced by: '<S30>/Constant'

  real_T Constant_Value_g[4];          // Expression: zeros(4,1)
                                          //  Referenced by: '<Root>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S4>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S4>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S4>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S4>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S4>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S4>/Saturation'

  real_T Constant6_Value[4];           // Expression: zeros(4,1)
                                          //  Referenced by: '<Root>/Constant6'

  real_T Gain_Gain;                    // Expression: 2/500
                                          //  Referenced by: '<Root>/Gain'

  real_T Gain1_Gain[4];                // Expression: [1;-1;-1;1]
                                          //  Referenced by: '<Root>/Gain1'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<S5>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                          //  Referenced by: '<S5>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S5>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S5>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_UpperSa;// Expression: 0.5
                                            //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_LowerSa;// Expression: -0.5
                                            //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T Constant1_Value;              // Expression: 500
                                          //  Referenced by: '<S3>/Constant1'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant5'

  real_T Constant_Value_m2;            // Expression: 0.35
                                          //  Referenced by: '<S3>/Constant'

  P_CoreSubsys_td3_test1_gm_T CoreSubsys_pn;// '<S4>/For Each Subsystem1'
  P_CoreSubsys_td3_test1_g_T CoreSubsys_p;// '<S4>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_td3_test1_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model td3_test1
class td3_test1
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_td3_test1_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  td3_test1();

  // Destructor
  ~td3_test1();

  // private data and function members
 private:
  // Block signals
  B_td3_test1_T td3_test1_B;

  // Block states
  DW_td3_test1_T td3_test1_DW;

  // Tunable parameters
  static P_td3_test1_T td3_test1_P;

  // private member function(s) for subsystem '<S4>/Current Time'
  static void td3_test1_CurrentTime_Init(DW_CurrentTime_td3_test1_T *localDW);
  void td3_test1_CurrentTime(B_CurrentTime_td3_test1_T *localB);
  static void td3_test1_CurrentTime_Term(DW_CurrentTime_td3_test1_T *localDW);

  // private member function(s) for subsystem '<Root>'
  void td3_test1_microKernel11(int32_T K, real32_T *A, int32_T LDA, const
    real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void td3_test1_macroKernel1(int32_T M, int32_T K, int32_T N, const real32_T *A,
    int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void td3_test1_matrixMultiply1(int32_T M, int32_T K, int32_T N, int32_T
    blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
    real32_T *B, real32_T *C);
  void td3_FullyConnectedLayer_predict(real32_T layer_Weights[3840], const
    real32_T layer_Bias[256], real32_T X[15], real32_T Z[256]);
  void t_FullyConnectedLayer_predict_d(real32_T layer_Weights[65536], const
    real32_T layer_Bias[256], real32_T X[256], real32_T Z[256]);
  void td3_test1_elementwise_relu(const real32_T *inputTensor, real32_T
    *outputTensor, int32_T numElements);
  void td3_test1_unaryElementwise(real32_T X[256], real32_T Z[256]);
  void FullyConnectedLayer_predict_dv(real32_T layer_Weights[512], const
    real32_T layer_Bias[2], real32_T X[256], real32_T Z[2]);
  void td3_test1_dlnetwork_predict(c_coder_internal_ctarget_dlne_T *obj, const
    real32_T varargin_1_Data[15], real32_T varargout_1_Data[2]);
  void td3_test1_SystemCore_setup_b1c(ros_slros2_internal_block_Pub_T *obj);
  void td3_test1_SystemCore_setup_b1cf(ros_slros2_internal_block_Pub_T *obj);
  void td3_test1_SystemCore_setup_b1(ros_slros2_internal_block_Sub_T *obj);
  void td3_test_SystemCore_setup_b1cf2(ros_slros2_internal_block_Sub_T *obj);
  void td3_test1_SystemCore_setup(ros_slros2_internal_block_Sub_T *obj);
  void td3_test1_SystemCore_setup_b(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_td3_test1_T td3_test1_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/Display1' : Unused code path elimination
//  Block '<Root>/Display2' : Unused code path elimination
//  Block '<Root>/Display3' : Unused code path elimination
//  Block '<Root>/Display4' : Unused code path elimination
//  Block '<Root>/Display5' : Unused code path elimination


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
//  '<Root>' : 'td3_test1'
//  '<S1>'   : 'td3_test1/Chart'
//  '<S2>'   : 'td3_test1/MATLAB Function3'
//  '<S3>'   : 'td3_test1/Subsystem'
//  '<S4>'   : 'td3_test1/cmd_pub'
//  '<S5>'   : 'td3_test1/controller'
//  '<S6>'   : 'td3_test1/ctc'
//  '<S7>'   : 'td3_test1/ctc1'
//  '<S8>'   : 'td3_test1/sbus'
//  '<S9>'   : 'td3_test1/Subsystem/Chart'
//  '<S10>'  : 'td3_test1/Subsystem/Compare To Constant'
//  '<S11>'  : 'td3_test1/Subsystem/For Each Subsystem'
//  '<S12>'  : 'td3_test1/Subsystem/MATLAB Function'
//  '<S13>'  : 'td3_test1/Subsystem/Subscribe'
//  '<S14>'  : 'td3_test1/Subsystem/Subscribe1'
//  '<S15>'  : 'td3_test1/Subsystem/Subscribe2'
//  '<S16>'  : 'td3_test1/Subsystem/Subscribe/Enabled Subsystem'
//  '<S17>'  : 'td3_test1/Subsystem/Subscribe1/Enabled Subsystem'
//  '<S18>'  : 'td3_test1/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S19>'  : 'td3_test1/cmd_pub/Blank Message1'
//  '<S20>'  : 'td3_test1/cmd_pub/Blank Message2'
//  '<S21>'  : 'td3_test1/cmd_pub/For Each Subsystem'
//  '<S22>'  : 'td3_test1/cmd_pub/For Each Subsystem1'
//  '<S23>'  : 'td3_test1/cmd_pub/Publish'
//  '<S24>'  : 'td3_test1/cmd_pub/Publish2'
//  '<S25>'  : 'td3_test1/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S26>'  : 'td3_test1/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S27>'  : 'td3_test1/controller/MATLAB Function'
//  '<S28>'  : 'td3_test1/controller/Policy'
//  '<S29>'  : 'td3_test1/controller/Policy/PolicyWrapper'
//  '<S30>'  : 'td3_test1/sbus/Subscribe'
//  '<S31>'  : 'td3_test1/sbus/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_td3_test1_h_

//
// File trailer for generated code.
//
// [EOF]
//
