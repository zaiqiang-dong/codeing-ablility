#include <glib.h>
#include <glib/gprintf.h>
#include "util//util.h"

typedef struct _MySource MySource;
static int count = 0;
struct _MySource
{
	GSource source;
	gchar text[256];
};

static gboolean prepare(GSource *source, gint *timeout)
{
	g_print("%s : called.\n", __FUNCTION__);
	*timeout = 0;

	return TRUE;
}

static gboolean check(GSource *source)
{
	g_print("%s : called.\n", __FUNCTION__);
	return TRUE;
}

static gboolean dispatch(GSource *source, GSourceFunc callback, gpointer user_data)
{
	g_print("%s : called.\n", __FUNCTION__);
	MySource *mysource = (MySource *)source;

	g_print("%d : %s :%ld\n", ++count, mysource->text, get_time_usec());

	return TRUE;
}

static void finalize(GSource *source)
{
	g_print("%s : called.\n", __FUNCTION__);
}


int main(void)
{
	GMainLoop *loop = g_main_loop_new(NULL, TRUE);
	GMainContext *context = g_main_loop_get_context(loop);
	GSourceFuncs source_funcs = {prepare, check, dispatch, finalize};
	GSource *source = g_source_new(&source_funcs, sizeof(MySource));

	/* 设置自定义事件数据 */
	g_sprintf(((MySource *)source)->text, "Glib idle diy event");
	g_source_attach(source, context);
	g_source_unref(source);

	g_main_loop_run(loop);

	g_main_context_unref(context);
	g_main_loop_unref(loop);

	return 0;
}
