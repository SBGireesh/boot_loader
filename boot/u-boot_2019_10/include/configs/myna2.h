/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2016~2023 Synaptics Incorporated. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or
 * later as published by the Free Software Foundation.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND
 * SYNAPTICS EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE, AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY
 * INTELLECTUAL PROPERTY RIGHTS. IN NO EVENT SHALL SYNAPTICS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, OR
 * CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED AND
 * BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF
 * COMPETENT JURISDICTION DOES NOT PERMIT THE DISCLAIMER OF DIRECT
 * DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS' TOTAL CUMULATIVE LIABILITY
 * TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S. DOLLARS.
 */

#define CONFIG_ENV_SIZE			(64 << 10) /* 64KiB */

#ifdef CONFIG_ENV_IS_IN_SPI_FLASH
/* Environment in SPI NOR flash */
#define SPI_FLASH_BL_END		(2 << 20) /* 2MiB */
#define CONFIG_ENV_OFFSET		(SPI_FLASH_BL_END - CONFIG_ENV_SIZE)
#define CONFIG_ENV_SECT_SIZE		(64 << 10) /* 64KiB sectors */
#endif

#ifdef CONFIG_ENV_IS_IN_MMC
/* Environment in eMMC, at the end of "bl_x" */
#define ENV_MMC_PART_NAME		"bl_a"
#define CONFIG_ENV_OFFSET_REDUND	1 /* only a flag */
#define ENV_MMC_PART_NAME_REDUND	"bl_b"
#endif

#define COUNTER_FREQUENCY			25000000 /* 25MHz */

#define CONFIG_SYS_MAX_NAND_DEVICE     1

#define CONFIG_SYS_LOAD_ADDR		0xef70000

#define CONFIG_SYS_AUTOLOAD		"n"			/* disable autoload image via tftp after dhcp */

//max malloc length
#define CONFIG_SYS_MALLOC_LEN		(1450 << 20)

//#define CONFIG_SYS_MALLOC_F_LEN		(4 << 20) /* Serial is required before relocation */

#define CONFIG_SYS_FLASH_BASE		0xF0000000
#define CONFIG_SYS_MAX_FLASH_BANKS		1

#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_TEXT_BASE - (2 << 20))

#define CONFIG_SYS_BOOTM_LEN	(32 << 20)

#define CONFIG_GICV2
#define GICD_BASE       0xf7901000
#define GICC_BASE       0xf7902000

#define CONFIG_EXTRA_ENV_SETTINGS "upgrade_available=0\0" "altbootcmd=if test ${boot_slot}  = 1; then bootslot set b; bootcount reset;bootcount reset; run bootcmd; else bootslot set a; bootcount reset; bootcount reset; run bootcmd;  fi"

/* Watchdog configs*/
/*
#define CONFIG_HW_WATCHDOG
#define CONFIG_DESIGNWARE_WATCHDOG

#define CONFIG_DW_WDT_BASE		0xF7FC5000

#define CONFIG_DW_WDT_CLOCK_KHZ	25000
#define CONFIG_WATCHDOG_TIMEOUT_MSECS 	0
*/
