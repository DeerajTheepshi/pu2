#include <unistd.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>

struct pam_response *reply;
int dConv(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr){
	*resp = reply;
	return PAM_SUCCESS;
}

static struct pam_conv conv = {
    dConv,
	NULL
};

int main(int argc, char *argv[])
{
    pam_handle_t *pamh=NULL;
    const char *username="nobody";

    if(argc == 2) {
		username = argv[1];
    }

    if(argc > 2 || argc<2) {
		fprintf(stdout, "Usage: check_user [username]\n");
		exit(1);
    }

    int retval = pam_start("d-lock", username, &conv, &pamh);
    if (retval == PAM_SUCCESS){
		reply = (struct pam_response *)malloc(sizeof(struct pam_response));
		char *pass = "diprivi@15";
		reply[0].resp = strdup(pass);
		reply[0].resp_retcode = 0;
        retval = pam_authenticate(pamh, 0);    
	}

    if (retval == PAM_SUCCESS){
        retval = pam_acct_mgmt(pamh, 0);      
	}

    if (retval == PAM_SUCCESS) {
		fprintf(stdout, "Authenticated\n");
    } else {
		fprintf(stdout, "Not Authenticated\n");
    }

    if (pam_end(pamh,retval) != PAM_SUCCESS) {    
		pamh = NULL;
		fprintf(stderr, "check_user: failed to release authenticator\n");
		exit(1);
    }

    return ( retval == PAM_SUCCESS ? 0:1 );     
}
