typedef struct ircserver
{
	char *hostname;
} ircserver;

typedef struct ircnet
{
	char *name;
	char *nick;
	char *user;
	char *real;
	char *pass;
	char *autojoin;
	char *command;
	char *comment;
	GSList *servlist;
	int selected;
	guint32 flags;
} ircnet;

extern GSList *network_list;

#define FLAG_CYCLE				1
#define FLAG_USE_GLOBAL			2
#define FLAG_USE_SSL				4
#define FLAG_AUTO_CONNECT		8
#define FLAG_USE_PROXY			16
#define FLAG_ALLOW_INVALID		32
#define FLAG_COUNT				6

void servlist_init (void);
void servlist_save (void);
int servlist_cycle (server *serv);
void servlist_connect (session *sess, ircnet *net);
int servlist_auto_connect (session *sess);

ircnet *servlist_net_add (char *name, char *comment);
void servlist_net_remove (ircnet *net);
ircnet *servlist_net_find (char *name, int *pos);

void servlist_server_remove (ircnet *net, ircserver *serv);
void servlist_server_remove_all (ircnet *net);
ircserver *servlist_server_add (ircnet *net, char *name);
ircserver *servlist_server_find (ircnet *net, char *name, int *pos);
