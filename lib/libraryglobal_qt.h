#ifndef LIBRARYNAME_GLOBAL_H
#define LIBRARYNAME_GLOBAL_H

#include "config.h"
#include <QtGlobal>

/**********************************
 * Library management
 *********************************/
#if defined(LIBRARYNAME_LIB_BUILD)
#  define LIBRARYNAME_EXPORT Q_DECL_EXPORT
#else
#  define LIBRARYNAME_EXPORT Q_DECL_IMPORT
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
#define BENCHMG_BUILTIN(x)  __has_builtin(x)
#else
#define BENCHMG_BUILTIN(x)  0
#endif

/**********************************
 * Custom macros in order to
 * not trigger warning on expected
 * behaviour
 *********************************/
#define BENCHMG_FALLTHROUGH  [[fallthrough]]    /**< Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough */

/**********************************
 * Context informations
 *********************************/
#define LIBRARYNAME_FILE            __FILE__
#define LIBRARYNAME_LINE            __LINE__
#define LIBRARYNAME_FCTNAME         __func__

#define LIBRARYNAME_FCTSIG          Q_FUNC_INFO

/**********************************
 * Classes behaviours
 *********************************/
#define LIBRARYNAME_DISABLE_COPY(Class) \
    Q_DISABLE_COPY(Class)

#define LIBRARYNAME_DISABLE_MOVE(Class) \
    Q_DISABLE_MOVE(Class)

#define LIBRARYNAME_DISABLE_COPY_MOVE(Class) \
    Q_DISABLE_COPY_MOVE(Class)

#endif // LIBRARYNAME_GLOBAL_H