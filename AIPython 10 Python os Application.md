### Programming using `os`

`os` is a built in module, that supports importing those [[Metaso_SystemCallsInterface]]

`uname` : check the detailed info of the OS
`os.environ` : a variable that stores all defined env vars
`os.environ,get('key')` : get a value from a env var

`os.path.abspath` : get the current abs path
`os.path.join` : In UNIX systems, it uses '/' to join the paths, and in Windows, it uses \ to join the paths.
Under many circumstances should we use this only, because path joined directly from string paths may not work as desired.

`os.listdir(path = '.')` : Going through current folder, and return a list containing the *item names* in a specific folder, which is given by `path`. The description is quite vague. Here is detailed explanation [[Metaso_Python os module]]
[[Metaso_DetailedOSJoinAndSplit]]



`os.mkdir(path, mode = 0o777, *, dir_fd = None)`

`os.rmdir(path, *, dir_fd = None)`

### Intro to OOP

