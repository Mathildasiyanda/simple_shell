#include "shell.h"

/**
 * get_custom_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containing the history file
 */

char *get_custom_history_file(info_t *info)
{
    char *directory, *historyFile;

    directory = _getenv(info, "HOME=");
    if (!directory)
        return (NULL);

    historyFile = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
    if (!historyFile)
    {
        free(directory);
        return (NULL);
    }

    historyFile[0] = 0;
    _strcpy(historyFile, directory);
    _strcat(historyFile, "/");
    _strcat(historyFile, HIST_FILE);
    free(directory);
    return (historyFile);
}

/**
 * write_custom_history - creates a file or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_custom_history(info_t *info)
{
    ssize_t fileDescriptor;
    char *filename = get_custom_history_file(info);
    list_t *node = NULL;

    if (!filename)
        return (-1);

    fileDescriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(filename);

    if (fileDescriptor == -1)
        return (-1);

    for (node = info->commandHistory; node; node = node->next)
    {
        _putsfd(node->str, fileDescriptor);
        _putfd('\n', fileDescriptor);
    }

    _putfd(BUF_FLUSH, fileDescriptor);
    close(fileDescriptor);
    return (1);
}

/**
 * read_custom_history - reads history from a file
 * @info: the parameter struct
 *
 * Return: history count on success, 0 otherwise
 */
int read_custom_history(info_t *info)
{
    int i, last = 0, historyCount = 0;
    ssize_t fileDescriptor, readLength, fileSize = 0;
    struct stat st;
    char *buffer = NULL, *filename = get_custom_history_file(info);

    if (!filename)
        return (0);

    fileDescriptor = open(filename, O_RDONLY);
    free(filename);

    if (fileDescriptor == -1)
        return (0);

    if (!fstat(fileDescriptor, &st))
        fileSize = st.st_size;

    if (fileSize < 2)
        return (0);

    buffer = malloc(sizeof(char) * (fileSize + 1));

    if (!buffer)
        return (0);

    readLength = read(fileDescriptor, buffer, fileSize);
    buffer[fileSize] = 0;

    if (readLength <= 0)
    {
        free(buffer);
        return 0;
    }

    close(fileDescriptor);

    for (i = 0; i < fileSize; i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = 0;
            build_custom_history_list(info, buffer + last, historyCount++);
            last = i + 1;
        }
    }

    if (last != i)
        build_custom_history_list(info, buffer + last, historyCount++);

    free(buffer);
    info->historyCount = historyCount;

    while (info->historyCount-- >= HIST_MAX)
        delete_node_at_index(&(info->commandHistory), 0);

    renumber_custom_history(info);
    return (info->historyCount);
}

/**
 * build_custom_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history line count
 *
 * Return: Always 0
 */
int build_custom_history_list(info_t *info, char *buf, int linecount)
{
    list_t *node = NULL;

    if (info->commandHistory)
        node = info->commandHistory;

    add_node_end(&node, buf, linecount);

    if (!info->commandHistory)
        info->commandHistory = node;

    return 0;
}

/**
 * renumber_custom_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new history count
 */
int renumber_custom_history(info_t *info)
{
    list_t *node = info->commandHistory;
    int i = 0;

    while (node)
    {
        node->num = i++;
        node = node->next;
    }

    return (info->historyCount = i);
}

