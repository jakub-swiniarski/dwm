# DWM - Dynamic Window Manager
This is a fork of [dwm](https://dwm.suckless.org/) from [suckless.org](https://suckless.org).

## Prerequisites
- gcc
- make
- xorg-server
- [st](https://github.com/jakub-swiniarski/st)
- [dmenu](https://github.com/jakub-swiniarski/dmenu)
- libx11
- libxft
- libxinerama

## Changes
- Removed many features that I don't use.
- Reduced amount of tags.
- Color changes.
- Added volume control for PulseAudio.
- Centered status bar.

## Keybindings
### Window and tag control
- Super + R - spawn dmenu
- Super + T - spawn a terminal (st by default)
- Super + C - kill a window
- Super + Z - move a window to master <br/>

**See more in config.h**

### Volume control (PulseAudio)
- Alt + F1 - mute the sound
- Alt + F2 - decrease the volume
- Alt + F3 - increase the volume
