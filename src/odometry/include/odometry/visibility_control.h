#ifndef ODOMETRY__VISIBILITY_CONTROL_H_
#define ODOMETRY__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ODOMETRY_EXPORT __attribute__ ((dllexport))
    #define ODOMETRY_IMPORT __attribute__ ((dllimport))
  #else
    #define ODOMETRY_EXPORT __declspec(dllexport)
    #define ODOMETRY_IMPORT __declspec(dllimport)
  #endif
  #ifdef ODOMETRY_BUILDING_LIBRARY
    #define ODOMETRY_PUBLIC ODOMETRY_EXPORT
  #else
    #define ODOMETRY_PUBLIC ODOMETRY_IMPORT
  #endif
  #define ODOMETRY_PUBLIC_TYPE ODOMETRY_PUBLIC
  #define ODOMETRY_LOCAL
#else
  #define ODOMETRY_EXPORT __attribute__ ((visibility("default")))
  #define ODOMETRY_IMPORT
  #if __GNUC__ >= 4
    #define ODOMETRY_PUBLIC __attribute__ ((visibility("default")))
    #define ODOMETRY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ODOMETRY_PUBLIC
    #define ODOMETRY_LOCAL
  #endif
  #define ODOMETRY_PUBLIC_TYPE
#endif
#endif  // ODOMETRY__VISIBILITY_CONTROL_H_
// Generated 14-Aug-2023 19:30:59
 