#ifndef AGENT2__VISIBILITY_CONTROL_H_
#define AGENT2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AGENT2_EXPORT __attribute__ ((dllexport))
    #define AGENT2_IMPORT __attribute__ ((dllimport))
  #else
    #define AGENT2_EXPORT __declspec(dllexport)
    #define AGENT2_IMPORT __declspec(dllimport)
  #endif
  #ifdef AGENT2_BUILDING_LIBRARY
    #define AGENT2_PUBLIC AGENT2_EXPORT
  #else
    #define AGENT2_PUBLIC AGENT2_IMPORT
  #endif
  #define AGENT2_PUBLIC_TYPE AGENT2_PUBLIC
  #define AGENT2_LOCAL
#else
  #define AGENT2_EXPORT __attribute__ ((visibility("default")))
  #define AGENT2_IMPORT
  #if __GNUC__ >= 4
    #define AGENT2_PUBLIC __attribute__ ((visibility("default")))
    #define AGENT2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AGENT2_PUBLIC
    #define AGENT2_LOCAL
  #endif
  #define AGENT2_PUBLIC_TYPE
#endif
#endif  // AGENT2__VISIBILITY_CONTROL_H_
// Generated 17-Jan-2026 22:00:21
 