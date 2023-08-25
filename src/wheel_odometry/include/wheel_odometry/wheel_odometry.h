//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: wheel_odometry.h
//
// Code generated for Simulink model 'wheel_odometry'.
//
// Model version                  : 1.25
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Aug 25 15:10:26 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_wheel_odometry_h_
#define RTW_HEADER_wheel_odometry_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros2_initialize.h"
#include "wheel_odometry_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_wheel_odometry_T {
  SL_Bus_nav_msgs_Odometry BusAssignment;// '<Root>/Bus Assignment'
  SL_Bus_sensor_msgs_Imu In1;          // '<S13>/In1'
  SL_Bus_sensor_msgs_Imu b_varargout_2;
  SL_Bus_geometry_msgs_PolygonStamped In1_b;// '<S12>/In1'
  SL_Bus_geometry_msgs_PolygonStamped In1_bo;// '<S11>/In1'
  SL_Bus_geometry_msgs_PolygonStamped b_varargout_2_m;
  real32_T ImpAsg_InsertedFor_x_at_inp[16];
  real32_T ImpAsg_InsertedFor_x_at_i_d[16];
  char_T b_zeroDelimTopic[17];
  real_T UnitDelay[2];                 // '<S7>/Unit Delay'
  real_T q[4];                         // '<S7>/MATLAB Function1'
  real_T XY_dot[2];                    // '<S7>/MATLAB Function'
  char_T prmName[15];
  real_T yaw;                          // '<S24>/yaw'
  real_T b_value;
};

// Block states (default storage) for system '<Root>'
struct DW_wheel_odometry_T {
  ros_slros2_internal_block_Get_T obj; // '<Root>/Get Parameter'
  ros_slros2_internal_block_Pub_T obj_o;// '<S2>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_a;// '<S5>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_l;// '<S4>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_j;// '<S3>/SourceBlock'
  real_T UnitDelay_DSTATE[2];          // '<S7>/Unit Delay'
};

// Parameters (default storage)
struct P_wheel_odometry_T_ {
  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S23>/Constant'

  SL_Bus_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S1>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0;      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S13>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value_i;// Computed Parameter: Constant_Value_i
                                             //  Referenced by: '<S5>/Constant'

  SL_Bus_geometry_msgs_PolygonStamped Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                   //  Referenced by: '<S11>/Out1'

  SL_Bus_geometry_msgs_PolygonStamped Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                   //  Referenced by: '<S12>/Out1'

  SL_Bus_geometry_msgs_PolygonStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                          //  Referenced by: '<S4>/Constant'

  SL_Bus_geometry_msgs_PolygonStamped Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                          //  Referenced by: '<S3>/Constant'

  real_T Gain_Gain;                    // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S17>/Gain'

  real_T XY_dot_Y0;                    // Computed Parameter: XY_dot_Y0
                                          //  Referenced by: '<S7>/XY_dot'

  real_T XY_Y0;                        // Computed Parameter: XY_Y0
                                          //  Referenced by: '<S7>/XY'

  real_T orientation_Y0;               // Computed Parameter: orientation_Y0
                                          //  Referenced by: '<S7>/orientation'

  real_T Constant_Value_j0[4];       // Expression: [k/2, k/2, 0.5-k/2, 0.5-k/2]
                                        //  Referenced by: '<S17>/Constant'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S7>/Unit Delay'

  real_T Gain_Gain_n;                  // Expression: 0.01
                                          //  Referenced by: '<S7>/Gain'

  real_T Constant_Value_e;             // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T Constant1_Value;              // Expression: 2*pi
                                          //  Referenced by: '<S20>/Constant1'

  real_T Constant_Value_lo;            // Expression: pi
                                          //  Referenced by: '<S20>/Constant'

  real_T Constant1_Value_f;            // Expression: 2*pi
                                          //  Referenced by: '<S21>/Constant1'

  real_T Constant_Value_d;             // Expression: pi
                                          //  Referenced by: '<S21>/Constant'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S24>/Out1'

  real_T Constant_Value_p;             // Expression: pi
                                          //  Referenced by: '<S10>/Constant'

  real32_T Gain1_Gain;                 // Expression: single(b/L)
                                          //  Referenced by: '<S17>/Gain1'

  real32_T Gain1_Gain_i[2];            // Computed Parameter: Gain1_Gain_i
                                          //  Referenced by: '<S8>/Gain1'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S17>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_wheel_odometry_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Class declaration for model wheel_odometry
class wheel_odometry
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_wheel_odometry_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  wheel_odometry();

  // Destructor
  ~wheel_odometry();

  // private data and function members
 private:
  // Block signals
  B_wheel_odometry_T wheel_odometry_B;

  // Block states
  DW_wheel_odometry_T wheel_odometry_DW;

  // Tunable parameters
  static P_wheel_odometry_T wheel_odometry_P;

  // private member function(s) for subsystem '<Root>'
  void wheel_odome_SystemCore_setup_pb(ros_slros2_internal_block_Sub_T *obj);
  void wheel_odomet_SystemCore_setup_p(ros_slros2_internal_block_Sub_T *obj);
  void wheel_odom_SystemCore_setup_pbe(ros_slros2_internal_block_Sub_T *obj);
  void wheel_odometry_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_wheel_odometry_T wheel_odometry_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S17>/Reshape' : Reshape block reduction
//  Block '<S17>/Reshape2' : Reshape block reduction
//  Block '<S8>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'wheel_odometry'
//  '<S1>'   : 'wheel_odometry/Blank Message'
//  '<S2>'   : 'wheel_odometry/Publish'
//  '<S3>'   : 'wheel_odometry/Subscribe'
//  '<S4>'   : 'wheel_odometry/Subscribe1'
//  '<S5>'   : 'wheel_odometry/Subscribe2'
//  '<S6>'   : 'wheel_odometry/Subsystem'
//  '<S7>'   : 'wheel_odometry/Subsystem1'
//  '<S8>'   : 'wheel_odometry/Subsystem2'
//  '<S9>'   : 'wheel_odometry/Subsystem3'
//  '<S10>'  : 'wheel_odometry/Subsystem5'
//  '<S11>'  : 'wheel_odometry/Subscribe/Enabled Subsystem'
//  '<S12>'  : 'wheel_odometry/Subscribe1/Enabled Subsystem'
//  '<S13>'  : 'wheel_odometry/Subscribe2/Enabled Subsystem'
//  '<S14>'  : 'wheel_odometry/Subsystem/For Each Subsystem'
//  '<S15>'  : 'wheel_odometry/Subsystem1/MATLAB Function'
//  '<S16>'  : 'wheel_odometry/Subsystem1/MATLAB Function1'
//  '<S17>'  : 'wheel_odometry/Subsystem1/Subsystem'
//  '<S18>'  : 'wheel_odometry/Subsystem2/For Each Subsystem'
//  '<S19>'  : 'wheel_odometry/Subsystem3/MATLAB Function'
//  '<S20>'  : 'wheel_odometry/Subsystem5/If Action Subsystem'
//  '<S21>'  : 'wheel_odometry/Subsystem5/If Action Subsystem1'
//  '<S22>'  : 'wheel_odometry/Subsystem5/Subsystem4'
//  '<S23>'  : 'wheel_odometry/Subsystem5/Subsystem4/Compare To Constant'
//  '<S24>'  : 'wheel_odometry/Subsystem5/Subsystem4/Enabled Subsystem1'

#endif                                 // RTW_HEADER_wheel_odometry_h_

//
// File trailer for generated code.
//
// [EOF]
//
