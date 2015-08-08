/*
 * Header file to make compatibility with older GTK versions less
 * painful, by #defining various things that are pure spelling changes
 * between GTK1 and GTK2.
 */

#if !GTK_CHECK_VERSION(2,0,0)

#include <ctype.h>
#include <X11/X.h>

/* Helper macro used in definitions below. Note that although it
 * *expands* w and flag twice, it does not *evaluate* them twice
 * because the evaluations are in exclusive branches of ?:. So it's
 * a side-effect-safe macro. */
#define gtk1_widget_set_unset_flag(w, flag, b)                    \
    ((b) ? GTK_WIDGET_SET_FLAGS(w, flag) : GTK_WIDGET_UNSET_FLAGS(w, flag))

#define G_CALLBACK(x) GTK_SIGNAL_FUNC(x)
#define G_OBJECT(x) GTK_OBJECT(x)

#define g_ascii_isspace(x) (isspace((unsigned char)(x)))
#define g_signal_connect gtk_signal_connect
#define g_object_set_data gtk_object_set_data

#define GDK_GRAB_SUCCESS GrabSuccess

#define gtk_widget_set_size_request gtk_widget_set_usize

#define gtk_dialog_get_content_area(dlg) ((dlg)->vbox)
#define gtk_dialog_get_action_area(dlg) ((dlg)->action_area)
#define gtk_dialog_set_can_default(dlg) ((dlg)->action_area)
#define gtk_widget_get_window(w) ((w)->window)
#define gtk_widget_get_parent(w) ((w)->parent)
#define gtk_widget_set_allocation(w, a) ((w)->allocation = *(a))
#define gtk_container_get_border_width(c) ((c)->border_width)
#define gtk_bin_get_child(b) ((b)->child)
#define gtk_color_selection_dialog_get_color_selection(cs) ((cs)->colorsel)
#define gtk_selection_data_get_target(sd) ((sd)->target)
#define gtk_selection_data_get_data_type(sd) ((sd)->type)
#define gtk_selection_data_get_data(sd) ((sd)->data)
#define gtk_selection_data_get_length(sd) ((sd)->length)
#define gtk_selection_data_get_format(sd) ((sd)->format)
#define gtk_adjustment_set_lower(a, val) ((a)->lower = (val))
#define gtk_adjustment_set_upper(a, val) ((a)->upper = (val))
#define gtk_adjustment_set_page_size(a, val) ((a)->page_size = (val))
#define gtk_adjustment_set_page_increment(a, val) ((a)->page_increment = (val))
#define gtk_adjustment_set_step_increment(a, val) ((a)->step_increment = (val))
#define gtk_adjustment_get_value(a) ((a)->value)
#define gdk_visual_get_depth(v) ((v)->depth)

#define gtk_widget_set_has_window(w, b)                 \
    gtk1_widget_set_unset_flag(w, GTK_NO_WINDOW, !(b))
#define gtk_widget_set_mapped(w, b)                     \
    gtk1_widget_set_unset_flag(w, GTK_MAPPED, (b))
#define gtk_widget_set_can_default(w, b)                \
    gtk1_widget_set_unset_flag(w, GTK_CAN_DEFAULT, (b))
#define gtk_widget_get_visible(w) GTK_WIDGET_VISIBLE(w)
#define gtk_widget_get_mapped(w) GTK_WIDGET_MAPPED(w)
#define gtk_widget_get_realized(w) GTK_WIDGET_REALIZED(w)
#define gtk_widget_get_state(w) GTK_WIDGET_STATE(w)

#define GDK_KEY_Alt_L                GDK_Alt_L
#define GDK_KEY_Alt_R                GDK_Alt_R
#define GDK_KEY_BackSpace            GDK_BackSpace
#define GDK_KEY_Begin                GDK_Begin
#define GDK_KEY_Break                GDK_Break
#define GDK_KEY_Delete               GDK_Delete
#define GDK_KEY_Down                 GDK_Down
#define GDK_KEY_End                  GDK_End
#define GDK_KEY_Escape               GDK_Escape
#define GDK_KEY_F10                  GDK_F10
#define GDK_KEY_F11                  GDK_F11
#define GDK_KEY_F12                  GDK_F12
#define GDK_KEY_F13                  GDK_F13
#define GDK_KEY_F14                  GDK_F14
#define GDK_KEY_F15                  GDK_F15
#define GDK_KEY_F16                  GDK_F16
#define GDK_KEY_F17                  GDK_F17
#define GDK_KEY_F18                  GDK_F18
#define GDK_KEY_F19                  GDK_F19
#define GDK_KEY_F1                   GDK_F1
#define GDK_KEY_F20                  GDK_F20
#define GDK_KEY_F2                   GDK_F2
#define GDK_KEY_F3                   GDK_F3
#define GDK_KEY_F4                   GDK_F4
#define GDK_KEY_F5                   GDK_F5
#define GDK_KEY_F6                   GDK_F6
#define GDK_KEY_F7                   GDK_F7
#define GDK_KEY_F8                   GDK_F8
#define GDK_KEY_F9                   GDK_F9
#define GDK_KEY_Home                 GDK_Home
#define GDK_KEY_Insert               GDK_Insert
#define GDK_KEY_ISO_Left_Tab         GDK_ISO_Left_Tab
#define GDK_KEY_KP_0                 GDK_KP_0
#define GDK_KEY_KP_1                 GDK_KP_1
#define GDK_KEY_KP_2                 GDK_KP_2
#define GDK_KEY_KP_3                 GDK_KP_3
#define GDK_KEY_KP_4                 GDK_KP_4
#define GDK_KEY_KP_5                 GDK_KP_5
#define GDK_KEY_KP_6                 GDK_KP_6
#define GDK_KEY_KP_7                 GDK_KP_7
#define GDK_KEY_KP_8                 GDK_KP_8
#define GDK_KEY_KP_9                 GDK_KP_9
#define GDK_KEY_KP_Add               GDK_KP_Add
#define GDK_KEY_KP_Begin             GDK_KP_Begin
#define GDK_KEY_KP_Decimal           GDK_KP_Decimal
#define GDK_KEY_KP_Delete            GDK_KP_Delete
#define GDK_KEY_KP_Divide            GDK_KP_Divide
#define GDK_KEY_KP_Down              GDK_KP_Down
#define GDK_KEY_KP_End               GDK_KP_End
#define GDK_KEY_KP_Enter             GDK_KP_Enter
#define GDK_KEY_KP_Home              GDK_KP_Home
#define GDK_KEY_KP_Insert            GDK_KP_Insert
#define GDK_KEY_KP_Left              GDK_KP_Left
#define GDK_KEY_KP_Multiply          GDK_KP_Multiply
#define GDK_KEY_KP_Page_Down         GDK_KP_Page_Down
#define GDK_KEY_KP_Page_Up           GDK_KP_Page_Up
#define GDK_KEY_KP_Right             GDK_KP_Right
#define GDK_KEY_KP_Subtract          GDK_KP_Subtract
#define GDK_KEY_KP_Up                GDK_KP_Up
#define GDK_KEY_Left                 GDK_Left
#define GDK_KEY_Meta_L               GDK_Meta_L
#define GDK_KEY_Meta_R               GDK_Meta_R
#define GDK_KEY_Num_Lock             GDK_Num_Lock
#define GDK_KEY_Page_Down            GDK_Page_Down
#define GDK_KEY_Page_Up              GDK_Page_Up
#define GDK_KEY_Return               GDK_Return
#define GDK_KEY_Right                GDK_Right
#define GDK_KEY_Tab                  GDK_Tab
#define GDK_KEY_Up                   GDK_Up

#endif

