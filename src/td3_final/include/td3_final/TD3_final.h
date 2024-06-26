//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TD3_final.h
//
// Code generated for Simulink model 'TD3_final'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Jun 21 14:28:05 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TD3_final_h_
#define RTW_HEADER_TD3_final_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "TD3_final_types.h"

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

// Block signals (default storage)
struct B_TD3_final_T {
  real32_T g[65536];
  real32_T e[4096];
  real32_T k[512];
  real32_T outT_f7_0_f1[256];
  real32_T fv[256];
  real32_T fv1[256];
  SL_Bus_custom_interfaces_ActuatorCommand actuaor_command;// '<Root>/Bus Assignment2' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S2>/Bus Assignment1' 
  real32_T fv2[16];
  real32_T varargin_1_Data[16];
  real_T delta[4];                     // '<Root>/MATLAB Function'
  cell_wrap_2_TD3_final_T b;
  cell_wrap_2_TD3_final_T c;
  dlarray_1_TD3_final_T dlArrayOutputs;
  real_T cf;
  real_T cr;
  real_T minval_idx_0;
  real_T minval_idx_1;
  real_T rtb_delta_tmp_tmp;
  real_T rtb_delta_tmp_tmp_m;
  real_T rtb_delta_tmp;
  real_T rtb_delta_tmp_c;
  real32_T fv3[2];
  real32_T bTemp;
  int32_T ForEach_itr;
  int32_T i;
  int32_T heightIdx;
  int32_T i1;
  int32_T i_k;
  int32_T k_c;
  int32_T i0_ub;
  int32_T k0_ub;
  int32_T j1;
  int32_T N2;
  int32_T k0;
  int32_T K2;
  int32_T i0;
  int32_T i2;
  int32_T i_b;
  int32_T j;
  int32_T idxA;
  int32_T idxB;
  int32_T idxC;
  int32_T idxA_p;
  int32_T idxB_c;
  int32_T k_f;
  int32_T c_tmp;
  int32_T c_tmp_g;
  int32_T c_tmp_g1;
  int32_T c_tmp_m;
  int32_T i3;
};

// Block states (default storage) for system '<Root>'
struct DW_TD3_final_T {
  c_rl_codegen_policy_rlDetermi_T policy;// '<S4>/PolicyWrapper'
  rl_codegen_model_DLNetworkMod_T gobj_2;// '<S4>/PolicyWrapper'
  ros_slros2_internal_block_Cur_T obj; // '<Root>/Current Time'
  ros_slros2_internal_block_Pub_T obj_l;// '<S5>/SinkBlock'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<Root>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<Root>/Discrete-Time Integrator1'
  c_coder_internal_ctarget_dlne_T gobj_1;// '<S4>/PolicyWrapper'
  boolean_T policy_not_empty;          // '<S4>/PolicyWrapper'
};

// Parameters for system: '<Root>/For Each Subsystem'
struct P_CoreSubsys_TD3_final_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S6>/Constant'

};

// Parameters (default storage)
struct P_TD3_final_T_ {
  real_T B;                            // Variable: B
                                          //  Referenced by: '<Root>/MATLAB Function'

  real_T L;                            // Variable: L
                                          //  Referenced by: '<Root>/MATLAB Function'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S1>/Constant'

  real_T Constant_Value_f[16];         // Expression: zeros(1, 16)
                                          //  Referenced by: '<Root>/Constant'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<Root>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_IC;   // Expression: 0
                                          //  Referenced by: '<Root>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_UpperSa;// Expression: 0.6
                                            //  Referenced by: '<Root>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator2_LowerSa;// Expression: -0.6
                                            //  Referenced by: '<Root>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<Root>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<Root>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_UpperSa;// Expression: 0.6
                                            //  Referenced by: '<Root>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_LowerSa;// Expression: -0.6
                                            //  Referenced by: '<Root>/Discrete-Time Integrator1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<Root>/Saturation'

  P_CoreSubsys_TD3_final_T CoreSubsys; // '<Root>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_TD3_final_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model TD3_final
class TD3_final
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_TD3_final_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  TD3_final();

  // Destructor
  ~TD3_final();

  // private data and function members
 private:
  // Block signals
  B_TD3_final_T TD3_final_B;

  // Block states
  DW_TD3_final_T TD3_final_DW;

  // Tunable parameters
  static P_TD3_final_T TD3_final_P;

  // private member function(s) for subsystem '<Root>'
  void TD3_final_microKernel11(int32_T K, real32_T *A, int32_T LDA, const
    real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void TD3_final_macroKernel1(int32_T M, int32_T K, int32_T N, const real32_T *A,
    int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
  void TD3_final_matrixMultiply1(int32_T M, int32_T K, int32_T N, int32_T
    blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
    real32_T *B, real32_T *C);
  void TD3_FullyConnectedLayer_predict(real32_T layer_Weights[4096], const
    real32_T layer_Bias[256], real32_T X[16], real32_T Z[256]);
  void T_FullyConnectedLayer_predict_b(real32_T layer_Weights[65536], const
    real32_T layer_Bias[256], real32_T X[256], real32_T Z[256]);
  void TD3_final_elementwise_relu(const real32_T *inputTensor, real32_T
    *outputTensor, int32_T numElements);
  void TD3_final_unaryElementwise(real32_T X[256], real32_T Z[256]);
  void FullyConnectedLayer_predict_bl(real32_T layer_Weights[512], const
    real32_T layer_Bias[2], real32_T X[256], real32_T Z[2]);
  void TD3_final_dlnetwork_predict(c_coder_internal_ctarget_dlne_T *obj, const
    real32_T varargin_1_Data[16], real32_T varargout_1_Data[2]);
  void TD3_final_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_TD3_final_T TD3_final_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'TD3_final'
//  '<S1>'   : 'TD3_final/Blank Message1'
//  '<S2>'   : 'TD3_final/For Each Subsystem'
//  '<S3>'   : 'TD3_final/MATLAB Function'
//  '<S4>'   : 'TD3_final/Policy'
//  '<S5>'   : 'TD3_final/Publish2'
//  '<S6>'   : 'TD3_final/For Each Subsystem/Blank Message4'
//  '<S7>'   : 'TD3_final/Policy/PolicyWrapper'

#endif                                 // RTW_HEADER_TD3_final_h_

//
// File trailer for generated code.
//
// [EOF]
//
