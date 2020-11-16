#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xae20673a, "module_layout" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb61e8967, "netdev_info" },
	{ 0x8df02a1d, "kmalloc_caches" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x7c31c473, "ethtool_op_get_ts_info" },
	{ 0xf9a482f9, "msleep" },
	{ 0x1ed8b599, "__x86_indirect_thunk_r8" },
	{ 0xe5d8aa8e, "skb_clone_tx_timestamp" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xdaf485b9, "pv_lock_ops" },
	{ 0xf4ec5b2, "napi_disable" },
	{ 0xb5c43cc5, "pci_read_config_byte" },
	{ 0xa7005f1, "napi_consume_skb" },
	{ 0xa6215b4c, "napi_schedule_prep" },
	{ 0xa4f06814, "__napi_schedule_irqoff" },
	{ 0x19f462ab, "kfree_call_rcu" },
	{ 0x7ae5ad74, "sme_active" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x1eb52985, "xdp_rxq_info_reg" },
	{ 0xb96142ca, "pci_disable_device" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x8d885868, "pci_disable_msix" },
	{ 0x4ea25709, "dql_reset" },
	{ 0xfa40e2fb, "netif_carrier_on" },
	{ 0xb3635b01, "_raw_spin_lock_bh" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0x6ff05169, "netif_carrier_off" },
	{ 0x88bfa7e, "cancel_work_sync" },
	{ 0x9558af0d, "xdp_rxq_info_unreg" },
	{ 0xf736cef2, "__dev_kfree_skb_any" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xd54e5ac8, "pci_release_regions" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x999e8297, "vfree" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xdd64e639, "strscpy" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xe71f3206, "ipv6_find_hdr" },
	{ 0x737d6b39, "__page_frag_cache_drain" },
	{ 0x532206d5, "__alloc_pages_nodemask" },
	{ 0x14dc7b1, "netif_napi_del" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x8dd00f1, "netif_rx" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5acf0a80, "pci_set_master" },
	{ 0x2a807f22, "netif_schedule_queue" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x7e526bfa, "__x86_indirect_thunk_r10" },
	{ 0xfb578fc5, "memset" },
	{ 0xf0815b5, "pci_enable_pcie_error_reporting" },
	{ 0xa068056b, "netif_tx_wake_queue" },
	{ 0xb5eff41f, "pci_restore_state" },
	{ 0x602e69e5, "netif_tx_stop_all_queues" },
	{ 0xa7e3c5bf, "dev_err" },
	{ 0x27e1a049, "printk" },
	{ 0xcd2d452f, "ethtool_op_get_link" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x31cd8869, "__cpu_online_mask" },
	{ 0xa00aca2a, "dql_completed" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x724036d8, "free_netdev" },
	{ 0xe7b00dfb, "__x86_indirect_thunk_r13" },
	{ 0xa46003f1, "register_netdev" },
	{ 0x5792f848, "strlcpy" },
	{ 0xf698f44b, "netdev_printk" },
	{ 0x594e62a2, "__dev_kfree_skb_irq" },
	{ 0x5012099c, "netif_set_real_num_rx_queues" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x81e747ef, "netif_set_real_num_tx_queues" },
	{ 0x794fbee8, "netif_napi_add" },
	{ 0x2072ee9b, "request_threaded_irq" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xfaccbd4, "build_skb" },
	{ 0x4caf8380, "arch_dma_alloc_attrs" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xe0a4e6ce, "eth_get_headlen" },
	{ 0x4473ee24, "netif_device_attach" },
	{ 0x60d7bd3d, "napi_gro_receive" },
	{ 0x23048ab6, "_dev_info" },
	{ 0x8ff4079b, "pv_irq_ops" },
	{ 0x380df13, "__free_pages" },
	{ 0x618911fc, "numa_node" },
	{ 0xec26e8cc, "netif_device_detach" },
	{ 0x93a219c, "ioremap_nocache" },
	{ 0x1eceec0f, "pci_enable_msix_range" },
	{ 0x12a38747, "usleep_range" },
	{ 0x49c41a57, "_raw_spin_unlock_bh" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xb8493f47, "skb_checksum_help" },
	{ 0x88e1d0f0, "page_frag_free" },
	{ 0x547ae09e, "napi_complete_done" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xbfdcb43a, "__x86_indirect_thunk_r11" },
	{ 0xfe9c108e, "pci_read_config_dword" },
	{ 0xcce95b4b, "eth_type_trans" },
	{ 0xe55ab73c, "pskb_expand_head" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x93df2876, "netdev_err" },
	{ 0x467df16d, "netdev_rss_key_fill" },
	{ 0x2b511217, "pci_unregister_driver" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x7cc14a5a, "kmem_cache_alloc_trace" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0x7577c696, "netdev_warn" },
	{ 0x869d7a26, "eth_validate_addr" },
	{ 0x4bf3e9e, "pci_disable_pcie_error_reporting" },
	{ 0x3baeb9e9, "tcf_block_cb_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0x43b78f82, "pci_request_regions" },
	{ 0x4d8ed454, "skb_add_rx_frag" },
	{ 0xedc03953, "iounmap" },
	{ 0xbb9c6564, "__pci_register_driver" },
	{ 0xb352177e, "find_first_bit" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x8af91482, "dev_warn" },
	{ 0xd765413a, "unregister_netdev" },
	{ 0x5c2bcd37, "bpf_warn_invalid_xdp_action" },
	{ 0x2e0d2f7f, "queue_work_on" },
	{ 0x28318305, "snprintf" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xf5b89ed8, "consume_skb" },
	{ 0xe08db3b3, "pci_enable_device_mem" },
	{ 0xb1a0dbf9, "__napi_alloc_skb" },
	{ 0xcc79388c, "skb_tstamp_tx" },
	{ 0x70f3b894, "pci_enable_device" },
	{ 0x4ec4856e, "skb_copy_bits" },
	{ 0xb2093846, "bpf_prog_put" },
	{ 0x80bafff, "pci_find_ext_capability" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x1cee61bc, "dma_ops" },
	{ 0x21faa2a, "tcf_block_cb_register" },
	{ 0xe9146eca, "__skb_pad" },
	{ 0x9c3fb41d, "dev_get_stats" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x29f3cf15, "pci_save_state" },
	{ 0x4c318f71, "alloc_etherdev_mqs" },
	{ 0xdc34a927, "__tracepoint_xdp_exception" },
	{ 0x8a35b432, "sme_me_mask" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00008086d000010EDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000152Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001515sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001530sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001565sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001564sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015B4sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "6EC1F9BB0153B29A565C153");
