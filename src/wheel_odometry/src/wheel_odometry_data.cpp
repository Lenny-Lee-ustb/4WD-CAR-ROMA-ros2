//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: wheel_odometry_data.cpp
//
// Code generated for Simulink model 'wheel_odometry'.
//
// Model version                  : 1.28
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Aug 25 16:50:23 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "wheel_odometry.h"

// Block parameters (default storage)
P_wheel_odometry_T wheel_odometry::wheel_odometry_P = {
  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S24>/Constant'

  0.5,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // child_frame_id

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // child_frame_id_SL_Info

    {
      {
        {
          0.0,                         // x
          0.0,                         // y
          0.0                          // z
        },                             // position

        {
          0.0,                         // x
          0.0,                         // y
          0.0,                         // z
          0.0                          // w
        }                              // orientation
      },                               // pose

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      // covariance
    },                                 // pose

    {
      {
        {
          0.0,                         // x
          0.0,                         // y
          0.0                          // z
        },                             // linear

        {
          0.0,                         // x
          0.0,                         // y
          0.0                          // z
        }                              // angular
      },                               // twist

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      // covariance
    }                                  // twist
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S13>/Out1'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      0.0,                             // x
      0.0,                             // y
      0.0,                             // z
      0.0                              // w
    },                                 // orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // orientation_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // angular_velocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // angular_velocity_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // linear_acceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // linear_acceleration_covariance
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S5>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      0.0,                             // x
      0.0,                             // y
      0.0,                             // z
      0.0                              // w
    },                                 // orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // orientation_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // angular_velocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // angular_velocity_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // linear_acceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // linear_acceleration_covariance
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S11>/Out1'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      {
        {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        } }
      ,                                // points

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // points_SL_Info
    }                                  // polygon
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S12>/Out1'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      {
        {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        } }
      ,                                // points

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // points_SL_Info
    }                                  // polygon
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S4>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      {
        {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        } }
      ,                                // points

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // points_SL_Info
    }                                  // polygon
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S3>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      {
        {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        }, {
          0.0F,                        // x
          0.0F,                        // y
          0.0F                         // z
        } }
      ,                                // points

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // points_SL_Info
    }                                  // polygon
  },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S18>/Gain'

  0.036337755620479584,

  // Expression: [0,0]
  //  Referenced by: '<S7>/Constant1'

  { 0.0, 0.0 },

  // Computed Parameter: XY_dot_Y0
  //  Referenced by: '<S7>/XY_dot'

  0.0,

  // Computed Parameter: XY_Y0
  //  Referenced by: '<S7>/XY'

  0.0,

  // Computed Parameter: orientation_Y0
  //  Referenced by: '<S7>/orientation'

  0.0,

  // Expression: [k/2, k/2, 0.5-k/2, 0.5-k/2]
  //  Referenced by: '<S18>/Constant'

  { 0.5, 0.5, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S7>/Unit Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S7>/Gain'

  0.01,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<S21>/Constant1'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S21>/Constant'

  3.1415926535897931,

  // Expression: 2*pi
  //  Referenced by: '<S22>/Constant1'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S22>/Constant'

  3.1415926535897931,

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S25>/Out1'

  0.0,

  // Expression: pi
  //  Referenced by: '<S10>/Constant'

  3.1415926535897931,

  // Expression: single(b/L)
  //  Referenced by: '<S18>/Gain1'

  0.605263174F,

  // Computed Parameter: Gain1_Gain_i
  //  Referenced by: '<S8>/Gain1'

  { 0.5F, 0.5F },

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<S18>/Manual Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
