/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "monospace:size=12" };
static const char dmenufont[]       = "monospace:size=12";
static const char col_black[]       = "#000000";
static const char col_white[]    	= "#ffffff";
static const char col_purple[]       = "#960f96";
static const char *colors[][3]      = {
	/*               fg         bg          border   */
	[SchemeNorm] = { col_white, col_black,   col_black },
	[SchemeSel]  = { col_white, col_purple,  col_purple  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* key definitions */
#define ALT Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ KeyPress,   SUPER,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ KeyPress,   SUPER|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ KeyPress,   SUPER|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ KeyPress,   SUPER|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* pulseaudio volume control */
static const char *upvol[]      = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "+10%",      NULL };
static const char *downvol[]    = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "-10%",      NULL };
static const char *mutevol[]    = { "/usr/bin/pactl",   "set-sink-mute",   "@DEFAULT_SINK@",      "toggle",   NULL };

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_white, "-sb", col_purple, "-sf", col_white, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/*           modifier                       key      function           argument */
	{ KeyPress,   SUPER,                       XK_r,       spawn,          {.v = dmenucmd } },
	{ KeyPress,   SUPER,                       XK_t,       spawn,          {.v = termcmd } },
	{ KeyPress,   SUPER,                       XK_j,       focusstack,     {.i = +1 } },
	{ KeyPress,   SUPER,                       XK_k,       focusstack,     {.i = -1 } },
	{ KeyPress,   SUPER,                       XK_z, 	   zoom,           {0} },
	{ KeyPress,   SUPER,		               XK_c,       killclient,     {0} },
	{ KeyPress,   SUPER,                       XK_comma,   focusmon,       {.i = -1 } },
	{ KeyPress,   SUPER,                       XK_period,  focusmon,       {.i = +1 } },
	{ KeyPress,   SUPER|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ KeyPress,   SUPER|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ KeyPress,   SUPER|ShiftMask,             XK_q,       quit,           {0} },
	{ KeyPress,   0,                           XK_Super_L, showbar,        {0} },
	{ KeyRelease, SUPER,                       XK_Super_L, hidebar,        {0} },

	/* volume control */
	{ KeyPress,   ALT,                       XK_F2,  spawn, {.v = downvol } },
	{ KeyPress,   ALT,                       XK_F1,  spawn, {.v = mutevol } },
	{ KeyPress,   ALT,                       XK_F3,  spawn, {.v = upvol   } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         SUPER,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         SUPER,         Button3,        resizemouse,    {0} },
};

