/*
   Recursos:
   http://zetcode.com/tutorials/gtktutorial/
   http://developer.gnome.org/gtk3/3.1/gtk-compiling.html
   http://developer.gnome.org/gtk/2.24/GtkTable.html#gtk-table-attach

   signal_connect(1,2,3,4), se llamara a callback como 3(1,4) cuando 2 se cumpla

   Compilar con:
   gcc gtk.c -o gtk `pkg-config --cflags --libs gtk+-3.0`
   Requiere paquetes: libgtk-3-dev libcanberra-gtk3-module
*/

#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define TITLE "GTK+3 Test"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define ABOUT_VERSION "vAlpha"
#define ABOUT_COPYRIGHT "Esteban De La Fuente"
#define ABOUT_COMMENTS "Ejemplo para el curso de Desarrollo de Aplicaciones Cliente Servidor en la Universidad Andrés Bello"
#define ABOUT_WEBSITE "http://unab.delaf.cl/irc234"

#define LAYERS 2
#define LAYER_ALUMNO_MOSTRAR 0
#define LAYER_ALUMNO_AGREGAR 1

// estructuras de datos
typedef struct {
	char title[100];
	char msg[100];
	GtkWindow *window;
} DialogArgs;

// variables globales
GtkWidget *layer[LAYERS];

// prototipos de funciones
GtkWidget *window_create();
void menubar_create (GtkWidget *window);
void layer_show (GtkWidget *widget, int id);
void about_show ();
void info_show (GtkWidget *widget, DialogArgs *args);
void error_show (GtkWidget *widget, DialogArgs *args);
void question_show (GtkWidget *widget, DialogArgs *args);
void warning_show (GtkWidget *widget, DialogArgs *args);
GdkPixbuf *pixbuf_create (const gchar *filename);

GtkWidget *alumnoMostrar_layer_create (GtkWidget *window, GtkWidget *container) {
	// crear capa
	GtkWidget *layer = gtk_table_new(3, 3, FALSE); // filas, columnas
	gtk_container_add(GTK_CONTAINER(container), layer);
	// labels
	GtkWidget *runLabel = gtk_label_new("Run");
	GtkWidget *nombreLabel = gtk_label_new("Nombre");
	GtkWidget *apellidoLabel = gtk_label_new("Apellido");
	// posicionar objetos en la capa
	gtk_table_attach(GTK_TABLE(layer), runLabel, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), nombreLabel, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), apellidoLabel, 2, 3, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	
	int i;
	for(i=0; i<2; ++i) {
		char run[10]; sprintf(run, "run_%d", i);
		char nombre[10]; sprintf(nombre, "nombre_%d", i);
		char apellido[10]; sprintf(apellido, "apellido_%d", i);
		GtkWidget *runEntry = gtk_label_new(run);
		GtkWidget *nombreEntry = gtk_label_new(nombre);
		GtkWidget *apellidoEntry = gtk_label_new(apellido);
		gtk_table_attach(GTK_TABLE(layer), runEntry, 0, 1, i+1, i+2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
		gtk_table_attach(GTK_TABLE(layer), nombreEntry, 1, 2, i+1, i+2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
		gtk_table_attach(GTK_TABLE(layer), apellidoEntry, 2, 3, i+1, i+2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	}
	
	// retornar capa
	return layer;
}

void alumnoGuardar (GtkWidget *widget, GtkWidget *runEntry) {
	printf("Guardando Alumno: run=%i\n", atoi(gtk_entry_get_text(GTK_ENTRY(runEntry))));
}


GtkWidget *alumnoAgregar_layer_create (GtkWidget *window, GtkWidget *container) {
	// crear capa
	GtkWidget *layer = gtk_table_new(4, 2, FALSE); // filas, columnas
	gtk_container_add(GTK_CONTAINER(container), layer);
	// labels
	GtkWidget *runLabel = gtk_label_new("Run");
	GtkWidget *nombreLabel = gtk_label_new("Nombre");
	GtkWidget *apellidoLabel = gtk_label_new("Apellido");
	// entrys
	GtkWidget *runEntry = gtk_entry_new();
	GtkWidget *nombreEntry = gtk_entry_new();
	GtkWidget *apellidoEntry = gtk_entry_new();
	// botones
	GtkWidget *submit = gtk_button_new_with_label("Guardar");
	// posicionar objetos en la capa
	gtk_table_attach(GTK_TABLE(layer), runLabel, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), nombreLabel, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), apellidoLabel, 0, 1, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), runEntry, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), nombreEntry, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), apellidoEntry, 1, 2, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(layer), submit, 1, 2, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	// guardar
	g_signal_connect(G_OBJECT(submit), "clicked", G_CALLBACK(alumnoGuardar), (GtkWidget *) runEntry);
/*	DialogArgs dialogArgs;
	bzero(&dialogArgs, sizeof(dialogArgs));
	strcpy(dialogArgs.title, "Título");
	strcpy(dialogArgs.msg, "Esto es un mensaje");
	dialogArgs.window = (GtkWindow *) window;
	g_signal_connect(G_OBJECT(submit), "clicked", G_CALLBACK(info_show), (gpointer) &dialogArgs);*/
	// retornar capa
	return layer;
}

int main (int argc, char **argv) {
	// iniciar GTK
	gtk_init(&argc, &argv);
	// crear ventana y mostrarla
	GtkWidget *window = window_create();
	gtk_widget_show(window);
	// crear contenedor principal y mostrarlo
	GtkWidget *mainContainer = gtk_vbox_new(FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), mainContainer);
	gtk_widget_show(mainContainer);
	// crear barra de menu
	menubar_create(mainContainer);
	// crear layers
	layer[LAYER_ALUMNO_MOSTRAR] = alumnoMostrar_layer_create(window, mainContainer);
	layer[LAYER_ALUMNO_AGREGAR] = alumnoAgregar_layer_create(window, mainContainer);
	// crear loop
	gtk_main();
	// retorno al sistema
	return EXIT_SUCCESS;
}

GtkWidget *window_create () {
	// variable para la ventana
	GtkWidget *window;
	// crear ventana con barra de titulo y bordes
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// colocar titulo a la ventana
	gtk_window_set_title(GTK_WINDOW(window), TITLE);
	// colocar tamaño por defecto
	gtk_window_set_default_size(GTK_WINDOW(window), SCREEN_WIDTH, SCREEN_HEIGHT);
	// ubicar ventana en la pantalla
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	// terminara la aplicacion cuando se presione la X
	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	// agregar icono a la aplicacion
	gtk_window_set_icon(GTK_WINDOW(window), pixbuf_create("data/image/icon.png"));
	// retornar ventana
	return window;
}

void menubar_create (GtkWidget *container) {
	// contenedor para la barra de menu
	GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(container), vbox);
	// barra de menu
	GtkWidget *menubar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);
	/// menu file
	GtkWidget *filemenubutton = gtk_menu_item_new_with_label("Archivo");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), filemenubutton);
	GtkWidget *filemenu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(filemenubutton), filemenu);
	// opciones
	GtkWidget *quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
	g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
	/// menu acciones
	GtkWidget *actionsmenubutton = gtk_menu_item_new_with_label("Acciones");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), actionsmenubutton);
	GtkWidget *actionsmenu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(actionsmenubutton), actionsmenu);
	/// submenu acciones -> alumno
	GtkWidget *alumnomenubutton = gtk_menu_item_new_with_label("Alumno");
	gtk_menu_shell_append(GTK_MENU_SHELL(actionsmenu), alumnomenubutton);
	GtkWidget *alumnomenu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(alumnomenubutton), alumnomenu);
	// opciones
	GtkWidget *alumnoMostrar = gtk_menu_item_new_with_label("Mostrar");
	gtk_menu_shell_append(GTK_MENU_SHELL(alumnomenu), alumnoMostrar);
	g_signal_connect(G_OBJECT(alumnoMostrar), "activate", G_CALLBACK(layer_show), (gpointer) LAYER_ALUMNO_MOSTRAR);
	GtkWidget *alumnoAgregar = gtk_image_menu_item_new_from_stock(GTK_STOCK_ADD, NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(alumnomenu), alumnoAgregar);
	g_signal_connect(G_OBJECT(alumnoAgregar), "activate", G_CALLBACK(layer_show), (gpointer) LAYER_ALUMNO_AGREGAR);
	/// menu ayuda
	GtkWidget *helpmenubutton = gtk_menu_item_new_with_label("Ayuda");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), helpmenubutton);
	GtkWidget *helpmenu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpmenubutton), helpmenu);
	// opciones
	GtkWidget *help = gtk_menu_item_new_with_label("Ayuda");
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), help);
	GtkWidget *about = gtk_menu_item_new_with_label("Acerca de...");
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);
	g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(about_show), NULL);
	/// mostrar menubar
	gtk_widget_show_all(vbox);
}

void layer_show (GtkWidget *widget, int id) {
	int i;
	for(i=0; i<LAYERS; ++i)
		gtk_widget_hide(layer[i]);
	gtk_widget_show_all(layer[id]);
}

void about_show () {
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("data/image/logo.png", NULL);
	GtkWidget *dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), ABOUT_VERSION);
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), ABOUT_COPYRIGHT);
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), ABOUT_COMMENTS);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), ABOUT_WEBSITE);
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
	g_object_unref(pixbuf), pixbuf = NULL;
	gtk_dialog_run(GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);
}

void info_show (GtkWidget *widget, DialogArgs *args) {
	GtkWidget *dialog = gtk_message_dialog_new(
		args->window,
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK,
		args->msg
	);
	gtk_window_set_title(GTK_WINDOW(dialog), args->title);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void error_show (GtkWidget *widget, DialogArgs *args) {
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(
		args->window,
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_ERROR,
		GTK_BUTTONS_OK,
		args->msg
	);
	gtk_window_set_title(GTK_WINDOW(dialog), args->title);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void question_show (GtkWidget *widget, DialogArgs *args) {
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(
		args->window,
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_QUESTION,
		GTK_BUTTONS_YES_NO,
		args->msg
	);
	gtk_window_set_title(GTK_WINDOW(dialog), args->title);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void warning_show (GtkWidget *widget, DialogArgs *args) {
	GtkWidget *dialog = gtk_message_dialog_new(
		args->window,
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_WARNING,
		GTK_BUTTONS_OK,
		args->msg
	);
	gtk_window_set_title(GTK_WINDOW(dialog), args->title);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

GdkPixbuf *pixbuf_create (const gchar *filename) {
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if(!pixbuf) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}
