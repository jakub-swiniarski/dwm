/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "monospace:size=12" };
static const char *colors[][3]      = {
	/*               fg         bg          border   */
	[SchemeNorm] = { "#ffffff", "#000000",  "#000000" },
	[SchemeSel]  = { "#ffffff", "#960f96",  "#960f96" },
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
	{ SUPER,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ SUPER|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ SUPER|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* pulseaudio volume control */
static const char *upvol[]      = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "+10%",      NULL };
static const char *downvol[]    = { "/usr/bin/pactl",   "set-sink-volume", "@DEFAULT_SINK@",      "-10%",      NULL };
static const char *mutevol[]    = { "/usr/bin/pactl",   "set-sink-mute",   "@DEFAULT_SINK@",      "toggle",   NULL };

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/*modifier                     key         function        argument */
	{ SUPER,                       XK_r,       spawn,          {.v = dmenucmd } },
	{ SUPER,                       XK_t,       spawn,          {.v = termcmd } },
	{ SUPER,                       XK_j,       focusstack,     {.i = +1 } },
	{ SUPER,                       XK_k,       focusstack,     {.i = -1 } },
	{ SUPER,                       XK_z, 	   zoom,           {0} },
	{ SUPER,		               XK_c,       killclient,     {0} },
	{ SUPER,                       XK_comma,   focusmon,       {.i = -1 } },
	{ SUPER,                       XK_period,  focusmon,       {.i = +1 } },
	{ SUPER|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ SUPER|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ SUPER|ShiftMask,             XK_q,       quit,           {0} },
	{ SUPER,                       XK_b,       togglebar,      {0} },

	/* volume control */
	{ ALT,                       XK_F2,  spawn, {.v = downvol } },
	{ ALT,                       XK_F1,  spawn, {.v = mutevol } },
	{ ALT,                       XK_F3,  spawn, {.v = upvol   } },
};

/* button definitions */
/* click can be ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         SUPER,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         SUPER,         Button3,        resizemouse,    {0} },
};

