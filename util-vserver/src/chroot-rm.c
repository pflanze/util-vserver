// $Id$    --*- c -*--

// Copyright (C) 2003,2004 Enrico Scholz <enrico.scholz@informatik.tu-chemnitz.de>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "util.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define ENSC_WRAPPERS_PREFIX "chroot-rm: "
#define ENSC_WRAPPERS_UNISTD 1
#include <wrappers.h>

int	wrapper_exit_code = 1;

static void
showHelp(char const *cmd)
{
  WRITE_MSG(1, "Usage:  ");
  WRITE_STR(1, cmd);
  WRITE_MSG(1,
	    " [--] <files>+\n\n"
	    "This program removes <files> by assuming the current directory\n"
	    "as a chroot directory.\n\n"
	    "Please report bugs to " PACKAGE_BUGREPORT "\n");
  exit(0);
}

static void
showVersion()
{
  WRITE_MSG(1,
	    "chroot-rm " VERSION " -- removes files under current directory\n"
	    "This program is part of " PACKAGE_STRING "\n\n"
	    "Copyright (C) 2003,2004 Enrico Scholz\n"
	    VERSION_COPYRIGHT_DISCLAIMER);
  exit(0);
}

int main(int argc, char *argv[])
{
  int		res = EXIT_SUCCESS;
  int		idx = 1;

  if (argc>1) {
    if (strcmp(argv[1], "--help")   ==0) showHelp(argv[0]);
    if (strcmp(argv[1], "--version")==0) showVersion();
    if (strcmp(argv[1], "--")==0)        ++idx;
  }

  if (idx==argc) {
    WRITE_MSG(2, "No files given; use '--help' for more information\n");
    return EXIT_FAILURE;
  }

  Echroot(".");
  
  for (; idx<argc; ++idx) {
    if (unlink(argv[idx])==-1) {
      PERROR_Q(ENSC_WRAPPERS_PREFIX "unlink", argv[idx]);
      res = EXIT_FAILURE;
    }
  }

  return res;
}
