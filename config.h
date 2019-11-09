/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 7;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=12" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 0xc0;
static const unsigned int borderalpha = 0xffU;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	//[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeNorm] = { col_gray3, col_gray1, "#000000" },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { 0xffU, 0xc0, 0x00U },
	[SchemeSel]  = { 0xffU, 0xc0, 0x00U },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      			instance    title       tags mask     isfloating   monitor */
	
	{ "Xfce4-appfinder",    NULL,       NULL,       0,            1,           -1 },
	{ "Gnome-calculator",   NULL,       NULL,       0,            1,           -1 },
	{ "Blueman-manager",    NULL,       NULL,       0,            1,           -1 },
	{ "Remmina",     		NULL,       NULL,       0,            1,           -1 },
	{ "Kazam",     			NULL,       NULL,       0,            1,           -1 },
	{ "VirtualBox Manager", NULL,       NULL,       0,            1,           -1 },
	{ "vlc",     			NULL,       NULL,       0,            1,           -1 },
	{ "Gimp",     			NULL,       NULL,       0,            1,           -1 },
	{ "Virtualbox", 		NULL,       NULL,       0,            1,           -1 },
	{ "feh", 				NULL,       NULL,       0,            1,           -1 },
//	{ "Sxiv", 				NULL,       NULL,       0,            1,           -1 },
	{ "Eog", 				NULL,       NULL,       0,            1,           -1 },
	{ "Pavucontrol", 		NULL,       NULL,       0,            1,           -1 },
	{ "Gnome-system-monitor",NULL,      NULL,       0,            1,           -1 },
	{ "Bluetooth-sendto",	NULL,       NULL,       0,            1,           -1 },
	{ "VirtualBox Machine",	NULL,       NULL,       0,            1,           -1 },
	{ "Pavucontrol",		NULL,       NULL,       0,            1,           -1 },
	{ "Cairo-dock",			NULL,       NULL,       0,            1,           -1 },

	{ "Wrapper-2.0",		NULL,       NULL,       0,            1,           1 },
	{ "wrapper-2.0",		NULL,       NULL,       0,            1,           1 },
	{ "Transmission",		NULL,       NULL,       0,            1,           1 },
	{ "Orage",				NULL,       NULL,       0,            1,           1 },
	
	{ "Stfloat",			NULL,       NULL,       0,            1,           -1 },


	//notes
	{ "Xfce4-notes",		NULL,       NULL,       1<<8,            1,           1 },
	{ "Xfce4-panel",		NULL,       NULL,       1<<8,            1,           1 },

	




	//{ "Firefox",  		NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *termcmdG[]  = { "gnome-terminal", NULL };
//static const char *termcmd[]  = { "st", NULL };
//static const char *termcmd[]  = { "st", NULL };
//static const char *sndup[]  = 		{ "/home/Petar/code/scripts/snd/up", NULL };
//static const char *snddown[]  = 	{ "/home/Petar/code/scripts/snd/down", NULL };
//static const char *sndcontrol[]  = 	{ "/usr/bin/pavucontrol", NULL };
//static const char *nautilus[]  = 	{ "/usr/bin/nautilus", NULL };
//static const char *appfinder[]  = 	{ "/usr/bin/xfce4-appfinder", NULL };

//my dmenu scripts
static const char *dm_dwmquit[]=	{ "/home/petar/.config/dmenu/dwmquit", NULL };
//static const char *dm_run[]  = 		{ "/home/Petar/.config/dmenu/run", NULL };

//static const char *runchromium[]  = { 	"/usr/bin/chromium", NULL };
//static const char *runfirefox[]  = { 	"/usr/bin/firefox","-P", "default", NULL };
//static const char *runopera[]  = { 		"/usr/bin/opera", NULL };
//static const char *runnautilus[]  = { 	"/usr/bin/nautilus", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_o,      		spawn,          {.v = appfinder } },
	{ MODKEY,                       XK_r,      		spawn,          {.v = dmenucmd } },
	//{ MODKEY,			            XK_Return,		spawn,          {.v = termcmd } },
	{ MODKEY,			            XK_c,			spawn,          {.v = termcmd } },
	{ MODKEY,			            XK_C,			spawn,          {.v = termcmdG } },

//	{ MODKEY,			            XK_e, 			spawn,          {.v = nautilus } },
//	{ 0,			            	0x1008ff13,		spawn,          {.v = sndup } },
//	{ 0,			            	0x1008ff11,		spawn,          {.v = snddown } },
//	{ 0,			            	0x1008ff12,		spawn,          {.v = sndcontrol } },

//	{ MODKEY,			            XK_F2,			spawn,          {.v = appfinder } },

	{ MODKEY,             			XK_q,      		spawn,          {.v = dm_dwmquit }}, 

//	{ MODKEY,             			XK_KP_End,		spawn,          {.v = runchromium }}, 
//	{ MODKEY,             			XK_KP_Down, 	spawn,          {.v = runfirefox }}, 
//	{ MODKEY,             			XK_KP_Page_Down,spawn,          {.v = runopera }}, 
	//{ MODKEY,             			XK_KP_Home,		spawn,          {.v = runnautilus }}, 


	{ MODKEY,                       XK_b,      		togglebar,      {0} },
	{ MODKEY,                     	XK_Page_Down,  	focusstack,     {.i = +1 } },
	{ MODKEY,                     	XK_Tab,  		focusstack,     {.i = +1 } },
	{ Mod1Mask,                     XK_Tab,     	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      		focusstack,     {.i = -1 } },
	{ MODKEY,                     	XK_Page_Up,  	focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,            	XK_Tab,  		focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Up,     		incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_Down,   		incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  		setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_s, 			zoom,           {0} },
	{ MODKEY,                       XK_y,   		view,           {0} },
	{ MODKEY,             			XK_KP_Page_Up,	killclient,     {0} },
	{ MODKEY,             			XK_BackSpace,	killclient,     {0} },
	{ MODKEY,                       XK_t, 			setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_Delete,		setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_KP_Right, 	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      		setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_End,   		setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_space,  		setlayout,      {0} },
//	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, {0} },
	{ MODKEY,             			XK_space,  		togglefloating, {0} },
	{ MODKEY,                       XK_0,      		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  		focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },

	{ MODKEY|ControlMask,			XK_Down,	moveresize,		{.v = (int []){ 0, 100, 0, 0 }}},
	{ MODKEY|ControlMask,			XK_Up,		moveresize,		{.v = (int []){ 0, -100, 0, 0 }}},
	{ MODKEY|ControlMask,			XK_Right,	moveresize,		{.v = (int []){ 100, 0, 0, 0 }}},
	{ MODKEY|ControlMask,			XK_Left,	moveresize,		{.v = (int []){ -100, 0, 0, 0 }}},
	{ MODKEY|ShiftMask,				XK_Down,	moveresize,		{.v = (int []){ 0, 0, 0, 100 }}},
	{ MODKEY|ShiftMask,				XK_Up,		moveresize,		{.v = (int []){ 0, 0, 0, -100 }}},
	{ MODKEY|ShiftMask,				XK_Right,	moveresize,		{.v = (int []){ 0, 0, 100, 0 }}},
	{ MODKEY|ShiftMask,				XK_Left,	moveresize,		{.v = (int []){ 0, 0, -100, 0 }}},





	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_F12,      quit,           {0} },
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

