/* appearance */
static const unsigned int BORDERPX  = 2;        /* border pixel of windows */
static const unsigned int SNAP      = 32;       /* snap pixel */
static const char *FONTS[]          = { "monospace:size=12" };
static const char *COLORS[][3]      = {
	/*               fg         bg (also used for borders)               */
	[SchemeNorm] = { "#ffffff", "#000000" },
	[SchemeSel]  = { "#ffffff", "#646464" },
};

/* tagging */
static const char *TAGS[] = { "1", "2", "3", "4", "5"};

/* layout(s) */
static const float MFACT = 0.6; /* factor of master area size [0.05..0.95] */
static const int NMASTER = 1;    /* number of clients in master area */

/* key definitions */
#define ALT Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ SUPER,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ SUPER|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ SUPER|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* pulseaudio volume control */
static const char *UPVOL[]      = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "+10%",      NULL };
static const char *DOWNVOL[]    = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "-10%",      NULL };
static const char *MUTEVOL[]    = { "/usr/bin/pactl",   "set-sink-mute",   "@DEFAULT_SINK@",      "toggle",   NULL };

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *DMENUCMD[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *TERMCMD[]  = { "st", NULL };

static const Key KEYS[] = {
	/*modifier                     key         function        argument */
	{ SUPER,                       XK_r,       spawn,          {.v = DMENUCMD } },
	{ SUPER,                       XK_t,       spawn,          {.v = TERMCMD } },
	{ SUPER,                       XK_j,       focusstack,     {.i = +1 } },
	{ SUPER,                       XK_k,       focusstack,     {.i = -1 } },
	{ SUPER,                       XK_z, 	   zoom,           {0} },
	{ SUPER,		               XK_c,       killclient,     {0} },
	{ SUPER,                       XK_h,       focusmon,       {.i = -1 } },
	{ SUPER,                       XK_l,       focusmon,       {.i = +1 } },
	{ SUPER|ShiftMask,             XK_h,       tagmon,         {.i = -1 } },
	{ SUPER|ShiftMask,             XK_l,       tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ SUPER|ShiftMask,             XK_q,       quit,           {0} },
	{ SUPER,                       XK_b,       togglebar,      {0} },

	/* volume control */
	{ ALT,                       XK_F3,  spawn, {.v = UPVOL   } },
	{ ALT,                       XK_F2,  spawn, {.v = DOWNVOL } },
	{ ALT,                       XK_F1,  spawn, {.v = MUTEVOL } },
};

/* button definitions */
static const Button BUTTONS[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         SUPER,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         SUPER,         Button3,        resizemouse,    {0} },
};

