# DWM - Dynamic Window Manager
This is a fork of [dwm](https://dwm.suckless.org/) from [suckless.org](https://suckless.org).

## Prerequisites:
- gcc,
- make,
- xorg-server,
- [st](https://github.com/jakub-swiniarski/st),
- [dmenu](https://github.com/jakub-swiniarski/dmenu),
- [X initialization script](https://github.com/jakub-swiniarski/xinitrc),
- libx11,
- libxft,
- libxinerama.

## Changes:
- removed many features that I don't use,
- reduced amount of tags,
- changed colors,
- added volume control for PulseAudio,
- centered status bar.

## Keybindings:
### Window and tag control
- Super + R - spawn dmenu,
- Super + T - spawn a terminal (st by default),
- Super + C - kill a window,
- Super + Z - move a window to master.<br/>

**See more in config.h**

### Volume control (PulseAudio)
- Alt + F1 - mute the sound,
- Alt + F2 - lower the volume,
- Alt + F3 - increase the volume.
