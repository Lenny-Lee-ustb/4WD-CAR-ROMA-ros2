#ifndef TD3_FINAL__VISIBILITY_CONTROL_H_
#define TD3_FINAL__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TD3_FINAL_EXPORT __attribute__ ((dllexport))
    #define TD3_FINAL_IMPORT __attribute__ ((dllimport))
  #else
    #define TD3_FINAL_EXPORT __declspec(dllexport)
    #define TD3_FINAL_IMPORT __declspec(dllimport)
  #endif
  #ifdef TD3_FINAL_BUILDING_LIBRARY
    #define TD3_FINAL_PUBLIC TD3_FINAL_EXPORT
  #else
    #define TD3_FINAL_PUBLIC TD3_FINAL_IMPORT
  #endif
  #define TD3_FINAL_PUBLIC_TYPE TD3_FINAL_PUBLIC
  #define TD3_FINAL_LOCAL
#else
  #define TD3_FINAL_EXPORT __attribute__ ((visibility("default")))
  #define TD3_FINAL_IMPORT
  #if __GNUC__ >= 4
    #define TD3_FINAL_PUBLIC __attribute__ ((visibility("default")))
    #define TD3_FINAL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TD3_FINAL_PUBLIC
    #define TD3_FINAL_LOCAL
  #endif
  #define TD3_FINAL_PUBLIC_TYPE
#endif
#endif  // TD3_FINAL__VISIBILITY_CONTROL_H_
// Generated 21-Jun-2024 14:28:12
 