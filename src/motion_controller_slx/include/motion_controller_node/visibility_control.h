#ifndef MOTION_CONTROLLER_NODE__VISIBILITY_CONTROL_H_
#define MOTION_CONTROLLER_NODE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MOTION_CONTROLLER_NODE_EXPORT __attribute__ ((dllexport))
    #define MOTION_CONTROLLER_NODE_IMPORT __attribute__ ((dllimport))
  #else
    #define MOTION_CONTROLLER_NODE_EXPORT __declspec(dllexport)
    #define MOTION_CONTROLLER_NODE_IMPORT __declspec(dllimport)
  #endif
  #ifdef MOTION_CONTROLLER_NODE_BUILDING_LIBRARY
    #define MOTION_CONTROLLER_NODE_PUBLIC MOTION_CONTROLLER_NODE_EXPORT
  #else
    #define MOTION_CONTROLLER_NODE_PUBLIC MOTION_CONTROLLER_NODE_IMPORT
  #endif
  #define MOTION_CONTROLLER_NODE_PUBLIC_TYPE MOTION_CONTROLLER_NODE_PUBLIC
  #define MOTION_CONTROLLER_NODE_LOCAL
#else
  #define MOTION_CONTROLLER_NODE_EXPORT __attribute__ ((visibility("default")))
  #define MOTION_CONTROLLER_NODE_IMPORT
  #if __GNUC__ >= 4
    #define MOTION_CONTROLLER_NODE_PUBLIC __attribute__ ((visibility("default")))
    #define MOTION_CONTROLLER_NODE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MOTION_CONTROLLER_NODE_PUBLIC
    #define MOTION_CONTROLLER_NODE_LOCAL
  #endif
  #define MOTION_CONTROLLER_NODE_PUBLIC_TYPE
#endif
#endif  // MOTION_CONTROLLER_NODE__VISIBILITY_CONTROL_H_
// Generated 03-Nov-2023 10:19:56
 