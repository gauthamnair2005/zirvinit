# zirvinit — MOSIX PID 1 (Reference Init)

Minimal init process for **MOSIX** operating systems. Launched as the first
userspace process (PID 1) by the kernel, it prints the MOSIX banner and spawns
the shell via `execve("/bin/shell")`.

Part of the [Zirvium](https://github.com/gauthamnair2005/zirvium) reference
MOSIX implementation. See the [MOSIX specification](https://github.com/gauthamnair2005/zirvworld)
for the full standard.

## Source

```
src/crt0.asm     _start -> main -> SYS_EXIT
src/main.c       Banner + execve("/bin/shell")
```

28 lines of C. Links against [zirvlibc](https://github.com/gauthamnair2005/zirvlibc).

## Build

```bash
make
```

Produces `zirvinit.elf` — static, freestanding, no-pie ELF64.
