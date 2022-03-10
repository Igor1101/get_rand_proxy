get_rand_proxy

simple program that gives random proxy address from file that
it downloads(by default file is choosen from conf.h but it can be given in argumenst).
format of data: X.X.X.X:X
Randomization:
    srand(time(NULL)+getpid());
so servers running this program even if start 
program in equal time will have different proxies.
in order to compile must be installed:

libcurl, gcc, make

arguments(all arguments are optional):
-u <url> alternative url to download file from
