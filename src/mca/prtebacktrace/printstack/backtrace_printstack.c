/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2006 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2006      Sun Microsystems, Inc.  All rights reserved.
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * Copyright (c) 2019-2020 Intel, Inc.  All rights reserved.
 * Copyright (c) 2020      Cisco Systems, Inc.  All rights reserved
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include "prte_config.h"

#include <stdio.h>
#include <ucontext.h>

#include "constants.h"
#include "src/mca/prtebacktrace/prtebacktrace.h"

int
prte_backtrace_print(FILE *file, char *prefix, int strip)
{
    int fd = prte_stacktrace_output_fileno;

    if( NULL != file ) {
        fd = fileno(file);
    }

    printstack(fd);

    return PRTE_SUCCESS;
}


int
prte_backtrace_buffer(char ***message_out, int *len_out)
{
    *message_out = NULL;
    *len_out = 0;

    /* BWB - I think we can implement this in a similar way that
       printstack is implemented.  I just don't have time right
       now. */

    return PRTE_ERR_NOT_IMPLEMENTED;
}
