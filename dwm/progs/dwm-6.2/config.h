/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {	"SF mono:pixelsize=11:antialias=false:autohint=true" };
static const char dmenufont[]       = "SF mono:pixelsize=11:antialias=false:autohint=true";
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#657b83";
static const char col_gray3[]       = "#ffffff";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#657b83";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2  },
	[SchemeStatus]  = { col_gray3, col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_gray4, col_cyan,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray3, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_gray4, col_gray1 /* col_cyan */,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gray3, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
//	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "st",      NULL,     NULL,           0,         0,          1,          -1,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ Mod1Mask,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Mod1Mask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "terminal", NULL };
static const char *newsboatcmd[]  = { "terminal", "newsboat", NULL };
static const char *pulsemixercmd[]  = { "terminal", "pulsemixer", NULL };
static const char *emailcmd[]  = { "terminal", "neomutt", NULL };

static const char *ncmpcppcmd[]  = { "terminal", "ncmpcpp", NULL };

static const char *wallselectcmd[]  = { "/home/anton/.scripts/wallselect", NULL };
static const char *browsercmd[] = { "/home/anton/.scripts/start_browser", NULL };
static const char *torbrowsercmd[] = { "torbrowser-launcher", NULL };

static const char *clipboardcmd[] = { "/home/anton/.scripts/open_from_clipboard", NULL };

static const char *dwmblockscmd[] = { "/home/anton/.scripts/restart_dwmblocks", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */

 /* Swedish chars */
 /* { MODKEY,                       XK_semicolon,      spawn,          {.v = ocmd } },
	{ MODKEY,                       XK_quotedbl,      spawn,          {.v = acmd } },
	{ MODKEY,                       XK_bracketleft,      spawn,          {.v = aacmd } },*/
 /* END Swedish chars */

	{ Mod1Mask,						XK_a,	   spawn,          SHCMD("setxkbmap -query | grep 'layout:     us' && setxkbmap se || setxkbmap us") },
	{ Mod1Mask,                     XK_u,      spawn,          {.v = browsercmd } },
	{ Mod1Mask|ShiftMask,           XK_u,      spawn,          {.v = torbrowsercmd } },
	{ Mod1Mask,                     XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod1Mask,						XK_w,	   spawn,		   {.v = wallselectcmd} },
	{ Mod1Mask,                     XK_n,      spawn,          {.v = termcmd } },
	{ Mod1Mask|ShiftMask,           XK_n,      spawn,          {.v = newsboatcmd } },
	{ Mod1Mask|ShiftMask,           XK_i,      spawn,          {.v = pulsemixercmd } },
	{ Mod1Mask|ShiftMask,           XK_m,      spawn,          {.v = emailcmd } },
	{ Mod1Mask|ShiftMask,           XK_o,      spawn,          {.v = ncmpcppcmd } },
	{ ControlMask|ShiftMask,		XK_d,      spawn,          {.v = clipboardcmd } },
	{ Mod1Mask|ShiftMask,                     XK_r,      spawn,		   SHCMD("mpc listall | shuf -n 1 | mpc add; mpc play") },
	{ Mod1Mask|ShiftMask,                     XK_e,      spawn,		   SHCMD("mpc next") },
	{ Mod1Mask,                     XK_b,      spawn,		   {.v = dwmblockscmd} },


	{ Mod1Mask, 					XK_z,	   spawn,          SHCMD("$(amixer -c 1 sset 'Master' 5%- || amixer -c 2 sset 'Master' 5%-); pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask,						XK_x,	   spawn,          SHCMD("$(amixer -c 1 sset 'Master' 5%+ || amixer -c 2 sset 'Master' 5%+); pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask, 					XK_m,	   spawn,          SHCMD("mpc toggle; pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask|ShiftMask,			XK_z,	   spawn,          SHCMD("mpc volume -5; pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask|ShiftMask,			XK_x,	   spawn,          SHCMD("mpc volume +5; pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask|ShiftMask,			XK_p,	   spawn,          SHCMD("sudo xkill") },
	{ Mod1Mask,						XK_s,	   spawn,          SHCMD("sleep 0.2;/home/anton/.scripts/screenshot") },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ Mod1Mask,                     XK_j,      focusstack,     {.i = +1 } },
	{ Mod1Mask,                     XK_k,      focusstack,     {.i = -1 } },
	{ Mod1Mask,                     XK_i,      incnmaster,     {.i = +1 } },
	{ Mod1Mask,                     XK_b,      incnmaster,     {.i = -1 } },
	{ Mod1Mask,                     XK_h,      setmfact,       {.f = -0.05} },
	{ Mod1Mask,                     XK_l,      setmfact,       {.f = +0.05} },
	{ Mod1Mask,                     XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ Mod1Mask,						XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ Mod1Mask,                     XK_comma,  focusmon,       {.i = -1 } },
	{ Mod1Mask,                     XK_period, focusmon,       {.i = +1 } },
	{ Mod1Mask|ShiftMask,           XK_comma,  tagmon,         {.i = -1 } },
	{ Mod1Mask|ShiftMask,           XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

