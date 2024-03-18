static const unsigned int BORDERPX = 2;
static const unsigned int SNAP = 32;
static const char *FONT = "monospace:size=12";
static const char *COLORS[][3] = {
	[SchemeNorm] = { "#ffffff", "#000000" },
	[SchemeSel]  = { "#ffffff", "#646464" },
};

static const char *TAGS[] = { "1", "2", "3", "4", "5"};

static const float MFACT = 0.6;
static const int NMASTER = 1;

#define ALT Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ SUPER,             KEY, view,       { .UI = 1 << TAG} }, \
	{ SUPER|ControlMask, KEY, toggleview, { .UI = 1 << TAG} }, \
	{ SUPER|ShiftMask,   KEY, tag,        { .UI = 1 << TAG} },

static const char *UPVOL[]   = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+10%",   NULL };
static const char *DOWNVOL[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-10%",   NULL };
static const char *MUTEVOL[] = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };

static char dmenumon[2] = "0";
static const char *DMENUCMD[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *TERMCMD[]  = { "st", NULL };

static const Key KEYS[] = {
	{ SUPER,           XK_r,   spawn,      { .V = DMENUCMD } },
	{ SUPER,           XK_t,   spawn,      { .V = TERMCMD } },
	{ SUPER,           XK_j,   focusstack, { .I = +1 } },
	{ SUPER,           XK_k,   focusstack, { .I = -1 } },
	{ SUPER,           XK_z,   zoom,       { 0 } },
	{ SUPER,		   XK_c,   killclient, { 0 } },
	{ SUPER,           XK_h,   focusmon,   { .I = -1 } },
	{ SUPER,           XK_l,   focusmon,   { .I = +1 } },
	{ SUPER|ShiftMask, XK_h,   tagmon,     { .I = -1 } },
	{ SUPER|ShiftMask, XK_l,   tagmon,     { .I = +1 } },
	{ SUPER|ShiftMask, XK_q,   quit,       { 0 } },
	{ SUPER,           XK_b,   togglebar,  { 0 } },
	{ ALT,             XK_F3,  spawn,      { .V = UPVOL   } },
	{ ALT,             XK_F2,  spawn,      { .V = DOWNVOL } },
	{ ALT,             XK_F1,  spawn,      { .V = MUTEVOL } },
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
};

static const Button BUTTONS[] = {
	{ ClkClientWin, SUPER, Button1, movemouse,   { 0 } },
	{ ClkClientWin, SUPER, Button3, resizemouse, { 0 } },
};

