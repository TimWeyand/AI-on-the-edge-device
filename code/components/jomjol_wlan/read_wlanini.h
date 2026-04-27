#pragma once

#ifndef READ_WLANINI_H
#define READ_WLANINI_H

#include <string>

struct wlan_config {
    std::string ssid = "";
    std::string password = "";
    std::string hostname = "watermeter";    // Default: watermeter
    std::string ipaddress = "";
    std::string gateway = "";
    std::string netmask = "";
    std::string dns = "";
    std::string http_username = "";
    std::string http_password = "";
    int rssi_threshold = 0;                 // Default: 0 -> ROAMING disabled
};
extern struct wlan_config wlan_config;


int LoadWlanFromFile(std::string fn);
bool ChangeHostName(std::string fn, std::string _newhostname);
bool ChangeRSSIThreshold(std::string fn, int _newrssithreshold);

/**
 * Update static IP configuration in wlan.ini.
 *
 * Replaces the ip/gateway/netmask/dns lines (preserving ssid/password/hostname/etc.).
 * Empty fields are written as commented-out lines, which causes the firmware to fall
 * back to DHCP for those fields at next boot.
 *
 * Pass all four values empty to switch back to DHCP.
 * Note: changes take effect only after reboot (wlan.ini is read at boot).
 *
 * Returns true on success, false on I/O error.
 */
bool ChangeStaticIP(std::string fn, std::string _ip, std::string _gateway, std::string _netmask, std::string _dns);


#endif //READ_WLANINI_H