main() { 
  struct iocb * iocbp = 0;
  struct ref_ptr * refp = 0;
  int code;
  char * buf = "Multics iox_$put_chars Rulez, UNIX Droolz";

  c_ioa("Multics Rulez, UNIX Droolz");

/*
  c_iox_find_iocb ("net_disk", & iocbp, & code);
  printf ("find_iocb code %d ptr %lo\n", code, iocbp);
*/

/*
  c_iox_attach_name ("net_disk", & iocbp, "rdisk_ d501 net_disk -dv dskb_01 -write", & refp, & code);
  printf ("attach_name code %d\n", code);
  if (code) c_com_err (code, "attach_name");
*/

/*
  c_iox_attach_name ("net_disk", & iocbp, "syn_ user_i/o -inh close put_chars", & refp, & code);
  printf ("attach_name code %d\n", code);
  if (code) c_com_err (code, "attach_name");
*/

/*
  c_iox_attach_ptr (iocbp, "syn_ user_i/o -inh close put_chars", & refp, & code);
  printf ("attach_ptr code %d\n", code);
  if (code) c_com_err (code, "attach_ptr");

  c_iox_close (iocbp, & code);
  if (code) c_com_err (code, "close");
*/

  c_iox_find_iocb ("user_output", & iocbp, & code);
  printf ("find_iocb code %d ptr %lo\n", code, iocbp);
  c_iox_put_chars (iocbp, buf, strlen (buf), & code);
  if (code) c_com_err (code, "put_chars");
  return 0;
}
