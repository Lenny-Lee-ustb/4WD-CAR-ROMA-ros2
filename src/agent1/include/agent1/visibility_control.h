#ifndef AGENT1__VISIBILITY_CONTROL_H_
#define AGENT1__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AGENT1_EXPORT __attribute__ ((dllexport))
    #define AGENT1_IMPORT __attribute__ ((dllimport))
  #else
    #define AGENT1_EXPORT __declspec(dllexport)
    #define AGENT1_IMPORT __declspec(dllimport)
  #endif
  #ifdef AGENT1_BUILDING_LIBRARY
    #define AGENT1_PUBLIC AGENT1_EXPORT
  #else
    #define AGENT1_PUBLIC AGENT1_IMPORT
  #endif
  #define AGENT1_PUBLIC_TYPE AGENT1_PUBLIC
  #define AGENT1_LOCAL
#else
  #define AGENT1_EXPORT __attribute__ ((visibility("default")))
  #define AGENT1_IMPORT
  #if __GNUC__ >= 4
    #define AGENT1_PUBLIC __attribute__ ((visibility("default")))
    #define AGENT1_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AGENT1_PUBLIC
    #define AGENT1_LOCAL
  #endif
  #define AGENT1_PUBLIC_TYPE
#endif
#endif  // AGENT1__VISIBILITY_CONTROL_H_
// Generated 28-Apr-2025 16:19:46
 