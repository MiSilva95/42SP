# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// Função que retorna o comprimento de uma string
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;  // Inicializa a variável i para contar os caracteres da string
	while (s[i])  // Enquanto o caractere não for o terminador '\0'
		i++;  // Incrementa o contador i
	return (i);  // Retorna o comprimento da string
}

// Função que encontra o primeiro caractere 'c' na string 's'
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;  // Converte o ponteiro para char
	while (*str != c)  // Enquanto o caractere atual não for o procurado
	{
		if (*str == '\0')  // Se atingir o final da string
			return (NULL);  // Retorna NULL, pois o caractere não foi encontrado
		str++;  // Avança para o próximo caractere
	}
	return (str);  // Retorna o ponteiro para o caractere encontrado
}

// Função que concatena duas strings e retorna a nova string
char	*ft_strjoin(char *s1, char *s2)
{
	char	*start;
	char	*str;

	if (!s1 || !s2)  // Verifica se alguma das strings é NULL
		return (NULL);  // Se for, retorna NULL
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));  // Aloca memória para a nova string
	if (!str)  // Verifica se a alocação falhou
		return (NULL);  // Retorna NULL em caso de erro de alocação
	start = str;  // Armazena o ponteiro inicial para retornar depois
	while (*s1)  // Copia os caracteres da primeira string
		*str++ = *s1++;  // Avança o ponteiro e copia o caractere
	while (*s2)  // Copia os caracteres da segunda string
		*str++ = *s2++;  // Avança o ponteiro e copia o caractere
	*str = '\0';  // Coloca o terminador de string no final
	return (start);  // Retorna o ponteiro para a nova string concatenada
}

// Função que aloca e inicializa a memória, semelhante ao calloc
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;  // Inicializa o contador
	if (nmemb > ((size_t) - 1) / size)  // Verifica se o número de elementos multiplicado pelo tamanho não causa overflow
		return (NULL);  // Se causar, retorna NULL
	ptr = malloc(nmemb * size);  // Aloca a memória
	if (ptr == NULL)  // Verifica se a alocação falhou
		return (NULL);  // Retorna NULL em caso de falha
	while (i < nmemb * size)  // Preenche a memória com zero
	{
		((unsigned char *)ptr)[i] = '\0';  // Define o byte como 0
		i++;  // Incrementa o contador
	}
	return (ptr);  // Retorna o ponteiro para a memória alocada e inicializada
}

// Função que copia uma string para outra com limite de tamanho
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;  // Inicializa o contador
	if (size == 0)  // Se o tamanho de destino for 0
	{
		while (src[i])  // Conta o comprimento da string de origem
			i++;  // Incrementa o contador
		return (i);  // Retorna o comprimento da origem
	}
	while (i < size - 1 && src[i])  // Enquanto não ultrapassar o tamanho do destino e não chegar ao fim da origem
	{
		dst[i] = src[i];  // Copia os caracteres da origem para o destino
		i++;  // Incrementa o contador
	}
	if (i < size)  // Se ainda houver espaço no destino
		dst[i] = '\0';  // Coloca o terminador de string
	while (src[i])  // Conta o comprimento da string de origem
		i++;  // Incrementa o contador
	return (i);  // Retorna o comprimento da origem
}

// Função que junta duas strings e libera a memória da primeira
char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);  // Junta as strings
	free(text);  // Libera a memória da primeira string
	return (temp);  // Retorna o ponteiro para a nova string
}

// Função que lê a primeira linha de um arquivo, armazenando seu conteúdo em 'text'
char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)  // Se 'text' for NULL, aloca memória para inicializá-la
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));  // Aloca memória para o buffer
	if (!buffer)  // Verifica se a alocação falhou
		return (NULL);  // Retorna NULL
	bytes_read = 1;  // Inicializa o contador de bytes lidos
	while (bytes_read > 0)  // Enquanto houver dados para ler
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);  // Lê até 'BUFFER_SIZE' bytes do arquivo
		if (bytes_read == -1)  // Se ocorrer erro na leitura
		{
			free (text);  // Libera a memória alocada para 'text'
			free (buffer);  // Libera a memória alocada para 'buffer'
			return (NULL);  // Retorna NULL
		}
		buffer[bytes_read] = 0;  // Adiciona o terminador de string
		text = ft_join_and_free(text, buffer);  // Junta o conteúdo lido ao 'text'
		if (ft_strchr(text, '\n'))  // Se encontrar uma nova linha
			break ;  // Para a leitura
	}
	free (buffer);  // Libera a memória do buffer
	return (text);  // Retorna o conteúdo acumulado em 'text'
}

// Função que extrai uma linha de 'text' até a primeira nova linha
char	*extract_line(char *text)
{
	int		i;
	char	*line;

	i = 0;  // Inicializa o contador
	if (!text || !*text)  // Se 'text' for NULL ou vazio
		return (NULL);  // Retorna NULL
	while (text[i] && text[i] != '\n')  // Conta até a primeira nova linha ou fim da string
		i++;  // Incrementa o contador
	line = ft_calloc(i + 2, sizeof(char));  // Aloca memória para a linha (inclui o '\0' e o '\n' caso presente)
	if (!line)  // Verifica se a alocação falhou
		return (NULL);  // Retorna NULL
	ft_strlcpy(line, text, i + 2);  // Copia a linha para 'line'
	return (line);  // Retorna a linha extraída
}

// Função que limpa a primeira linha de 'text', removendo a parte lida
char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;  // Inicializa o contador
	j = 0;  // Inicializa o contador para a nova string
	while (text[i] && text[i] != '\n')  // Encontra o índice da nova linha
		i++;  // Incrementa o contador
	if (!text[i])  // Se não houver nova linha (fim da string)
	{
		free (text);  // Libera a memória de 'text'
		return (NULL);  // Retorna NULL
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));  // Aloca memória para a nova string
	if (!str)  // Verifica se a alocação falhou
		return (NULL);  // Retorna NULL
	while (text[++i])  // Copia o restante da string após a nova linha
		str[j++] = text[i];  // Incrementa e copia os caracteres
	str[j] = '\0';  // Coloca o terminador de string
	free (text);  // Libera a memória de 'text'
	return (str);  // Retorna o restante da string
}

// Função principal que retorna a próxima linha do arquivo
char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text;  // Variável estática para armazenar o conteúdo lido do arquivo

	if (fd < 0 || BUFFER_SIZE <= 0)  // Verifica se o fd ou BUFFER_SIZE são inválidos
		return (NULL);  // Retorna NULL
	text = read_first_line(fd, text);  // Lê a primeira linha do arquivo
	if (!text)  // Se houver erro na leitura
		return (NULL);  // Retorna NULL
	output_text = extract_line(text);  // Extrai a próxima linha
	text = clean_first_line(text);  // Limpa a primeira linha lida
	return (output_text);  // Retorna a linha extraída
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Type: ./a.out get_next_line.h\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	// fd = 0;
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}