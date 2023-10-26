# DWM - Dynamic Window Manager
This is a fork of [dwm](https://dwm.suckless.org/) from [suckless.org](https://suckless.org).

## Prerequisites:
- xorg-server,
- [st](https://github.com/jakub-swiniarski/st),
- dmenu,
- [X initialization script](https://github.com/jakub-swiniarski/xinitrc).

## Changes:
- changed colors,
- added volume control for PulseAudio,
- removed functions and keybinding that I don't use,
- removed all layouts except tile.

## Keybindings:
### Window and tag control
- Super + R - spawn dmenu,
- Super + T - spawn terminal,
- Super + C - kill a window,
- Super + Z - move a window to master.<br/>

**See more in config.h**

### Volume control (PulseAudio)
- Alt + F1 - mute the sound,
- Alt + F2 - lower the volume,
- Alt + F3 - increase the volume.

## Removed features:
- toggling the bar on/off,
- increasing/decreasing the number of windows on master,
- changing the layout,
- switching to previous tag,
- increasing/decreasing master size,
- making a window appear on all tags,
- toggling to previous layout,
- making an individual window float,
- all mouse controls except resizing and moving windows,
- reduced amount of tags. <br/>

**And more! I want to make this WM as minimal as possible.**
