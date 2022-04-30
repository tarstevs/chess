### For debugging in CLion with GDB

Make sure the project root directory has it's own .gdbinit file designating what the debugger should skip. Then put a
second .gdbinit file in the users operating system home directory, containing `set auto-load local-gdbinit on` on the
first line, followed by a line for each C++ project root directory where the format for each such line
is `add-auto-load-safe-path /path/to/project/root/.gdbinit`

* set auto-load local-gdbinit on
* add-auto-load-safe-path /home/jason/dev/chess/.gdbinit

#### Acknowledgements

Art for chess pieces are being used under the CC BY-SA 3.0 license. The creator of the art requested the following
copyright/attribution notice:
JohnPablok's improved Cburnett chess set.