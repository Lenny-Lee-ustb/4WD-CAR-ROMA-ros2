//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_circle_test.h
//
// Code generated for Simulink model 'motion_controller_circle_test'.
//
// Model version                  : 2.180
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 20:42:25 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_circle_test_h_
#define RTW_HEADER_motion_controller_circle_test_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "motion_controller_circle_test_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define motion_controller_circle_test_M (motion_controller_circle_tes_M)

// Block signals for system '<S1>/Current Time'
struct B_CurrentTime_motion_controll_T {
  SL_Bus_builtin_interfaces_Time CurrentTime;// '<S1>/Current Time'
};

// Block states (default storage) for system '<S1>/Current Time'
struct DW_CurrentTime_motion_control_T {
  ros_slros2_internal_block_Cur_T obj; // '<S1>/Current Time'
  boolean_T objisempty;                // '<S1>/Current Time'
};

// Block signals (default storage)
struct B_motion_controller_circle_te_T {
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S1>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S8>/Bus Assignment1' 
  SL_Bus_sbus_interface_Sbus In1;      // '<S16>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2;
  real_T angle_cmd[4];                 // '<S2>/Chart'
  real_T spd_cmd[4];                   // '<S2>/Chart'
  real_T effort_cmd[4];                // '<S2>/Chart'
  int8_T mode;                         // '<S2>/Chart'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S1>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S1>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_circle_t_T {
  ros_slros2_internal_block_Get_T obj; // '<S2>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_e;// '<S2>/Get Parameter'
  ros_slros2_internal_block_Pub_T obj_c;// '<S10>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_b;// '<S9>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S14>/SourceBlock'
  real_T sum;                          // '<S2>/Chart'
  real_T check;                        // '<S2>/Chart'
  uint32_T counter_check;              // '<S2>/Chart'
  uint8_T is_active_c3_motion_controller_;// '<S2>/Chart'
  uint8_T is_Is_ready;                 // '<S2>/Chart'
  uint8_T is_cmd;                      // '<S2>/Chart'
  boolean_T ready;                     // '<S2>/Chart'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S1>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S1>/Current Time'
};

// Parameters for system: '<S1>/For Each Subsystem'
struct P_CoreSubsys_motion_controlle_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S11>/Constant'

};

// Parameters for system: '<S1>/For Each Subsystem1'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S12>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_circle_te_T_ {
  int16_T ctc_const;                   // Mask Parameter: ctc_const
                                          //  Referenced by: '<S3>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S6>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S5>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0;  // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S16>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S14>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 1.6
                                          //  Referenced by: '<S1>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1.6
                                          //  Referenced by: '<S1>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 5
                                          //  Referenced by: '<S1>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -5
                                          //  Referenced by: '<S1>/Saturation1'

  real_T Saturation_UpperSat;          // Expression: 0.75
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.75
                                          //  Referenced by: '<S1>/Saturation'

  real_T Saturation_UpperSat_h;        // Expression: 0.4
                                          //  Referenced by: '<S2>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: -0.4
                                          //  Referenced by: '<S2>/Saturation'

  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S1>/For Each Subsystem1'
  P_CoreSubsys_motion_controlle_T CoreSubsys;// '<S1>/For Each Subsystem'
};

// Real-time Model Data Structure
struct tag_RTM_motion_controller_cir_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model motion_controller_circle_test
class motion_controller_circle_test
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_motion_controller_ci_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  motion_controller_circle_test();

  // Destructor
  ~motion_controller_circle_test();

  // private data and function members
 private:
  // Block signals
  B_motion_controller_circle_te_T motion_controller_circle_test_B;

  // Block states
  DW_motion_controller_circle_t_T motion_controller_circle_tes_DW;

  // Tunable parameters
  static P_motion_controller_circle_te_T motion_controller_circle_test_P;

  // private member function(s) for subsystem '<S1>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_c_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<Root>'
  void motion_control_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
  void motion_contr_SystemCore_setup_d(ros_slros2_internal_block_Pub_T *obj);
  void motion_cont_SystemCore_setup_de(ros_slros2_internal_block_Sub_T *obj);

  // Real-Time Model
  RT_MODEL_motion_controller_ci_T motion_controller_circle_tes_M;
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
//  Block '<S15>/Display' : Unused code path elimination
//  Block '<S15>/Display1' : Unused code path elimination
//  Block '<S15>/Display10' : Unused code path elimination
//  Block '<S15>/Display11' : Unused code path elimination
//  Block '<S15>/Display12' : Unused code path elimination
//  Block '<S15>/Display13' : Unused code path elimination
//  Block '<S15>/Display14' : Unused code path elimination
//  Block '<S15>/Display15' : Unused code path elimination
//  Block '<S15>/Display2' : Unused code path elimination
//  Block '<S15>/Display3' : Unused code path elimination
//  Block '<S15>/Display4' : Unused code path elimination
//  Block '<S15>/Display5' : Unused code path elimination
//  Block '<S15>/Display6' : Unused code path elimination
//  Block '<S15>/Display7' : Unused code path elimination
//  Block '<S15>/Display8' : Unused code path elimination
//  Block '<S15>/Display9' : Unused code path elimination


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
//  '<Root>' : 'motion_controller_circle_test'
//  '<S1>'   : 'motion_controller_circle_test/cmd_pub'
//  '<S2>'   : 'motion_controller_circle_test/controller'
//  '<S3>'   : 'motion_controller_circle_test/ctc'
//  '<S4>'   : 'motion_controller_circle_test/subscription'
//  '<S5>'   : 'motion_controller_circle_test/cmd_pub/Blank Message1'
//  '<S6>'   : 'motion_controller_circle_test/cmd_pub/Blank Message2'
//  '<S7>'   : 'motion_controller_circle_test/cmd_pub/For Each Subsystem'
//  '<S8>'   : 'motion_controller_circle_test/cmd_pub/For Each Subsystem1'
//  '<S9>'   : 'motion_controller_circle_test/cmd_pub/Publish'
//  '<S10>'  : 'motion_controller_circle_test/cmd_pub/Publish2'
//  '<S11>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S12>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S13>'  : 'motion_controller_circle_test/controller/Chart'
//  '<S14>'  : 'motion_controller_circle_test/subscription/Subscribe'
//  '<S15>'  : 'motion_controller_circle_test/subscription/display'
//  '<S16>'  : 'motion_controller_circle_test/subscription/Subscribe/Enabled Subsystem'

#endif                           // RTW_HEADER_motion_controller_circle_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
