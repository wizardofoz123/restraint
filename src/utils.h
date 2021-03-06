/*  
    This file is part of Restraint.

    Restraint is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Restraint is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Restraint.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __UTILS_H
#define __UTILS_H

#include <glib.h>
#define BASE10 10

guint64 parse_time_string (gchar *time_string, GError **error);
gboolean file_exists (gchar *filename);
void cmd_usage(GOptionContext *context);
gchar *get_package_version(gchar *pkg_name, GError **error);
void set_rstrnt_cmd_env(void);
gchar *get_taskid (void);
gchar *get_recipe_url (void);

#endif
