/*
  File autogenerated by gengetopt version 2.7.1
  generated with the following command:
  /usr/bin/gengetopt --input cmdline.sh 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
/* Check for configure's getopt check result.  */
#ifndef HAVE_GETOPT_LONG
#include "lib/getopt.h"
#else
#include <getopt.h>
#endif

#ifndef HAVE_STRDUP
#define strdup gengetopt_strdup
#endif /* HAVE_STRDUP */

#include "cmdline.h"


void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", PACKAGE, VERSION);
}

void
cmdline_parser_print_help (void)
{
  cmdline_parser_print_version ();
  printf("\n"
  "Purpose:\n"
  "  The Ganglia Meta Daemon (gmetad) collects information from\n"
  "  multiple gmond or gmetad data sources, saves the information to local\n"
  "  round-robin databases, and exports XML which is the concatentation of\n"
  "  all data sources\n"
  "\n"
  "Usage: %s [OPTIONS]...\n", PACKAGE);
  printf("   -h         --help         Print help and exit\n");
  printf("   -V         --version      Print version and exit\n");
  printf("   -cSTRING   --conf=STRING  Location of gmetad configuration file (default='/etc/gmetad.conf')\n");
  printf("   -dINT      --debug=INT    Debug level. If greater than zero, daemon will stay in foreground. (default=0)\n");
}


#ifndef HAVE_STRDUP
/* gengetopt_strdup(): automatically generated from strdup.c. */
/* strdup.c replacement of strdup, which is not standard */
static char *
gengetopt_strdup (const char *s)
{
  char *result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}
#endif /* HAVE_STRDUP */

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  int c;	/* Character of the parsed option.  */
  int missing_required_options = 0;	

  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->conf_given = 0 ;
  args_info->debug_given = 0 ;
#define clear_args() { \
  args_info->conf_arg = strdup("/etc/gmetad.conf") ;\
  args_info->debug_arg = 0 ;\
}

  clear_args();

  optarg = 0;
  optind = 1;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "conf",	1, NULL, 'c' },
        { "debug",	1, NULL, 'd' },
        { NULL,	0, NULL, 0 }
      };

      c = getopt_long (argc, argv, "hVc:d:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          clear_args ();
          cmdline_parser_print_help ();
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          clear_args ();
          cmdline_parser_print_version ();
          exit (EXIT_SUCCESS);

        case 'c':	/* Location of gmetad configuration file.  */
          if (args_info->conf_given)
            {
              fprintf (stderr, "%s: `--conf' (`-c') option given more than once\n", PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->conf_given = 1;
          args_info->conf_arg = strdup (optarg);
          break;

        case 'd':	/* Debug level. If greater than zero, daemon will stay in foreground..  */
          if (args_info->debug_given)
            {
              fprintf (stderr, "%s: `--debug' (`-d') option given more than once\n", PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->debug_given = 1;
          args_info->debug_arg = atoi (optarg);
          break;


        case 0:	/* Long option with no short option */

        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          exit (EXIT_FAILURE);

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c\n", PACKAGE, c);
          abort ();
        } /* switch */
    } /* while */

  if ( missing_required_options )
    exit (EXIT_FAILURE);

  return 0;
}
