
import hashlib


dictionary = open("dictionary.txt", "r").read().split()

correct_pw_hash = open('level5.hash.bin', 'rb').read()


def hash_pw(pw_str):
    pw_bytes = bytearray()
    pw_bytes.extend(pw_str.encode())
    m = hashlib.md5()
    m.update(pw_bytes)
    return m.digest()

for pow in dictionary:
    if(correct_pw_hash == hash_pw(pow)):
        print(pow)