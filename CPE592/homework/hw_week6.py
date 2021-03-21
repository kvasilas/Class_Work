# Kirk Vasilas
#
# CPE 592
# Homework 3, Week 6
# RSA Encryption
#
# 3/20/2021

from math import pow

def decrypt(C,d,n):
    dec_bit= 1
    for j in range(d):
        num = C % n
        dec_bit = dec_bit * num
    return dec_bit % n 

# Take in message string
# msg = "Kirk Vasilas"
msg = "rsa"

# Convert message to array or ints
msg_array = []
for i in msg:
    num = ord(i) - 96
    msg_array.append(num)

# Assign p and q.  TODO make random gen num
p=5
q=11
n = p*q
y = (p-1)*(q-1)
e = 7 #TODO assign random number that is reletively prime to y
d = 23 #TODO still kinda confused on this look at puc

pub_key = [e,n]
pri_key = [d,n]

print("Public Key  : "+str(pub_key),"Private Key : "+str(pri_key)+"\n", sep="\n")

#Encrypt
encrypted_array = []
encrypted_msg = ""
for i in msg_array:
    C = int(pow(i,e) % n)
    encrypted_array.append(C)
    encrypted_msg += chr(C+96)

print("Message : "+msg,"Cipher MSG : "+encrypted_msg,"Message Array : "+str(msg_array),"Cipher Array  : "+str(encrypted_array), sep="\n")
print()

#Decrypt
decrypt_array = []
decrypt_msg = ""
for i in encrypted_array:
    dec = decrypt(i,d,n)
    decrypt_array.append(dec)
    decrypt_msg += chr(dec+96)
print("Decrypted Array : "+str(decrypt_array),"Decrypted MSG : "+decrypt_msg, sep ="\n")