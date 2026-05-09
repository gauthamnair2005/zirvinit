# zirvinit — MOSIX PID 1

Minimal init process for the Zirvium kernel. Launched as the first userspace process by the kernel, it sets up the MOSIX environment and spawns the shell via `execve("/bin/shell")`.

## Build

```bash
make
```

Produces `zirvinit.elf` — a statically linked, freestanding, no-pie ELF binary embedded into the kernel at `/bin/init`.
