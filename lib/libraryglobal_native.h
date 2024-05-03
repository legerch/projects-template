#ifndef LIBRARYNAME_GLOBAL_H
#define LIBRARYNAME_GLOBAL_H

#include "config.h"

/**********************************
 * Library management
 *********************************/
#ifdef __GNUC__
#   if defined(LIBRARYNAME_LIBRARY)
#       define LIBRARYNAME_EXPORT __attribute__((visibility("default")))
#   else
#       define LIBRARYNAME_EXPORT
#   endif
#else
#   if defined(LIBRARYNAME_LIBRARY)
#       define LIBRARYNAME_EXPORT __declspec(dllexport)
#   else
#       define LIBRARYNAME_EXPORT __declspec(dllimport)
#   endif
#endif

/**********************************
 * Deprecations warnings
 *********************************/
#define LIBRARYNAME_DEPREC              [[deprecated]]          /**< Use to mark a method as deprecated. \n\code{.cpp}LIBRARYNAME_DEPREC void myOldFct(); \endcode */
#define LIBRARYNAME_DEPREC_X(reason)    [[deprecated(reason)]] 	/**< Use to mark a method as deprecated and specify a reason. \n\code{.cpp}LIBRARYNAME_DEPREC_X("Use myNewFct() instead") void myOldFunc(); \endcode */

/**********************************
 * Custom macros used to detect custom
 * built-in functions
 * Sources:
 * - MSVC: No equivalent
 * - GCC: https://gcc.gnu.org/onlinedocs/gcc-13.2.0/cpp/_005f_005fhas_005fbuiltin.html
 * - Clang: https://clang.llvm.org/docs/LanguageExtensions.html#has-builtin
 *********************************/
#if defined(__GNUC__) || defined(__clang__)
#   define LIBRARYNAME_BUILTIN(x)  __has_builtin(x)
#else
#   define LIBRARYNAME_BUILTIN(x)  0
#endif

/**********************************
 * Custom macros in order to
 * not trigger warning on expected
 * behaviour
 *********************************/
#define LIBRARYNAME_FALLTHROUGH  [[fallthrough]]    /**< Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough */

#endif // LIBRARYNAME_GLOBAL_H