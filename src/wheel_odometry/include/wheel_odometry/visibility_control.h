#ifndef WHEEL_ODOMETRY__VISIBILITY_CONTROL_H_
#define WHEEL_ODOMETRY__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define WHEEL_ODOMETRY_EXPORT __attribute__ ((dllexport))
    #define WHEEL_ODOMETRY_IMPORT __attribute__ ((dllimport))
  #else
    #define WHEEL_ODOMETRY_EXPORT __declspec(dllexport)
    #define WHEEL_ODOMETRY_IMPORT __declspec(dllimport)
  #endif
  #ifdef WHEEL_ODOMETRY_BUILDING_LIBRARY
    #define WHEEL_ODOMETRY_PUBLIC WHEEL_ODOMETRY_EXPORT
  #else
    #define WHEEL_ODOMETRY_PUBLIC WHEEL_ODOMETRY_IMPORT
  #endif
  #define WHEEL_ODOMETRY_PUBLIC_TYPE WHEEL_ODOMETRY_PUBLIC
  #define WHEEL_ODOMETRY_LOCAL
#else
  #define WHEEL_ODOMETRY_EXPORT __attribute__ ((visibility("default")))
  #define WHEEL_ODOMETRY_IMPORT
  #if __GNUC__ >= 4
    #define WHEEL_ODOMETRY_PUBLIC __attribute__ ((visibility("default")))
    #define WHEEL_ODOMETRY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define WHEEL_ODOMETRY_PUBLIC
    #define WHEEL_ODOMETRY_LOCAL
  #endif
  #define WHEEL_ODOMETRY_PUBLIC_TYPE
#endif
#endif  // WHEEL_ODOMETRY__VISIBILITY_CONTROL_H_
// Generated 03-Sep-2023 12:16:59
 