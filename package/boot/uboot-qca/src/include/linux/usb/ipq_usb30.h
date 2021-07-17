/*
 * Copyright (c) 2014, 2017 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MSM_USB30_H
#define __MSM_USB30_H

/*
 * QSCRATCH registers
 */
#define IPQ_SSUSB_REG_QSCRATCH_REV				0xF8800
#define IPQ_SSUSB_REG_QSCRATCH_CTRL				0xF8804
#define IPQ_SSUSB_REG_QSCRATCH_RAM1				0xF880C
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL			0xF8810
#define IPQ_SSUSB_REG_QSCRATCH_PARAMETER_OVERRIDE_X		0xF8814
#define IPQ_SSUSB_REG_QSCRATCH_CHARGING_DET_CTRL		0xF8818
#define IPQ_SSUSB_REG_QSCRATCH_CHARGING_DET_OUTPUT		0xF881C
#define IPQ_SSUSB_REG_QSCRATCH_ALT_INTERRUPT_EN			0xF8820
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_IRQ_STAT			0xF8824
#define IPQ_SSUSB_REG_QSCRATCH_CGCTL				0xF8828
#define IPQ_SSUSB_REG_QSCRATCH_DBG_BUS				0xF882C
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1		0xF8834
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_2		0xF8838
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_DATA_IN		0xF883C
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_DATA_OUT		0xF8840
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_CAP_ADDR		0xF8844
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_CAP_DATA		0xF8848
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_READ		0xF884C
#define IPQ_SSUSB_REG_QSCRATCH_SS_CR_PROTOCOL_WRITE		0xF8850
#define IPQ_SSUSB_REG_QSCRATCH_SS_STATUS_READ_ONLY		0xF8854
#define IPQ_SSUSB_REG_QSCRATCH_PWR_EVNT_IRQ_STAT		0xF8858
#define IPQ_SSUSB_REG_QSCRATCH_PWR_EVNT_IRQ_MASK		0xF885C
#define IPQ_SSUSB_REG_QSCRATCH_HW_SW_EVT_CTRL			0xF8860
#define IPQ_SSUSB_REG_QSCRATCH_VMIDMT_AMEMTYPE_CTRL		0xF8864
#define IPQ_SSUSB_REG_QSCRATCH_QSCRTCH(n)			0xF8868 + ((n) * 0x4)

/*
 * Global config registers
 */

#define IPQ_SSUSB_REG_GCTL_U2RSTECN			(1 << 16)
#define IPQ_SSUSB_REG_GCTL_U2EXIT_LFPS			(1 << 2)

#define IPQ_SSUSB_REG_QSCRATCH_CGCTL_RAM13_EN		(1 << 4)
#define IPQ_SSUSB_REG_QSCRATCH_CGCTL_RAM1112_EN		(1 << 3)
#define IPQ_SSUSB_REG_QSCRATCH_CGCTL_BAM_NDP_EN		(1 << 2)
#define IPQ_SSUSB_REG_QSCRATCH_CGCTL_DBM_FSM_EN		(1 << 1)
#define IPQ_SSUSB_REG_QSCRATCH_CGCTL_DBM_REG_EN		(1 << 0)

#define IPQ_SSUSB_REG_QSCRATCH_RAM1_RAM13_EN		(1 << 2)
#define IPQ_SSUSB_REG_QSCRATCH_RAM1RAM12_EN		(1 << 1)
#define IPQ_SSUSB_REG_QSCRATCH_RAM1_RAM11_EN		(1 << 0)

#define IPQ_GPIO_IN_OUTn(n)				(MSM_TLMM_BASE + \
							0x00001004 + 0x10 * (n))
#define IPQ_GPIO_IN_OUTn_GPIO_OUT_SHFT			1

/*
 * USB Reset control register
 */
#define IPQ_USB30_RESET_PORT2_HS_PHY_ASYNC_RESET	(1 << 5)
#define IPQ_USB30_RESET_MASTER_ASYNC_RESET		(1 << 4)
#define IPQ_USB30_RESET_SLEEP_ASYNC_RESET		(1 << 3)
#define IPQ_USB30_RESET_MOC_UTMI_ASYNC_RESET		(1 << 2)
#define IPQ_USB30_RESET_POWERON_ASYNC_RESET		(1 << 1)
#define IPQ_USB30_RESET_PHY_ASYNC_RESET			(1 << 0)
#define IPQ_USB30_RESET_MASK				0x3F

#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL_COMMONONN		(1 << 11)
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL_USE_CLKCORE		(1 << 18)
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL_FSEL_VAL 		0x70
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL_AUTORESUME 		(1 << 19)
#define IPQ_SSUSB_REG_QSCRATCH_HS_PHY_CTRL_UTMI_OTG_VBUS_VALID	(1 << 20)

#define IPQ_QSCRATCH_REG_OFFSET			(0x000F8800)
#define IPQ_QSCRATCH_GENERAL_CFG		(IPQ_QSCRATCH_REG_OFFSET + 0x08)
#define IPQ_CHARGING_DET_CTRL_REG		(IPQ_QSCRATCH_REG_OFFSET + 0x18)
#define IPQ_CHARGING_DET_OUTPUT_REG		(IPQ_QSCRATCH_REG_OFFSET + 0x1C)
#define IPQ_ALT_INTERRUPT_EN_REG		(IPQ_QSCRATCH_REG_OFFSET + 0x20)
#define IPQ_HS_PHY_IRQ_STAT_REG			(IPQ_QSCRATCH_REG_OFFSET + 0x24)
#define IPQ_SS_PHY_CTRL_REG			(IPQ_QSCRATCH_REG_OFFSET + 0x30)
#define IPQ_SS_PHY_PARAM_CTRL_1_REG		(IPQ_QSCRATCH_REG_OFFSET + 0x34)

/*
 * PHY control Registers
 */
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_REF_USE_PAD		(1 << 28)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_TEST_BURNIN		(1 << 27)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_TEST_POWERDOWN		(1 << 26)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_RTUNE_REQ		(1 << 25)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_LANE0_PWR_PRESENT	(1 << 24)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_USB2_REF_CLK_EN		(1 << 23)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_USB2_REF_CLK_SEL		(1 << 22)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_SSC_REF_CLK_SEL(n)	((n) << 13)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_SSC_RANGE(n)		((n) << 10)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_REF_USB2_EN		(1 << 9)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_REF_SS_PHY_EN		(1 << 8)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_SS_PHY_RESET		(1 << 7)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_MPLL_MULTI(n)		((n) << 0)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_SS_PHY_RESET		(1 << 7)
#define IPQ_SSUSB_QSCRATCH_SS_PHY_CTRL_SS_PHY_RESET		(1 << 7)

#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_LANE0_TX_TERM_OFFSET(n)	((n) << 27)
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_TX_SWING_FULL(n)		((n) << 20)
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_TX_DEEMPH_6DB(n)		((n) << 14)
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_TX_DEEMPH_3_5DB(n)		((n) << 8)
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_LOS_LEVEL(n)			((n) << 3)
#define IPQ_SSUSB_REG_QSCRATCH_SS_PHY_PARAM_CTRL_1_LOS_BIAS(n)			((n) << 0)
#define IPQ_SSUSB_REG_QSCRATCH_GENERAL_CFG_XHCI_REV(n)				((n) << 2)
#define IPQ_SSUSB_REG_QSCRATCH_GENERAL_CFG_DBM_EN				(1 << 1)

#define IPQ_TCSR_USB_CONTROLLER_TYPE_SEL	0x1A4000B0
#define IPQ806X_USB_CONT_TYPE			0x3
#define IPQ806X_USB_REG_MAP_SIZE		0x4

#define USB30_MODE_DEVICE	0
#define USB30_MODE_HOST		1

struct dwc3_platform_data {
	u8 usb_mode;
	u8 pwr_en;
	u8 pwr_en_gpio1;
	u8 pwr_en_gpio2;
};
#endif /*__MSM_USB30_H */
