#include "rpctestshelper.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Enum documentations       */
/*****************************/

/*****************************/
/* Structure documentations  */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Macro definitions         */
/*****************************/
#if !defined(LIBRARYNAME_TESTS_DIR_EXTERNAL_RSC)
#error "Macro 'LIBRARYNAME_TESTS_DIR_EXTERNAL_RSC' is not defined, please set up !"
#endif

/*****************************/
/* Start namespace           */
/*****************************/

/*****************************/
/* Constants defintitions    */
/*****************************/

/*****************************/
/* Functions implementations */
/*****************************/

std::string RpcTestsHelper::getPathExternalRsc(const std::string &filename)
{
    return LIBRARYNAME_TESTS_DIR_EXTERNAL_RSC + filename;
}

/*****************************/
/* End namespace             */
/*****************************/

/*****************************/
/* End file                  */
/*****************************/