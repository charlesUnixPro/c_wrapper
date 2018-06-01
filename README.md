# c\_wrapper

Multics library wrappers for 'cc'

Note:

Strings are assumed to be less then 2^16 bytes long.


```void c_ioa (char * control_string)

Degenerate wrapper for "ioa_"; only a single parameter.



void c_com_err (int code, char * control_string)

Degenerate wrapper for "com_err_"; only two parameters.



c_iox_attach_name (char * switch_name, struct iocb * *, char * atd,
                   void * ref_proc, int * code) 

Wrapper for "iox_$attach_name".



c_iox_close (struct iocb * iocb, int * code)

Wrapper for "iox_$close".



c_iox_close_file (struct iocb * iocb, char * cld, int * code)

Wrapper for "iox_$close_file".



c_iox_control (struct iocb * iocb, char * order, struct info * info,
               int * code)

Wrapper for "iox_$control".



c_iox_find_iocb (char * switch_name, struct iocb * * iocb, int * code)

Wrapper for "iox_$find_iocb".



c_iox_modes (struct iocb * iocb, char * new_modes, char * old_modes, int * code) 
Wrapper for "iox_$modes".
"old_modes" is assumed to be allocated "char[512]";


c_iox_put_chars (struct iocb * iocb, char * buf, int n, int * code)

Wrapper for "iox_$put_chars".



```
