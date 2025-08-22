#include <common.h>
#include <command.h>
#include <linux/types.h>
#include <linux/string.h>

static int do_netboot(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    ulong ram_addr;
    ulong dtb_offset;
    ulong dtb_addr;
    char *filename;
    char cmd[128];

    if (argc != 4) {
        printf("\nUsage: netboot <kernel_addr> <dtb_offset> <filename>\n");
    }
    ram_addr = simple_strtoul(argv[1], NULL, 16);
    dtb_offset  = simple_strtoul(argv[2], NULL, 16);
    filename    = argv[3];

    dtb_addr = ram_addr + dtb_offset;

    ulong kernel_addr = ram_addr + 0x190;

    run_command("net_init", 0);

    printf("Loading %s to 0x%08lx...\n", filename, ram_addr);
    snprintf(cmd, sizeof(cmd), "tftpboot 0x%08lx %s", ram_addr, filename);
    run_command(cmd, 0);

    printf("Booting kernel from 0x%08lx with FDT at 0x%08lx...\n", kernel_addr, dtb_addr);
    snprintf(cmd, sizeof(cmd), "bootm 0x%08lx - 0x%08lx", kernel_addr, dtb_addr);
    run_command(cmd, 0);

    return 0;
}

U_BOOT_CMD(
    netboot,    4,    0,    do_netboot,
    "Boots a kernel from tftp",
    "netboot <kernel_addr> <dtb_offset> <filename>"
);
