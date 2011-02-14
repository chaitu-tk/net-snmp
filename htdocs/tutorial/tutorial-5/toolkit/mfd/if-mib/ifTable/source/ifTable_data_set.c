/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.16 $ of : mfd-data-set.m2c,v $
 *
 * $Id$
 *
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ifTable.h"


/** @defgroup data_set data_set: Routines to set data
 *
 * These routines are used to set the value for individual objects. The
 * row context is passed, along with the new value.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * ifTable is subid 2 of interfaces.
 * It's status is Current.
 * OID: .1.3.6.1.2.1.2.2, length: 8
 */
    /*
     ***********************************************************************
     * Baby Steps Flow Chart (2004.06.05)                                  *
     *                                                                     *
     * +--------------+    +================+    U = unconditional path    *
     * |optional state|    ||required state||    S = path for success      *
     * +--------------+    +================+    E = path for error        *
     ***********************************************************************
     *
     *                        +--------------+
     *                        |     pre      |
     *                        |   request    |
     *                        +--------------+
     *                               | U
     *                        +==============+
     *       +----------------||  object    ||
     *       |              E ||  lookup    ||
     *       |                +==============+
     *       |                       | S
     *       |                +==============+
     *       |              E ||   check    ||
     *       |<---------------||   values   ||
     *       |                +==============+
     *       |                       | S
     *       |                +==============+
     *       |       +<-------||   undo     ||
     *       |       |      E ||   setup    ||
     *       |       |        +==============+
     *       |       |               | S
     *       |       |        +==============+
     *       |       |        ||    set     ||-------------------------->+
     *       |       |        ||   value    || E                         |
     *       |       |        +==============+                           |
     *       |       |               | S                                 |
     *       |       |        +--------------+                           |
     *       |       |        |    check     |-------------------------->|
     *       |       |        |  consistency | E                         |
     *       |       |        +--------------+                           |
     *       |       |               | S                                 |
     *       |       |        +==============+         +==============+  |
     *       |       |        ||   commit   ||-------->||     undo   ||  |
     *       |       |        ||            || E       ||    commit  ||  |
     *       |       |        +==============+         +==============+  |
     *       |       |               | S                     U |<--------+
     *       |       |        +--------------+         +==============+
     *       |       |        | irreversible |         ||    undo    ||
     *       |       |        |    commit    |         ||     set    ||
     *       |       |        +--------------+         +==============+
     *       |       |               | U                     U |
     *       |       +-------------->|<------------------------+
     *       |                +==============+
     *       |                ||   undo     ||
     *       |                ||  cleanup   ||
     *       |                +==============+
     *       +---------------------->| U
     *                        +--------------+
     *                        |    post      |
     *                        |   request    |
     *                        +--------------+
     *
     */

/**
 * commit new values.
 *
 * At this point, you should have done everything you can to ensure that
 * this commit will not fail.
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * ifTable_oids.h.
 *
 * @param ifTable_rowreq_ctx
 *        Pointer to the users context.
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error
 */
int
ifTable_commit(ifTable_rowreq_ctx * rowreq_ctx)
{
    /*
     * set not implemented
     */
    return MFD_ERROR;
}

/**
 * undo commit new values.
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * ifTable_oids.h.
 *
 * @param ifTable_rowreq_ctx
 *        Pointer to the users context.
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error
 */
int
ifTable_undo_commit(ifTable_rowreq_ctx * rowreq_ctx)
{
    int             rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:ifTable_undo_commit", "called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:
     * undo commit data
     */

    return rc;
}

/*---------------------------------------------------------------------
 * IF-MIB::ifEntry.ifAdminStatus
 * ifAdminStatus is subid 7 of ifEntry.
 * It's status is Current, and it's access level is ReadWrite.
 * OID: .1.3.6.1.2.1.2.2.1.7
 * Description:
The desired state of the interface.  The testing(3) state
            indicates that no operational packets can be passed.  When a
            managed system initializes, all interfaces start with
            ifAdminStatus in the down(2) state.  As a result of either
            explicit management action or per configuration information
            retained by the managed system, ifAdminStatus is then
            changed to either the up(1) or testing(3) states (or remains
            in the down(2) state).
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 2/8. Values:  up(1), down(2), testing(3)
 *
 * It's syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Check that the proposed new value is potentially valid.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param ifAdminStatus_val
 *        A long containing the new value.
 *
 * @retval MFD_SUCCESS        : incoming value is legal
 * @retval MFD_NOT_VALID_NOW  : incoming value is not valid now
 * @retval MFD_NOT_VALID_EVER : incoming value is never valid
 *
 * This is the place to check for requirements that are not
 * expressed in the mib syntax (for example, a requirement that
 * is detailed in the description for an object).
 *
 * You should check that the requested change between the undo value and the
 * new value is legal (ie, the transistion from one value to another
 * is legal).
 *      
 *@note
 * This check is only to determine if the new value
 * is \b potentially valid. This is the first check of many, and
 * is one of simplest ones.
 * 
 *@note
 * this is not the place to do any checks for values
 * which depend on some other value in the mib. Those
 * types of checks should be done in the
 * ifTable_check_dependencies() function.
 *
 * The following checks have already been done for you:
 *    The syntax is ASN_INTEGER
 *    The value is one of  up(1), down(2), testing(3)
 *
 * If there a no other checks you need to do, simply return MFD_SUCCESS.
 *
 * For example, an object with the syntax INTEGER(0..500) will
 * have already been checked for a value between 0 and 500. But
 * if the description also specifies that the value must be an
 * even number, you would enforce that requirement here. If and odd
 * numer is set, return MFD_NOT_VALID_EVER. If the description also
 * specified that changed must be made in single steps of 2, then a set
 * to change the value 10 to an even value other than 8 or 12 should
 * return MFD_NOT_VALID_NOW.
 *
 */
int
ifAdminStatus_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                          u_long ifAdminStatus_val)
{
    DEBUGMSGTL(("verbose:ifTable:ifAdminStatus_check_value", "called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:
     * check that new value is legal
     */

    /*
     * if everything looks ok, return 0 
     */
    return MFD_SUCCESS;
}

/**
 * Save old value information
 *
 * @param rowreq_ctx
 *        Pointer to the table context (ifTable_rowreq_ctx)
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error. set will fail.
 *
 * This function will be called after the table level undo setup function
 * ifTable_undo_setup has been called.
 *
 *@note
 * this function will only be called if a new value is set for this column.
 *
 * If there is any setup specific to a particular column (e.g. allocating
 * memory for a string), you should do that setup in this function, so it
 * won't be done unless it is necessary.
 */
int
ifAdminStatus_undo_setup(ifTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ifTable:ifAdminStatus_undo_setup", "called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO: copy ifAdminStatus data
     * copy ifAdminStatus data
     *  from rowreq_ctx->data.ifAdminStatus to rowreq_ctx->undo->ifAdminStatus
     */
    rowreq_ctx->undo->ifAdminStatus = rowreq_ctx->data.ifAdminStatus;


    return MFD_SUCCESS;
}

/**
 * Set the new value.
 *
 * @param rowreq_ctx
 *        Pointer to the users context. You should know how to
 *        manipulate the value from this object.
 * @param ifAdminStatus_val
 *        A long containing the new value.
 */
int
ifAdminStatus_set(ifTable_rowreq_ctx * rowreq_ctx,
                  u_long ifAdminStatus_val)
{

    DEBUGMSGTL(("verbose:ifTable:ifAdminStatus_set", "called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:
     * reverse value mapping
     *
     * If the values for your data type don't exactly match the
     * possible values defined by the mib, you should map them here.
     */
    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    switch (ifAdminStatus_val) {
    case IFADMINSTATUS_UP:
        ifAdminStatus_val = INTERNAL_IFADMINSTATUS_UP;
        break;

    case IFADMINSTATUS_DOWN:
        ifAdminStatus_val = INTERNAL_IFADMINSTATUS_DOWN;
        break;

    case IFADMINSTATUS_TESTING:
        ifAdminStatus_val = INTERNAL_IFADMINSTATUS_TESTING;
        break;

    default:
        snmp_log(LOG_ERR,
                 "couldn't reverse map value %d for ifAdminStatus\n",
                 ifAdminStatus_val);
        return SNMP_ERR_GENERR;
    }
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/

    /*
     * TODO:
     * set ifAdminStatus value in rowreq_ctx->data.
     */
    rowreq_ctx->data.ifAdminStatus = ifAdminStatus_val;

    return MFD_SUCCESS;
}

/**
 * undo the previous set.
 *
 * @param rowreq_ctx
 *        Pointer to the users context.
 */
int
ifAdminStatus_undo(ifTable_rowreq_ctx * rowreq_ctx)
{

    DEBUGMSGTL(("verbose:ifTable:ifAdminStatus_undo", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO: copy ifAdminStatus data
     * copy ifAdminStatus data
     *  from rowreq_ctx->undo->ifAdminStatus to rowreq_ctx->data.ifAdminStatus
     */
    rowreq_ctx->data.ifAdminStatus = rowreq_ctx->undo->ifAdminStatus;


    return MFD_SUCCESS;
}

/**
 * check dependencies
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * ifTable_oids.h.
 *
 * @retval MFD_SUCCESS all the changes to the row are legal
 * @retval MFD_ERROR   one or more changes are not legal
 *
 * (see README-table-ifTable if you don't have dependencies)
 */
int
ifTable_check_dependencies(ifTable_rowreq_ctx * rowreq_ctx)
{
    int             rc = SNMP_ERR_NOERROR;

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:
     * check that all new value are legal.
     *
     * This is useful for for tables which have dependencies
     * between columns (or rows, or tables).
     *
     * For example, two columns allocating a percentage of something
     * should add up to 100%.
     */
    return rc;
}

/** @} */