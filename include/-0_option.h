#ifndef G_0_OPTION_H
#define G_0_OPTION_H

#include "-0_utils.h"

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
#define G_0_OPTION_XOR(type) g_0_option__##type##__xor
#define G_0_OPTION_MAP(type) g_0_option__##type##__map

#define G_0_OPTION_DEFINE_TYPE(type)                                           \
  typedef union {                                                              \
    unsigned char none;                                                        \
    type some;                                                                 \
  } g_0_option__##type##__value;                                               \
  typedef struct g_0_option__##type {                                          \
    _Bool is_some;                                                             \
    g_0_option__##type##__value value;                                         \
  } g_0_option__##type##__t;                                                   \
  static inline type g_0_option__##type##__unwrap(                             \
      g_0_option__##type##__t option) {                                        \
    g_0_assert(option.is_some);                                                \
    return option.value.some;                                                  \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option__##type##__some(            \
      type value) {                                                            \
    return (g_0_option__##type##__t){.is_some = 1, .value = {.some = value}};  \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option__##type##__none(void) {     \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }                                                                            \
  static inline _Bool g_0_option__##type##__is_some(                           \
      g_0_option__##type##__t *option) {                                       \
    return option->is_some;                                                    \
  }                                                                            \
  static inline _Bool g_0_option__##type##__is_none(                           \
      g_0_option__##type##__t *option) {                                       \
    return !option->is_some;                                                   \
  }                                                                            \
  static inline type g_0_option__##type##__unwrap_or(                          \
      g_0_option__##type##__t option, type *fallback) {                        \
    if (!option.is_some) {                                                     \
      return *fallback;                                                        \
    }                                                                          \
    return option.value.some;                                                  \
  }                                                                            \
  static inline type g_0_option__##type##__unwrap_or_else(                     \
      g_0_option__##type##__t option, type (*fallback)(void)) {                \
    if (!option.is_some) {                                                     \
      return fallback();                                                       \
    }                                                                          \
    return option.value.some;                                                  \
  }                                                                            \
  static inline type *g_0_option__##type##__unwrap_unchecked(                  \
      g_0_option__##type##__t *option) {                                       \
    return &option->value.some;                                                \
  }                                                                            \
  static inline g_0_option__##type##__t *g_0_option_##type##__or(              \
      g_0_option__##type##__t *option, g_0_option__##type##__t *fallback) {    \
    if (option->is_some) {                                                     \
      return option;                                                           \
    }                                                                          \
    return fallback;                                                           \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option_##type##__or_else(          \
      g_0_option__##type##__t *option,                                         \
      g_0_option__##type##__t (*fallback)(void)) {                             \
    if (option->is_some) {                                                     \
      return *option;                                                          \
    }                                                                          \
    return fallback();                                                         \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option_##type##__and(              \
      g_0_option__##type##__t *option, g_0_option__##type##__t *alternative) { \
    if (option->is_some) {                                                     \
      return *alternative;                                                     \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option_##type##__and_then(         \
      g_0_option__##type##__t *option,                                         \
      g_0_option__##type##__t (*alternative)(type * option)) {                 \
    if (option->is_some) {                                                     \
      return alternative(&option->value.some);                                 \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option_##type##__xor(              \
      g_0_option__##type##__t *option, g_0_option__##type##__t *alternative) { \
    if (option->is_some && alternative->is_some) {                             \
      return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};    \
    } else if (option->is_some) {                                              \
      return *option;                                                          \
    } else if (alternative->is_some) {                                         \
      return *alternative;                                                     \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }                                                                            \
  static inline g_0_option__##type##__t g_0_option_##type##__map(              \
      g_0_option__##type##__t *option,                                         \
      g_0_option__##type##__t (*map)(type * value)) {                          \
    if (option->is_some) {                                                     \
      return map(&option->value.some);                                         \
    }                                                                          \
    return (g_0_option__##type##__t){.is_some = 0, .value = {.none = 0}};      \
  }

#endif
