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

#pragma once

#include <glib.h>

G_BEGIN_DECLS

/**
 * HackableError:
 * @HACKABLE_ERROR_INTERNAL_ERROR: Unrecoverable internal error
 *
 * Error enumeration for domain related errors.
 */
typedef enum {
  HACKABLE_ERROR_INTERNAL_ERROR
} HackableError;

#define HACKABLE_ERROR hackable_error_quark ()
GQuark hackable_error_quark (void);

G_END_DECLS
