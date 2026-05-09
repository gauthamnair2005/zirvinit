#include <stdio.h>
#include <unistd.h>
#include <string.h>

static void mosix_banner(void)
{
    printf("\n  Z I R V I N I T\n");
    printf("  ---------------\n");
    printf("  MOSIX Compliant PID 1\n");
    printf("  Lead Developer: Gautham Nair\n\n");
}

int main(void)
{
    mosix_banner();
    printf("[ INIT ] Starting MOSIX lifecycle...\n");
    printf("[ INIT ] Verifying /zirv namespace...\n");
    printf("[ INIT ] Launching ZirvShell...\n");

    char *argv[] = { "/bin/shell", NULL };
    char *envp[] = { NULL };

    execve("/bin/shell", argv, envp);

    printf("[ INIT ] execve failed!\n");
    for (;;) ;
    return 0;
}
