#ifndef G_0_OPTION_H
#define G_0_OPTION_H

#include "-0_debug.h"

#define G_0_OPTION(type) g_0_option__##type##__t

#define G_0_OPTION_UNWRAP(type) g_0_option__##type##__unwrap
#define G_0_OPTION_SOME(type) g_0_option__##type##__some
#define G_0_OPTION_NONE(type) g_0_option__##type##__none
#define G_0_OPTION_IS_SOME(type) g_0_option__##type##__is_some
#define G_0_OPTION_IS_NONE(type) g_0_option__##type##__is_none
#define G_0_OPTION_UNWRAP_OR(type) g_0_option__##type##__unwrap_or
#define G_0_OPTION_UNWRAP_OR_ELSE(type) g_0_option__##type##__unwrap_or_else
#define G_0_OPTION_UNWRAP_UNCHECKED(type) g_0_option__##type##__unwrap_unchecked
#define G_0_OPTION_OR(type) g_0_option__##type##__or
#define G_0_OPTION_OR_ELSE(type) g_0_option__##type##__or_else
#define G_0_OPTION_AND(type) g_0_option__##type##__and
#define G_0_OPTION_AND_THEN(type) g_0_option__##type##__and_then

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
  }                                                                            \
  _Bool g_0_option__##type##__is_some(                                         \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option) {  \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    return option->is_some;                                                    \
  }                                                                            \
  _Bool g_0_option__##type##__is_none(                                         \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option) {  \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    return !option->is_some;                                                   \
  }                                                                            \
  type g_0_option__##type##__unwrap_or(                                        \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t option,     \
      type *fallback) {                                                        \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (!option.is_some) {                                                     \
      return *fallback;                                                        \
    }                                                                          \
    return option.value.some;                                                  \
  }                                                                            \
  type g_0_option__##type##__unwrap_or_else(                                   \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t option,     \
      type (*fallback)(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0)) {               \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (!option.is_some) {                                                     \
      return fallback(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE0);                   \
    }                                                                          \
    return option.value.some;                                                  \
  }                                                                            \
  type *g_0_option__##type##__unwrap_unchecked(                                \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option) {  \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    return &option->value.some;                                                \
  }                                                                            \
  g_0_option__##type##__t *g_0_option_##type##__or(                            \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option,    \
      g_0_option__##type##__t *fallback) {                                     \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (option->is_some) {                                                     \
      return option;                                                           \
    }                                                                          \
    return fallback;                                                           \
  }                                                                            \
  g_0_option__##type##__t g_0_option_##type##__or_else(                        \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option,    \
      g_0_option__##type##__t (*fallback)(                                     \
          G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0)) {                            \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (option->is_some) {                                                     \
      return *option;                                                          \
    }                                                                          \
    return fallback(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE0);                     \
  }                                                                            \
  g_0_option__##type##__t g_0_option_##type##__and(                            \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option,    \
      g_0_option__##type##__t *alternative) {                                  \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (option->is_some) {                                                     \
      return *alternative;                                                     \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }                                                                            \
  g_0_option__##type##__t g_0_option_##type##__and_then(                       \
      G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_0_option__##type##__t *option,    \
      g_0_option__##type##__t (*alternative)(                                  \
          G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE type * option)) {               \
    G_0_DEBUG_FUNCTION_BODY_PRELUDE;                                           \
    if (option->is_some) {                                                     \
      return alternative(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE &                 \
                         option->value.some);                                  \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }

#endif
