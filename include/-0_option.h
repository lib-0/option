#ifndef G_0_OPTION_H
#define G_0_OPTION_H

#include "-0_debug.h"

#define G_0_OPTION(type) g_0_option__##type##__t

#define G_0_OPTION_UNWRAP(type) g_0_option__##type##__unwrap
#define G_0_OPTION_SOME(type) g_0_option__##type##__some
#define G_0_OPTION_NONE(type) g_0_option__##type##__none

#define G_0_OPTION_DEFINE_TYPE(type)                                           \
  typedef union {                                                              \
    unsigned char none;                                                        \
    type some;                                                                 \
  } g_0_option__##type##__value;                                               \
  typedef struct g_0_option__##type {                                          \
    _Bool is_some;                                                             \
    g_0_option__##type##__value value;                                         \
  } g_0_option__##type##__t;                                                   \
  type g_0_option__##type##__unwrap(                                           \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t option) {   \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (!option.is_some) {                                                     \
      g_0_debug_die(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE "unwrap failed");      \
    }                                                                          \
    return option.value.some;                                                  \
  }                                                                            \
  g_0_option__##type##__t g_0_option__##type##__some(                          \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE type value) {                       \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    return (g_0_option__##type##__t){.is_some = 1, .value = {.some = value}};  \
  }                                                                            \
  g_0_option__##type##__t g_0_option__##type##__none(                          \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0) {                                 \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }

#endif
