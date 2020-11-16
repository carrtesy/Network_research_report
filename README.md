# Network research report

## Details

2020 Fall, Undergraduate Research Project @SKKU

## SRIOV setup
How to setup?
1. Configure the number of VMs. 
```https://blog.hkwon.me/ubuntu-18-04-netplan/
$ echo 4 > /sys/class/net/<device name>/device/sriov_numvfs
```
2. check businfo with
```
$ lshw -c network -businfo
```

3. create ip for machine, if needed by: https://www.cyberciti.biz/faq/linux-kvm-libvirt-dnsmasq-dhcp-static-ip-address-configuration-for-guest-os/

4. (virt-manager) using GUI, add Hardware in PCI with name *Virtual Functions*

5. add counterparts to the vm's routing table ( counterpart's ip: 10.0.0.4, for example)

```
route add -net 10.0.0.0 netmask 255.255.255.0 dev ens9
```

6. add vm to the counterparts' routing table ( vm's ip: 20.0.0.3 , for example)
```
route add -net 20.0.0.0 netmask 255.255.255.0 dev ens6f1
```

## Intel ixgbe driver
https://sourceforge.net/projects/e1000/files/ixgbevf%20stable/4.9.3/

## Driver On and Off
Dive into Kernel

- check current driver

- Make Kernel File
```
	make -J 10
```

- Disable current(original) driver
```
	sudo rmmod ixgbe
```

- Enable new driver
```
	sudo inmod ./ixgbe.ko
```

- Return to current driver
```
	sudo modeprobe ixgbe
```

## Check system logs
1.
```
    dmesg
```
2. 
```
    sudo vi /var/log/syslog 
```


## Logs

### 2020-11-13
Thoughts on Further Tasks

1. If SR_IOV is set, and numvfs == 2, 2 interfaces noticable.
![1113-ifconfig](./imgs/1113_ifconfig.png)

2. Ip setting possible, by netplan

3. **However**, packet is sent to ixgbe interface, not ixgbevf interface


So, 
1. Follow up the process of the vf interface is set to vm interface

2. can be done by: 
- fix ixgbe driver at host,
- perform add hw, or something to set vf interface and vfdriver up
- and follow the kernel ixgbe logs 

Good Luck!

### 2020-11-12
Objectives:
1. How PF distinguish VM0, VM1, ... so on
2. How VF sends message to PF, saying "it's me"
3. what kind of roles the KVM takes?

Answers:
1. 

Code 1: at ixgbe_sriov.c, function __ixgbe_enable_sriov
```
/* Allocate memory for per VF control structures */
adapter->vfinfo = kcalloc(num_vfs, sizeof(struct vf_data_storage),
				  GFP_KERNEL);
```

Code 2: struct ixgbe_adapter at ixgbe.h

```
struct ixgbe_adapter {
...
	unsigned int num_vfs;
	unsigned int max_vfs;
	struct vf_data_storage *vfinfo;
	int vf_rate_link_speed;
	struct vf_macvlans vf_mvs;
	struct vf_macvlans *mv_list;
...
}
```

Code 3: struct vf_data_storage, struct vf_macvlans at ixgbe.h 

```
struct vf_data_storage {
	struct pci_dev *vfdev;
	unsigned char vf_mac_addresses[ETH_ALEN];
	u16 vf_mc_hashes[IXGBE_MAX_VF_MC_ENTRIES];
	u16 num_vf_mc_hashes;
	bool clear_to_send;
	struct vf_stats vfstats;
	struct vf_stats last_vfstats;
	struct vf_stats saved_rst_vfstats;
	bool pf_set_mac;
	u16 pf_vlan; /* When set, guest VLAN config not allowed. */
	u16 pf_qos;
	u16 tx_rate;
	u8 spoofchk_enabled;
#ifdef HAVE_NDO_SET_VF_RSS_QUERY_EN
	bool rss_query_enabled;
#endif
	u8 trusted;
	int xcast_mode;
	unsigned int vf_api;
};

struct vf_macvlans {
	struct list_head l;
	int vf;
	bool free;
	bool is_macvlan;
	u8 vf_macvlan[ETH_ALEN];
};
```

adapter->vfinfo
Memory allocation



### 2020-11-11
Objective
1. Test some functions on [Companion Guide](./82599-sr-iov-driver-companion-guide.pdf)
- ethtools: VF driver is a standard driver
![ethtools1](./imgs/ethtools1.png)

### 2020-11-10
To enable drivers,
- go to ixgbe-<x.x.x>/src/
- and sudo make
	- binutils(https://zoomadmin.com/HowToInstall/UbuntuPackage/binutils-common) : sudo apt install -y binutils-common
	- install gcc
- and ixgbe.ko will be on at
/lib/modules/5.4.0-52-generic/updates/drivers/net/ethernet/intel/ixgbevf/ixgbevf.ko

- *Do* 
```
	make
```

```
	sudo rmmod ixgbe
```

```
	sudo inmod ./ixgbe.ko
```

### 2020-11-09
Dive into Kernel

- check current driver

- Make Kernel File
```
	make -J 10
```

- Disable current(original) driver
```
	sudo rmmod ixgbe
```

- Enable new driver
```
	sudo inmod ./ixgbe.ko
```

- Return to current driver
```
	sudo modeprobe ixgbe
```

- View Logs
```
	dmesg
```

netplan setup
https://blog.hkwon.me/ubuntu-18-04-netplan/

### 2020-11-04
downloaded ixgbe_vf from : https://sourceforge.net/projects/e1000/

How to setup?
1. Configure the number of VMs. 
```
$ echo 4 > /sys/class/net/<device name>/device/sriov_numvfs
```
2. check businfo with
```
$ lshw -c network -businfo
```

3. create ip for machine, if needed by: https://www.cyberciti.biz/faq/linux-kvm-libvirt-dnsmasq-dhcp-static-ip-address-configuration-for-guest-os/

4. (virt-manager) using GUI, add Hardware in PCI with name *Virtual Functions*

5. add counterparts to the vm's routing table ( counterpart's ip: 10.0.0.4, for example)
```
route add -net 10.0.0.0 netmask 255.255.255.0 dev ens9
```

6. add vm to the counterparts' routing table ( vm's ip: 20.0.0.3 , for example)
```
route add -net 20.0.0.0 netmask 255.255.255.0 dev ens6f1
```


### 2020-11-02
problems
1. Network default is not active
![1102_prob1](./imgs/1102_prob1.png)
2. Tried to restart, but "protocol wrong type for socket" error
![1102_prob2](./imgs/1102_prob2.png)

### 2020-10-30
How to setup?
1. Configure the number of VMs. 
```
$ echo 4 > /sys/class/net/<device name>/device/sriov_numvfs
```
2. check businfo with
```
$ lshw -c network -businfo
```

3. create ip for machine, if needed by: https://www.cyberciti.biz/faq/linux-kvm-libvirt-dnsmasq-dhcp-static-ip-address-configuration-for-guest-os/
	- issue1 :  
	```
	$ sudo virsh net-start default
	```
	```
         	error: Failed to start network default
         	error: internal error: Failed to apply firewall rules /sbin/iptables -w --table filter --insert FORWARD --destination 192.168.122.0/24 --out-interface virbr0 --match conntrack --ctstate ESTABLISHED,RELATED --jump ACCEPT: iptables: Protocol wrong type for socket.
	```
	
	-issue 2: virsh default xml missing
	https://blog.programster.org/kvm-missing-default-network
	

3. (virt-manager) using GUI, add Hardware in PCI with name *Virtual Functions*


### 2020-10-29
About VMDq(virtual machine device queue): https://www.youtube.com/watch?v=QvKXbpV6WXk
=> into multiple queues

![vmdq](./imgs/vmdq.png)
![vmdq_visual](./imgs/vmdq_gr.png)


About SR-IOV(Single Root IO Virtualization): https://www.youtube.com/watch?v=hRHsk8Nycdg
=> DMA'd
![sriov_vf](./imgs/sriov_vf.png)
![sriov_ex](./imgs/sriov_ex.png)
![sriov_de](./imgs/sriov_de.png)
![sriov_de](./imgs/sriov_gr.png)




### 2020-10-28
Analysis of code flow: set sriov_numvf to be 2 ---(?)----> interface 1, 2 created

- main
ixgbe_main.c
```c
#ifdef HAVE_RHEL6_SRIOV_CONFIGURE
static struct pci_driver_rh ixgbe_driver_rh = {
	.sriov_configure = ixgbe_pci_sriov_configure,
};
#endif
```

- sriov main
ixgbe_sriov.c
```c
int ixgbe_pci_sriov_configure(struct pci_dev *dev, int num_vfs)
{
	if (num_vfs == 0)
		return ixgbe_pci_sriov_disable(dev);
	else
		return ixgbe_pci_sriov_enable(dev, num_vfs);
}
``` 

- if num_vfs != 0, enable
```c
static int ixgbe_pci_sriov_enable(struct pci_dev __maybe_unused *dev, int __maybe_unused num_vfs)
{
...
    // !set here
	err = __ixgbe_enable_sriov(adapter, num_vfs);
	if (err)
		goto err_out;

	for (i = 0; i < adapter->num_vfs; i++)
		ixgbe_vf_configuration(dev, (i | 0x10000000));

	/* reset before enabling SRIOV to avoid mailbox issues */
	ixgbe_sriov_reinit(adapter);

	err = pci_enable_sriov(dev, num_vfs);
	if (err) {
		e_dev_warn("Failed to enable PCI sriov: %d\n", err);
		goto err_out;
	}
	ixgbe_get_vfs(adapter);

out:
	return num_vfs;

err_out:
	return err;
...
}
```

1.  enable sriov
```c
static int __ixgbe_enable_sriov(struct ixgbe_adapter *adapter,
				unsigned int num_vfs)
```
=> flag setups : SRIOV, VMDQ

=> vfinfo setups

=> num_vfs

=> alloc_vf_macvlans *

=> ring feature

=> L2SWITCH, SRIOV REPLICATION flags



2.  ixgbe_vf_configuration
```c
#ifdef CONFIG_PCI_IOV
int ixgbe_vf_configuration(struct pci_dev *pdev, unsigned int event_mask)
{
	unsigned char vf_mac_addr[6];
	struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
	unsigned int vfn = (event_mask & 0x3f);
	bool enable = ((event_mask & 0x10000000U) != 0);

	if (enable) {
		memset(vf_mac_addr, 0, ETH_ALEN);
		memcpy(adapter->vfinfo[vfn].vf_mac_addresses, vf_mac_addr, 6);
	}

	return 0;
}
```
-> allocate mac address

struct ixgbe_hw
```c
struct ixgbe_hw *hw = &adapter->hw;
``` 

3. reinit
```c
ixgbe_sriov_reinit(adapter);
```

4. pci_enable_sriov
```c
err = pci_enable_sriov(dev, num_vfs);
```

5. ixgbe_get_vfs(adapter)
```c
ixgbe_get_vfs(adapter);
```

- others
@ ixgbe_type.h
```c
struct ixgbe_hw {
	u8 IOMEM *hw_addr;
	void *back;
	struct ixgbe_mac_info mac;
	struct ixgbe_addr_filter_info addr_ctrl;
	struct ixgbe_fc_info fc;
	struct ixgbe_phy_info phy;
	struct ixgbe_link_info link;
	struct ixgbe_eeprom_info eeprom;
	struct ixgbe_bus_info bus;
	struct ixgbe_mbx_info mbx;
	const u32 *mvals;
	u16 device_id;
	u16 vendor_id;
	u16 subsystem_device_id;
	u16 subsystem_vendor_id;
	u8 revision_id;
	bool adapter_stopped;
	int api_version;
	bool force_full_reset;
	bool allow_unsupported_sfp;
	bool wol_enabled;
	bool need_crosstalk_fix;
};
```

- struct ixgbe_adapter
@ixgbe.h
```c
/* board specific private data structure */
struct ixgbe_adapter {
...

	/* Some features need tri-state capability,
	 * thus the additional *_CAPABLE flags.
	 */
	u32 flags;
...

#define IXGBE_FLAG_VMDQ_ENABLED			(u32)(1 << 11)
...
#define IXGBE_FLAG_SRIOV_ENABLED		(u32)(1 << 20)
...
	int num_q_vectors;	/* current number of q_vectors for device */
	int max_q_vectors;	/* upper limit of q_vectors for device */
	struct ixgbe_ring_feature ring_feature[RING_F_ARRAY_SIZE];
	struct msix_entry *msix_entries;
...
};
```

struct ring_feature
@ixgbe.h
```c
struct ixgbe_ring_feature {
	u16 limit;	/* upper limit on feature indices */
	u16 indices;	/* current value of indices */
	u16 mask;	/* Mask used for feature to ring mapping */
	u16 offset;	/* offset to start of feature */
};
```

- allocate vf macvlan, set offset, enable L2 switch
```c
adapter->num_vfs = num_vfs;

ixgbe_alloc_vf_macvlans(adapter, num_vfs);

adapter->ring_feature[RING_F_VMDQ].offset = num_vfs;

/* enable L2 switch and replication */
adapter->flags |= IXGBE_FLAG_SRIOV_L2SWITCH_ENABLE |
			IXGBE_FLAG_SRIOV_REPLICATION_ENABLE;
```



### 2020-10-27
- successfully set 2 VMs with SR-IOV: https://software.intel.com/content/www/us/en/develop/articles/configure-sr-iov-network-virtual-functions-in-linux-kvm.html#vf-interface-name 

	todo:
	- check funciton ixgbe_pci_sriov_configure @ ixgbe_sriov.c
	- check function ixgbe_pci_sriov_enable @ixgbe_sriov.c
	- check function ixgbe_enable_sriov @ ixgbe_sriov.c
 

### 2020-10-26
- assigning static ip address by: https://www.cyberciti.biz/faq/linux-kvm-libvirt-dnsmasq-dhcp-static-ip-address-configuration-for-guest-os/

### 2020-09-22
- completed SR-IOV setup based on:
https://software.intel.com/content/www/us/en/develop/articles/configure-sr-iov-network-virtual-functions-in-linux-kvm.html

- setups
assigned 1 vm, with SR-IOV

- ping test

vm0 -> server0 -> NIC(1G)   ------------------------> NIC -> server1 (vm without SR-IOV)
```
PING 115.145.179.20 (115.145.179.20) 56(84) bytes of data.
64 bytes from 115.145.179.20: icmp_seq=7 ttl=64 time=0.473 ms
64 bytes from 115.145.179.20: icmp_seq=8 ttl=64 time=0.476 ms
64 bytes from 115.145.179.20: icmp_seq=9 ttl=64 time=0.439 ms
64 bytes from 115.145.179.20: icmp_seq=10 ttl=64 time=0.443 ms
64 bytes from 115.145.179.20: icmp_seq=11 ttl=64 time=0.379 ms
^C
--- 115.145.179.20 ping statistics ---
11 packets transmitted, 5 received, 54% packet loss, time 10232ms
rtt min/avg/max/mdev = 0.379/0.442/0.476/0.034 ms
```
	
vm0 -> server0 -> NIC(10G) ------------------------> NIC -> server1(vm with SR-IOV)
```
PING 10.0.0.4 (10.0.0.4) 56(84) bytes of data.
64 bytes from 10.0.0.4: icmp_seq=1 ttl=64 time=0.192 ms
64 bytes from 10.0.0.4: icmp_seq=2 ttl=64 time=0.119 ms
64 bytes from 10.0.0.4: icmp_seq=3 ttl=64 time=0.122 ms
64 bytes from 10.0.0.4: icmp_seq=4 ttl=64 time=0.119 ms
64 bytes from 10.0.0.4: icmp_seq=5 ttl=64 time=0.116 ms
^C
--- 10.0.0.4 ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4085ms
rtt min/avg/max/mdev = 0.116/0.133/0.192/0.031 ms

```

server0 -> NIC(1G) ------------------------> NIC -> server1 ( no vm setup )
```
PING 115.145.179.20 (115.145.179.20) from 115.145.179.15 enp0s25: 56(84) bytes of data.
64 bytes from 115.145.179.20: icmp_seq=1 ttl=64 time=0.130 ms
64 bytes from 115.145.179.20: icmp_seq=2 ttl=64 time=0.163 ms
64 bytes from 115.145.179.20: icmp_seq=3 ttl=64 time=0.166 ms
64 bytes from 115.145.179.20: icmp_seq=4 ttl=64 time=0.162 ms
64 bytes from 115.145.179.20: icmp_seq=5 ttl=64 time=0.164 ms
^C
--- 115.145.179.20 ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4086ms
rtt min/avg/max/mdev = 0.130/0.157/0.166/0.013 ms
```

### 2020-09-17
- overview of packet reception: https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/performance_tuning_guide/s-network-packet-reception

- commands
	- image creation
```
qemu-img create -f qcow2 ~/QEMU/img.qcow2 10G
```
	- 
```
sudo qemu-system-x86_64   -m 2048   -vga virtio   -show-cursor   -usb        -device usb-tablet    -enable-kvm   -cdrom ~/QEMU/ubuntu-18.04.5-live-server-amd64.iso   -drive file=~/QEMU/img.qcow2,if=virtio   -cpu host 

sudo qemu-system-x86_64   -m 2048   -vga virtio   -show-cursor   -usb        -device usb-tablet -serial null -nographic   -enable-kvm   -cdrom ~/QEMU/ubuntu-18.04.5-live-server-amd64.iso   -drive file=~/QEMU/img.qcow2,if=virtio   -cpu host 

sudo qemu-system-x86_64 -m 2048 -vga virtio -show-cursor -usb -device usb-tablet -serial mon:stdio -kernel -append '/dev/ttyS0' -nographic -enable-kvm -cdrom ~/QEMU/ubuntu-18.04.5-live-server-amd64.iso -drive file=~/QEMU/img.qcow2,if=virtio -cpu host

sudo qemu-system-x86_64 -m 2048 -vga virtio -show-cursor -usb -device usb-tablet -serial pty -nographic -enable-kvm -cdrom ~/QEMU/ubuntu-18.04.5-live-server-amd64.iso -drive file=~/QEMU/img.qcow2,if=virtio -cpu host
```

- setting ethernet on vm : not yet

### 2020-09-16
- Setting virtual machine: ssh -X was **successful**
- used virt-manager
![virt-manager](./imgs/virt-manager.png)
- host machine: server
- virtual machine
![vm0](./imgs/vm0.png)
	- virtual machine setup
		- machine name: guest0
		- user name: vm0
		- pw ****
		- host device network: enpos25: mactap

### 2020-09-14
- Try setting up venv on server, failed
	- https://smdaudhilbe.wordpress.com/2013/04/11/how-to-install-ubuntu-inside-qemu-emulator-and-make-a-virtual-machine/

### 2020-09-10
- Concepts study: Virtualized Networking
	- SR-IOV
		- Separable : https://docs.microsoft.com/ko-kr/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-
			- "Each PF and VF is assigned a unique PCI Express Requester ID (RID) that allows an I/O memory management unit (IOMMU) to differentiate between different traffic streams and apply memory and interrupt translations between the PF and VFs. This allows traffic streams to be delivered directly to the appropriate Hyper-V parent or child partition. As a result, nonprivileged data traffic flows from the PF to VF without affecting other VFs."
		- Architecture
			![SR-IOV](./imgs/sriovarchitecture.png)			
		- PF
			- Enable Virtualization
			- exposing VFs
		- NIC Switch
			-  Setup : [OID_NIC_SWITCH_CREATE_SWITCH](https://docs.microsoft.com/ko-kr/windows-hardware/drivers/network/oid-nic-switch-create-switch)
			- VPORT: [OID_NIC_CREATE_VPORT](https://docs.microsoft.com/ko-kr/windows-hardware/drivers/network/oid-nic-switch-create-vport)
		- [Interface](https://docs.microsoft.com/ko-kr/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov--interface)
			- PCIe VF is assigned a unique Requester ID.
			- IOMMU do:
				Distinguish/ isolation of traffic
			
	- VMQ
		- CPU Intervention needed	

### 2020-09-09
- Concept study: SR-IOV
	- History
		- NDIS 6.20: introduces the virtual machine queue (VMQ) interface to support Microsoft Hyper-V network performance improvements.
		- NDIS 6.30: https://docs.microsoft.com/ko-kr/windows-hardware/drivers/network/virtualized-networking-enhancements-in-ndis-6-30
		
			- SR-IOV: partitioning of the hardware resources on a PCI Express (PCIe) NW adapter -> virtual interfaces(VFs). 
			bypass the virtual software switch layer by assigning a VF to the Hyper-V child partition directly. 
			- Hyper-V Extensible Switch: virtualized ethernet switch, runs in the management operating system of the Hyper-V parent partition.
			
	- SR-IOV
		
		![SR-IOV](./imgs/sriovarchitecture.png) 
		- PF: parent
		- VF: child
		- idea: PF for CPU, VF for GPU (by on/off?)
		
- tomorrow
	- Detailed study on SR-IOV
	- Details on RSS and others (https://www.kernel.org/doc/Documentation/networking/scaling.txt)
	- Search for keyword VMQ (https://www.intel.co.kr/content/www/kr/ko/support/articles/000006703/network-and-i-o/ethernet-products.html)
	
### 2020-09-08

- Concept study: RSS(Receive Side Scaling)
	- Introduction to RSS: 
	https://docs.microsoft.com/en-us/windows-hardware/drivers/network/introduction-to-receive-side-scaling
- Searching for sNIC / programmable NIC to modify RSS part
	- SmartNIC
		- [ConnectX-6 Lx Dual 25GbE / Single 50GbE SmartNIC](https://www.mellanox.com/files/doc-2020/pb-connectx-6-lx-en-card.pdf) : Stateless Offloads – Received Side Scaling (RSS) also on encapsulated packet
		- [ConnectX-6 Dx Dual 100GbE / Single 200GbE SmartNIC](https://www.mellanox.com/files/doc-2020/pb-connectx-6-dx-en-card.pdf)
		- [ConnectX®-6 200GbE Single/Dual-Port Adapters](https://www.mellanox.com/files/doc-2020/pb-connectx-6-en-card.pdf)
		- [ConnectX®-5 100GbE Single/Dual-Port Adapters](https://www.mellanox.com/files/doc-2020/pb-connectx-5-en-card.pdf)
		- [ConnectX®-4 Lx EN 10/25/40/50GbE Ethernet Adapter Cards](https://www.mellanox.com/files/doc-2020/pb-connectx-4-lx-en-card.pdf)
	- Programmable SNIC
		- [bluefield-2-smart-nic](https://www.mellanox.com/files/doc-2020/pb-bluefield-2-smart-nic-eth.pdf) – RSS (also on encapsulated packets), TSS, HDS, VLAN insertion/stripping, Receive Flow Steering
		- [bluefield-smart-nic](https://www.mellanox.com/files/doc-2020/pb-bluefield-smart-nic.pdf) – RSS (also on encapsulated packets), TSS, HDS, VLAN insertion/stripping, Receive Flow Steering 
		- [innova-2-flex](https://www.mellanox.com/files/doc-2020/pb-innova-2-flex.pdf) – RSS VLAN and MPLS tag insertion/stripping,
Receive flow steering
- Tomorrow
	- Details on RSS and others (https://www.kernel.org/doc/Documentation/networking/scaling.txt)
	- Search for keyword VMQ (https://www.intel.co.kr/content/www/kr/ko/support/articles/000006703/network-and-i-o/ethernet-products.html)
	
### 2020-09-07

- Concept study: RSS(Receive Side Scaling)
	- Introduction to RSS: 
	https://docs.microsoft.com/en-us/windows-hardware/drivers/network/introduction-to-receive-side-scaling
- Searching for sNIC / programmable NIC to modify RSS part
	- Hard to find
	- Community guide
