#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define KEY_V 0x19

static void mosix_banner(void)
{
    printf("\n");
    printf("  +--------------------------------------+\n");
    printf("  |                                      |\n");
    printf("  |           Z I R V I U M              |\n");
    printf("  |    MOSIX Operating System            |\n");
    printf("  |                                      |\n");
    printf("  +--------------------------------------+\n");
    printf("\n");
}

int main(void)
{
    mosix_banner();
    printf("[INIT] Starting MOSIX lifecycle...\n");
    printf("[INIT] Verifying /zirv namespace...\n");
    printf("[INIT] Press 'v' for CLI shell...\n");

    int launch_shell = 0;
    for (int i = 0; i < 50; i++) {
        key_event_t ev;
        if (read_keys(&ev) == 0 && ev.pressed && ev.keycode == KEY_V) {
            launch_shell = 1;
            break;
        }
        msleep(10);
    }

    if (launch_shell) {
        printf("[INIT] Launching ZirvShell...\n\n");
        char *argv[] = { "/bin/shell", NULL };
        char *envp[] = { NULL };
        execve("/bin/shell", argv, envp);
    } else {
        printf("[INIT] Launching ZirvUI desktop...\n\n");
        char *argv[] = { "/bin/zirvui", NULL };
        char *envp[] = { NULL };
        execve("/bin/zirvui", argv, envp);

        printf("[INIT] GUI exited, launching shell...\n\n");
        char *argv2[] = { "/bin/shell", NULL };
        execve("/bin/shell", argv2, envp);
    }

    printf("[INIT] execve failed!\n");
    for (;;) ;
    return 0;
}
