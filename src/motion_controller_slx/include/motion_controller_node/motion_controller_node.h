//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_node.h
//
// Code generated for Simulink model 'motion_controller_node'.
//
// Model version                  : 2.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Nov  3 10:19:25 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_node_h_
#define RTW_HEADER_motion_controller_node_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_node_types.h"

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
struct B_motion_controller_node_T {
  SL_Bus_custom_interfaces_ActuatorState In1;// '<S26>/In1'
  SL_Bus_custom_interfaces_ActuatorState b_varargout_2;
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S2>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S8>/Bus Assignment1' 
  SL_Bus_sbus_interface_Sbus In1_m;    // '<S25>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2_m;
  real_T ImpAsg_InsertedFor_Out1_at_[16];
  real_T angle_cmd[4];                 // '<S3>/Chart'
  real_T spd_cmd[4];                   // '<S3>/Chart'
  real_T effort_cmd[4];                // '<S3>/Chart'
  real_T r;
  real_T Gain1;                        // '<S14>/Gain1'
  real_T Gain2;                        // '<S14>/Gain2'
  int8_T mode;                         // '<S3>/Chart'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S2>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S2>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_node_T {
  ros_slros2_internal_block_Get_T obj; // '<S17>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_l;// '<S17>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_d;// '<S16>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_c;// '<S15>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_j;// '<S15>/Get Parameter'
  ros_slros2_internal_block_Pub_T obj_ca;// '<S10>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_b;// '<S9>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_m;// '<S23>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S22>/SourceBlock'
  real_T sum;                          // '<S3>/Chart'
  real_T counter;                      // '<S3>/Chart'
  real_T check;                        // '<S3>/Chart'
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
struct P_motion_controller_node_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S17>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S15>/MATLAB Function'
                                          //    '<S17>/MATLAB Function'

  real_T WHEEL_OFFSET;                 // Variable: WHEEL_OFFSET
                                          //  Referenced by: '<S17>/MATLAB Function'

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

  real_T Saturation2_UpperSat;         // Expression: 1.6
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1.6
                                          //  Referenced by: '<S2>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 5
                                          //  Referenced by: '<S2>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -5
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
struct tag_RTM_motion_controller_nod_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_node
class motion_controller_node
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_motion_controller_no_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  motion_controller_node();

  // Destructor
  ~motion_controller_node();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_node_T motion_controller_node_B;

  // Block states
  DW_motion_controller_node_T motion_controller_node_DW;

  // Tunable parameters
  static P_motion_controller_node_T motion_controller_node_P;

  // private member function(s) for subsystem '<S2>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_n_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S3>/get_angle'
  void motion_controlle_get_angle_Init();
  void motion_controller_nod_get_angle(real_T rtu_angle, real_T rty_angle_cmd[4]);
  void motion_controlle_get_angle_Term();

  // private member function(s) for subsystem '<S3>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_no_get_effort(real_T rtu_longdrive, real_T
    rty_effort_cmd[4]);
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S3>/get_spd'
  void motion_controller__get_spd_Init();
  void motion_controller_node_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]);
  void motion_controller__get_spd_Term();

  // private member function(s) for subsystem '<Root>'
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_f(ros_slros2_internal_block_Pub_T *obj);
  void motion_cont_SystemCore_setup_fs(ros_slros2_internal_block_Sub_T *obj);
  void motion_con_SystemCore_setup_fsy(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_no_T motion_controller_node_M;
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
//  '<Root>' : 'motion_controller_node'
//  '<S1>'   : 'motion_controller_node/Compare To Constant'
//  '<S2>'   : 'motion_controller_node/cmd_pub'
//  '<S3>'   : 'motion_controller_node/controller'
//  '<S4>'   : 'motion_controller_node/subscription'
//  '<S5>'   : 'motion_controller_node/cmd_pub/Blank Message1'
//  '<S6>'   : 'motion_controller_node/cmd_pub/Blank Message2'
//  '<S7>'   : 'motion_controller_node/cmd_pub/For Each Subsystem'
//  '<S8>'   : 'motion_controller_node/cmd_pub/For Each Subsystem1'
//  '<S9>'   : 'motion_controller_node/cmd_pub/Publish'
//  '<S10>'  : 'motion_controller_node/cmd_pub/Publish2'
//  '<S11>'  : 'motion_controller_node/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S12>'  : 'motion_controller_node/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S13>'  : 'motion_controller_node/controller/Chart'
//  '<S14>'  : 'motion_controller_node/controller/Subsystem'
//  '<S15>'  : 'motion_controller_node/controller/get_angle'
//  '<S16>'  : 'motion_controller_node/controller/get_effort'
//  '<S17>'  : 'motion_controller_node/controller/get_spd'
//  '<S18>'  : 'motion_controller_node/controller/get_angle/MATLAB Function'
//  '<S19>'  : 'motion_controller_node/controller/get_effort/MATLAB Function'
//  '<S20>'  : 'motion_controller_node/controller/get_spd/MATLAB Function'
//  '<S21>'  : 'motion_controller_node/subscription/For Each Subsystem'
//  '<S22>'  : 'motion_controller_node/subscription/Subscribe'
//  '<S23>'  : 'motion_controller_node/subscription/Subscribe1'
//  '<S24>'  : 'motion_controller_node/subscription/display'
//  '<S25>'  : 'motion_controller_node/subscription/Subscribe/Enabled Subsystem'
//  '<S26>'  : 'motion_controller_node/subscription/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_motion_controller_node_h_

//
// File trailer for generated code.
//
// [EOF]
//
