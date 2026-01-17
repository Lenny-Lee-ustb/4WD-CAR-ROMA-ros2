//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_cktest.h
//
// Code generated for Simulink model 'motion_controller_cktest'.
//
// Model version                  : 2.260
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jul 12 16:44:08 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_cktest_h_
#define RTW_HEADER_motion_controller_cktest_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_cktest_types.h"

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

// Block signals for system '<S2>/Current Time'
struct B_CurrentTime_motion_controll_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S2>/Current Time'
};

// Block states (default storage) for system '<S2>/Current Time'
struct DW_CurrentTime_motion_control_T {
  ros_slros2_internal_block_Cur_T obj; // '<S2>/Current Time'
  boolean_T objisempty;                // '<S2>/Current Time'
};

// Block signals (default storage)
struct B_motion_controller_cktest_T {
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S2>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S8>/Bus Assignment1' 
  SL_Bus_sbus_interface_Sbus In1;      // '<S25>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_m;
  real_T out;                          // '<S14>/Chart2'
  real_T GetParameter1;                // '<S3>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S3>/Chart'
  real_T spd_cmd[4];                   // '<S3>/Chart'
  real_T effort_cmd[4];                // '<S3>/Chart'
  real_T direction;
  real_T rate;
  real_T b_value;
  real_T b_value_c;
  real_T Gain2;                        // '<S14>/Gain2'
  int8_T mode;                         // '<S3>/Chart'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S2>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S2>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_cktest_T {
  ros_slros2_internal_block_Get_T obj; // '<S14>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_e;// '<S14>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l;// '<S14>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_c;// '<S14>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o;// '<S14>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_m;// '<S14>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_j;// '<S3>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_f;// '<S3>/Get Parameter1'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S10>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_b;// '<S9>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_mo;// '<S23>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S22>/SourceBlock'
  real_T angle_out;                    // '<S14>/MATLAB Function'
  real_T sum;                          // '<S3>/Chart'
  real_T counter;                      // '<S3>/Chart'
  real_T check;                        // '<S3>/Chart'
  uint8_T is_active_c6_motion_controller_;// '<S14>/Chart2'
  uint8_T is_active_c3_motion_controller_;// '<S3>/Chart'
  uint8_T is_Is_ready;                 // '<S3>/Chart'
  uint8_T is_cmd;                      // '<S3>/Chart'
  boolean_T ready;                     // '<S3>/Chart'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S2>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S2>/Current Time'
};

// Parameters for system: '<S2>/For Each Subsystem'
struct P_CoreSubsys_motion_controlle_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S11>/Constant'

};

// Parameters for system: '<S2>/For Each Subsystem1'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S12>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_cktest_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S16>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S16>/MATLAB Function'

  real_T b;                            // Variable: b
                                          //  Referenced by: '<S16>/MATLAB Function'

  int16_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S26>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S23>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S6>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S5>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S25>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S22>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S2>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S2>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S2>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S2>/Saturation'

  real_T Gain_Gain;                    // Expression: 0
                                          //  Referenced by: '<S16>/Gain'

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S14>/Constant2'

  real_T Gain1_Gain;                   // Expression: 1/500
                                          //  Referenced by: '<S14>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S14>/Constant'

  real_T Gain_Gain_f;                  // Expression: 1/500
                                          //  Referenced by: '<S14>/Gain'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S14>/Gain2'

  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S2>/For Each Subsystem1'
  P_CoreSubsys_motion_controlle_T CoreSubsys;// '<S2>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_motion_controller_ckt_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_cktest
class motion_controller_cktest
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_motion_controller_ck_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  motion_controller_cktest();

  // Destructor
  ~motion_controller_cktest();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_cktest_T motion_controller_cktest_B;

  // Block states
  DW_motion_controller_cktest_T motion_controller_cktest_DW;

  // Tunable parameters
  static P_motion_controller_cktest_T motion_controller_cktest_P;

  // private member function(s) for subsystem '<S2>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_c_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S3>/get_angle_4w'
  void motion_controller__get_angle_4w(real_T rtu_delta_f, real_T rtu_delta_r,
    real_T rty_angle_cmd[4]) const;

  // private member function(s) for subsystem '<S3>/get_spd'
  void motion_controller_cktes_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

  // private member function(s) for subsystem '<Root>'
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_n(ros_slros2_internal_block_Pub_T *obj);
  void motion_cont_SystemCore_setup_nt(ros_slros2_internal_block_Sub_T *obj);
  void motion_con_SystemCore_setup_nt1(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_ck_T motion_controller_cktest_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S14>/Display' : Unused code path elimination
//  Block '<S14>/Display1' : Unused code path elimination
//  Block '<S24>/Display' : Unused code path elimination
//  Block '<S24>/Display1' : Unused code path elimination
//  Block '<S24>/Display10' : Unused code path elimination
//  Block '<S24>/Display11' : Unused code path elimination
//  Block '<S24>/Display12' : Unused code path elimination
//  Block '<S24>/Display13' : Unused code path elimination
//  Block '<S24>/Display14' : Unused code path elimination
//  Block '<S24>/Display15' : Unused code path elimination
//  Block '<S24>/Display2' : Unused code path elimination
//  Block '<S24>/Display3' : Unused code path elimination
//  Block '<S24>/Display4' : Unused code path elimination
//  Block '<S24>/Display5' : Unused code path elimination
//  Block '<S24>/Display6' : Unused code path elimination
//  Block '<S24>/Display7' : Unused code path elimination
//  Block '<S24>/Display8' : Unused code path elimination
//  Block '<S24>/Display9' : Unused code path elimination


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
//  '<Root>' : 'motion_controller_cktest'
//  '<S1>'   : 'motion_controller_cktest/Compare To Constant'
//  '<S2>'   : 'motion_controller_cktest/cmd_pub'
//  '<S3>'   : 'motion_controller_cktest/controller'
//  '<S4>'   : 'motion_controller_cktest/subscription'
//  '<S5>'   : 'motion_controller_cktest/cmd_pub/Blank Message1'
//  '<S6>'   : 'motion_controller_cktest/cmd_pub/Blank Message2'
//  '<S7>'   : 'motion_controller_cktest/cmd_pub/For Each Subsystem'
//  '<S8>'   : 'motion_controller_cktest/cmd_pub/For Each Subsystem1'
//  '<S9>'   : 'motion_controller_cktest/cmd_pub/Publish'
//  '<S10>'  : 'motion_controller_cktest/cmd_pub/Publish2'
//  '<S11>'  : 'motion_controller_cktest/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S12>'  : 'motion_controller_cktest/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S13>'  : 'motion_controller_cktest/controller/Chart'
//  '<S14>'  : 'motion_controller_cktest/controller/Subsystem'
//  '<S15>'  : 'motion_controller_cktest/controller/get_angle_4w'
//  '<S16>'  : 'motion_controller_cktest/controller/get_spd'
//  '<S17>'  : 'motion_controller_cktest/controller/Subsystem/Chart2'
//  '<S18>'  : 'motion_controller_cktest/controller/Subsystem/MATLAB Function'
//  '<S19>'  : 'motion_controller_cktest/controller/get_angle_4w/MATLAB Function'
//  '<S20>'  : 'motion_controller_cktest/controller/get_spd/MATLAB Function'
//  '<S21>'  : 'motion_controller_cktest/subscription/For Each Subsystem'
//  '<S22>'  : 'motion_controller_cktest/subscription/Subscribe'
//  '<S23>'  : 'motion_controller_cktest/subscription/Subscribe1'
//  '<S24>'  : 'motion_controller_cktest/subscription/display'
//  '<S25>'  : 'motion_controller_cktest/subscription/Subscribe/Enabled Subsystem'
//  '<S26>'  : 'motion_controller_cktest/subscription/Subscribe1/Enabled Subsystem'

#endif                                // RTW_HEADER_motion_controller_cktest_h_

//
// File trailer for generated code.
//
// [EOF]
//
