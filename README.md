# DWM - Dynamic Window Manager
This is a fork of [dwm](https://dwm.suckless.org/) from [suckless.org](https://suckless.org).

## Prerequisites:
- xorg-server,
- [st](https://st.suckless.org/),
- [dmenu](https://tools.suckless.org/dmenu/),
- [X initialization script](https://github.com/jakub-swiniarski/xinitrc) (optional).

## Changes:
- changed colors,
- added volume control for PulseAudio,
- removed functions and keybinding that I don't use,
- removed all layouts except tile.

## Keybindings:
### Window and tag control
- Super + R - spawn dmenu,
- Super + T - spawn terminal,
- Super + C - kill a window. <br/>

**See more in config.h**

### Volume control (PulseAudio)
- Alt + F1 - mute the sound,
- Alt + F2 - lower the volume,
- Alt + F3 - increase the volume.

## Removed functions:
- toggling the bar on/off,
- increasing/decreasing the number of windows on master,
- changing the layout,
- switching to previous tag,
- increasing/decreasing master size,
- making a window appear on all tags,
- toggling to previous layout,
- making an individual window float using keyboard,
- spawning a terminal using mouse,
- moving a window to master using mouse,
- changing the layout using mouse,
- making a window float using mouse,
- moving a window to another tag using maouse,
- copying the window to another tag using mouse.
