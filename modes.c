main(argc, argv) 
  int argc;
  char * argv [];
{
  /* char * new_modes = "ll132"; */
  char old_modes [513];
  int i, code;
  struct iocb * iocbp = 0;

  c_iox_find_iocb ("user_output", & iocbp, & code);
  printf ("find_iocb code %d ptr %lo\n", code, iocbp);
  c_iox_modes (iocbp, argv[1], old_modes, & code);
  printf ("modes code %d\n", code);
  if (code) c_com_err (code, "modes");
  old_modes [512] = 0;
  for (i = 511; i >= 0; i --)
    if (old_modes[i] != ' ')
      break;
  old_modes[i+1] = 0;
  printf ("old <%s>\n", old_modes);
  return 0;
}
