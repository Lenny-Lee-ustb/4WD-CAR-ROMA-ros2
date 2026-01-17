#ifndef MOTION_CONTROLLER_CKTEST__VISIBILITY_CONTROL_H_
#define MOTION_CONTROLLER_CKTEST__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MOTION_CONTROLLER_CKTEST_EXPORT __attribute__ ((dllexport))
    #define MOTION_CONTROLLER_CKTEST_IMPORT __attribute__ ((dllimport))
  #else
    #define MOTION_CONTROLLER_CKTEST_EXPORT __declspec(dllexport)
    #define MOTION_CONTROLLER_CKTEST_IMPORT __declspec(dllimport)
  #endif
  #ifdef MOTION_CONTROLLER_CKTEST_BUILDING_LIBRARY
    #define MOTION_CONTROLLER_CKTEST_PUBLIC MOTION_CONTROLLER_CKTEST_EXPORT
  #else
    #define MOTION_CONTROLLER_CKTEST_PUBLIC MOTION_CONTROLLER_CKTEST_IMPORT
  #endif
  #define MOTION_CONTROLLER_CKTEST_PUBLIC_TYPE MOTION_CONTROLLER_CKTEST_PUBLIC
  #define MOTION_CONTROLLER_CKTEST_LOCAL
#else
  #define MOTION_CONTROLLER_CKTEST_EXPORT __attribute__ ((visibility("default")))
  #define MOTION_CONTROLLER_CKTEST_IMPORT
  #if __GNUC__ >= 4
    #define MOTION_CONTROLLER_CKTEST_PUBLIC __attribute__ ((visibility("default")))
    #define MOTION_CONTROLLER_CKTEST_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MOTION_CONTROLLER_CKTEST_PUBLIC
    #define MOTION_CONTROLLER_CKTEST_LOCAL
  #endif
  #define MOTION_CONTROLLER_CKTEST_PUBLIC_TYPE
#endif
#endif  // MOTION_CONTROLLER_CKTEST__VISIBILITY_CONTROL_H_
// Generated 12-Jul-2025 16:44:15
 