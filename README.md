gethal
======
C++ game

Graphical game depends on NotEye, which requires the following. Please visit the [Official NotEye site](www.roguetemple.com/z/noteye.php) to obtain the latest version.
* noteye-curses.h and noteye.h must be in the header search path.
* libnoteye.so must be in the library search path.
* zlib and curses must also be in the library search path as these are required by noteye.
* the game must know the location of the noteye directory and the noteye user directory. These can be passed in either through the command line parameters, or by setting the NOTEYE\_HOME and NOTEYE\_USER\_HOME environment variables. If neither of these are defined, then it will default to the default install locations ( /usr/share/noteye and ~/.config/noteye). The noteye directory is expected to contain the common, games, gfx, and sounds subdirectories. The noteye user dir is expected to contain a file called config.noe which specifies the user's noteye config.
