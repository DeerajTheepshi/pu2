#ifndef _AUTH_DLOCK_H
#define _AUTH_DLOCK_H

#include <security/pam_appl.h>
#include <security/pam_misc.h>

int dConv(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr);
int login(char *username, char *password);


#endif