#include "ft_printf.h"

/*
** ft_formats: Processa os diferentes formatos do printf.
** Chama a função correspondente ao tipo de formato especificado.
**
** args: Lista de argumentos fornecida pelo va_list.
** format: O caractere que indica o formato (ex.: 'c', 's', 'd', etc.).
**
** Retorna o número de caracteres impressos pela função correspondente.
*/
int ft_formats(va_list args, const char format)
{
    int i;

    i = 0; // Inicializa o contador de caracteres impressos
    if (format == 'c') 
        i += ft_printchar(va_arg(args, int)); // Imprime um caractere
    else if (format == 's') 
        i += ft_printstr(va_arg(args, char *)); // Imprime uma string
    else if (format == 'p') 
        i += ft_printptr(va_arg(args, void *)); // Imprime um ponteiro
    else if (format == 'd' || format == 'i') 
        i += ft_printnbr(va_arg(args, int)); // Imprime um número inteiro
    else if (format == 'u') 
        i += ft_printunsigned(va_arg(args, unsigned int)); // Imprime número sem sinal
    else if (format == 'x') 
        i += ft_printhex_lower(va_arg(args, unsigned int)); // Hexadecimal minúsculo
    else if (format == 'X') 
        i += ft_printhex_upper(va_arg(args, unsigned int)); // Hexadecimal maiúsculo
    else if (format == '%') 
        i += ft_printpercent(); // Imprime '%'
    return (i); // Retorna o total de caracteres impressos
}

/*
** ft_printf: Implementa a funcionalidade do printf.
** Percorre a string de entrada e processa os formatos indicados.
**
** str: String de formato contendo texto e especificadores de formato.
**
** Retorna o número total de caracteres impressos.
*/
int ft_printf(const char *str, ...)
{
    va_list args;  // Lista de argumentos variáveis
    int count;     // Contador total de caracteres impressos
    int i;         // Índice para percorrer a string

    count = 0;
    va_start(args, str); // Inicializa os argumentos variáveis
    i = 0;

    while (str[i]) // Percorre a string até o final
    {
        if (str[i] == '%') // Identifica especificadores de formato
        {
            i++;
            if (str[i])
                count += ft_formats(args, str[i]); // Processa o formato
            else
                break; // Caso de formato incompleto
        }
        else
            count += ft_printchar(str[i]); // Imprime caracteres literais
        i++;
    }

    va_end(args); // Libera a memória da lista de argumentos
    return (count); // Retorna o número total de caracteres impressos
}

/*
** ft_printhex_lower: Imprime um número em hexadecimal com letras minúsculas.
**
** n: Número a ser convertido para hexadecimal.
**
** Retorna o número total de caracteres impressos.
*/
int ft_printhex_lower(unsigned long n)
{
    if (n >= 16)
        return (ft_printhex_lower(n / 16) + \
                ft_printchar("0123456789abcdef"[n % 16]));
    return (ft_printchar("0123456789abcdef"[n]));
}

/*
** ft_printptr: Imprime um ponteiro em formato hexadecimal.
**
** p: Ponteiro a ser impresso.
**
** Retorna o número total de caracteres impressos.
*/
int ft_printptr(void *p)
{
    unsigned long add;
    int len;

    if (p == NULL)
    {
        ft_printstr("(nil)");
        return (5);
    }
    add = (unsigned long)p;
    ft_printstr("0x"); // Prefixo de ponteiro
    len = ft_printhex_lower(add); // Imprime o endereço em hexadecimal
    return (len + 2); // Adiciona o comprimento do prefixo "0x"
}

/*
** ft_utoa: Converte um número inteiro sem sinal em uma string.
**
** n: Número inteiro sem sinal a ser convertido.
**
** Retorna a string resultante ou NULL em caso de erro.
*/
char *ft_utoa(unsigned int n)
{
    char *str;
    unsigned int tmp;
    int len;

    tmp = n;
    len = 1;
    while (tmp > 9) // Calcula o número de dígitos
    {
        tmp /= 10;
        len++;
    }
    str = malloc(len + 1); // Aloca memória para a string
    if (str == NULL)
        return (NULL);
    str[len] = '\0'; // Finaliza a string
    while (len--) // Converte os dígitos para caracteres
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

/*
** ft_printunsigned: Imprime um número inteiro sem sinal.
**
** n: Número a ser impresso.
**
** Retorna o número total de caracteres impressos.
*/
int ft_printunsigned(int n)
{
    unsigned int num;
    char *str;
    int len;

    num = (unsigned int)n;
    str = ft_utoa(num); // Converte o número para string
    if (str == NULL)
        return (0);
    len = ft_printstr(str); // Imprime a string
    free(str); // Libera a memória da string
    return (len);
}

/*
** ft_printchar: Imprime um único caractere.
**
** c: Caractere a ser impresso.
**
** Retorna 1 (o número de caracteres impressos).
*/
int ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

/*
** ft_printstr: Imprime uma string.
**
** str: Ponteiro para a string a ser impressa.
**
** Retorna o número de caracteres impressos.
*/
int ft_printstr(char *str)
{
    int len;

    if (str == NULL) // Trata strings nulas
    {
        write(1, "(null)", 6);
        return (6);
    }
    len = ft_strlen(str);
    write(1, str, len);
    return (len);
}

/*
** ft_printnbr: Imprime um número inteiro.
**
** n: Número a ser impresso.
**
** Retorna o número de caracteres impressos.
*/
int ft_printnbr(int n)
{
    int len;
    char *num;

    num = ft_itoa(n); // Converte o número para string
    len = ft_printstr(num); // Imprime a string
    free(num); // Libera a memória da string
    return (len);
}

/*
** ft_printpercent: Imprime o caractere '%'.
**
** Retorna 1 (o número de caracteres impressos).
*/
int ft_printpercent(void)
{
    write(1, "%", 1);
    return (1);
}
