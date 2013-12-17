typedef void (*ProcessFinishCallback)	(gint		pid_result,
					 gboolean	localwatchdog,
					 gpointer	user_data);

#define RESTRAINT_PROCESS_ERROR restraint_process_error()
GQuark restraint_process_error(void);

typedef enum {
    RESTRAINT_PROCESS_FORK_ERROR,
} RestraintProcessError;

typedef struct {
    // Command to run
    const gchar **command;
    // Environment to use
    const gchar **environ;
    // The path to chdir before executing
    const gchar *path;
    guint64 max_time;
} CommandData;

typedef struct {
    CommandData *command_data;
    // pid of our forked process
    pid_t pid;
    // file descriptor of our pty
    gint fd;
    // return code result from command
    gint pid_result;
    // id of the io handler
    guint io_handler_id;
    // id of the pid handler
    guint pid_handler_id;
    // id of the timeout handler
    guint timeout_handler_id;
    // True if localwatch kicked in for this process
    gboolean localwatchdog;
    // next handler to call.
    ProcessFinishCallback finish_callback;
    gpointer user_data;
    GError *error;
} ProcessData;

gboolean process_run (CommandData *command_data,
                      GIOFunc io_callback,
                      ProcessFinishCallback finish_callback,
                      gpointer user_data,
                      GError **error);
//gboolean process_io_callback (GIOChannel *io, GIOCondition condition, gpointer user_data);
void process_pid_callback (GPid pid, gint status, gpointer user_data);
void process_pid_finish (gpointer user_data);
gboolean process_timeout_callback (gpointer user_data);
//gboolean process_heartbeat_callback (gpointer user_data);
void process_free (ProcessData *process_data);

extern char **environ;
int    kill(pid_t, int);