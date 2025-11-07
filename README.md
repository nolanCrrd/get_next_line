# 📖 get_next_line (gnl)

This project is a project in the beginning of 42 common core, the objective was to create a function that allow to read a / severals file(s) descriptor(s) line by line.

The main restriction was that we can only read by BUFFER_SIZE (defined by -D during compilation), it's default value is 42 (coincidence 👀)

## ⚙️ Usage

We call the function with the fd that we want to read and it return an allocated `char *`that contain the line.

Each call give the next line of the given file.

```c
get_next_line(int fd);
```

It can be used to read multiple fd at the same time without conflicts.

## ⚠️ Warning

There will be memory leak for each fd that wasn't read to the end because `gnl` free information about a fd only when there still nothing to read in it.

## 🚫 Errors

If there is an error during the call, or if there is nothing left to read in the file it return a NULL pointer.

---

## 💭 Learned here

- Static variable in functions
- `read()` usage and optimizations (not reading 1 by 1)
- The utility of struct like chained_list