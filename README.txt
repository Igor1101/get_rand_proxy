get_rand_proxy
проста програма, яка дає випадкову адресу проксі з файлу that
він завантажується (за замовчуванням файл вибирається з conf.h, але його можна вказати в argumenst).
формат даних: X.X.X.X:X
Рандомізація:
     srand(time(NULL)+getpid());
тому сервери, на яких запущена ця програма, навіть якщо запущена
програма в один і той же час, матиме різні проксі.
для компіляції необхідно встановити:

libcurl, gcc, make

аргументи (усі аргументи необов'язкові):
-u <url> альтернативна URL-адреса для завантаження файлу
приклад використання:
docker run --env http_proxy="http://$(./get_rand_proxy)" --env https_proxy="http://$(./get_rand_proxy)" nginx sh -c "curl google.com"

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
example of use:
docker run --env http_proxy="http://$(./get_rand_proxy)" --env https_proxy="http://$(./get_rand_proxy)"     nginx sh -c "curl google.com"
