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
	{ 0xdc39d17d, "alloc_pages_current" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb61e8967, "netdev_info" },
	{ 0x8df02a1d, "kmalloc_caches" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x7c31c473, "ethtool_op_get_ts_info" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xf9a482f9, "msleep" },
	{ 0x862258db, "timecounter_init" },
	{ 0x33c5f919, "dcb_ieee_setapp" },
	{ 0x1ed8b599, "__x86_indirect_thunk_r8" },
	{ 0xe5d8aa8e, "skb_clone_tx_timestamp" },
	{ 0xbdff473a, "pci_enable_sriov" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xaf1ffdc0, "pci_write_config_word" },
	{ 0x9488c451, "debugfs_create_dir" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xdaf485b9, "pv_lock_ops" },
	{ 0x826c210b, "param_ops_int" },
	{ 0xabff15d7, "dcb_ieee_delapp" },
	{ 0xf4ec5b2, "napi_disable" },
	{ 0x754d539c, "strlen" },
	{ 0x90375220, "pci_sriov_set_totalvfs" },
	{ 0xb5c43cc5, "pci_read_config_byte" },
	{ 0xa7005f1, "napi_consume_skb" },
	{ 0xa6215b4c, "napi_schedule_prep" },
	{ 0xa4f06814, "__napi_schedule_irqoff" },
	{ 0x43a53735, "__alloc_workqueue_key" },
	{ 0x8f996a30, "ethtool_convert_legacy_u32_to_link_mode" },
	{ 0x19f462ab, "kfree_call_rcu" },
	{ 0x7ae5ad74, "sme_active" },
	{ 0x1eb52985, "xdp_rxq_info_reg" },
	{ 0xb96142ca, "pci_disable_device" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x8d885868, "pci_disable_msix" },
	{ 0x4ea25709, "dql_reset" },
	{ 0x99913a13, "netdev_set_num_tc" },
	{ 0xfa40e2fb, "netif_carrier_on" },
	{ 0xb3635b01, "_raw_spin_lock_bh" },
	{ 0x8305ba9a, "pci_disable_sriov" },
	{ 0x4371e863, "__hw_addr_sync_dev" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xdf566a59, "__x86_indirect_thunk_r9" },
	{ 0xa1f9a134, "__x86_indirect_thunk_rsi" },
	{ 0x6ff05169, "netif_carrier_off" },
	{ 0xad27f361, "__warn_printk" },
	{ 0x88bfa7e, "cancel_work_sync" },
	{ 0xaaa6344e, "pci_dev_get" },
	{ 0xc29957c3, "__x86_indirect_thunk_rcx" },
	{ 0x87b8798d, "sg_next" },
	{ 0x9558af0d, "xdp_rxq_info_unreg" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x9e582f80, "pcie_print_link_status" },
	{ 0xf7908571, "call_netdevice_notifiers" },
	{ 0xb960a5c9, "driver_for_each_device" },
	{ 0xf736cef2, "__dev_kfree_skb_any" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x999e8297, "vfree" },
	{ 0x243eabcb, "netdev_reset_tc" },
	{ 0xa66179c8, "debugfs_create_file" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xb348a850, "ex_handler_refcount" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x559b27f8, "xdp_do_flush_map" },
	{ 0xe71f3206, "ipv6_find_hdr" },
	{ 0x91715312, "sprintf" },
	{ 0x8c5fd08d, "debugfs_remove_recursive" },
	{ 0x737d6b39, "__page_frag_cache_drain" },
	{ 0xf2e5f85, "pci_dev_driver" },
	{ 0x14dc7b1, "netif_napi_del" },
	{ 0xa776c015, "xdp_return_frame_rx_napi" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6e40a704, "__dynamic_netdev_dbg" },
	{ 0xa792fd7f, "cpumask_next" },
	{ 0x44b5ee9a, "kasprintf" },
	{ 0xd470d2a0, "__pskb_pull_tail" },
	{ 0xe4d85ae5, "ptp_clock_unregister" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0xb54a40a2, "netdev_set_tc_queue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5acf0a80, "pci_set_master" },
	{ 0x61dde9e0, "dca3_get_tag" },
	{ 0x2a807f22, "netif_schedule_queue" },
	{ 0x1612f476, "ptp_clock_event" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x7e526bfa, "__x86_indirect_thunk_r10" },
	{ 0xfb578fc5, "memset" },
	{ 0xdd01c6af, "devm_hwmon_device_register_with_groups" },
	{ 0x81079340, "dcb_getapp" },
	{ 0x1a1a2ce7, "dcb_setapp" },
	{ 0xf0815b5, "pci_enable_pcie_error_reporting" },
	{ 0xac34ecec, "dca_register_notify" },
	{ 0x2a70864d, "__cpu_possible_mask" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xa068056b, "netif_tx_wake_queue" },
	{ 0xb5eff41f, "pci_restore_state" },
	{ 0x602e69e5, "netif_tx_stop_all_queues" },
	{ 0x1a33ab9, "dca_unregister_notify" },
	{ 0xa7e3c5bf, "dev_err" },
	{ 0x3812050a, "_raw_spin_unlock_irqrestore" },
	{ 0xe334ae6f, "dev_addr_del" },
	{ 0xc62989ce, "netif_set_xps_queue" },
	{ 0x27e1a049, "printk" },
	{ 0xcd2d452f, "ethtool_op_get_link" },
	{ 0x20c55ae0, "sscanf" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x31cd8869, "__cpu_online_mask" },
	{ 0xa00aca2a, "dql_completed" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcd279169, "nla_find" },
	{ 0x724036d8, "free_netdev" },
	{ 0xe7b00dfb, "__x86_indirect_thunk_r13" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x9166fada, "strncpy" },
	{ 0xa46003f1, "register_netdev" },
	{ 0x8e0ef3ce, "pci_read_config_word" },
	{ 0x5792f848, "strlcpy" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xa3e44e2b, "dev_close" },
	{ 0x5012099c, "netif_set_real_num_rx_queues" },
	{ 0xc2cdbf1, "synchronize_sched" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x81e747ef, "netif_set_real_num_tx_queues" },
	{ 0x794fbee8, "netif_napi_add" },
	{ 0xce8b1878, "__x86_indirect_thunk_r14" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x98c7e0c5, "dcb_ieee_getapp_mask" },
	{ 0x9b439638, "ptp_clock_register" },
	{ 0x2072ee9b, "request_threaded_irq" },
	{ 0xada4b853, "xdp_return_frame" },
	{ 0x6e226718, "dca_add_requester" },
	{ 0x23818463, "simple_open" },
	{ 0xd3abd8ae, "pci_enable_msi" },
	{ 0x53ac875f, "dev_open" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0x6f9e763b, "timecounter_read" },
	{ 0xfaccbd4, "build_skb" },
	{ 0x6c854815, "pci_find_capability" },
	{ 0x4caf8380, "arch_dma_alloc_attrs" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xe0a4e6ce, "eth_get_headlen" },
	{ 0xb2743f75, "pci_select_bars" },
	{ 0x55e31703, "ethtool_convert_link_mode_to_legacy_u32" },
	{ 0xb8212341, "timecounter_cyc2time" },
	{ 0x4473ee24, "netif_device_attach" },
	{ 0x60d7bd3d, "napi_gro_receive" },
	{ 0x9fd4c787, "__hw_addr_unsync_dev" },
	{ 0x23048ab6, "_dev_info" },
	{ 0x8ff4079b, "pv_irq_ops" },
	{ 0x8199123b, "dev_addr_add" },
	{ 0x380df13, "__free_pages" },
	{ 0x6de11d09, "pci_disable_link_state" },
	{ 0xb601be4c, "__x86_indirect_thunk_rdx" },
	{ 0x618911fc, "numa_node" },
	{ 0xec26e8cc, "netif_device_detach" },
	{ 0x76da2507, "__alloc_skb" },
	{ 0x93a219c, "ioremap_nocache" },
	{ 0x12a38747, "usleep_range" },
	{ 0x1eceec0f, "pci_enable_msix_range" },
	{ 0x49c41a57, "_raw_spin_unlock_bh" },
	{ 0xc12755c6, "pci_cleanup_aer_uncorrect_error_status" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xb8493f47, "skb_checksum_help" },
	{ 0xaabf46f6, "kfree_skb" },
	{ 0x3e0942cf, "ndo_dflt_fdb_add" },
	{ 0x547ae09e, "napi_complete_done" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xbfdcb43a, "__x86_indirect_thunk_r11" },
	{ 0xfe9c108e, "pci_read_config_dword" },
	{ 0xcce95b4b, "eth_type_trans" },
	{ 0x40d2800a, "xdp_rxq_info_reg_mem_model" },
	{ 0xcd8dd495, "dma_pool_alloc" },
	{ 0xe55ab73c, "pskb_expand_head" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x93df2876, "netdev_err" },
	{ 0x9379688a, "netdev_features_change" },
	{ 0x467df16d, "netdev_rss_key_fill" },
	{ 0x2b511217, "pci_unregister_driver" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x7cc14a5a, "kmem_cache_alloc_trace" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x51760917, "_raw_spin_lock_irqsave" },
	{ 0x3748ff7, "pci_set_power_state" },
	{ 0x7577c696, "netdev_warn" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0x869d7a26, "eth_validate_addr" },
	{ 0x4bf3e9e, "pci_disable_pcie_error_reporting" },
	{ 0x9d77a9c4, "xdp_do_redirect" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe018efba, "___pskb_trim" },
	{ 0xa1c2f8dc, "param_array_ops" },
	{ 0x917d3c3a, "ptp_clock_index" },
	{ 0x68ea8cdc, "pci_disable_msi" },
	{ 0x4d8ed454, "skb_add_rx_frag" },
	{ 0x51474697, "pci_num_vf" },
	{ 0xedc03953, "iounmap" },
	{ 0xe784e0c4, "pci_prepare_to_sleep" },
	{ 0xbb9c6564, "__pci_register_driver" },
	{ 0x15af7f4, "system_state" },
	{ 0x9c142c7a, "pci_get_device" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x8af91482, "dev_warn" },
	{ 0xd765413a, "unregister_netdev" },
	{ 0x8534d8e0, "ndo_dflt_bridge_getlink" },
	{ 0x5c2bcd37, "bpf_warn_invalid_xdp_action" },
	{ 0x55f5019b, "__kmalloc_node" },
	{ 0xf8ae273d, "pci_dev_put" },
	{ 0x2e0d2f7f, "queue_work_on" },
	{ 0x78e65eeb, "pci_vfs_assigned" },
	{ 0x28318305, "snprintf" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xf5b89ed8, "consume_skb" },
	{ 0x42e2c030, "dca_remove_requester" },
	{ 0xe08db3b3, "pci_enable_device_mem" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xb1a0dbf9, "__napi_alloc_skb" },
	{ 0xcc79388c, "skb_tstamp_tx" },
	{ 0xdb2e0f47, "skb_put" },
	{ 0xa0a5c1df, "pci_wake_from_d3" },
	{ 0x4de4d25a, "devm_kmalloc" },
	{ 0xffe0790e, "pci_release_selected_regions" },
	{ 0xc1a655b2, "pci_request_selected_regions" },
	{ 0x263074f8, "irq_set_affinity_hint" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x250beb9b, "dma_pool_create" },
	{ 0x4ec4856e, "skb_copy_bits" },
	{ 0xb2093846, "bpf_prog_put" },
	{ 0x80bafff, "pci_find_ext_capability" },
	{ 0x23fd3028, "vmalloc_node" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x1cee61bc, "dma_ops" },
	{ 0xe9146eca, "__skb_pad" },
	{ 0xd4ab3f10, "pcie_capability_read_word" },
	{ 0x853619a5, "device_set_wakeup_enable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x29f3cf15, "pci_save_state" },
	{ 0x4c318f71, "alloc_etherdev_mqs" },
	{ 0xdc34a927, "__tracepoint_xdp_exception" },
	{ 0xa93f0d81, "netdev_crit" },
	{ 0x8a35b432, "sme_me_mask" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dca";

MODULE_ALIAS("pci:v00008086d000010B6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000150Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010ECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001508sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010FCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001517sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010FBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001507sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001514sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000152Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001529sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000151Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001528sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000154Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001557sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000154Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001558sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001560sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001563sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ADsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015AEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015CCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015CEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015E4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015E5sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "9CCE1867D1D933E3FDFB5DD");
