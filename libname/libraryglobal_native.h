#ifndef LIBRARYNAME_GLOBAL_H
#define LIBRARYNAME_GLOBAL_H

#include "config.h"

/**********************************
 * Library management
 *********************************/
#ifdef __GNUC__
#   if defined(LIBRARYNAME_LIBRARY_BUILD)
#       define LIBRARYNAME_EXPORT __attribute__((visibility("default")))
#   else
#       define LIBRARYNAME_EXPORT
#   endif
#else
#   if defined(LIBRARYNAME_LIBRARY_BUILD)
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

/**********************************
 * Context informations
 *********************************/
#define LIBRARYNAME_FILE            __FILE__
#define LIBRARYNAME_LINE            __LINE__
#define LIBRARYNAME_FCTNAME         __func__

#if defined(_MSC_VER)
#define LIBRARYNAME_FCTSIG          __FUNCSIG__
#else
#define LIBRARYNAME_FCTSIG          __PRETTY_FUNCTION__
#endif

/**********************************
 * Variables attributes
 *********************************/
#define LIBRARYNAME_VAR_MAYBE_UNUSED    [[maybe_unused]]
#define LIBRARYNAME_VAR_UNUSED          LIBRARYNAME_VAR_MAYBE_UNUSED

/**********************************
 * Classes behaviours
 *********************************/
#define LIBRARYNAME_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

#define LIBRARYNAME_DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

#define LIBRARYNAME_DISABLE_COPY_MOVE(Class) \
    LIBRARYNAME_DISABLE_COPY(Class) \
    LIBRARYNAME_DISABLE_MOVE(Class)

#endif // LIBRARYNAME_GLOBAL_H