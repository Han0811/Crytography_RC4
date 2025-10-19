# Crytography RC4

# Run file 

- Open file Encoder.c
- Replace the key and plaintext with the values you want to encode:

<p align="center">
<img src=".\image\1.png">
</p>

# Encoder

- Open terminal and build Encoder.exe:
```
gcc Encoder.c RC4.c -o Encoder
```
- Then run this command to execute the program and generate the 'ciphertext.txt' file:
```
Encoder
```

# Decoder

- Build Decoder.exe:
```
gcc Decoder.c RC4.c -o Decoder
```

- Run file Decoder.exe:
```
Decoder
```

# Result

After running all the commands below, you will get the result as follows:

<p align="center">
<img src=".\image\2.png">
</p>