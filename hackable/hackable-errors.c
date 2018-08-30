/* Copyright 2018 Endless Mobile, Inc.
 *
 * libhackable is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * libhackable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with eos-discovery-feed.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors:
 * - Sam Spilsbury <sam@endlessm.com>
 */

#include <gio/gio.h>

#include "hackable-errors.h"

static const GDBusErrorEntry hackable_error_entries[] =
{
  { HACKABLE_ERROR_INTERNAL_ERROR, "com.endlessm.Hackable.InternalError" }
};

GQuark
hackable_error_quark (void)
{
  static volatile gsize quark_volatile = 0;
  g_dbus_error_register_error_domain ("animation-dbus-error-quark",
                                      &quark_volatile,
                                      hackable_error_entries,
                                      G_N_ELEMENTS (hackable_error_entries));

  return (GQuark) quark_volatile;
}
