#ifndef AGENT5000__VISIBILITY_CONTROL_H_
#define AGENT5000__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AGENT5000_EXPORT __attribute__ ((dllexport))
    #define AGENT5000_IMPORT __attribute__ ((dllimport))
  #else
    #define AGENT5000_EXPORT __declspec(dllexport)
    #define AGENT5000_IMPORT __declspec(dllimport)
  #endif
  #ifdef AGENT5000_BUILDING_LIBRARY
    #define AGENT5000_PUBLIC AGENT5000_EXPORT
  #else
    #define AGENT5000_PUBLIC AGENT5000_IMPORT
  #endif
  #define AGENT5000_PUBLIC_TYPE AGENT5000_PUBLIC
  #define AGENT5000_LOCAL
#else
  #define AGENT5000_EXPORT __attribute__ ((visibility("default")))
  #define AGENT5000_IMPORT
  #if __GNUC__ >= 4
    #define AGENT5000_PUBLIC __attribute__ ((visibility("default")))
    #define AGENT5000_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AGENT5000_PUBLIC
    #define AGENT5000_LOCAL
  #endif
  #define AGENT5000_PUBLIC_TYPE
#endif
#endif  // AGENT5000__VISIBILITY_CONTROL_H_
// Generated 22-Apr-2025 13:56:20
 