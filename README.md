# get_next_line

This project is part of the curriculum at 42 school and aims to provide a function that reads a line from a file descriptor.

## Table of Contents

- [Project Description](#project-description)
- [Function Description](#function-description)
- [Installation](#installation)
- [Usage](#usage)

## Project Description

The "get_next_line" project focuses on developing a function that can read and return a line from a file descriptor. The main objectives of the project are:

1. Implementing a function that can read and return a line from a file descriptor.
2. Managing dynamic memory allocation and deallocation.
3. Utilizing a static variable to retain the remaining portion of the line between function calls.

## Function Description

The `get_next_line` function has the following prototype:

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.

The function reads a line from the specified file descriptor and returns it as a null-terminated string. It dynamically allocates memory to store the line, which must be freed by the caller when it is no longer needed.

The function returns:
- A pointer to the read line if a line has been read successfully.
- `NULL` when the end of file has been reached or when an error occurs.

## Installation

To use the "get_next_line" function, follow these steps:

1. Clone the repository to your local machine:

```
git clone <repo url> gnl
```

2. Navigate to the project directory:

```
cd gnl
```

3. Include the `get_next_line.h` header file in your code:

```c
#include "get_next_line.h"
```

4. Compile your project, linking it with the `get_next_line` function:

```
gcc your_code.c get_next_line.c get_next_line_utils.c -o your_program
```

## Usage

To use the `get_next_line` function, follow these steps:

1. Open a file and obtain its file descriptor.

2. Call the `get_next_line` function, passing the file descriptor as an argument.

3. Repeat the `get_next_line` function call in a loop to read the entire file line by line.

Remember to free the memory allocated for each line using `free(line)` after processing it.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    // Open the file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("");
        return (1);
    }

    // Print each line from the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    // Close the file
    close(fd);
    return (0);
}
```