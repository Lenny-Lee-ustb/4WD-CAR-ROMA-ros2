#ifndef MOTION_CONTROLLER_ACC_AND_BRK__VISIBILITY_CONTROL_H_
#define MOTION_CONTROLLER_ACC_AND_BRK__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MOTION_CONTROLLER_ACC_AND_BRK_EXPORT __attribute__ ((dllexport))
    #define MOTION_CONTROLLER_ACC_AND_BRK_IMPORT __attribute__ ((dllimport))
  #else
    #define MOTION_CONTROLLER_ACC_AND_BRK_EXPORT __declspec(dllexport)
    #define MOTION_CONTROLLER_ACC_AND_BRK_IMPORT __declspec(dllimport)
  #endif
  #ifdef MOTION_CONTROLLER_ACC_AND_BRK_BUILDING_LIBRARY
    #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC MOTION_CONTROLLER_ACC_AND_BRK_EXPORT
  #else
    #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC MOTION_CONTROLLER_ACC_AND_BRK_IMPORT
  #endif
  #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC_TYPE MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC
  #define MOTION_CONTROLLER_ACC_AND_BRK_LOCAL
#else
  #define MOTION_CONTROLLER_ACC_AND_BRK_EXPORT __attribute__ ((visibility("default")))
  #define MOTION_CONTROLLER_ACC_AND_BRK_IMPORT
  #if __GNUC__ >= 4
    #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC __attribute__ ((visibility("default")))
    #define MOTION_CONTROLLER_ACC_AND_BRK_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC
    #define MOTION_CONTROLLER_ACC_AND_BRK_LOCAL
  #endif
  #define MOTION_CONTROLLER_ACC_AND_BRK_PUBLIC_TYPE
#endif
#endif  // MOTION_CONTROLLER_ACC_AND_BRK__VISIBILITY_CONTROL_H_
// Generated 24-Jan-2024 19:43:46
 