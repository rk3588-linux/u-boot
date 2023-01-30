#include <common.h>
#include <dm.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch-rockchip/ioc_rk3588.h>
#include <asm/arch-rockchip/hardware.h>

DECLARE_GLOBAL_DATA_PTR;

#define PMU2_IOC_BASE			0xfd5f4000
#define BUS_IOC_BASE            0xfd5f8000
#define GPIO0B_UART2_TXM0 (0xa << 8)
#define GPIO0B_UART2_RXM0 (0xa << 4)

enum {
	GPIO0B5_SHIFT		= 4,
	GPIO0B5_MASK		= GENMASK(7, 4),
	GPIO0B5_REFER		= 8,
	GPIO0B5_UART2_TX_M0	= 10,

	GPIO0B6_SHIFT		= 8,
	GPIO0B6_MASK		= GENMASK(11, 8),
	GPIO0B6_REFER		= 8,
	GPIO0B6_UART2_RX_M0	= 10,
};

static struct mm_region rk3588_mem_map[] = {
	{
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = 0xf0000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		.virt = 0xf0000000UL,
		.phys = 0xf0000000UL,
		.size = 0x10000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},  {
		.virt = 0x900000000,
		.phys = 0x900000000,
		.size = 0x150000000,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},  {
		/* List terminator */
		0,
	}
};

struct mm_region *mem_map = rk3588_mem_map;

void board_debug_uart_init(void)
{
	static struct rk3588_pmu2_ioc * const pmu2_ioc = (void *)PMU2_IOC_BASE;
    static struct rk3588_bus_ioc * const bus_ioc = (void *)BUS_IOC_BASE;

	/* Set UART2 GPIO */
    /* pmu2_ioc->gpio0b_iomux_sel_h |= (8 << 4) | (8 << 8); */
    /* bus_ioc->gpio0b_iomux_sel_h |= GPIO0B_UART2_TXM0 | GPIO0B_UART2_RXM0; */

    /* Refer to BUS_IOC */
	rk_clrsetreg(&pmu2_ioc->gpio0b_iomux_sel_h,
			GPIO0B6_MASK | GPIO0B5_MASK,
			GPIO0B6_REFER << GPIO0B6_SHIFT |
			GPIO0B5_REFER << GPIO0B5_SHIFT);

	/* UART2_M0 Switch iomux */
	rk_clrsetreg(&bus_ioc->gpio0b_iomux_sel_h,
			GPIO0B6_MASK | GPIO0B5_MASK,
			GPIO0B6_UART2_RX_M0 << GPIO0B6_SHIFT |
			GPIO0B5_UART2_TX_M0 << GPIO0B5_SHIFT);
}

int arch_cpu_init(void)
{
	return 0;
}
