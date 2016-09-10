int main (int argc, char **argv)
{
	struct input cmd;
	cmd.blur = 0;
  cmd.sharpen = 0;
  cmd.fname = NULL;

	int c;
  opterr = 0;
  while ((c = getopt (argc, argv, "bsf:")) != -1)
    switch (c)
      {
      case 'b':
        cmd.blur = 1;
        break;
      case 's':
        cmd.sharpen = 1;
        break;
      case 'f':
        cmd.fname = optarg;
        break;
      case '?':
        if (optopt == 'f')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  printf ("blur = %d, sharpen = %d, filename = %s\n",
          cmd.blur, cmd.sharpen, cmd.fname);

  for (int i = optind; i < argc; i++)
    printf ("Non-option argument %s\n", argv[i]);
  return 0;
}
