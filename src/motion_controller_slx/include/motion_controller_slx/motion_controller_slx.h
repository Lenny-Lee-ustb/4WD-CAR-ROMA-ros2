//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_slx.h
//
// Code generated for Simulink model 'motion_controller_slx'.
//
// Model version                  : 2.179
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Dec 19 20:08:59 2023
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
struct B_motion_controller_slx_T {
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S28>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S2>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S8>/Bus Assignment1' 
  SL_Bus_sbus_interface_Sbus In1_m;    // '<S27>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_m;
  real_T ImpAsg_InsertedFor_Out1_at_[16];
  real_T out;                          // '<S14>/Chart2'
  real_T out_o;                        // '<S14>/Chart1'
  real_T GetParameter1;                // '<S3>/Get Parameter1'
  real_T angle_cmd[4];                 // '<S3>/Chart'
  real_T spd_cmd[4];                   // '<S3>/Chart'
  real_T effort_cmd[4];                // '<S3>/Chart'
  real_T b_value;
  real_T b_value_c;
  real_T b_value_k;
  real_T rtb_Gain_c;
  int32_T ForEach_itr;
  int8_T mode;                         // '<S3>/Chart'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S2>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S2>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_slx_T {
  ros_slros2_internal_block_Get_T obj; // '<S16>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_e;// '<S14>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_l;// '<S14>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_c;// '<S14>/Get Parameter2'
  ros_slros2_internal_block_Get_T obj_o;// '<S14>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_m;// '<S14>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_f;// '<S3>/Get Parameter1'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S10>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_b;// '<S9>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_mo;// '<S25>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S24>/SourceBlock'
  real_T sum;                          // '<S3>/Chart'
  real_T counter;                      // '<S3>/Chart'
  real_T check;                        // '<S3>/Chart'
  uint8_T is_active_c6_motion_controller_;// '<S14>/Chart2'
  uint8_T is_active_c7_motion_controller_;// '<S14>/Chart1'
  uint8_T is_active_c3_motion_controller_;// '<S3>/Chart'
  uint8_T is_Is_ready;                 // '<S3>/Chart'
  uint8_T is_cmd;                      // '<S3>/Chart'
  uint8_T is_effort_mode;              // '<S3>/Chart'
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
struct P_motion_controller_slx_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S17>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S17>/MATLAB Function'

  real_T b;                            // Variable: b
                                          //  Referenced by: '<S17>/MATLAB Function'

  int16_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_custom_interfaces_ActuatorState Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S28>/Out1'

  SL_Bus_custom_interfaces_ActuatorState Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S25>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S6>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S5>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S27>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S24>/Constant'

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

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S14>/Constant2'

  real_T Gain1_Gain;                   // Expression: 1/500
                                          //  Referenced by: '<S14>/Gain1'

  real_T Constant_Value_ff;            // Expression: 500
                                          //  Referenced by: '<S14>/Constant'

  real_T Gain_Gain;                    // Expression: 1/500
                                          //  Referenced by: '<S14>/Gain'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S14>/Gain2'

  real_T Gain_Gain_n[4];               // Expression: ones(1,4)/4
                                          //  Referenced by: '<S4>/Gain'

  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S2>/For Each Subsystem1'
  P_CoreSubsys_motion_controlle_T CoreSubsys;// '<S2>/For Each Subsystem'
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

  // private member function(s) for subsystem '<S2>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_s_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S3>/get_angle'
  void motion_controller_slx_get_angle(real_T rtu_angle, real_T rty_angle_cmd[4])
    const;

  // private member function(s) for subsystem '<S3>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_sl_get_effort(real_T rtu_longdrive, real_T
    rty_effort_cmd[4]);
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S3>/get_spd'
  void motion_controller_slx_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

  // private member function(s) for subsystem '<Root>'
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_o(ros_slros2_internal_block_Pub_T *obj);
  void motion_cont_SystemCore_setup_o0(ros_slros2_internal_block_Sub_T *obj);
  void motion_con_SystemCore_setup_o0a(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_sl_T motion_controller_slx_M;
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
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S26>/Display' : Unused code path elimination
//  Block '<S26>/Display1' : Unused code path elimination
//  Block '<S26>/Display10' : Unused code path elimination
//  Block '<S26>/Display11' : Unused code path elimination
//  Block '<S26>/Display12' : Unused code path elimination
//  Block '<S26>/Display13' : Unused code path elimination
//  Block '<S26>/Display14' : Unused code path elimination
//  Block '<S26>/Display15' : Unused code path elimination
//  Block '<S26>/Display2' : Unused code path elimination
//  Block '<S26>/Display3' : Unused code path elimination
//  Block '<S26>/Display4' : Unused code path elimination
//  Block '<S26>/Display5' : Unused code path elimination
//  Block '<S26>/Display6' : Unused code path elimination
//  Block '<S26>/Display7' : Unused code path elimination
//  Block '<S26>/Display8' : Unused code path elimination
//  Block '<S26>/Display9' : Unused code path elimination


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
//  '<S2>'   : 'motion_controller_slx/cmd_pub'
//  '<S3>'   : 'motion_controller_slx/controller'
//  '<S4>'   : 'motion_controller_slx/subscription'
//  '<S5>'   : 'motion_controller_slx/cmd_pub/Blank Message1'
//  '<S6>'   : 'motion_controller_slx/cmd_pub/Blank Message2'
//  '<S7>'   : 'motion_controller_slx/cmd_pub/For Each Subsystem'
//  '<S8>'   : 'motion_controller_slx/cmd_pub/For Each Subsystem1'
//  '<S9>'   : 'motion_controller_slx/cmd_pub/Publish'
//  '<S10>'  : 'motion_controller_slx/cmd_pub/Publish2'
//  '<S11>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S12>'  : 'motion_controller_slx/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S13>'  : 'motion_controller_slx/controller/Chart'
//  '<S14>'  : 'motion_controller_slx/controller/Subsystem'
//  '<S15>'  : 'motion_controller_slx/controller/get_angle'
//  '<S16>'  : 'motion_controller_slx/controller/get_effort'
//  '<S17>'  : 'motion_controller_slx/controller/get_spd'
//  '<S18>'  : 'motion_controller_slx/controller/Subsystem/Chart1'
//  '<S19>'  : 'motion_controller_slx/controller/Subsystem/Chart2'
//  '<S20>'  : 'motion_controller_slx/controller/get_angle/MATLAB Function'
//  '<S21>'  : 'motion_controller_slx/controller/get_effort/MATLAB Function'
//  '<S22>'  : 'motion_controller_slx/controller/get_spd/MATLAB Function'
//  '<S23>'  : 'motion_controller_slx/subscription/For Each Subsystem'
//  '<S24>'  : 'motion_controller_slx/subscription/Subscribe'
//  '<S25>'  : 'motion_controller_slx/subscription/Subscribe1'
//  '<S26>'  : 'motion_controller_slx/subscription/display'
//  '<S27>'  : 'motion_controller_slx/subscription/Subscribe/Enabled Subsystem'
//  '<S28>'  : 'motion_controller_slx/subscription/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_motion_controller_slx_h_

//
// File trailer for generated code.
//
// [EOF]
//
