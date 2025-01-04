#ifndef TD3_TEST1__VISIBILITY_CONTROL_H_
#define TD3_TEST1__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TD3_TEST1_EXPORT __attribute__ ((dllexport))
    #define TD3_TEST1_IMPORT __attribute__ ((dllimport))
  #else
    #define TD3_TEST1_EXPORT __declspec(dllexport)
    #define TD3_TEST1_IMPORT __declspec(dllimport)
  #endif
  #ifdef TD3_TEST1_BUILDING_LIBRARY
    #define TD3_TEST1_PUBLIC TD3_TEST1_EXPORT
  #else
    #define TD3_TEST1_PUBLIC TD3_TEST1_IMPORT
  #endif
  #define TD3_TEST1_PUBLIC_TYPE TD3_TEST1_PUBLIC
  #define TD3_TEST1_LOCAL
#else
  #define TD3_TEST1_EXPORT __attribute__ ((visibility("default")))
  #define TD3_TEST1_IMPORT
  #if __GNUC__ >= 4
    #define TD3_TEST1_PUBLIC __attribute__ ((visibility("default")))
    #define TD3_TEST1_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TD3_TEST1_PUBLIC
    #define TD3_TEST1_LOCAL
  #endif
  #define TD3_TEST1_PUBLIC_TYPE
#endif
#endif  // TD3_TEST1__VISIBILITY_CONTROL_H_
// Generated 28-Jun-2024 10:48:08
 