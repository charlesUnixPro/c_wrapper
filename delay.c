main(argc, argv) 
  int argc;
  char * argv [];
{
  int i, code;
  struct iocb * iocbp = 0;

  struct delay_struct
    {
      int version;
      int dflt;
      struct delay
        {
          int vert_nl;
          float horz_nl;
          int const_tab;
          float var_tab;
          int backspace;
          int vt_ff;
        } delay;
    };

  struct delay_struct delays;

  delays.version = 1;
  delays.dflt = 0;
  delays.delay.vert_nl = 0;
  delays.delay.horz_nl = 0;
  delays.delay.const_tab = 0;
  delays.delay.var_tab = 0.0;
  delays.delay.backspace = 0;
  delays.delay.vt_ff = 0;

  c_iox_find_iocb ("user_output", & iocbp, & code);
  printf ("find_iocb code %d ptr %lo\n", code, iocbp);

  c_iox_control (iocbp, "get_delay", & delays, & code);
  if (code) c_com_err (code, "get_delay");

  printf ("old vert_nl %d\n", delays.delay.vert_nl);

  delays.delay.vert_nl ++;

  c_iox_control (iocbp, "set_delay", & delays, & code);
  if (code) c_com_err (code, "set_delay");

  return 0;
}
