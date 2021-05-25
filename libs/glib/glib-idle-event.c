#include <glib.h>

#include "util/util.h"

static int count = 0;
/* 空闲时执行 */
static gboolean idle_func(gpointer data)
{
	g_print("%d : %s : %ld\n", ++count, (gchar *)data, get_time_usec());

	return TRUE;
}

int main(void)
{
	GMainLoop *loop = g_main_loop_new(NULL, TRUE);
	GMainContext *context = g_main_loop_get_context(loop);

	g_idle_add(idle_func, "Glib idle event");
	g_main_loop_run(loop);
	g_main_context_unref(context);
	g_main_loop_unref(loop);

	return 0;
}
