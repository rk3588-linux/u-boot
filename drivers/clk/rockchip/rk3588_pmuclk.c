#include <common.h>
#include <bitfield.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <syscon.h>
#include <asm/arch-rockchip/cru_rk3588.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/hardware.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <dt-bindings/clock/rk3588-cru.h>

DECLARE_GLOBAL_DATA_PTR;

static ulong rk3588_pmuclk_get_rate(struct clk *clk)
{

}

static ulong rk3588_pmuclk_set_rate(struct clk *clk, ulong rate)
{

}

static int rk3588_pmuclk_set_parent(struct clk *clk, struct clk *parent)
{
    return 0;
}

static struct clk_ops rk3588_pmuclk_ops = {
	.get_rate = rk3588_pmuclk_get_rate,
	.set_rate = rk3588_pmuclk_set_rate,
	.set_parent = rk3588_pmuclk_set_parent,
};

static int rk3588_pmuclk_probe(struct udevice *dev)
{

    return 0;
}

static int rk3588_pmuclk_ofdata_to_platdata(struct udevice *dev)
{
    struct rk3588_pmuclk_priv *priv = dev_get_priv(dev);
    priv->pmucru = dev_read_addr_ptr(dev);

	return 0;
}

static int rk3588_pmuclk_bind(struct udevice *dev)
{
    return 0;
}

static const struct udevice_id rk3588_pmuclk_ids[] = {
	{ .compatible = "rockchip,rk3588-pmucru" },
	{ }
};

U_BOOT_DRIVER(rockchip_rk3588_pmucru) = {
	.name		= "rockchip_rk3588_pmucru",
	.id		= UCLASS_CLK,
	.of_match	= rk3588_pmuclk_ids,
	.priv_auto = sizeof(struct rk3588_pmuclk_priv),
	.of_to_plat = rk3588_pmuclk_ofdata_to_platdata,
	.ops		= &rk3588_pmuclk_ops,
	.bind		= rk3588_pmuclk_bind,
	.probe		= rk3588_pmuclk_probe,
};
