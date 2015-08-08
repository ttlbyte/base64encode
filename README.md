This project provide 2 files.
+ decode.c
+ encode.c

##Usage
To build the code:
```
$ gcc --std=c99 decode.c -o decode
$ gcc --std=c99 encode.c -o encode
```
To run the code:

```
./encode base64encode
YmFzZTY0Y29kZQ==
./decode YmFzZTY0Y29kZQ==
base64code
```
