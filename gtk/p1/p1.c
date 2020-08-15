#include <gtk/gtk.h>
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    /*
     若该回调函数返回 FALSE, GTK会发出 "destroy" 信号
     返回 TRUE, 你不希望关闭窗口
     返回 FALSE, 会调用destroy()关闭窗口
     */
    g_print("delete_event occurred\n");
    return TRUE;
    
}

void destroy(GtkWidget *widget, gpointer data) {
    // 退出
    gtk_main_quit();
}


int main(int argc, char **argv) {
    // GtkWidget 是构建的储存类型
    GtkWidget *window;
    GtkWidget *button;
    
    // 这个函数在所有GTK 程序中都要调用, 参数由命令中解析出来并且送到该程序中
    gtk_init(&argc, &argv);
    // 创建一个新的窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // 设置窗口标题
    gtk_window_set_title(GTK_WINDOW(window), "This is first gtk programa!");
    /*
     当窗口收到 "delete_event" 信号(这个信号窗口管理器发出, 通常是"关闭"
     若回调参数为NULL, 则回调函数会忽略
     */
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    
    // 创建新的按钮
    button = gtk_button_new_with_label("quit");
    // 点击按钮时, 触发gtk_widget_destroy()函数销毁widdow
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), window);
    // 添加按钮控件到窗口中
    gtk_container_add(GTK_CONTAINER(window), button);
    // 设置窗口容器 border 宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 250);

    // 显示创建的窗口和按钮
    gtk_widget_show(window);
    gtk_widget_show(button);
    /*
     * 所有的GTK程序必须有一个gtk_main()函数, 程序会在此进行循环
     */
    gtk_main();
    return 0;
    
}
