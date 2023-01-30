// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2021 Rockchip Electronics Co., Ltd
 */

#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <regmap.h>
#include <syscon.h>
#include <dt-bindings/pinctrl/rockchip.h>

#include "pinctrl-rockchip.h"

#define RK_GPIO0_A0	0
#define RK_GPIO0_A1	1
#define RK_GPIO0_A2	2
#define RK_GPIO0_A3	3
#define RK_GPIO0_A4	4
#define RK_GPIO0_A5	5
#define RK_GPIO0_A6	6
#define RK_GPIO0_A7	7
#define RK_GPIO0_B0	8
#define RK_GPIO0_B1	9
#define RK_GPIO0_B2	10
#define RK_GPIO0_B3	11
#define RK_GPIO0_B4	12
#define RK_GPIO0_B5	13
#define RK_GPIO0_B6	14
#define RK_GPIO0_B7	15
#define RK_GPIO0_C0	16
#define RK_GPIO0_C1	17
#define RK_GPIO0_C2	18
#define RK_GPIO0_C3	19
#define RK_GPIO0_C4	20
#define RK_GPIO0_C5	21
#define RK_GPIO0_C6	22
#define RK_GPIO0_C7	23
#define RK_GPIO0_D0	24
#define RK_GPIO0_D1	25
#define RK_GPIO0_D2	26
#define RK_GPIO0_D3	27
#define RK_GPIO0_D4	28
#define RK_GPIO0_D5	29
#define RK_GPIO0_D6	30
#define RK_GPIO0_D7	31

#define RK_GPIO1_A0	32
#define RK_GPIO1_A1	33
#define RK_GPIO1_A2	34
#define RK_GPIO1_A3	35
#define RK_GPIO1_A4	36
#define RK_GPIO1_A5	37
#define RK_GPIO1_A6	38
#define RK_GPIO1_A7	39
#define RK_GPIO1_B0	40
#define RK_GPIO1_B1	41
#define RK_GPIO1_B2	42
#define RK_GPIO1_B3	43
#define RK_GPIO1_B4	44
#define RK_GPIO1_B5	45
#define RK_GPIO1_B6	46
#define RK_GPIO1_B7	47
#define RK_GPIO1_C0	48
#define RK_GPIO1_C1	49
#define RK_GPIO1_C2	50
#define RK_GPIO1_C3	51
#define RK_GPIO1_C4	52
#define RK_GPIO1_C5	53
#define RK_GPIO1_C6	54
#define RK_GPIO1_C7	55
#define RK_GPIO1_D0	56
#define RK_GPIO1_D1	57
#define RK_GPIO1_D2	58
#define RK_GPIO1_D3	59
#define RK_GPIO1_D4	60
#define RK_GPIO1_D5	61
#define RK_GPIO1_D6	62
#define RK_GPIO1_D7	63

#define RK_GPIO2_A0	64
#define RK_GPIO2_A1	65
#define RK_GPIO2_A2	66
#define RK_GPIO2_A3	67
#define RK_GPIO2_A4	68
#define RK_GPIO2_A5	69
#define RK_GPIO2_A6	70
#define RK_GPIO2_A7	71
#define RK_GPIO2_B0	72
#define RK_GPIO2_B1	73
#define RK_GPIO2_B2	74
#define RK_GPIO2_B3	75
#define RK_GPIO2_B4	76
#define RK_GPIO2_B5	77
#define RK_GPIO2_B6	78
#define RK_GPIO2_B7	79
#define RK_GPIO2_C0	80
#define RK_GPIO2_C1	81
#define RK_GPIO2_C2	82
#define RK_GPIO2_C3	83
#define RK_GPIO2_C4	84
#define RK_GPIO2_C5	85
#define RK_GPIO2_C6	86
#define RK_GPIO2_C7	87
#define RK_GPIO2_D0	88
#define RK_GPIO2_D1	89
#define RK_GPIO2_D2	90
#define RK_GPIO2_D3	91
#define RK_GPIO2_D4	92
#define RK_GPIO2_D5	93
#define RK_GPIO2_D6	94
#define RK_GPIO2_D7	95

#define RK_GPIO3_A0	96
#define RK_GPIO3_A1	97
#define RK_GPIO3_A2	98
#define RK_GPIO3_A3	99
#define RK_GPIO3_A4	100
#define RK_GPIO3_A5	101
#define RK_GPIO3_A6	102
#define RK_GPIO3_A7	103
#define RK_GPIO3_B0	104
#define RK_GPIO3_B1	105
#define RK_GPIO3_B2	106
#define RK_GPIO3_B3	107
#define RK_GPIO3_B4	108
#define RK_GPIO3_B5	109
#define RK_GPIO3_B6	110
#define RK_GPIO3_B7	111
#define RK_GPIO3_C0	112
#define RK_GPIO3_C1	113
#define RK_GPIO3_C2	114
#define RK_GPIO3_C3	115
#define RK_GPIO3_C4	116
#define RK_GPIO3_C5	117
#define RK_GPIO3_C6	118
#define RK_GPIO3_C7	119
#define RK_GPIO3_D0	120
#define RK_GPIO3_D1	121
#define RK_GPIO3_D2	122
#define RK_GPIO3_D3	123
#define RK_GPIO3_D4	124
#define RK_GPIO3_D5	125
#define RK_GPIO3_D6	126
#define RK_GPIO3_D7	127

#define RK_GPIO4_A0	128
#define RK_GPIO4_A1	129
#define RK_GPIO4_A2	130
#define RK_GPIO4_A3	131
#define RK_GPIO4_A4	132
#define RK_GPIO4_A5	133
#define RK_GPIO4_A6	134
#define RK_GPIO4_A7	135
#define RK_GPIO4_B0	136
#define RK_GPIO4_B1	137
#define RK_GPIO4_B2	138
#define RK_GPIO4_B3	139
#define RK_GPIO4_B4	140
#define RK_GPIO4_B5	141
#define RK_GPIO4_B6	142
#define RK_GPIO4_B7	143
#define RK_GPIO4_C0	144
#define RK_GPIO4_C1	145
#define RK_GPIO4_C2	146
#define RK_GPIO4_C3	147
#define RK_GPIO4_C4	148
#define RK_GPIO4_C5	149
#define RK_GPIO4_C6	150
#define RK_GPIO4_C7	151
#define RK_GPIO4_D0	152
#define RK_GPIO4_D1	153
#define RK_GPIO4_D2	154
#define RK_GPIO4_D3	155
#define RK_GPIO4_D4	156
#define RK_GPIO4_D5	157
#define RK_GPIO4_D6	158
#define RK_GPIO4_D7	159

#define RK3588_PIN_BANK_FLAGS(ID, PIN, LABEL, M, P)			\
	PIN_BANK_IOMUX_FLAGS_PULL_FLAGS(ID, PIN, LABEL, M, M, M, M, P, P, P, P)

static int rk3588_set_mux(struct rockchip_pin_bank *bank, int pin, int mux)
{
	struct rockchip_pinctrl_priv *priv = bank->priv;
	struct regmap *regmap;
	int iomux_num = (pin / 8);
	int reg, ret, mask;
	u8 bit;
	u32 data;

	debug("setting mux of GPIO%d-%d to %d\n", bank->bank_num, pin, mux);

	regmap = priv->regmap_base;
	reg = bank->iomux[iomux_num].offset;
	if ((pin % 8) >= 4)
		reg += 0x4;
	bit = (pin % 4) * 4;
	mask = 0xf;

	if (bank->bank_num == 0) {
		if ((pin >= RK_PB4) && (pin <= RK_PD7)) {
			if (mux < 8) {
				reg += 0x4000 - 0xC; /* PMU2_IOC_BASE */
				data = (mask << (bit + 16));
				data |= (mux & mask) << bit;
				ret = regmap_write(regmap, reg, data);
			} else {
				u32 reg0 = 0;

				reg0 = reg + 0x4000 - 0xC; /* PMU2_IOC_BASE */
				data = (mask << (bit + 16));
				data |= 8 << bit;
				ret = regmap_write(regmap, reg0, data);

				reg0 = reg + 0x8000; /* BUS_IOC_BASE */
				data = (mask << (bit + 16));
				data |= mux << bit;
				regmap = priv->regmap_base;
				regmap_write(regmap, reg0, data);
			}
		} else {
			data = (mask << (bit + 16));
			data |= (mux & mask) << bit;
			ret = regmap_write(regmap, reg, data);
		}
		return ret;
	} else if (bank->bank_num > 0) {
		reg += 0x8000; /* BUS_IOC_BASE */
	}

	data = (mask << (bit + 16));
	data |= (mux & mask) << bit;

	return regmap_write(regmap, reg, data);
}

#define rk3588_DRV_PMU_OFFSET		0x70
#define rk3588_DRV_GRF_OFFSET		0x200
#define rk3588_DRV_BITS_PER_PIN		8
#define rk3588_DRV_PINS_PER_REG		2
#define rk3588_DRV_BANK_STRIDE		0x40

#define PMU1_IOC_REG		(0x0000)
#define PMU2_IOC_REG		(0x4000)
#define BUS_IOC_REG		(0x8000)
#define VCCIO1_4_IOC_REG	(0x9000)
#define VCCIO3_5_IOC_REG	(0xA000)
#define VCCIO2_IOC_REG		(0xB000)
#define VCCIO6_IOC_REG		(0xC000)
#define EMMC_IOC_REG		(0xD000)

static const u32 rk3588_ds_regs[][2] = {
	{RK_GPIO0_A0, PMU1_IOC_REG + 0x0010},
	{RK_GPIO0_A4, PMU1_IOC_REG + 0x0014},
	{RK_GPIO0_B0, PMU1_IOC_REG + 0x0018},
	{RK_GPIO0_B4, PMU2_IOC_REG + 0x0014},
/*	{RK_GPIO0_C0, PMU2_IOC_REG + 0x0018},
	{RK_GPIO0_C4, PMU2_IOC_REG + 0x001C},
	{RK_GPIO0_D0, PMU2_IOC_REG + 0x0020},
	{RK_GPIO0_D4, PMU2_IOC_REG + 0x0024},*/
	{RK_GPIO1_A0, VCCIO1_4_IOC_REG + 0x0020},
/*	{RK_GPIO1_A4, VCCIO1_4_IOC_REG + 0x0024},
	{RK_GPIO1_B0, VCCIO1_4_IOC_REG + 0x0028},
	{RK_GPIO1_B4, VCCIO1_4_IOC_REG + 0x002C},
	{RK_GPIO1_C0, VCCIO1_4_IOC_REG + 0x0030},
	{RK_GPIO1_C4, VCCIO1_4_IOC_REG + 0x0034},
	{RK_GPIO1_D0, VCCIO1_4_IOC_REG + 0x0038},
	{RK_GPIO1_D4, VCCIO1_4_IOC_REG + 0x003C},*/
	{RK_GPIO2_A0, EMMC_IOC_REG + 0x0040},
/*	{RK_GPIO2_A4, EMMC_IOC_REG + 0x0044},
	{RK_GPIO2_B0, EMMC_IOC_REG + 0x0048},
	{RK_GPIO2_B4, EMMC_IOC_REG + 0x004C},
	{RK_GPIO2_C0, EMMC_IOC_REG + 0x0050},
	{RK_GPIO2_C4, EMMC_IOC_REG + 0x0054},
	{RK_GPIO2_D0, EMMC_IOC_REG + 0x0058},
	{RK_GPIO2_D4, EMMC_IOC_REG + 0x005C},*/
	{RK_GPIO3_A0, VCCIO3_5_IOC_REG + 0x0060},
/*	{RK_GPIO3_A4, VCCIO3_5_IOC_REG + 0x0064},
	{RK_GPIO3_B0, VCCIO3_5_IOC_REG + 0x0068},
	{RK_GPIO3_B4, VCCIO3_5_IOC_REG + 0x006C},
	{RK_GPIO3_C0, VCCIO3_5_IOC_REG + 0x0070},
	{RK_GPIO3_C4, VCCIO3_5_IOC_REG + 0x0074},
	{RK_GPIO3_D0, VCCIO3_5_IOC_REG + 0x0078},
	{RK_GPIO3_D4, VCCIO3_5_IOC_REG + 0x007C},*/
	{RK_GPIO4_A0, VCCIO6_IOC_REG + 0x0080},
/*	{RK_GPIO4_A4, VCCIO6_IOC_REG + 0x0084},
	{RK_GPIO4_B0, VCCIO6_IOC_REG + 0x0088},
	{RK_GPIO4_B4, VCCIO6_IOC_REG + 0x008C},
	{RK_GPIO4_C0, VCCIO6_IOC_REG + 0x0090},*/
};

static const u32 rk3588_p_regs[][2] = {
	{RK_GPIO0_A0, PMU1_IOC_REG + 0x0020},
	{RK_GPIO0_B0, PMU1_IOC_REG + 0x0024},
	{RK_GPIO0_B5, PMU2_IOC_REG + 0x0028},
	{RK_GPIO0_C0, PMU2_IOC_REG + 0x002C},
	{RK_GPIO0_D0, PMU2_IOC_REG + 0x0030},
	{RK_GPIO1_A0, VCCIO1_4_IOC_REG + 0x0110},
/*	{RK_GPIO1_B0, VCCIO1_4_IOC_REG + 0x0114},
	{RK_GPIO1_C0, VCCIO1_4_IOC_REG + 0x0118},
	{RK_GPIO1_D0, VCCIO1_4_IOC_REG + 0x011C},*/
	{RK_GPIO2_A0, EMMC_IOC_REG + 0x0120},
/*	{RK_GPIO2_D0, EMMC_IOC_REG + 0x012C},*/
	{RK_GPIO3_A0, VCCIO3_5_IOC_REG + 0x0130},
/*	{RK_GPIO3_B0, VCCIO3_5_IOC_REG + 0x0134},
	{RK_GPIO3_C0, VCCIO3_5_IOC_REG + 0x0138},
	{RK_GPIO3_D0, VCCIO3_5_IOC_REG + 0x013C},*/
	{RK_GPIO4_A0, VCCIO6_IOC_REG + 0x0140},
/*	{RK_GPIO4_B0, VCCIO6_IOC_REG + 0x0144},
	{RK_GPIO4_C0, VCCIO6_IOC_REG + 0x0148},
	{RK_GPIO4_D0, VCCIO2_IOC_REG + 0x014C},*/
};

static const u32 rk3588_smt_regs[][2] = {
	{RK_GPIO0_A0, PMU1_IOC_REG + 0x0030},
	{RK_GPIO0_B0, PMU1_IOC_REG + 0x0034},
	{RK_GPIO0_B5, PMU2_IOC_REG + 0x0040},
	{RK_GPIO0_C0, PMU2_IOC_REG + 0x0044},
	{RK_GPIO0_D0, PMU2_IOC_REG + 0x0048},
	{RK_GPIO1_A0, VCCIO1_4_IOC_REG + 0x0210},
/*	{RK_GPIO1_B0, VCCIO1_4_IOC_REG + 0x0214},
	{RK_GPIO1_C0, VCCIO1_4_IOC_REG + 0x0218},
	{RK_GPIO1_D0, VCCIO1_4_IOC_REG + 0x021C},*/
	{RK_GPIO2_A0, EMMC_IOC_REG + 0x0220},
	{RK_GPIO2_D0, EMMC_IOC_REG + 0x022C},
	{RK_GPIO3_A0, VCCIO3_5_IOC_REG + 0x0230},
/*	{RK_GPIO3_B0, VCCIO3_5_IOC_REG + 0x0234},
	{RK_GPIO3_C0, VCCIO3_5_IOC_REG + 0x0238},
	{RK_GPIO3_D0, VCCIO3_5_IOC_REG + 0x023C},*/
	{RK_GPIO4_A0, VCCIO6_IOC_REG + 0x0240},
/*	{RK_GPIO4_B0, VCCIO6_IOC_REG + 0x0244},
	{RK_GPIO4_C0, VCCIO6_IOC_REG + 0x0248},
	{RK_GPIO4_D0, VCCIO2_IOC_REG + 0x024C},*/
};

#define RK3588_PULL_BITS_PER_PIN		2
#define RK3588_PULL_PINS_PER_REG		8

static void rk3588_calc_pull_reg_and_bit(struct rockchip_pin_bank *bank,
					 int pin_num, struct regmap **regmap,
					 int *reg, u8 *bit)
{
	struct rockchip_pinctrl_priv *info = bank->priv;
	u8 bank_num = bank->bank_num;
	u32 pin = bank_num * 32 + pin_num;
	int i;

	for (i = ARRAY_SIZE(rk3588_p_regs) - 1; i >= 0; i--) {
		if (pin >= rk3588_p_regs[i][0]) {
			*reg = rk3588_p_regs[i][1];
			break;
		}
	}

	*regmap = info->regmap_base;
	*reg += ((pin - rk3588_p_regs[i][0]) / RK3588_PULL_PINS_PER_REG) * 4;
	*bit = pin_num % RK3588_PULL_PINS_PER_REG;
	*bit *= RK3588_PULL_BITS_PER_PIN;
}

#define RK3588_DRV_BITS_PER_PIN		4
#define RK3588_DRV_PINS_PER_REG		4

static void rk3588_calc_drv_reg_and_bit(struct rockchip_pin_bank *bank,
					int pin_num, struct regmap **regmap,
					int *reg, u8 *bit)
{
	struct rockchip_pinctrl_priv *info = bank->priv;
	u8 bank_num = bank->bank_num;
	u32 pin = bank_num * 32 + pin_num;
	int i;

	for (i = ARRAY_SIZE(rk3588_ds_regs) - 1; i >= 0; i--) {
		if (pin >= rk3588_ds_regs[i][0]) {
			*reg = rk3588_ds_regs[i][1];
			break;
		}
	}

	*regmap = info->regmap_base;
	*reg += ((pin - rk3588_ds_regs[i][0]) / RK3588_DRV_PINS_PER_REG) * 4;
	*bit = pin_num % RK3588_DRV_PINS_PER_REG;
	*bit *= RK3588_DRV_BITS_PER_PIN;
}

#define RK3588_SMT_BITS_PER_PIN		1
#define RK3588_SMT_PINS_PER_REG		8

static int rk3588_calc_schmitt_reg_and_bit(struct rockchip_pin_bank *bank,
					   int pin_num, struct regmap **regmap,
					   int *reg, u8 *bit)
{
	struct rockchip_pinctrl_priv *info = bank->priv;
	u8 bank_num = bank->bank_num;
	u32 pin = bank_num * 32 + pin_num;
	int i;

	for (i = ARRAY_SIZE(rk3588_smt_regs) - 1; i >= 0; i--) {
		if (pin >= rk3588_smt_regs[i][0]) {
			*reg = rk3588_smt_regs[i][1];
			break;
		}
	}

	*regmap = info->regmap_base;
	*reg += ((pin - rk3588_smt_regs[i][0]) / RK3588_SMT_PINS_PER_REG) * 4;
	*bit = pin_num % RK3588_SMT_PINS_PER_REG;
	*bit *= RK3588_SMT_BITS_PER_PIN;

	return 0;
}

static int rk3588_set_pull(struct rockchip_pin_bank *bank,
			   int pin_num, int pull)
{
	struct regmap *regmap;
	int reg;
	u32 data;
	u8 bit;

	rk3588_calc_pull_reg_and_bit(bank, pin_num, &regmap, &reg, &bit);

	/* enable the write to the equivalent lower bits */
	data = ((1 << ROCKCHIP_PULL_BITS_PER_PIN) - 1) << (bit + 16);
	data |= (pull << bit);

	return regmap_write(regmap, reg, data);
}

static int rk3588_set_drive(struct rockchip_pin_bank *bank,
			    int pin_num, int strength)
{
	struct regmap *regmap;
	int reg;
	u32 data;
	u8 bit;

	rk3588_calc_drv_reg_and_bit(bank, pin_num, &regmap, &reg, &bit);

	/* enable the write to the equivalent lower bits */
	data = ((1 << rk3588_DRV_BITS_PER_PIN) - 1) << (bit + 16);
	data |= (strength << bit);

	return regmap_write(regmap, reg, data);
}

static int rk3588_set_schmitt(struct rockchip_pin_bank *bank,
			      int pin_num, int enable)
{
	struct regmap *regmap;
	int reg;
	u32 data;
	u8 bit;

	rk3588_calc_schmitt_reg_and_bit(bank, pin_num, &regmap, &reg, &bit);

	/* enable the write to the equivalent lower bits */
	data = ((1 << RK3588_SMT_BITS_PER_PIN) - 1) << (bit + 16);
	data |= (enable << bit);

	return regmap_write(regmap, reg, data);
}

static struct rockchip_pin_bank rk3588_pin_banks[] = {
	RK3588_PIN_BANK_FLAGS(0, 32, "gpio0",
			      IOMUX_WIDTH_4BIT, PULL_TYPE_IO_1V8_ONLY),
	RK3588_PIN_BANK_FLAGS(1, 32, "gpio1",
			      IOMUX_WIDTH_4BIT, PULL_TYPE_IO_1V8_ONLY),
	RK3588_PIN_BANK_FLAGS(2, 32, "gpio2",
			      IOMUX_WIDTH_4BIT, PULL_TYPE_IO_1V8_ONLY),
	RK3588_PIN_BANK_FLAGS(3, 32, "gpio3",
			      IOMUX_WIDTH_4BIT, PULL_TYPE_IO_1V8_ONLY),
	RK3588_PIN_BANK_FLAGS(4, 32, "gpio4",
			      IOMUX_WIDTH_4BIT, PULL_TYPE_IO_1V8_ONLY),
};

static const struct rockchip_pin_ctrl rk3588_pin_ctrl = {
	.pin_banks		= rk3588_pin_banks,
	.nr_banks		= ARRAY_SIZE(rk3588_pin_banks),
	.nr_pins		= 160,
	.set_mux		= rk3588_set_mux,
	.set_pull		= rk3588_set_pull,
	.set_drive		= rk3588_set_drive,
	.set_schmitt		= rk3588_set_schmitt,
};

static const struct udevice_id rk3588_pinctrl_ids[] = {
	{
		.compatible = "rockchip,rk3588-pinctrl",
		.data = (ulong)&rk3588_pin_ctrl
	},
	{ }
};

U_BOOT_DRIVER(pinctrl_rk3588) = {
	.name		= "rockchip_rk3588_pinctrl",
	.id		= UCLASS_PINCTRL,
	.of_match	= rk3588_pinctrl_ids,
	.priv_auto = sizeof(struct rockchip_pinctrl_priv),
	.ops		= &rockchip_pinctrl_ops,
#if !CONFIG_IS_ENABLED(OF_REAL)
	.bind		= dm_scan_fdt_dev,
#endif
	.probe		= rockchip_pinctrl_probe,
};
