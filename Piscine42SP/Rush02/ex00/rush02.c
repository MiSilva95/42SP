/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:26:29 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/31 16:39:04 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int	is_valid_number(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
	str++;
	}
	return (1);
}

void	read_file(int fd, char **buffer, ssize_t *totalbytesread)
{
	ssize_t	bytesread;
	size_t	remaining_bytes;

	remaining_bytes = BUFFER_SIZE;
	*buffer = malloc(BUFFER_SIZE);
	if (*buffer == NULL)
	{
		close(fd);
		return ;
	}
	*totalbytesread = 0;
	while (1)
	{
		bytesread = read(fd, *buffer + *totalbytesread, remaining_bytes);
		if (bytesread < 0)
			write (1, "Error", 6);
		if (bytesread == 0)
			break ;
		*totalbytesread += bytesread;
		remaining_bytes -= bytesread;
	}
	close(fd);
}

void	print_file_content(const char *filename)
{
	char	*buffer;
	int		fd;
	ssize_t	totalbytesread;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error", 6);
		return ;
	}
	read_file(fd, &buffer, &totalbytesread);
	write(1, buffer, totalbytesread);
	free(buffer);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	if (!is_valid_number(argv[1]))
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	print_file_content("numbers.dict");
	return (0);
}
