#include "auth.h"

#include <stdio.h>
#include <unistd.h>

struct pam_response *reply;
int dConv(int num_msg, const struct pam_message **msg,
          struct pam_response **resp, void *appdata_ptr) {
    *resp = reply;
    return PAM_SUCCESS;
}

static struct pam_conv conv = {dConv, NULL};

int login(char *username, char *password) {
    pam_handle_t *pamh = NULL;
    int retval = pam_start("d-lock", username, &conv, &pamh);
    if (retval == PAM_SUCCESS) {
        reply = (struct pam_response *)malloc(sizeof(struct pam_response));
        reply[0].resp = strdup(password);
        reply[0].resp_retcode = 0;
        retval = pam_authenticate(pamh, 0);
    }

    if (retval == PAM_SUCCESS) {
        retval = pam_acct_mgmt(pamh, 0);
    }

    if (retval == PAM_SUCCESS) {
        fprintf(stdout, "Authenticated\n");
    } else {
        fprintf(stdout, "Not Authenticated\n");
    }

    if (pam_end(pamh, retval) != PAM_SUCCESS) {
        pamh = NULL;
        fprintf(stdout, "check_user: failed to release authenticator\n");
        exit(1);
    }

    return (retval == PAM_SUCCESS ? 1 : 0);
}
