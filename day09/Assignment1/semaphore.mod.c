#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8616a905, "device_destroy" },
	{ 0xd21a69c6, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcf2a6966, "up" },
	{ 0x8b505010, "pcpu_hot" },
	{ 0x6626afca, "down" },
	{ 0x30a80826, "__kfifo_from_user" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0x6a8d7be2, "kmalloc_caches" },
	{ 0xea8042e2, "kmalloc_trace" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xdcc94c38, "__class_create" },
	{ 0xc1435ca2, "device_create" },
	{ 0x72b35bcd, "cdev_init" },
	{ 0x94a7f8d7, "cdev_add" },
	{ 0x122c3a7e, "_printk" },
	{ 0x4c1155d8, "cdev_del" },
	{ 0xb3debb2c, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A5A5B707255BB5301F3C357");
