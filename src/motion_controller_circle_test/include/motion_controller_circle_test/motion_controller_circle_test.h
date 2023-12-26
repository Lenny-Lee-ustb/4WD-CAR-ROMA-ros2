//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_circle_test.h
//
// Code generated for Simulink model 'motion_controller_circle_test'.
//
// Model version                  : 2.201
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Dec 19 21:19:51 2023
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

#define motion_controller_circle_test_M (motion_controller_circle_tes_M)

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
struct B_motion_controller_circle_te_T {
  SL_Bus_custom_interfaces_ActuatorCommand BusAssignment1;// '<S2>/Bus Assignment1' 
  SL_Bus_custom_interfaces_Actuator ImpAsg_InsertedFor_actuaor_[4];// '<S11>/Bus Assignment1' 
  SL_Bus_sbus_interface_Sbus In1;      // '<S25>/In1'
  SL_Bus_sbus_interface_Sbus b_varargout_2;
  real_T angle_cmd[4];                 // '<S3>/Chart1'
  real_T spd_cmd[4];                   // '<S3>/Chart1'
  real_T effort_cmd[4];                // '<S3>/Chart1'
  real_T GetParameter1;                // '<S3>/Get Parameter1'
  real_T out;                          // '<S1>/Chart2'
  real_T angle_out;                    // '<S1>/Chart'
  real_T direction;
  real_T b_value;
  real_T b_value_m;
  real_T Gain2;                        // '<S1>/Gain2'
  int8_T mode;                         // '<S3>/Chart1'
  B_CurrentTime_motion_controll_T CurrentTime1;// '<S2>/Current Time'
  B_CurrentTime_motion_controll_T CurrentTime;// '<S2>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_motion_controller_circle_t_T {
  ros_slros2_internal_block_Get_T obj; // '<S18>/Get Parameter'
  ros_slros2_internal_block_Get_T obj_k;// '<S3>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_b;// '<S1>/Get Parameter4'
  ros_slros2_internal_block_Get_T obj_o;// '<S1>/Get Parameter3'
  ros_slros2_internal_block_Get_T obj_h;// '<S1>/Get Parameter1'
  ros_slros2_internal_block_Get_T obj_e;// '<S1>/Get Parameter'
  ros_slros2_internal_block_Pub_T obj_c;// '<S13>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_bq;// '<S12>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S23>/SourceBlock'
  real_T sum;                          // '<S3>/Chart1'
  real_T counter;                      // '<S3>/Chart1'
  real_T check;                        // '<S3>/Chart1'
  real_T counter_d;                    // '<S1>/Chart'
  real_T ini;                          // '<S1>/Chart'
  real_T direction;                    // '<S1>/Chart'
  uint8_T is_active_c6_motion_controller_;// '<S3>/Chart1'
  uint8_T is_Is_ready;                 // '<S3>/Chart1'
  uint8_T is_cmd;                      // '<S3>/Chart1'
  uint8_T is_active_c1_motion_controller_;// '<S1>/Chart2'
  uint8_T is_active_c8_motion_controller_;// '<S1>/Chart'
  uint8_T is_steer;                    // '<S1>/Chart'
  boolean_T ready;                     // '<S3>/Chart1'
  DW_CurrentTime_motion_control_T CurrentTime1;// '<S2>/Current Time'
  DW_CurrentTime_motion_control_T CurrentTime;// '<S2>/Current Time'
};

// Parameters for system: '<S2>/For Each Subsystem'
struct P_CoreSubsys_motion_controlle_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S14>/Constant'

};

// Parameters for system: '<S2>/For Each Subsystem1'
struct P_CoreSubsys_motion_control_g_T_ {
  SL_Bus_custom_interfaces_Actuator Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S15>/Constant'

};

// Parameters (default storage)
struct P_motion_controller_circle_te_T_ {
  real_T L;                            // Variable: L
                                          //  Referenced by:
                                          //    '<S17>/MATLAB Function'
                                          //    '<S19>/MATLAB Function'

  real_T Tw;                           // Variable: Tw
                                          //  Referenced by:
                                          //    '<S17>/MATLAB Function'
                                          //    '<S19>/MATLAB Function'

  real_T b;                            // Variable: b
                                          //  Referenced by: '<S19>/MATLAB Function'

  int16_T ctc_const;                   // Mask Parameter: ctc_const
                                          //  Referenced by: '<S4>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S9>/Constant'

  SL_Bus_custom_interfaces_ActuatorCommand Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                               //  Referenced by: '<S8>/Constant'

  SL_Bus_sbus_interface_Sbus Out1_Y0;  // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S25>/Out1'

  SL_Bus_sbus_interface_Sbus Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                 //  Referenced by: '<S23>/Constant'

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

  real_T Constant_Value_iw;            // Expression: 500
                                          //  Referenced by: '<S1>/Constant'

  real_T Gain_Gain;                    // Expression: 1/500
                                          //  Referenced by: '<S1>/Gain'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S1>/Gain2'

  real_T Constant2_Value;              // Expression: 500
                                          //  Referenced by: '<S1>/Constant2'

  real_T Gain1_Gain;                   // Expression: 1/500
                                          //  Referenced by: '<S1>/Gain1'

  real_T Saturation_UpperSat_k;        // Expression: 0.3
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: -0.3
                                          //  Referenced by: '<Root>/Saturation'

  P_CoreSubsys_motion_control_g_T CoreSubsys_p;// '<S2>/For Each Subsystem1'
  P_CoreSubsys_motion_controlle_T CoreSubsys;// '<S2>/For Each Subsystem'
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

  // private member function(s) for subsystem '<S2>/Current Time'
  static void motion_control_CurrentTime_Init(DW_CurrentTime_motion_control_T
    *localDW);
  void motion_controller_c_CurrentTime(B_CurrentTime_motion_controll_T *localB);
  static void motion_control_CurrentTime_Term(DW_CurrentTime_motion_control_T
    *localDW);

  // private member function(s) for subsystem '<S3>/get_angle'
  void motion_controller_cir_get_angle(real_T rtu_angle, real_T rty_angle_cmd[4])
    const;

  // private member function(s) for subsystem '<S3>/get_effort'
  void motion_controll_get_effort_Init();
  void motion_controller_ci_get_effort();
  void motion_controll_get_effort_Term();

  // private member function(s) for subsystem '<S3>/get_spd'
  void motion_controller_circl_get_spd(real_T rtu_angle, real_T rtu_longdrive,
    real_T rty_spd_cmd[4]) const;

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
//  '<Root>' : 'motion_controller_circle_test'
//  '<S1>'   : 'motion_controller_circle_test/Subsystem'
//  '<S2>'   : 'motion_controller_circle_test/cmd_pub'
//  '<S3>'   : 'motion_controller_circle_test/controller'
//  '<S4>'   : 'motion_controller_circle_test/ctc'
//  '<S5>'   : 'motion_controller_circle_test/subscription'
//  '<S6>'   : 'motion_controller_circle_test/Subsystem/Chart'
//  '<S7>'   : 'motion_controller_circle_test/Subsystem/Chart2'
//  '<S8>'   : 'motion_controller_circle_test/cmd_pub/Blank Message1'
//  '<S9>'   : 'motion_controller_circle_test/cmd_pub/Blank Message2'
//  '<S10>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem'
//  '<S11>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem1'
//  '<S12>'  : 'motion_controller_circle_test/cmd_pub/Publish'
//  '<S13>'  : 'motion_controller_circle_test/cmd_pub/Publish2'
//  '<S14>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem/Blank Message4'
//  '<S15>'  : 'motion_controller_circle_test/cmd_pub/For Each Subsystem1/Blank Message4'
//  '<S16>'  : 'motion_controller_circle_test/controller/Chart1'
//  '<S17>'  : 'motion_controller_circle_test/controller/get_angle'
//  '<S18>'  : 'motion_controller_circle_test/controller/get_effort'
//  '<S19>'  : 'motion_controller_circle_test/controller/get_spd'
//  '<S20>'  : 'motion_controller_circle_test/controller/get_angle/MATLAB Function'
//  '<S21>'  : 'motion_controller_circle_test/controller/get_effort/MATLAB Function'
//  '<S22>'  : 'motion_controller_circle_test/controller/get_spd/MATLAB Function'
//  '<S23>'  : 'motion_controller_circle_test/subscription/Subscribe'
//  '<S24>'  : 'motion_controller_circle_test/subscription/display'
//  '<S25>'  : 'motion_controller_circle_test/subscription/Subscribe/Enabled Subsystem'

#endif                           // RTW_HEADER_motion_controller_circle_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
