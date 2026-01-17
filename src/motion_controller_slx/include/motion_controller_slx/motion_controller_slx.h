//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_slx.h
//
// Code generated for Simulink model 'motion_controller_slx'.
//
// Model version                  : 2.255
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jul  8 21:38:08 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_slx_h_
#define RTW_HEADER_motion_controller_slx_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_slx_types.h"

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

// Block signals for system '<S3>/Current Time'
struct B_CurrentTime_motion_controll_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S3>/Current Time'
};

// Block states (default storage) for system '<S3>/Current Time'
struct DW_CurrentTime_motion_control_T {
  ros_slros2_internal_block_Cur_T obj; // '<S3>/Current Time'
  boolean_T objisempty;                // '<S3>/Current Time'
};

// Block signals (default storage)
struct B_motion_controller_slx_T {
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S35>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  SL_Bus_nav_msgs_Odometry In1_g;      // '<S8>/In1'
  SL_Bus_nav_msgs_Odometry b_varargout_2_m;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S3>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S13>/Bus Assignment1' 
  SL_Bus_sensor_msgs_Imu In1_m;        // '<S9>/In1'
  SL_Bus_sensor_msgs_Imu b_varargout_2_c;
  SL_Bus_sbus_interface_Sbus In1_me;   // '<S34>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_k;
  real_T ImpAsg_InsertedFor_Out1_at_[16];
  real_T spd_cmd_j[4];                 // '<S4>/MATLAB Function'
  real_T effort_cmd_l[4];              // '<S4>/MATLAB Function'
  real_T out;                          // '<S20>/Chart2'
  real_T GetParameter1;                // '<S4>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S4>/Chart'
  real_T spd_cmd[4];                   // '<S4>/Chart'
  real_T effort_cmd[4];                // '<S4>/Chart'
  real_T Fzf;
  real_T Fzr;
  real_T effort;
  real_T y;
  real_T b_y;
  real_T b_value;
  real_T b_value_m;
  real_T b_value_c;
  real_T b_value_k;
  real_T b_value_cx;
  real_T direction;
  real_T rate;
  real_T b_value_cxa;
  real_T b_value_b;
  real_T Gain2;                        // '<S20>/Gain2'
  int32_T ForEach_itr;
  int32_T ForEach_itr_j_p;
  int32_T ForEach_itr_p_c;
  int8_T mode;                         // '<S4>/Chart'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S3>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S3>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_slx_T {
  ros_slros2_internal_block_Get_T obj; // '<S22>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_d;// '<S22>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l;// '<S22>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_a;// '<S22>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_p;// '<S22>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_d2;// '<S22>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_g;// '<S20>/Get Parameter5'
  ros_slros2_internal_block_Get_T obj_e;// '<S20>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l4;// '<S20>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_c;// '<S20>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o;// '<S20>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_m;// '<S20>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_i;// '<S4>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_f;// '<S4>/Get Parameter1'
  ros_slros2_internal_block_Sub_T obj_mo;// '<S32>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S31>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_ed;// '<S7>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_os;// '<S6>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S15>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_b;// '<S14>/SinkBlock'
  real_T angle_out;                    // '<S20>/MATLAB Function'
  real_T sum;                          // '<S4>/Chart'
  real_T counter;                      // '<S4>/Chart'
  real_T check;                        // '<S4>/Chart'
  uint8_T is_active_c6_motion_controller_;// '<S20>/Chart2'
  uint8_T is_active_c3_motion_controller_;// '<S4>/Chart'
  uint8_T is_Is_ready;                 // '<S4>/Chart'
  uint8_T is_cmd;                      // '<S4>/Chart'
  uint8_T is_effort_mode;              // '<S4>/Chart'
  boolean_T ready;                     // '<S4>/Chart'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S3>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S3>/Current Time'
};

// Parameters for system: '<S3>/For Each Subsystem'
struct P_CoreSubsys_motion_controlle_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S16>/Constant'

};

// Parameters for system: '<S3>/For Each Subsystem1'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S17>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_slx_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S21>/MATLAB Function'
                                          //    '<S22>/getFz'
                                          //    '<S23>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S21>/MATLAB Function'
                                          //    '<S23>/MATLAB Function'

  real_T a;                            // Variable: a
                                          //  Referenced by: '<S22>/getFz'

  real_T b;                            // Variable: b
                                          //  Referenced by:
                                          //    '<S22>/getFz'
                                          //    '<S23>/MATLAB Function'

  real_T g;                            // Variable: g
                                          //  Referenced by: '<S22>/getFz'

  real_T h;                            // Variable: h
                                          //  Referenced by: '<S22>/getFz'

  real_T m;                            // Variable: m
                                          //  Referenced by: '<S22>/getFz'

  int16_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S35>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S32>/Constant'

  SL_Bus_nav_msgs_Odometry Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S8>/Out1'

  SL_Bus_nav_msgs_Odometry Constant_Value_f;// Computed Parameter: Constant_Value_f
                                               //  Referenced by: '<S6>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f3;// Computed Parameter: Constant_Value_f3
                                                                //  Referenced by: '<S11>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S10>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0_p;    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S9>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_f5;// Computed Parameter: Constant_Value_f5
                                              //  Referenced by: '<S7>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S34>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S31>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 8
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -8
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S3>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S3>/Saturation'

  real_T MATLABFunction_J;             // Expression: J
                                          //  Referenced by: '<S22>/MATLAB Function'

  real_T MATLABFunction_Re;            // Expression: Re
                                          //  Referenced by: '<S22>/MATLAB Function'

  real_T Constant_Value_m;             // Expression: 0.00399/4
                                          //  Referenced by: '<S22>/Constant'

  real_T Constant1_Value;              // Expression: 0.0104/4
                                          //  Referenced by: '<S22>/Constant1'

  real_T Constant2_Value;              // Expression: Re
                                          //  Referenced by: '<S22>/Constant2'

  real_T Gain_Gain;                    // Expression: 0.036675
                                          //  Referenced by: '<S22>/Gain'

  real_T Constant3_Value;              // Expression: 0.21275
                                          //  Referenced by: '<S22>/Constant3'

  real_T Gain_Gain_m;                  // Expression: 0
                                          //  Referenced by: '<S23>/Gain'

  real_T Constant2_Value_f;            // Expression: 500
                                          //  Referenced by: '<S20>/Constant2'

  real_T Gain1_Gain;                   // Expression: 1/500
                                          //  Referenced by: '<S20>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S20>/Constant'

  real_T Gain_Gain_f;                  // Expression: 1/500
                                          //  Referenced by: '<S20>/Gain'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S20>/Gain2'

  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S3>/For Each Subsystem1'
  P_CoreSubsys_motion_controlle_T CoreSubsys;// '<S3>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_motion_controller_slx_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_slx
class motion_controller_slx
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_motion_controller_sl_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  motion_controller_slx();

  // Destructor
  ~motion_controller_slx();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_slx_T motion_controller_slx_B;

  // Block states
  DW_motion_controller_slx_T motion_controller_slx_DW;

  // Tunable parameters
  static P_motion_controller_slx_T motion_controller_slx_P;

  // private member function(s) for subsystem '<S3>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_s_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S4>/get_angle_4w'
  void motion_controller__get_angle_4w(real_T rtu_delta_f, real_T rtu_delta_r,
    real_T rty_angle_cmd[4]) const;

  // private member function(s) for subsystem '<S4>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_sl_get_effort(real_T rtu_longdrive, real_T rtu_vx,
    real_T rtu_dvx, const real_T rtu_omega4w[4], real_T rty_effort_cmd[4]);
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S4>/get_spd'
  void motion_controller_slx_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

  // private member function(s) for subsystem '<Root>'
  void motion_cont_SystemCore_setup_o0(ros_slros2_internal_block_Pub_T *obj);
  void motion_con_SystemCore_setup_o0a(ros_slros2_internal_block_Pub_T *obj);
  void motion_co_SystemCore_setup_o0aj(ros_slros2_internal_block_Sub_T *obj);
  void motion_c_SystemCore_setup_o0ajj(ros_slros2_internal_block_Sub_T *obj);
  void motion_contr_SystemCore_setup_o(ros_slros2_internal_block_Sub_T *obj);
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_sl_T motion_controller_slx_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S20>/Display' : Unused code path elimination
//  Block '<S20>/Display1' : Unused code path elimination
//  Block '<S22>/Display' : Unused code path elimination
//  Block '<S22>/Display1' : Unused code path elimination
//  Block '<S33>/Display' : Unused code path elimination
//  Block '<S33>/Display1' : Unused code path elimination
//  Block '<S33>/Display10' : Unused code path elimination
//  Block '<S33>/Display11' : Unused code path elimination
//  Block '<S33>/Display12' : Unused code path elimination
//  Block '<S33>/Display13' : Unused code path elimination
//  Block '<S33>/Display14' : Unused code path elimination
//  Block '<S33>/Display15' : Unused code path elimination
//  Block '<S33>/Display2' : Unused code path elimination
//  Block '<S33>/Display3' : Unused code path elimination
//  Block '<S33>/Display4' : Unused code path elimination
//  Block '<S33>/Display5' : Unused code path elimination
//  Block '<S33>/Display6' : Unused code path elimination
//  Block '<S33>/Display7' : Unused code path elimination
//  Block '<S33>/Display8' : Unused code path elimination
//  Block '<S33>/Display9' : Unused code path elimination
//  Block '<S4>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'motion_controller_slx'
//  '<S1>'   : 'motion_controller_slx/Compare To Constant'
//  '<S2>'   : 'motion_controller_slx/Subsystem'
//  '<S3>'   : 'motion_controller_slx/cmd_pub'
//  '<S4>'   : 'motion_controller_slx/controller'
//  '<S5>'   : 'motion_controller_slx/subscription'
//  '<S6>'   : 'motion_controller_slx/Subsystem/Subscribe'
//  '<S7>'   : 'motion_controller_slx/Subsystem/Subscribe1'
//  '<S8>'   : 'motion_controller_slx/Subsystem/Subscribe/Enabled Subsystem'
//  '<S9>'   : 'motion_controller_slx/Subsystem/Subscribe1/Enabled Subsystem'
//  '<S10>'  : 'motion_controller_slx/cmd_pub/Blank Message1'
//  '<S11>'  : 'motion_controller_slx/cmd_pub/Blank Message2'
//  '<S12>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem'
//  '<S13>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem1'
//  '<S14>'  : 'motion_controller_slx/cmd_pub/Publish'
//  '<S15>'  : 'motion_controller_slx/cmd_pub/Publish2'
//  '<S16>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S17>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S18>'  : 'motion_controller_slx/controller/Chart'
//  '<S19>'  : 'motion_controller_slx/controller/MATLAB Function'
//  '<S20>'  : 'motion_controller_slx/controller/Subsystem'
//  '<S21>'  : 'motion_controller_slx/controller/get_angle_4w'
//  '<S22>'  : 'motion_controller_slx/controller/get_effort'
//  '<S23>'  : 'motion_controller_slx/controller/get_spd'
//  '<S24>'  : 'motion_controller_slx/controller/Subsystem/Chart2'
//  '<S25>'  : 'motion_controller_slx/controller/Subsystem/MATLAB Function'
//  '<S26>'  : 'motion_controller_slx/controller/get_angle_4w/MATLAB Function'
//  '<S27>'  : 'motion_controller_slx/controller/get_effort/MATLAB Function'
//  '<S28>'  : 'motion_controller_slx/controller/get_effort/getFz'
//  '<S29>'  : 'motion_controller_slx/controller/get_spd/MATLAB Function'
//  '<S30>'  : 'motion_controller_slx/subscription/For Each Subsystem'
//  '<S31>'  : 'motion_controller_slx/subscription/Subscribe'
//  '<S32>'  : 'motion_controller_slx/subscription/Subscribe1'
//  '<S33>'  : 'motion_controller_slx/subscription/display'
//  '<S34>'  : 'motion_controller_slx/subscription/Subscribe/Enabled Subsystem'
//  '<S35>'  : 'motion_controller_slx/subscription/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_motion_controller_slx_h_

//
// File trailer for generated code.
//
// [EOF]
//
