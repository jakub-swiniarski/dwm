static const unsigned int borderpx = 2;
static const unsigned int snap = 32;
static const int topbar = 0;
static const char *font = "monospace:size=12";
static const char *colors[][3] = {
	[SchemeNorm] = { "#ffffff", "#000000" },
	[SchemeSel]  = { "#ffffff", "#0066aa" },
};

static const char *tags[] = { "1", "2", "3", "4", "5" };

static const float mfact = 0.6;
static const int nmaster = 1;

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,             KEY, view,       { .ui = 1 << TAG} }, \
	{ MODKEY|ControlMask, KEY, toggleview, { .ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,   KEY, tag,        { .ui = 1 << TAG} },

static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+10%",   NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-10%",   NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	{ MODKEY,           XK_r,   spawn,      { .v = dmenucmd } },
	{ MODKEY,           XK_t,   spawn,      { .v = termcmd } },
	{ MODKEY,           XK_j,   focusstack, { .i = +1 } },
	{ MODKEY,           XK_k,   focusstack, { .i = -1 } },
	{ MODKEY,           XK_z,   zoom,       { 0 } },
	{ MODKEY,		    XK_c,   killclient, { 0 } },
	{ MODKEY,           XK_h,   focusmon,   { .i = -1 } },
	{ MODKEY,           XK_l,   focusmon,   { .i = +1 } },
	{ MODKEY|ShiftMask, XK_h,   tagmon,     { .i = -1 } },
	{ MODKEY|ShiftMask, XK_l,   tagmon,     { .i = +1 } },
	{ MODKEY|ShiftMask, XK_q,   quit,       { 0 } },
	{ MODKEY,           XK_b,   togglebar,  { 0 } },
	{ MODKEY,           XK_F3,  spawn,      { .v = upvol   } },
	{ MODKEY,           XK_F2,  spawn,      { .v = downvol } },
	{ MODKEY,           XK_F1,  spawn,      { .v = mutevol } },
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
};

static const Button buttons[] = {
	{ ClkClientWin, MODKEY, Button1, movemouse,   { 0 } },
	{ ClkClientWin, MODKEY, Button3, resizemouse, { 0 } },
};

